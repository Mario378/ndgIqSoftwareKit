//
//  Generated by the J2ObjC translator.  DO NOT EDIT!
//  source: //com/intel/wearable/platform/timeiq/triggers/mot/MotTriggerInner.java
//

#ifndef _MotTriggerInner_H_
#define _MotTriggerInner_H_

@class MotTransition;
@class MotTrigger;
@class MotType;
@protocol ITSOTimeUtil;
@protocol ITrigger;
#import "JBHashtable.h"

#import "JB.h"
#import "BaseTriggerInner.h"

/**
 @brief Created by mleib on 26/04/2015.
 */
@interface MotTriggerInner : BaseTriggerInner {
 @public
  MotTransition *m_motTransition_;
  MotType *m_motType_;
}

- (instancetype)init;

- (instancetype)initWithMotTrigger:(MotTrigger *)motTrigger;

- (instancetype)initWithMotTrigger:(MotTrigger *)motTrigger
                  withITSOTimeUtil:(id<ITSOTimeUtil>)tsoTimeUtil;

- (MotType *)getMotType;

- (MotTransition *)getMotTransition;

- (boolean)isEqual:(id)o;

- (NSUInteger)hash;

- (void)initObjectFromMapWithJavaUtilMap:(HashMap*)stringObjectMap OBJC_METHOD_FAMILY_NONE;

- (HashMap*)objectToMap;

- (id<ITrigger>)createTrigger;

- (void)copyAllFieldsTo:(MotTriggerInner *)other;

@end

__attribute__((always_inline)) inline void MotTriggerInner_init() {}

//J2OBJC_FIELD_SETTER(MotTriggerInner, m_motTransition_, MotTransition *)
//J2OBJC_FIELD_SETTER(MotTriggerInner, m_motType_, MotType *)

FOUNDATION_EXPORT NSString *MotTriggerInner_MOT_TRANSITION_FIELD_;
J2OBJC_STATIC_FIELD_GETTER(MotTriggerInner, MOT_TRANSITION_FIELD_, NSString *)

FOUNDATION_EXPORT NSString *MotTriggerInner_MOT_TYPE_FIELD_;
J2OBJC_STATIC_FIELD_GETTER(MotTriggerInner, MOT_TYPE_FIELD_, NSString *)

typedef MotTriggerInner ComIntelWearablePlatformTimeiqTriggersMotMotTriggerInner;

#endif // _MotTriggerInner_H_
