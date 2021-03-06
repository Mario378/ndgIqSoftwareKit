//
//  Generated by the J2ObjC translator.  DO NOT EDIT!
//  source: //com/intel/wearable/platform/timeiq/sensors/replay/SimulatedSensor.java
//

#ifndef _SimulatedSensor_H_
#define _SimulatedSensor_H_

#import "JBClass.h"
#import "JBThread.h"
#import "JBArrayList.h"
@class PlaybackFileManager;
@class PolicyChangeInfo;
@class PolicyMode;
@class ReplayMode;
@class SensorType;
@class SensorsEngine;
@class SimulatedSensor_DumpFileReaderWorker;
@protocol ISimulateListener;
#import "JBHashtable.h"

#import "JB.h"
#import "IPolicyListener.h"
#import "JBRunnable.h"

/**
 @brief Created by orencoh2 on 9/11/14
 */
@interface SimulatedSensor : NSObject < IPolicyListener > {
 @public
  ReplayMode *m_repReplayMode_;
  SimulatedSensor_DumpFileReaderWorker *m_dumpFileReaderWorker_;
  Thread *m_sensorSimThread_;
  SensorsEngine *m_sensorsEngine_;
  id<ISimulateListener> m_iSimulateListener_;
  PlaybackFileManager *m_playbackFileManager_;
  HashMap* m_sensorsPoliciesMap_;
  HashMap* m_sensorsLastSampleMap_;
  PolicyMode *m_policyMode_;
  boolean m_applyResourceManager_;
  Class alarmManagerClass_;
  Class timeUtilClass_;
}

/**
 @brief RES MANAGER TASKS - add check box on activity+ with/without resource manager - remove option for replay mode, every one is using the insane anyway - need to apply the fact that each file represents a new run - on this case start with regular and go on from there - apply the filter subject to m_applyResourceManager
 */
- (instancetype)init;

+ (void)init__ OBJC_METHOD_FAMILY_NONE;

+ (void)dispose;

+ (SimulatedSensor *)getInstance;

- (void)initiateSimulatedSensorWithArrayList:(ArrayList *)dumpFileNames OBJC_METHOD_FAMILY_NONE;

- (void)initiateSimulatedSensorFromInputStreamListWithArrayList:(ArrayList *)dumpFileNames OBJC_METHOD_FAMILY_NONE;

/**
 @brief Notify that the entire policy was changed
 @param policyChangeInfo new policy
 */
- (void)onPolicyChangeWithPolicyChangeInfo:(PolicyChangeInfo *)policyChangeInfo;

/**
 @brief Notify that there is a change on location sample mode: GPS available or lost
 @param isHighAccuracySample
 */
- (void)onLocationSampleChangeWithBoolean:(boolean)isHighAccuracySample;

- (boolean)approvedByPolicyWithSensorType:(SensorType *)sensorType
                                      withLong:(long64)currentTimeStamp;

- (void)startReplayWithArrayList:(ArrayList *)dumpFileNames
                      withReplayMode:(ReplayMode *)replayMode;

- (void)startReplayWithArrayList:(ArrayList *)dumpFileNames
                      withReplayMode:(ReplayMode *)replayMode
                             withBoolean:(boolean)applyResourceManager;

/**
 @brief Hard Clean sensor engine - stop sensors & soft clean
 */
- (void)hardCleanSensorsEngine;

/**
 @brief Soft Clean sensor engine - reset & unregister (sensors are still running)
 */
- (void)softCleanSensorsEngine;

- (void)startReplayWithInputStreamWithArrayList:(ArrayList *)dumpFileNames
                                     withReplayMode:(ReplayMode *)replayMode
                                            withBoolean:(boolean)applyResourceManager;

- (void)launchReplayWithReplayMode:(ReplayMode *)replayMode
                           withBoolean:(boolean)applyResourceManager;

- (boolean)stopReplay;

/**
 @brief register debug classes for AlarmManager and TimeUtil
 */
- (void)startDebugTimeUtil;

