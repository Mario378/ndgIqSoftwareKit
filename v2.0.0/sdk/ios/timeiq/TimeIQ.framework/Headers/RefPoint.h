//
//  Generated by the J2ObjC translator.  DO NOT EDIT!
//  source: //com/intel/wearable/platform/timeiq/places/modules/placesmodule/wifi/RefPoint.java
//

#ifndef _RefPoint_H_
#define _RefPoint_H_

@class DBRefPoint;
#import "JBHashSet.h"
#import "JBArrayList.h"
#import "JBHashtable.h"

#import "JB.h"
#import "IMappable.h"
#import "ITSOSyncDbObject.h"
#import "Coord.h"

@interface RefPoint : Coord < ITSOSyncDbObject, IMappable > {
 @public
  NSString *objectId_;
  NSString *userId_;
  long64 modificationTimeStamp_;
  long64 creationTime_;
  HashMap* hashTable_;
  double sumlat_;
  double sumlong_;
  int nPoints_;
}

- (instancetype)initWithDouble:(double)latitude
                    withDouble:(double)longitude;

- (instancetype)init;

- (NSString *)print;

- (void)addPointWithCoord:(Coord *)point
         withJavaUtilList:(ArrayList*)aps;

- (void)filter;

- (Set*)getApStat;

- (HashMap*)getHashTable;

- (NSString *)description;

- (void)updateCenter;

- (NSString *)getObjectId;

- (void)setObjectIdWithNSString:(NSString *)newId;

- (long64)getCreationTime;

- (long64)getLastUserInteractionTime;

- (void)setLastUserInteractionTimeWithLong:(long64)l;

- (NSString *)getUserId;

- (void)setUserIdWithNSString:(NSString *)userId;

- (long64)getModificationTimeStamp;

- (void)setModificationTimeStampWithLong:(long64)modificationTimeStamp;

- (void)initObjectFromMapWithJavaUtilMap:(HashMap*)map OBJC_METHOD_FAMILY_NONE;

- (HashMap*)objectToMap;

- (DBRefPoint *)createDBRefPoint;

- (void)copyAllFieldsTo:(RefPoint *)other;

@end

__attribute__((always_inline)) inline void RefPoint_init() {}

//J2OBJC_FIELD_SETTER(RefPoint, objectId_, NSString *)
//J2OBJC_FIELD_SETTER(RefPoint, userId_, NSString *)
//J2OBJC_FIELD_SETTER(RefPoint, hashTable_, HashMap*)

FOUNDATION_EXPORT NSString *RefPoint_OBJECT_ID_FIELD_;
J2OBJC_STATIC_FIELD_GETTER(RefPoint, OBJECT_ID_FIELD_, NSString *)

FOUNDATION_EXPORT NSString *RefPoint_USER_ID_FIELD_;
J2OBJC_STATIC_FIELD_GETTER(RefPoint, USER_ID_FIELD_, NSString *)

FOUNDATION_EXPORT NSString *RefPoint_MODIFICATION_TIME_;
J2OBJC_STATIC_FIELD_GETTER(RefPoint, MODIFICATION_TIME_, NSString *)

FOUNDATION_EXPORT NSString *RefPoint_CREATION_TIME_FIELD_;
J2OBJC_STATIC_FIELD_GETTER(RefPoint, CREATION_TIME_FIELD_, NSString *)

typedef RefPoint ComIntelWearablePlatformTimeiqPlacesModulesPlacesmoduleWifiRefPoint;

#endif // _RefPoint_H_