//
//  Generated by the J2ObjC translator.  DO NOT EDIT!
//  source: //com/intel/wearable/platform/timeiq/extended_events/ExtendedEventInstance.java
//

#ifndef _ExtendedEventInstance_H_
#define _ExtendedEventInstance_H_

@class ExtendedEventTemplate;
#import "JBArrayList.h"
@class eExtendedEventState;

#import "JB.h"

/**
 @brief Created by smoradof on 7/28/2015.
 */
@interface ExtendedEventInstance : NSObject {
 @public
  ExtendedEventTemplate *mExtendedEventTemplate_;
  eExtendedEventState *mState_;
  NSString *mId_;
  ArrayList *mReminderIds_;
  NSString *mBeEventId_;
}

- (instancetype)initWithExtendedEventTemplate:(ExtendedEventTemplate *)extendedEventTemplate;

- (ExtendedEventTemplate *)getExtendedEventTemplate;

- (eExtendedEventState *)getState;

- (NSString *)getId;

- (void)setBeEventIdWithNSString:(NSString *)id_;

- (void)addReminderIdWithNSString:(NSString *)id_;

- (NSString *)getBeEventId;

- (ArrayList *)getReminderIds;

- (void)copyAllFieldsTo:(ExtendedEventInstance *)other;

@end

__attribute__((always_inline)) inline void ExtendedEventInstance_init() {}

//J2OBJC_FIELD_SETTER(ExtendedEventInstance, mExtendedEventTemplate_, ExtendedEventTemplate *)
//J2OBJC_FIELD_SETTER(ExtendedEventInstance, mState_, eExtendedEventState *)
//J2OBJC_FIELD_SETTER(ExtendedEventInstance, mId_, NSString *)
//J2OBJC_FIELD_SETTER(ExtendedEventInstance, mReminderIds_, ArrayList *)
//J2OBJC_FIELD_SETTER(ExtendedEventInstance, mBeEventId_, NSString *)

typedef ExtendedEventInstance ComIntelWearablePlatformTimeiqExtended_eventsExtendedEventInstance;

#endif // _ExtendedEventInstance_H_