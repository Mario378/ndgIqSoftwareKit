//
//  Generated by the J2ObjC translator.  DO NOT EDIT!
//  source: //com/intel/wearable/platform/timeiq/api/events/TSOEventsResponse.java
//

#ifndef _TSOEventsResponse_H_
#define _TSOEventsResponse_H_

#import "JBArrayList.h"

#import "JB.h"

/**
 @brief This class is the Events Engine response to getEvent functions.
 The developer requests current events or events in time frame and receives the events list within this class.
 */
@interface TSOEventsResponse : NSObject {
 @public
  /**
   @brief The list of returned events - according to the requested query
   */
  ArrayList* eventsList_;
}

- (instancetype)initWithJavaUtilList:(ArrayList*)events;

/**
 @brief This function returns the event list within the response
 @return List<IEvent> - the list of events
 */
- (ArrayList*)getEventsList;

/**
 @brief This function allows the developer to set the event list returned within the response
 @param eventsList - list of events to be included in the response
 */
- (void)setEventsListWithJavaUtilList:(ArrayList*)eventsList;

- (void)copyAllFieldsTo:(TSOEventsResponse *)other;

@end

__attribute__((always_inline)) inline void TSOEventsResponse_init() {}

//J2OBJC_FIELD_SETTER(TSOEventsResponse, eventsList_, ArrayList*)

typedef TSOEventsResponse ComIntelWearablePlatformTimeiqApiEventsTSOEventsResponse;

#endif // _TSOEventsResponse_H_
