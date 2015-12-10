//
//  Generated by the J2ObjC translator.  DO NOT EDIT!
//  source: //com/intel/wearable/platform/timeiq/reminders/phoneBasedReminder/BasePhoneReminderInner.java
//

#ifndef _BasePhoneReminderInner_H_
#define _BasePhoneReminderInner_H_

@class BasePhoneReminder;
@class ContactInfo;
@protocol ITSOTimeUtil;
#import "JBHashtable.h"

#import "JB.h"
#import "BaseReminderInner.h"

/**
 @brief Created by mleib on 30/04/2015.
 */
@interface BasePhoneReminderInner : BaseReminderInner {
 @public
  ContactInfo *m_contactInfo_;
}

- (instancetype)init;

- (instancetype)initWithBasePhoneReminder:(BasePhoneReminder *)phoneBasedReminder
                         withITSOTimeUtil:(id<ITSOTimeUtil>)tsoTimeUtil;

- (ContactInfo *)getContactInfo;

- (boolean)isEqual:(id)o;

- (NSUInteger)hash;

- (void)initObjectFromMapWithJavaUtilMap:(HashMap*)stringObjectMap OBJC_METHOD_FAMILY_NONE;

- (HashMap*)objectToMap;

- (void)copyAllFieldsTo:(BasePhoneReminderInner *)other;

@end

__attribute__((always_inline)) inline void BasePhoneReminderInner_init() {}

//J2OBJC_FIELD_SETTER(BasePhoneReminderInner, m_contactInfo_, ContactInfo *)

FOUNDATION_EXPORT NSString *BasePhoneReminderInner_CONTACT_INFO_FIELD_;
J2OBJC_STATIC_FIELD_GETTER(BasePhoneReminderInner, CONTACT_INFO_FIELD_, NSString *)

typedef BasePhoneReminderInner ComIntelWearablePlatformTimeiqRemindersPhoneBasedReminderBasePhoneReminderInner;

#endif // _BasePhoneReminderInner_H_