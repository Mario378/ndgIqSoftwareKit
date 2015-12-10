//
//  Generated by the J2ObjC translator.  DO NOT EDIT!
//  source: //com/intel/wearable/platform/timeiq/places/engine/IPlacesEngine.java
//

#ifndef _IPlacesEngine_H_
#define _IPlacesEngine_H_

#import "JBVector.h"
@class ModuleState;
@class ModuleType;
@class ResultData;
@protocol IExternalPlaceListener;
@protocol IMotChangeListener;
@protocol IPlaceListener;
@protocol IVisitEntry;
@protocol IVisitInPlaceListener;
@protocol IVisitListener;
#import "JBHashSet.h"
#import "JBArrayList.h"

#import "JB.h"

/**
 @brief The PlacesEngine provides an API for visits and places detection.
 The engine invokes internal modules for visit detection and places detection. It relies on the SensorsEngine to provide sensors information available on the current platform and registers it's modules to receive the required sensors data such as location, activity, Wifi etc...
 */
@protocol IPlacesEngine < NSObject >

/**
 @brief Activates all Modules which require sensor's sampling. such modules are available on init, yet not activated automatically.
 */
- (void)activateAllModules;

/**
 @brief Deactivates all Modules which affects stopping sensor's sampling if the module is the sole consumer of these sensor
 */
- (void)deactivateModule;

/**
 @brief Activate a single Module which require sensor's sampling. such modules are available on init, yet not activated automatically.
 @param moduleType
 */
- (void)activateModuleWithModuleType:(ModuleType *)moduleType;

/**
 @brief Deactivates a single Module which affects stopping sensor's sampling if the module is the sole consumer of these sensor
 @param moduleType
 */
- (void)deactivateModuleWithModuleType:(ModuleType *)moduleType;

- (ModuleState *)getModuleStateWithModuleType:(ModuleType *)moduleType;

/**
 @brief Registration for visit detection.
 Register a listener to be notified on visit detection start/end events.
 @param listener Listener to be called for visit start/end reporting.
 */
- (void)registerVisitListenerWithIVisitListener:(id<IVisitListener>)listener;

/**
 @brief Un-register the visit detection start/end events.
 @param listener Listener to remove from the visits reporting.
 */
- (void)unregisterVisitListenerWithIVisitListener:(id<IVisitListener>)listener;

/**
 @brief Returns the current detected visit in progress, if exists.
 @return Visit entry for the currently detected visit.
 */
- (id<IVisitEntry>)getCurrentVisit;

/**
 @brief Returns all of the detected visits accumulated in the system.
 @return Vector containing all of the detected visits accumulated in the system.
 */
- (Vector *)getAllVisits;

/**
 @brief Register a visit-in-place listener
 @param listener Listener to be called for visit-in-place start/end reporting.
 */
- (void)registerVisitedPlaceListenerWithIVisitInPlaceListener:(id<IVisitInPlaceListener>)listener;

/**
 @brief Unregister a visit-in-place listener
 @param listener Listener to be removed
 */
- (void)unregisterVisitedPlaceListenerWithIVisitInPlaceListener:(id<IVisitInPlaceListener>)listener;

- (ArrayList*)getAllPlaces;

- (Set*)getCurrentVisitsInPlace;

/**
 @brief Registration for MOT ( means of transport ) changes.
 The MOT module is responsible for identifying the user's means of transport such as running, walking, driving, stationary etc. The module will report the detected MOT only when it's differs from the currently detected MOT in the system. For more information refer to MotDetectionModule
 @param listener Listener to be called for MOT change reporting.
 */
- (void)registerMotListenerWithIMotChangeListener:(id<IMotChangeListener>)listener;

/**
 @brief Un-register for MOT changes.
 @param listener Listener to be called for MOT change reporting.
 */
- (void)unregisterMotListenerWithIMotChangeListener:(id<IMotChangeListener>)listener;

/**
 @brief Returns the currently identified MOT state.
 @return detected MOT information
 */
- (ResultData *)getCurrentMOT;

/**
 @brief Invokes a place detection process which is executed in a background thread.
 Place detection takes accumulated sensors data such as position (GPS / fuse-location) and Wi-Fi scans in order to detect user significant places based on clustering algorithms. Once the detection process is completed, any listener registered with #registerPlaceDetectionListener(IPlaceListener) is notified. Detected places are available using the #getAllDetectedPlaces()
 */
- (void)startPlacesDetectionWithBoolean:(boolean)onDemand;

/**
 @brief Invokes a semantic place detection process which is executed in a background thread.
 Semantic place detection takes all the user's detected places and external places and tries to match them, with a successful merged pair forming a SemanticDetectedPlace . Once the detection process is completed, any listener registered with #registerSemanticPlaceDetectionListener(IPlaceListener) is notified. Detected places are available using the #getAllSemanticDetectedPlaces()
 */
- (void)startSemanticPlacesDetection;

/**
 @brief Returns all of the detected places identified by the PlaceDetection module.
 @return vector containing all of the detected places.
 */
- (Vector *)getAllDetectedPlaces;

/**
 @brief Returns all of the detected places identified by the PlaceDetection module.
 @return vector containing all of the detected places.
 */
- (Set*)getAllSemanticDetectedPlaces;

/**
 @brief Registration for notification of place detection completion.
 Register a listener to be notified once the place detection has completed it's processing.
 @param listener Listener to be called when upon Place Detection processing completion.
 */
- (void)registerPlaceDetectionListenerWithIPlaceListener:(id<IPlaceListener>)listener;

/**
 @brief Registration for notification of semantic place detection completion.
 Register a listener to be notified once the semantic place detection process has completed.
 @param listener Listener to be called when upon Semantic Place Detection processing completion.
 */
- (void)registerSemanticPlaceDetectionListenerWithIPlaceListener:(id<IPlaceListener>)listener;

/**
 @brief Un-register for semantic place detection completion notifications.
 @param listener Listener to be removed
 */
- (void)unregisterSemanticPlaceDetectionListenerWithIPlaceListener:(id<IPlaceListener>)listener;

/**
 @brief Un-register for place detection completion notifications.
 @param listener Listener to be removed
 */
- (void)unregisterPlaceDetectionListenerWithIPlaceListener:(id<IPlaceListener>)listener;

/**
 @param listener
 */
- (void)registerOnExternalPlaceChangeWithIExternalPlaceListener:(id<IExternalPlaceListener>)listener;

/**
 @param listener
 */
- (void)unregisterOnExternalPlaceChangeWithIExternalPlaceListener:(id<IExternalPlaceListener>)listener;

/**
 @return 
 */
- (Vector *)getAllExternalPlaces;

/**
 @brief Invokes modules persistence mechanism.
 This will allow internal modules to dump all internal data in persistance storage. This method should be called whenever the SDK is stopped and/or terminated in order to preserve on-going data.
 */
- (void)storeModulesMemory;

/**
 @brief Internal modules persistence restore.
 Restores internal module as stored by #storeModulesMemory() This should be called after the application has started in order to restore the engine state.
 */
- (void)restoreModulesMemory;

- (boolean)syncRemoteSlaveDbs;

@end

__attribute__((always_inline)) inline void IPlacesEngine_init() {}

#define ComIntelWearablePlatformTimeiqPlacesEngineIPlacesEngine IPlacesEngine

#endif // _IPlacesEngine_H_