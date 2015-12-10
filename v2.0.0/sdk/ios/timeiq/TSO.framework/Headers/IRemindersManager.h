//
//  Generated by the J2ObjC translator.  DO NOT EDIT!
//  source: //com/intel/wearable/platform/timeiq/api/reminders/IRemindersManager.java
//

#ifndef _IRemindersManager_H_
#define _IRemindersManager_H_

#import "JBEnumSet.h"
@class ReminderEndReason;
@class Result;
@class ResultData;
@class SnoozeOption;
@protocol IReminder;
@protocol ITrigger;

#import "JB.h"

/**
 @brief Enables to add reminder with a trigger. the manager will send a message through the EventsManager. include utility methods for get reminders, remove and snooze them.
 Example for creating and adding a reminder for "Turn on the car lights" when you start driving: //create a trigger: ITrigger trigger = null; try { trigger = new MotTrigger.MotTriggerBuilder(MotType.CAR, MotTransition.START).build();  // trigger for mot to change to car started (will not be triggered now, if you are currently driving) } catch (TriggerBuildException e) {  } //create a reminder IReminder reminder = null; if (trigger != null) { try { reminder = new DoReminder.DoReminderBuilder(trigger, "Turn on the car lights").build(); }catch (ReminderBuildException e) {  } } if(reminder != null) { // add the reminder Result result = TimeIQBGService.mTimeIQApi.getRemindersManager().addReminder(reminder); // TimeIQBGService.mTimeIQApi - see below String message = result.isSuccess() ? "reminder_was_added" : // reminder added OK "reminder_was_not_added" + result.getMessage(); // reminder was not added with the error } to initialize the SDK and listen for reminders that were triggered see: TimeIQApi
 */
@protocol IRemindersManager < NSObject >

/**
 @brief Add a new reminder
 @param reminderToAdd the reminder to be added
 @return a result that state whether the adding process was successful (test with Result#isSuccess() ) or not (error will be supplied in Result#getResultCode() and Result#getMessage() )
 */
- (Result *)addReminderWithIReminder:(id<IReminder>)reminderToAdd;

/**
 @brief Remove an existing reminder by its unique ID
 @param reminderId the unique ID of the reminder
 @return a success result if the reminder was successfully removed and error result otherwise
 */
- (Result *)removeReminderWithNSString:(NSString *)reminderId;

/**
 @brief Remove all the reminders
 @return a success result if the reminder was successfully removed and error result otherwise
 */
- (Result *)removeAllReminders;

/**
 @brief Get snooze options for a specific reminder using its unique ID <BR> the snooze options can be used to defer the reminder until a later time (or state)
 @param reminderId the unique ID of the reminder
 @return the snooze options that can be used to defer the reminder
 */
- (ResultData *)getSnoozeOptionsWithNSString:(NSString *)reminderId;

/**
 @brief Defer a specific reminder until a later time (or state) using snooze options <BR> <B>Only a triggered ( ReminderStatus#Triggered ) reminder can be snoozed</B>
 @param reminderId the unique ID of the reminder
 @param snoozeOption the snooze options to be used to defer the reminder
 @return a result that state whether the snoozing process was successful (test with Result#isSuccess() ) or not (error will be supplied in Result#getResultCode() and Result#getMessage() )
 */
- (Result *)snoozeReminderWithSnoozeOptionWithNSString:(NSString *)reminderId
                                      withSnoozeOption:(SnoozeOption *)snoozeOption;

/**
 @brief Defer a specific reminder until a later time (or state) using a new trigger <BR> <B>Only a triggered ( ReminderStatus#Triggered ) reminder can be snoozed</B>
 @param reminderId the unique ID of the reminder
 @param newTrigger the new trigger to be used to defer the reminder
 @return a result that state whether the snoozing process was successful (test with Result#isSuccess() ) or not (error will be supplied in Result#getResultCode() and Result#getMessage() )
 */
- (Result *)snoozeReminderWithTriggerWithNSString:(NSString *)reminderId
                                     withITrigger:(id<ITrigger>)newTrigger;

/**
 @brief Use when stopping the reminders, to avoid reminders being triggered
 */
- (void)onDestroy;

/**
 @brief Get an existing reminder by its unique ID
 @param reminderId the unique ID of the reminder
 @return IReminder
 */
- (ResultData *)getReminderWithNSString:(NSString *)reminderId;

/**
 @brief Get reminders by their status, for example: <BR> remindersManager.getReminders(EnumSet.allOf(ReminderStatus.class)); <BR> or <BR> remindersManager.getReminders(EnumSet.of(ReminderStatus.Active));
 @param reminderStatuses the status of the reminders that should be returned (as seen in the examples)
 @return multiple IReminder the ResultData is always success, the data might be an empty collection.
 */
- (ResultData *)getRemindersWithEnumSet:(EnumSet *)reminderStatuses;

/**
 @brief Mark a triggered reminder as ended
 @param reminderId the unique ID of the reminder
 @param reminderEndReason The end reason of the reminder
 @return a result that state whether the ending process was successful (test with Result#isSuccess() ) or not (error will be supplied in Result#getResultCode() and Result#getMessage() )
 */
- (Result *)endReminderWithNSString:(NSString *)reminderId
          withReminderEndReason:(ReminderEndReason *)reminderEndReason;

@end

__attribute__((always_inline)) inline void IRemindersManager_init() {}

#define ComIntelWearablePlatformTimeiqApiRemindersIRemindersManager IRemindersManager

#endif // _IRemindersManager_H_