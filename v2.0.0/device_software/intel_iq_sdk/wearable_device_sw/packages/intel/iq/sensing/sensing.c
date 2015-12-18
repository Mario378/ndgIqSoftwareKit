/*
 * Copyright (c) 2015, Intel Corporation. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
 * and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its contributors
 * may be used to endorse or promote products derived from this software without
 * specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#include "os/os.h"
#include "infra/log.h"

#include "cfw/cfw.h"
/* CFW messages definition, to get connection messages definitions */
#include "cfw/cfw_messages.h"
/* Get services queue */
#include "services/service_queue.h"

/* Main sensors API */
#include "services/sensor_service/sensor_svc_api.h"
/* Utility API */
#include "services/sensor_service/sensor_svc_utils.h"

/* Sensors properties */
static cfw_client_t * sensor_client;

static void (*sensing_gesture_cb)(uint8_t *) = NULL;
static void (*sensing_tapping_cb)(int16_t) = NULL;
static void (*sensing_stepcounter_cb)(uint32_t, uint32_t, uint32_t) = NULL;

/* handle for sensors data */
static void handle_sensor_subscribe_data(struct cfw_message *msg)
{
	ss_sensor_subscribe_data_event_t *p_evt =
		(ss_sensor_subscribe_data_event_t *)msg;
	ss_sensor_data_header_t *p_data_header = &p_evt->sensor_data_header;
	uint8_t sensor_type = GET_SENSOR_TYPE(p_evt->handle);

	switch (sensor_type) {
	/* TODO: use a header from sensor service defining these structs:
	 * redifining message structure is not a good practice. */
	case SENSOR_PATTERN_MATCHING_GESTURE: {
		struct gs_personalize *p =
			(struct gs_personalize *)p_data_header->data;
		pr_info(LOG_MODULE_IQ, "GESTURE=%d,size=%d",
			p->nClassLabel, p->size);
		if(sensing_gesture_cb) {
			sensing_gesture_cb(p_data_header->data);
		}
	}
	break;
	case SENSOR_ABS_TAPPING: {
		struct tapping_result *p =
			(struct tapping_result *)p_data_header->data;
		pr_info(LOG_MODULE_IQ, "TAPPING=%d", p->tapping_cnt);
		if(sensing_tapping_cb) {
			sensing_tapping_cb(p->tapping_cnt);
		}
	}
	break;
	case SENSOR_ABS_STEPCOUNTER: {
		struct stepcounter_result *p =
			(struct stepcounter_result *)p_data_header->data;
		pr_info(LOG_MODULE_IQ, "steps:%d  activity:%d",
			p->steps, p->activity);
		if(sensing_stepcounter_cb) {
			sensing_stepcounter_cb(p->steps,
					       p->activity,
					       p_data_header->timestamp);
		}
	}
	break;
	case SENSOR_ACCELEROMETER:
	{
		int i = 0;
		static int accel_read_count = 0;
		int data_len = p_data_header->data_length;
		int data_num = data_len / sizeof(struct accel_phy_data);
		uint8_t data_type = ACCEL_DATA;
		if (accel_read_count++ >= 3) {
			ss_sensor_unsubscribe_data(sensor_client, NULL,
						   p_evt->handle, &data_type, 1);
			accel_read_count = 0;
			break;
		}

		for (i = 0; i < data_num; i++) {
			struct accel_phy_data *p_data =
				(struct accel_phy_data *)p_data_header->data +
				i;
			pr_debug(
				LOG_MODULE_SS_SVC,
				"[APP][NUM=%d]stamp(ms):%d, x(mg):%d, y(mg):%d, z(mg):%d",
				i, p_data_header->timestamp, (p_data->ax),
				(p_data->ay), (p_data->az));
		}
	} break;
	}
}

static void handle_start_scanning_evt(struct cfw_message *msg)
{
	ss_sensor_scan_event_t *p_evt = (ss_sensor_scan_event_t *)msg;
	ss_on_board_scan_data_t on_board_data = p_evt->on_board_data;
	uint8_t sensor_type = p_evt->sensor_type;

	p_evt->handle = GET_SENSOR_HANDLE(sensor_type, on_board_data.ch_id);
	uint8_t data_type = ACCEL_DATA;
	switch (sensor_type) {
	case SENSOR_PATTERN_MATCHING_GESTURE:
		ss_sensor_subscribe_data(sensor_client, NULL, p_evt->handle,
					 &data_type, 1, 100, 10);

		break;
	case SENSOR_ABS_TAPPING:
		ss_sensor_subscribe_data(sensor_client, NULL, p_evt->handle,
					 &data_type, 1, 100, 0);
		break;
	case SENSOR_ABS_STEPCOUNTER:
		ss_sensor_subscribe_data(sensor_client, NULL, p_evt->handle,
					 &data_type, 1, 33, 0);
		break;
	case SENSOR_ACCELEROMETER:
		ss_sensor_subscribe_data(sensor_client, NULL, p_evt->handle,
				&data_type, 1, 1, 1000);
		break;
	case SENSOR_GYROSCOPE:
		ss_sensor_subscribe_data(sensor_client, NULL, p_evt->handle,
				&data_type, 1, 1, 1000);
		break;

	}
}

static void sensor_handle_msg(struct cfw_message *msg, void *data)
{
	switch (CFW_MESSAGE_ID(msg)) {
	case MSG_ID_SS_START_SENSOR_SCANNING_EVT:
		handle_start_scanning_evt(msg);
		break;
	case MSG_ID_SS_SENSOR_SUBSCRIBE_DATA_EVT:
		handle_sensor_subscribe_data(msg);
		break;
	}
	cfw_msg_free(msg);
}

static void sensing_start_sensor_scanning(cfw_service_conn_t *conn, void *param)
{
	sensor_client = conn;
	ss_start_sensor_scanning(conn, NULL,
				  PATTERN_MATCHING_TYPE_MASK
				 | TAPPING_TYPE_MASK
				 | STEPCOUNTER_TYPE_MASK
				 );
}

void sensing_iq_init(T_QUEUE queue)
{
	static bool sensing_initialized = false;

	if (!sensing_initialized){
		sensor_client = cfw_client_init(queue, sensor_handle_msg, NULL);

		cfw_open_service_helper(sensor_client, ARC_SC_SVC_ID,
				sensing_start_sensor_scanning, NULL);
		sensing_initialized = true;
	}
}

void sensing_set_gesture_cb(void (*gesture_cb)(uint8_t *))
{
	sensing_gesture_cb = gesture_cb;
}
void sensing_set_tapping_cb(void (*tapping_cb)(int16_t))
{
	sensing_tapping_cb = tapping_cb;
}
void sensing_set_stepcounter_cb(void (*stepcounter_cb)(uint32_t, uint32_t, uint32_t))
{
	sensing_stepcounter_cb = stepcounter_cb;
}
