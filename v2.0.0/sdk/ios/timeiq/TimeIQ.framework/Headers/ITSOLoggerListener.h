//
//  Generated by the J2ObjC translator.  DO NOT EDIT!
//  source: //com/intel/wearable/platform/timeiq/common/logger/ITSOLoggerListener.java
//

#ifndef _ITSOLoggerListener_H_
#define _ITSOLoggerListener_H_

#import "JB.h"

/**
 @brief Created by smoradof on 1/20/15.
 */
@protocol ITSOLoggerListener < NSObject >

- (void)onLogChangedWithNSString:(NSString *)log;

@end

__attribute__((always_inline)) inline void ITSOLoggerListener_init() {}

#define ComIntelWearablePlatformTimeiqCommonLoggerITSOLoggerListener ITSOLoggerListener

#endif // _ITSOLoggerListener_H_