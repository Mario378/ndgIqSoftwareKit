//
//  Generated by the J2ObjC translator.  DO NOT EDIT!
//  source: //com/intel/wearable/platform/timeiq/common/network/http/IHttpProvider.java
//

#ifndef _IHttpProvider_H_
#define _IHttpProvider_H_

@class InputStream;
@class ResultData;
@protocol IHttpSentDataListener;
@protocol JavaLangReflectType;

#import "JB.h"

/**
 @brief Created by ibeider on 29/01/2015.
 */
@protocol IHttpProvider < NSObject >

/**
 @brief This Function posting a Data Object to specific Restful API (based on default values for timeout)
 @param request // request Object to the Server
 @param typeOfResponse // response class
 @param url // server URL
 @return // HttpResponse
 */
- (ResultData *)sendAndReceiveWithId:(id)request
             withReflectType:(JavaLangReflectType)typeOfResponse
                        withNSString:(NSString *)url;

/**
 @brief This Function posting a Data Object to specific Restful API (based on non-default values for timeout)
 @param request
 @param typeOfResponse
 @param url
 @param readTimeOut
 @param connectionTimeOut
 @param < T >
 @return 
 */
- (ResultData *)sendAndReceiveWithId:(id)request
             withReflectType:(JavaLangReflectType)typeOfResponse
                        withNSString:(NSString *)url
                             withInt:(int)readTimeOut
                             withInt:(int)connectionTimeOut;

/**
 @brief This Function posting input stream to specific Restful API (based on default values for timeout)
 @param inputStream
 @param typeOfResponse
 @param url
 @param < T >
 @return 
 */
- (ResultData *)sendAndReceiveWithInputStream:(InputStream *)inputStream
                            withReflectType:(JavaLangReflectType)typeOfResponse
                                       withNSString:(NSString *)url;

/**
 @brief Register for info of sent data over network
 @param httpSentDataListener
 */
- (void)registerListenerWithIHttpSentDataListener:(id<IHttpSentDataListener>)httpSentDataListener;

/**
 @brief UnRegister from info of sent data over network
 @param httpSentDataListener
 */
- (void)unRegisterListenerWithIHttpSentDataListener:(id<IHttpSentDataListener>)httpSentDataListener;

/**
 @brief Set network level authentication credentials as supported by implementation
 @param credentials
 */
- (void)setNetworkCredentialsWithId:(id)credentials;

@end

__attribute__((always_inline)) inline void IHttpProvider_init() {}

#define ComIntelWearablePlatformTimeiqCommonNetworkHttpIHttpProvider IHttpProvider

#endif // _IHttpProvider_H_
