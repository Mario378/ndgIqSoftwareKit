//
//  Generated by the J2ObjC translator.  DO NOT EDIT!
//  source: //com/intel/wearable/platform/timeiq/internalApi/ttlAlerts/ITSOAlertListener.java
//

#ifndef _ITSOAlertListener_H_
#define _ITSOAlertListener_H_

@class TSOAlertTriggeredResult;
@class TSOAlertUpdatedResult;

#import "JB.h"

/**
 @brief A listener to get the TSOAlertTriggeredResult when an alert was triggered and TSOAlertUpdatedResult when an alert is updated
 */
@protocol ITSOAlertListener < NSObject >

/**
 @brief Called when an alert is triggered.
 @param result - the detailed result of the alert
 */
- (void)onAlertTriggeredWithTSOAlertTriggeredResult:(TSOAlertTriggeredResult *)result;

/**
 @brief Called when an alert is updated, this does not precede #onAlertTriggered(TSOAlertTriggeredResult) , and might notify about the termination of the alert in some cases (cannot reach the destination in time, etc.)
 @param result - the detailed result of the alert
 */
- (void)onAlertUpdatedWithTSOAlertUpdatedResult:(TSOAlertUpdatedResult *)result;

@end

__attribute__((always_inline)) inline void ITSOAlertListener_init() {}

#define ComIntelWearablePlatformTimeiqInternalApiTtlAlertsITSOAlertListener ITSOAlertListener

#endif // _ITSOAlertListener_H_