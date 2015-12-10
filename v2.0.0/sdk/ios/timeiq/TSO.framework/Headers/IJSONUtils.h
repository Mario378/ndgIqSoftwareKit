//
//  Generated by the J2ObjC translator.  DO NOT EDIT!
//  source: //com/intel/wearable/platform/timeiq/common/externallibs/IJSONUtils.java
//

#ifndef _IJSONUtils_H_
#define _IJSONUtils_H_

#import "JBClass.h"
@protocol JavaLangReflectType;

#import "JB.h"

/**
 @brief Created by smoradof on 4/14/15.
 */
@protocol IJSONUtils < NSObject >

- (id)fromJsonWithNSString:(NSString *)data
              withIOSClass:(Class )classOfT;

- (id)fromJsonWithNSString:(NSString *)json
   withReflectType:(JavaLangReflectType)typeOfT;

- (NSString *)toJsonWithId:(id)src;

- (NSString *)toJsonWithId:(id)data
   withReflectType:(JavaLangReflectType)typeOfSrc;

- (NSString *)serializeNullsToJsonWithId:(id)src;

- (id)serializeNullsFromJsonWithNSString:(NSString *)json
                 withReflectType:(JavaLangReflectType)typeOfT;

@end

__attribute__((always_inline)) inline void IJSONUtils_init() {}

#define ComIntelWearablePlatformTimeiqCommonExternallibsIJSONUtils IJSONUtils

#endif // _IJSONUtils_H_