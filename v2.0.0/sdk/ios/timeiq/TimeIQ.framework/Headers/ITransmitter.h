//
//  Generated by the J2ObjC translator.  DO NOT EDIT!
//  source: //com/intel/wearable/platform/timeiq/common/network/http/ITransmitter.java
//

#ifndef _ITransmitter_H_
#define _ITransmitter_H_

@class InputStream;

#import "JB.h"

/**
 @brief Created by ibeider on 28/01/2015.
 */
@protocol ITransmitter < NSObject >

- (boolean)sendWithInputStream:(InputStream *)inputStream;

@end

__attribute__((always_inline)) inline void ITransmitter_init() {}

#define ComIntelWearablePlatformTimeiqCommonNetworkHttpITransmitter ITransmitter

#endif // _ITransmitter_H_