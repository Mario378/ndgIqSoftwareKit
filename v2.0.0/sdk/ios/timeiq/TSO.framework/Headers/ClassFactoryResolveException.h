//
//  Generated by the J2ObjC translator.  DO NOT EDIT!
//  source: //com/intel/tso/sdk/common/ioc/ClassFactoryResolveException.java
//

#ifndef _ClassFactoryResolveException_H_
#define _ClassFactoryResolveException_H_

#import "JBClass.h"
#import "NSException+JavaAPI.h"

#import "JB.h"
#import "NSException+JavaAPI.h"

/**
 @brief Created by gilsharo on 6/17/2015.
 */
@interface ClassFactoryResolveException : RuntimeException {
}

- (instancetype)initWithProtocol :(Protocol *)type;

- (instancetype)initWithProtocol :(Protocol *)type
           withException:(Exception *)innerException;

@end

__attribute__((always_inline)) inline void ClassFactoryResolveException_init() {}

FOUNDATION_EXPORT NSString *ClassFactoryResolveException_ERROR_TEXT_;
J2OBJC_STATIC_FIELD_GETTER(ClassFactoryResolveException, ERROR_TEXT_, NSString *)

typedef ClassFactoryResolveException ComIntelTsoSdkCommonIocClassFactoryResolveException;

#endif // _ClassFactoryResolveException_H_

