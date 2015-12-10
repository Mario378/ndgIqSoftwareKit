//
//  Generated by the J2ObjC translator.  DO NOT EDIT!
//  source: //com/intel/wearable/platform/timeiq/sensors/resourcemanager/policy/PolicyHistoryInfo.java
//

#ifndef _PolicyHistoryInfo_H_
#define _PolicyHistoryInfo_H_

@class DBPolicyHistoryInfo;
@class PolicyMode;
@class SDKPolicy;
#import "JBHashtable.h"

#import "JB.h"
#import "ATSOSyncDbObject.h"

/**
 @brief Created by eleuchte on 3/25/2015.
 */
@interface PolicyHistoryInfo : ATSOSyncDbObject {
 @public
  PolicyMode *m_previousPolicy_;
  PolicyMode *m_newPolicy_;
  long64 m_timeStamp_;
  HashMap* m_sensorsSampleIntervals_;
}

- (instancetype)init;

- (instancetype)initWithPolicyMode:(PolicyMode *)previousPolicyMode
                         withSDKPolicy:(SDKPolicy *)newPolicy
                              withLong:(long64)timeStamp;

- (instancetype)initWithDBPolicyHistoryInfo:(DBPolicyHistoryInfo *)dbPolicyHistoryInfo;

- (PolicyMode *)getPreviousPolicy;

- (PolicyMode *)getNewPolicy;

- (long64)getTimeStamp;

- (HashMap*)getSensorsSampleIntervals;

- (boolean)isEqual:(id)o;

- (NSUInteger)hash;

- (void)initObjectFromMapWithJavaUtilMap:(HashMap*)stringObjectMap OBJC_METHOD_FAMILY_NONE;

- (HashMap*)objectToMap;

- (DBPolicyHistoryInfo *)convertPolicyHistoryToDBPolicyHistory;

- (void)copyAllFieldsTo:(PolicyHistoryInfo *)other;

@end

__attribute__((always_inline)) inline void PolicyHistoryInfo_init() {}

//J2OBJC_FIELD_SETTER(PolicyHistoryInfo, m_previousPolicy_, PolicyMode *)
//J2OBJC_FIELD_SETTER(PolicyHistoryInfo, m_newPolicy_, PolicyMode *)
//J2OBJC_FIELD_SETTER(PolicyHistoryInfo, m_sensorsSampleIntervals_, HashMap*)

FOUNDATION_EXPORT NSString *PolicyHistoryInfo_PREVIOUS_POLICY_FIELD_;
J2OBJC_STATIC_FIELD_GETTER(PolicyHistoryInfo, PREVIOUS_POLICY_FIELD_, NSString *)

FOUNDATION_EXPORT NSString *PolicyHistoryInfo_NEW_POLICY_FIELD_;
J2OBJC_STATIC_FIELD_GETTER(PolicyHistoryInfo, NEW_POLICY_FIELD_, NSString *)

FOUNDATION_EXPORT NSString *PolicyHistoryInfo_TIMESTAMP_FIELD_;
J2OBJC_STATIC_FIELD_GETTER(PolicyHistoryInfo, TIMESTAMP_FIELD_, NSString *)

FOUNDATION_EXPORT NSString *PolicyHistoryInfo_SENSORS_SAMPLE_INTERVALS_KEYS_FIELD_;
J2OBJC_STATIC_FIELD_GETTER(PolicyHistoryInfo, SENSORS_SAMPLE_INTERVALS_KEYS_FIELD_, NSString *)

FOUNDATION_EXPORT NSString *PolicyHistoryInfo_SENSORS_SAMPLE_INTERVALS_VALUES_FIELD_;
J2OBJC_STATIC_FIELD_GETTER(PolicyHistoryInfo, SENSORS_SAMPLE_INTERVALS_VALUES_FIELD_, NSString *)

typedef PolicyHistoryInfo ComIntelWearablePlatformTimeiqSensorsResourcemanagerPolicyPolicyHistoryInfo;

#endif // _PolicyHistoryInfo_H_