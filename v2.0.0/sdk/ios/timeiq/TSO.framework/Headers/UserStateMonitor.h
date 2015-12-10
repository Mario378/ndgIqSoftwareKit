//
//  Generated by the J2ObjC translator.  DO NOT EDIT!
//  source: //com/intel/wearable/platform/timeiq/userstate/UserStateMonitor.java
//

#ifndef _UserStateMonitor_H_
#define _UserStateMonitor_H_

@class ClassFactory;
@class UserState;
@protocol IMotStateDataProvider;
@protocol ITSOLogger;
@protocol ITSOTimeUtil;
@protocol IVipStateDataProvider;

#import "JB.h"
#import "BaseUserStateChangeProvider.h"
#import "IStateDataChangeListener.h"
#import "IUserStateMonitor.h"

/**
 @brief Created by gilsharo on 5/18/2015.
 */
@interface UserStateMonitor : BaseUserStateChangeProvider < IUserStateMonitor, IStateDataChangeListener > {
 @public
  id<ITSOLogger> m_logger_;
  id<ITSOTimeUtil> m_timeUtil_;
  id<IVipStateDataProvider> m_vipDataProvider_;
  id<IMotStateDataProvider> m_motDataProvider_;
}

- (instancetype)init;

- (instancetype)initWithClassFactory:(ClassFactory *)classFactory;

- (instancetype)initWithITSOTimeUtil:(id<ITSOTimeUtil>)timeUtil
                      withITSOLogger:(id<ITSOLogger>)tsoLogger
           withIVipStateDataProvider:(id<IVipStateDataProvider>)vipDataProvider
           withIMotStateDataProvider:(id<IMotStateDataProvider>)motDataProvider;

- (UserState *)createNewState;

- (void)onDataChanged;

- (void)copyAllFieldsTo:(UserStateMonitor *)other;

@end

FOUNDATION_EXPORT BOOL UserStateMonitor_initialized;
J2OBJC_STATIC_INIT(UserStateMonitor)

//J2OBJC_FIELD_SETTER(UserStateMonitor, m_logger_, id<ITSOLogger>)
//J2OBJC_FIELD_SETTER(UserStateMonitor, m_timeUtil_, id<ITSOTimeUtil>)
//J2OBJC_FIELD_SETTER(UserStateMonitor, m_vipDataProvider_, id<IVipStateDataProvider>)
//J2OBJC_FIELD_SETTER(UserStateMonitor, m_motDataProvider_, id<IMotStateDataProvider>)

FOUNDATION_EXPORT NSString *UserStateMonitor_TAG_;
J2OBJC_STATIC_FIELD_GETTER(UserStateMonitor, TAG_, NSString *)

typedef UserStateMonitor ComIntelWearablePlatformTimeiqUserstateUserStateMonitor;

#endif // _UserStateMonitor_H_