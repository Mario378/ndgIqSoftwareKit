//
//  Generated by the J2ObjC translator.  DO NOT EDIT!
//  source: //com/intel/wearable/platform/timeiq/places/locationprovider/ILocationProvider.java
//

#ifndef _ILocationProvider_H_
#define _ILocationProvider_H_

@class ResultData;

#import "JB.h"

/**
 @brief Created by eleuchte on 04/01/2015.
 */
@protocol ILocationProvider < NSObject >

/**
 @brief tries to get the last known location of the user (without invoking any sensors), will try to do so in 2 ways: actual location sensor in case available on cache (accuracy<30, age<1 minute), otherwise platform 'passive provider' location
 @return 
 */
- (ResultData *)getLastKnownLocation;

/**
 @brief Gets the User's location given it's not older than the max required this will usually NOT invoke any sensor
 @param maximumAgeInMillis
 @return 
 */
- (ResultData *)getUserLocationWithLong:(long64)maximumAgeInMillis;

/**
 @brief Gets the User's location given it's accuracy & age are as required this will usually NOT invoke any sensor
 @param minimumAccuracy
 @param maximumAgeInMillis
 @return 
 */
- (ResultData *)getUserLocationWithDouble:(double)minimumAccuracy
                                 withLong:(long64)maximumAgeInMillis;

@end

__attribute__((always_inline)) inline void ILocationProvider_init() {}

#define ComIntelWearablePlatformTimeiqPlacesLocationproviderILocationProvider ILocationProvider

#endif // _ILocationProvider_H_
