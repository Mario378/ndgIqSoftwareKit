//
//  Generated by the J2ObjC translator.  DO NOT EDIT!
//  source: //com/intel/wearable/platform/timeiq/events/EventIdManager.java
//

#ifndef _EventIdManager_H_
#define _EventIdManager_H_

@class EventIdInfo;
@class EventsPersistenceUtil;
@protocol ITSOLogger;
#import "TrReadWriteLock.h"

#import "JB.h"

/**
 @brief Created by stzour on 30/06/2015.
 */
@interface EventIdManager : NSObject {
 @public
  id<ITSOLogger> logger_;
  EventsPersistenceUtil *eventsPersistence_;
  Hashtable* eventIdToInfo_;
  Hashtable* clientToEventId_;
  Hashtable* meetingToEventId_;
}

- (instancetype)init;

- (instancetype)initWithITSOLogger:(id<ITSOLogger>)logger
         withEventsPersistenceUtil:(EventsPersistenceUtil *)eventsPersistence;

- (EventIdInfo *)getEventIdInfoWithNSString:(NSString *)eventId;

- (void)updatePersistenceWithEventIdInfo:(EventIdInfo *)eventIdInfo;

- (void)deleteFromPersistenceWithEventIdInfo:(EventIdInfo *)eventIdInfo;

- (void)addPersistenceWithEventIdInfo:(EventIdInfo *)eventIdInfo;

- (void)readFromPersistence;

- (EventIdInfo *)getEventIdInfoByClientIdWithNSString:(NSString *)clientId;

- (EventIdInfo *)getEventIdInfoByMeetingIdWithNSString:(NSString *)meetingId;

- (NSString *)getEventIdByClientIdWithNSString:(NSString *)clientId;

- (NSString *)getEventIdByMeetingWithNSString:(NSString *)meetingId;

- (boolean)deleteClientIdWithNSString:(NSString *)clientId;

- (boolean)deleteMeetingIdWithNSString:(NSString *)meetingId;

- (boolean)deleteClientAndMeetingIdWithNSString:(NSString *)clientId
                                    withNSString:(NSString *)meetingId;

- (boolean)addClientAndMeetingIdWithNSString:(NSString *)eventId
                                 withNSString:(NSString *)clientId
                                 withNSString:(NSString *)meetingId;

- (boolean)addClientIdWithNSString:(NSString *)eventId
                       withNSString:(NSString *)clientId;

- (boolean)addMeetingIdWithNSString:(NSString *)eventId
                        withNSString:(NSString *)meetingId;

- (void)removeIfEmptyWithEventIdInfo:(EventIdInfo *)eventIdInfo;

- (boolean)clientIdExistsWithNSString:(NSString *)clientId;

- (boolean)meetingExistsWithNSString:(NSString *)meetingId;

- (boolean)updateClientIdWithNSString:(NSString *)eventId
                          withNSString:(NSString *)currentClientId
                          withNSString:(NSString *)newClientId;

- (boolean)updateMeetingIdWithNSString:(NSString *)eventId
                           withNSString:(NSString *)currentMeetingId
                           withNSString:(NSString *)newMeetingId;

- (NSString *)getMeetingIdByEventIdWithNSString:(NSString *)eventId;

- (NSString *)getClientIdByEventIdWithNSString:(NSString *)eventId;

- (void)clearAll;

- (void)printStackTrace;

- (void)copyAllFieldsTo:(EventIdManager *)other;

@end

__attribute__((always_inline)) inline void EventIdManager_init() {}

//J2OBJC_FIELD_SETTER(EventIdManager, logger_, id<ITSOLogger>)
//J2OBJC_FIELD_SETTER(EventIdManager, eventsPersistence_, EventsPersistenceUtil *)
//J2OBJC_FIELD_SETTER(EventIdManager, eventIdToInfo_, Hashtable*)
//J2OBJC_FIELD_SETTER(EventIdManager, clientToEventId_, Hashtable*)
//J2OBJC_FIELD_SETTER(EventIdManager, meetingToEventId_, Hashtable*)

FOUNDATION_EXPORT NSString *EventIdManager_TAG_;
J2OBJC_STATIC_FIELD_GETTER(EventIdManager, TAG_, NSString *)

typedef EventIdManager ComIntelWearablePlatformTimeiqEventsEventIdManager;

#endif // _EventIdManager_H_