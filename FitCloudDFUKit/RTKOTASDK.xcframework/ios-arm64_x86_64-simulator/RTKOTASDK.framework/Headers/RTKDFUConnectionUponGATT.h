//
//  RTKDFURoutineGATT.h
//  RTKOTASDK
//
//  Created by jerome_gu on 2021/10/19.
//  Copyright © 2022 Realtek. All rights reserved.
//

#ifdef RTK_SDK_IS_STATIC_LIBRARY
#import "libRTKLEFoundation.h"
#import "RTKDFURoutine.h"
#else
#import <RTKLEFoundation/RTKLEFoundation.h>
#import <RTKOTASDK/RTKDFURoutine.h>
#endif


NS_ASSUME_NONNULL_BEGIN


/// In terms of upgrading, the possilble mode that a device runs.
typedef NS_ENUM(NSUInteger, RTKDFUPeripheralMode) {
    /// The mode that serve normal functionality.
    RTKDFUPeripheralMode_normal,
    /// The mode that serve upgrade task.
    RTKDFUPeripheralMode_ota,
};


/// A concrete subclass of `RTKConnectionUponGATT` which communicate with a remote LE device to perform upgrade related procedure.
///
/// The `RTKDFUConnectionUponGATT` conforms to ``RTKDFURoutine`` protocol, providing interfaces to interact with device for upgrade. In addition, `RTKDFUConnectionUponGATT` defines properties and method to manage entering OTA mode and update LE connection parameter. When be requested to switching to OTA mode, the device will reboot to a dedicated mode, and be treated as another `RTKDFUConnectionUponGATT` instance.
///
/// You can tell if the device can switching to OTA mode by ``RTKDFUConnectionUponGATT/canEnterOTAMode`` property, and tell if device can be started upgrade by ``RTKDFUConnectionUponGATT/canUpgrade`` property.
@interface RTKDFUConnectionUponGATT : RTKConnectionUponGATT <RTKDFURoutine>


/// Returns a boolean value that indicates whether the connected device can switch to a mode dedicated for upgrade.
///
/// When this property is `YES`, you can call ``RTKDFUConnectionUponGATT/switchToOTAModeWithCompletionHandler:`` to make device switching to *OTA* mode.
@property (nonatomic, readonly) BOOL canEnterOTAMode;


/// Return a boolean value that determines whether connected device can upgrade without switching to a mode dedicated for upgrade.
///
/// If this property is `NO`, you can not call any image upgrade action methods defined in  ``RTKDFURoutine`` .
@property (nonatomic, readonly) BOOL canUpgrade;


/// Request peripheral to upgrade VP image.
@property (nonatomic) BOOL upgradeVP;


/// Request the connected device to initiate a connection parameter update procedure.
///
/// - Parameter minInterval: Used to calculate the minimum value for the connection interval. Range from 6 to 3200.
/// - Parameter maxInterval: Used to calculate the maximum value for the connection interval. Range from 6 to 3200.
/// - Parameter latency: The slave latency parameter.
/// - Parameter timeout: Used for calculate connection timeout parameter.
/// - Parameter handler: The completion handler to call when the request is complete.
///
/// You may call this method to update connection parameter for a faster upgrade speed. The connection parameters you passed may not be accepted by remote device.
///
/// Refers to SIG Bluetooth Spec for the connection parameter requirements.
- (void)updateConnectionParameterWithMinInterval:(NSUInteger)minInterval
                                     maxInterval:(NSUInteger)maxInterval
                                         latency:(NSUInteger)latency
                             supervisionTimeout:(NSUInteger)timeout
                               completionHandler:(nullable RTKLECompletionBlock)handler;

/// Send the image version to the device.
///
/// - Parameter imageInfo: The imageID and imageVersion to be send.
/// - Parameter handler: The completion handler to call when the request is complete.
- (void)sendImageVersionOfImageInfo:(RTKImageVersionInfo_t)imageInfo withCompletionHandler:(nullable RTKLECompletionBlock)handler;


/// Request the connected device to activate received images and reset to a specified runing mode.
///
/// - Parameter mode: The device mode used for device next boot.
/// - Parameter handler: The completion handler to call when the request is complete.
///
/// This method is expected be called by an `RTKDFUUpgrade`.
- (void)activateImagesAndResetToMode:(RTKDFUPeripheralMode)mode ofDeviceInfo:(RTKOTADeviceInfo *)deviceInfo withCompletionHandler:(nullable RTKLECompletionBlock)handler;


/// Request the receiver to switching to a mode dedicated for upgrade.
///
/// - Parameter handler: The completion handler to call when the request is complete.
///
/// You can call this method only if ``RTKDFUConnectionUponGATT/canEnterOTAMode`` return `YES`. You should not call this method when receiver represents a device already in OTA mode.
///
/// A success switching will result in current connection disconnected, you typically call ``RTKDFUManager/scanForOTAModeDeviceConnectionOfDeviceConnection:withDeviceInfo:completionHandler:`` to scan for the device in OTA mode.
- (void)switchToOTAModeWithCompletionHandler:(nullable RTKLECompletionBlock)handler;


/// Report information about the current upgrade image.
///
/// - Parameter imageID: The imageID of the current upgrade image.
/// - Parameter currentNumber: Indicates the current upgrade image number.
/// - Parameter totalNumber: Indicates the number of all upgrade images.
/// - Parameter handler: The completion handler to call when the request is complete.
- (void)reportImageID:(RTKImageId)imageID currentImageNumber:(uint8_t)currentNumber totalImageNumber:(uint8_t)totalNumber withCompletionHandler:(nullable RTKLECompletionBlock)handler;


/// Request to check pub key information.
///
/// - Parameter imageNum: The count of the images containing pub key information.
/// - Parameter imagesKey: Key information of all images.
/// - Parameter handler: The completion handler to call when the request is complete.
- (void)checkImagesKeyOfCount:(uint16_t)imageNum andKeyInfo:(RTKImageKeyInfo_t *)imagesKey withCompletionHandler:(nullable RTKLECompletionBlock)handler;

@end

NS_ASSUME_NONNULL_END
