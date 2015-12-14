//
//  Generated by the J2ObjC translator.  DO NOT EDIT!
//  source: //com/intel/wearable/platform/timeiq/places/modules/placesmodule/djcluster/FusePoint.java
//

#ifndef _FusePoint_H_
#define _FusePoint_H_

#import "JB.h"
#import "Coord.h"

@interface FusePoint : Coord {
 @public
  long64 time_;
}

- (instancetype)initWithDouble:(double)latitude
                    withDouble:(double)longitude
                      withLong:(long64)time;

- (long64)getTime;

- (void)copyAllFieldsTo:(FusePoint *)other;

@end

__attribute__((always_inline)) inline void FusePoint_init() {}

typedef FusePoint ComIntelWearablePlatformTimeiqPlacesModulesPlacesmoduleDjclusterFusePoint;

#endif // _FusePoint_H_