/**
 @brief unregister debug time classes
 */
- (void)stopDebugTimeUtil;

- (void)registerListenerWithISimulateListener:(id<ISimulateListener>)iSimulateListener;

- (void)copyAllFieldsTo:(SimulatedSensor *)other;

@end

FOUNDATION_EXPORT BOOL SimulatedSensor_initialized;
J2OBJC_STATIC_INIT(SimulatedSensor)

//J2OBJC_FIELD_SETTER(SimulatedSensor, m_repReplayMode_, ReplayMode *)
//J2OBJC_FIELD_SETTER(SimulatedSensor, m_dumpFileReaderWorker_, SimulatedSensor_DumpFileReaderWorker *)
//J2OBJC_FIELD_SETTER(SimulatedSensor, m_sensorSimThread_, Thread *)
//J2OBJC_FIELD_SETTER(SimulatedSensor, m_sensorsEngine_, SensorsEngine *)
//J2OBJC_FIELD_SETTER(SimulatedSensor, m_iSimulateListener_, id<ISimulateListener>)
//J2OBJC_FIELD_SETTER(SimulatedSensor, m_playbackFileManager_, PlaybackFileManager *)
//J2OBJC_FIELD_SETTER(SimulatedSensor, m_sensorsPoliciesMap_, HashMap*)
//J2OBJC_FIELD_SETTER(SimulatedSensor, m_sensorsLastSampleMap_, HashMap*)
//J2OBJC_FIELD_SETTER(SimulatedSensor, m_policyMode_, PolicyMode *)
//J2OBJC_FIELD_SETTER(SimulatedSensor, alarmManagerClass_, Class )
//J2OBJC_FIELD_SETTER(SimulatedSensor, timeUtilClass_, Class )

FOUNDATION_EXPORT NSString *SimulatedSensor_TAG_;
J2OBJC_STATIC_FIELD_GETTER(SimulatedSensor, TAG_, NSString *)

FOUNDATION_EXPORT int SimulatedSensor_TIME_FACTOR_REAL_TIME_;
J2OBJC_STATIC_FIELD_GETTER(SimulatedSensor, TIME_FACTOR_REAL_TIME_, int)
//J2OBJC_STATIC_FIELD_REF_GETTER(SimulatedSensor, TIME_FACTOR_REAL_TIME_, int)

FOUNDATION_EXPORT int SimulatedSensor_TIME_FACTOR_FAST_FORWARD_;
J2OBJC_STATIC_FIELD_GETTER(SimulatedSensor, TIME_FACTOR_FAST_FORWARD_, int)
//J2OBJC_STATIC_FIELD_REF_GETTER(SimulatedSensor, TIME_FACTOR_FAST_FORWARD_, int)

FOUNDATION_EXPORT SimulatedSensor *SimulatedSensor_m_instance_;
J2OBJC_STATIC_FIELD_GETTER(SimulatedSensor, m_instance_, SimulatedSensor *)
//J2OBJC_STATIC_FIELD_SETTER(SimulatedSensor, m_instance_, SimulatedSensor *)

typedef SimulatedSensor ComIntelWearablePlatformTimeiqSensorsReplaySimulatedSensor;

@interface SimulatedSensor_DumpFileReaderWorker : NSObject < Runnable > {
 @public
  SimulatedSensor *this$0_;
  NSString *TAG_;
}

- (instancetype)initWithSimulatedSensor:(SimulatedSensor *)outer$;

- (void)run;

- (void)copyAllFieldsTo:(SimulatedSensor_DumpFileReaderWorker *)other;

@end

__attribute__((always_inline)) inline void SimulatedSensor_DumpFileReaderWorker_init() {}

//J2OBJC_FIELD_SETTER(SimulatedSensor_DumpFileReaderWorker, this$0_, SimulatedSensor *)
//J2OBJC_FIELD_SETTER(SimulatedSensor_DumpFileReaderWorker, TAG_, NSString *)

#endif // _SimulatedSensor_H_
