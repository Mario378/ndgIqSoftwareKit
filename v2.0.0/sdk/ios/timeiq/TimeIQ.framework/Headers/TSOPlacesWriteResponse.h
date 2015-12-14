//
//  Generated by the J2ObjC translator.  DO NOT EDIT!
//  source: //com/intel/wearable/platform/timeiq/protocol/response/TSOPlacesWriteResponse.java
//

#ifndef _TSOPlacesWriteResponse_H_
#define _TSOPlacesWriteResponse_H_

@class DBResponse;
#import "JBHashtable.h"

#import "JB.h"
#import "IMappable.h"

@interface TSOPlacesWriteResponse : NSObject < IMappable > {
 @public
  DBResponse *dbResponse_;
}

- (instancetype)init;

- (instancetype)initWithDBResponse:(DBResponse *)dbResponse;

- (DBResponse *)getDbResponse;

- (void)setDbResponseWithDBResponse:(DBResponse *)dbResponse;

- (NSUInteger)hash;

- (boolean)isEqual:(id)obj;

- (void)initObjectFromMapWithJavaUtilMap:(HashMap*)map OBJC_METHOD_FAMILY_NONE;

- (HashMap*)objectToMap;

- (void)copyAllFieldsTo:(TSOPlacesWriteResponse *)other;

@end

__attribute__((always_inline)) inline void TSOPlacesWriteResponse_init() {}

//J2OBJC_FIELD_SETTER(TSOPlacesWriteResponse, dbResponse_, DBResponse *)

FOUNDATION_EXPORT NSString *TSOPlacesWriteResponse_DB_RESPONSE_FIELD_;
J2OBJC_STATIC_FIELD_GETTER(TSOPlacesWriteResponse, DB_RESPONSE_FIELD_, NSString *)

typedef TSOPlacesWriteResponse ComIntelWearablePlatformTimeiqProtocolResponseTSOPlacesWriteResponse;

#endif // _TSOPlacesWriteResponse_H_