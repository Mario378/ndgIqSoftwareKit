//
//  Generated by the J2ObjC translator.  DO NOT EDIT!
//  source: //com/intel/wearable/platform/timeiq/places/modules/visitinplacemodule/ManualDetected.java
//

#ifndef _ManualDetected_H_
#define _ManualDetected_H_

@class DetectedPlace;
@class ManualPlace;

#import "JB.h"

/**
 @brief Created by ylempert on 14-May-15.
 */
@interface ManualDetected : NSObject {
 @public
  ManualPlace *manual_;
  DetectedPlace *detected_;
}

- (instancetype)initWithManualPlace:(ManualPlace *)manual
                  withDetectedPlace:(DetectedPlace *)detected;

- (DetectedPlace *)getDetected;

- (ManualPlace *)getManual;

- (void)copyAllFieldsTo:(ManualDetected *)other;

@end

__attribute__((always_inline)) inline void ManualDetected_init() {}

//J2OBJC_FIELD_SETTER(ManualDetected, manual_, ManualPlace *)
//J2OBJC_FIELD_SETTER(ManualDetected, detected_, DetectedPlace *)

typedef ManualDetected ComIntelWearablePlatformTimeiqPlacesModulesVisitinplacemoduleManualDetected;

#endif // _ManualDetected_H_