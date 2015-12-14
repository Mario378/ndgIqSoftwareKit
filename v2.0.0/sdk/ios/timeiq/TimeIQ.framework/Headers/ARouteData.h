//
//  Generated by the J2ObjC translator.  DO NOT EDIT!
//  source: //com/intel/wearable/platform/timeiq/api/route/ARouteData.java
//

#ifndef _ARouteData_H_
#define _ARouteData_H_

@class MotType;
@class RouteDataType;
@class TSOCoordinate;
#import "JBArrayList.h"

#import "JB.h"
#import "IRouteData.h"

/**
 @brief The result of ISegmentedRouteProvider#getTTL(TSOCoordinate,TSOCoordinate,long,MotType,MotType) <BR> It contains a list of RouteSegment ordered by time, from the time to leave until the arrival time.
 */
@interface ARouteData : NSObject < IRouteData > {
 @public
  RouteDataType *m_routeDataType_;
  double m_aerialDistance_;
  ArrayList* m_routeSegments_;
  MotType *m_mainMotType_;
  long64 m_routeDuration_;
}

/**
 @param routeSegments list of RouteSegment ordered by time, from the time to leave until the arrival time
 */
- (instancetype)initWithRouteDataType:(RouteDataType *)routeDataType
                               withDouble:(double)aerialDistance
                         withJavaUtilList:(ArrayList*)routeSegments
                          withMotType:(MotType *)mainMotType;

- (RouteDataType *)getRouteDataType;

/**
 @brief Get the main MOT of the route
 @return the main MOT of the route
 */
- (MotType *)getMainMotType;

/**
 @brief Get the route duration
 @return the duration of the route
 */
- (long64)getRouteDuration;

/**
 @brief Get the origin of the route
 @return the origin of the route
 */
- (TSOCoordinate *)getRouteOrigin;

/**
 @brief Get the destination of the route
 @return the destination of the route
 */
- (TSOCoordinate *)getRouteDestination;

/**
 @brief Get the aerial distance from origin to destination
 @return the aerial distance from origin to destination
 */
- (double)getAerialDistance;

/**
 @brief Get all the route segments that constitute the route to the destination location as defined by the user in creation time of the alert.
 <BR> The list of RouteSegment is ordered by time, from the time to leave until the arrival time.<BR>
 @return a list of RouteSegment ordered from the time to leave until the arrivalTime
 */
- (ArrayList*)getRouteSegments;

- (NSString *)description;

- (void)copyAllFieldsTo:(ARouteData *)other;

@end

__attribute__((always_inline)) inline void ARouteData_init() {}

//J2OBJC_FIELD_SETTER(ARouteData, m_routeDataType_, RouteDataType *)
//J2OBJC_FIELD_SETTER(ARouteData, m_routeSegments_, ArrayList*)
//J2OBJC_FIELD_SETTER(ARouteData, m_mainMotType_, MotType *)

typedef ARouteData ComIntelWearablePlatformTimeiqApiRouteARouteData;

#endif // _ARouteData_H_