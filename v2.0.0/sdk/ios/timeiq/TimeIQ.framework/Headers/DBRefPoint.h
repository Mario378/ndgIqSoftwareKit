//
//  Generated by the J2ObjC translator.  DO NOT EDIT!
//  source: //com/intel/wearable/platform/timeiq/dbobjects/places/wifi/DBRefPoint.java
//

#ifndef _DBRefPoint_H_
#define _DBRefPoint_H_

#import "JBHashtable.h"

#import "JB.h"
#import "ATSOSyncDbObject.h"
#import "IRefPoint.h"

@interface DBRefPoint : ATSOSyncDbObject < IRefPoint > {
 @public
  HashMap* hashTable_;
  double sumlat_;
  double sumlong_;
  int nPoints_;
}

- (instancetype)init;

- (long64)getModificationTimeStamp;

- (void)setModificationTimeStampWithLong:(long64)modificationTimeStamp;

- (HashMap*)getHashTable;

- (void)setHashTableWithJavaUtilMap:(HashMap*)hashTable;

- (double)getSumlat;

- (void)setSumlatWithDouble:(double)sumlat;

- (double)getSumlong;

- (void)setSumlongWithDouble:(double)sumlong;

- (int)getnPoints;

- (void)setnPointsWithInt:(int)nPoints;

- (void)initObjectFromMapWithJavaUtilMap:(HashMap*)map OBJC_METHOD_FAMILY_NONE;

- (HashMap*)objectToMap;

- (NSUInteger)hash;

- (boolean)isEqual:(id)obj;

- (void)copyAllFieldsTo:(DBRefPoint *)other;

@end

__attribute__((always_inline)) inline void DBRefPoint_init() {}

//J2OBJC_FIELD_SETTER(DBRefPoint, hashTable_, HashMap*)

typedef DBRefPoint ComIntelWearablePlatformTimeiqDbobjectsPlacesWifiDBRefPoint;

#endif // _DBRefPoint_H_