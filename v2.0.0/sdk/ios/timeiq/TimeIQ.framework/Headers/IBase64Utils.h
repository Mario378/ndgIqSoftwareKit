//
//  Generated by the J2ObjC translator.  DO NOT EDIT!
//  source: //com/intel/wearable/platform/timeiq/common/externallibs/IBase64Utils.java
//

#ifndef _IBase64Utils_H_
#define _IBase64Utils_H_

@class ByteArray;

#import "JB.h"

/**
 @brief Created by smoradof on 4/26/15.
 */
@protocol IBase64Utils < NSObject >

- (ByteArray *)decodeBase64WithByteArray:(ByteArray *)base64Data;

- (ByteArray *)encodeBase64WithByteArray:(ByteArray *)binaryData;

@end

__attribute__((always_inline)) inline void IBase64Utils_init() {}

#define ComIntelWearablePlatformTimeiqCommonExternallibsIBase64Utils IBase64Utils

#endif // _IBase64Utils_H_
