//
//  Generated by the J2ObjC translator.  DO NOT EDIT!
//  source: //com/intel/wearable/platform/timeiq/reminders/RemindersManager.java
//

#ifndef _RemindersManager_H_
#define _RemindersManager_H_

@class ClassFactory;
#import "JBEnumSet.h"
@class ReminderEndReason;
@class Result;
@class ResultData;
@class SnoozeOption;
@protocol IApiUsageUtil;
@protocol IReminder;
@protocol IRemindersManagerModule;
@protocol ITrigger;

#import "JB.h"
#import "IRemindersManager.h"

/**
 @brief Created by stzour on 07/12/2015.
 */
@interface RemindersManager : NSObject < IRemindersManager > {
 @public
  id<IRemindersManagerModule> remindersManagerModule_;
  id<IApiUsageUtil> apiUsageUtil_;
}

- (instancetype)init;

- (instancetype)initWithClassFactory:(ClassFactory *)classFactory;

- (instancetype)initWithIRemindersManagerModule:(id<IRemindersManagerModule>)remindersManagerModule
                              withIApiUsageUtil:(id<IApiUsageUtil>)apiUsageUtil;

- (Result *)addReminderWithIReminder:(id<IReminder>)reminderToAdd;

- (Result *)removeReminderWithNSString:(NSString *)reminderId;

- (Result *)removeAllReminders;

- (ResultData *)getSnoozeOptionsWithNSString:(NSString *)reminderId;

- (Result *)snoozeReminderWithSnoozeOptionWithNSString:(NSString *)reminderId
                                      withSnoozeOption:(SnoozeOption *)snoozeOption;

- (Result *)snoozeReminderWithTriggerWithNSString:(NSString *)reminderId
                                     withITrigger:(id<ITrigger>)newTrigger;

- (void)onDestroy;

- (ResultData *)getReminderWithNSString:(NSString *)reminderId;

- (ResultData *)getRemindersWithEnumSet:(EnumSet *)reminderStatuses;

- (Result *)endReminderWithNSString:(NSString *)reminderId
          withReminderEndReason:(ReminderEndReason *)reminderEndReason;

- (void)copyAllFieldsTo:(RemindersManager *)other;

@end

__attribute__((always_inline)) inline void RemindersManager_init() {}

//J2OBJC_FIELD_SETTER(RemindersManager, remindersManagerModule_, id<IRemindersManagerModule>)
//J2OBJC_FIELD_SETTER(RemindersManager, apiUsageUtil_, id<IApiUsageUtil>)

typedef RemindersManager ComIntelWearablePlatformTimeiqRemindersRemindersManager;

#endif // _RemindersManager_H_