//
//  RTKDFUUpgrade.h
//  RTKOTASDK
//
//  Created by jerome_gu on 2020/3/19.
//  Copyright © 2022 Realtek. All rights reserved.
//

#import <Foundation/Foundation.h>

#ifdef RTK_SDK_IS_STATIC_LIBRARY
#import "libRTKLEFoundation.h"
#import "RTKOTAUpgradeBin.h"
#import "RTKOTADeviceInfo.h"
#import "RTKDFURoutine.h"
#else
#import <RTKLEFoundation/RTKLEFoundation.h>
#import <RTKOTASDK/RTKOTAUpgradeBin.h>
#import <RTKOTASDK/RTKOTADeviceInfo.h>
#import <RTKOTASDK/RTKDFURoutine.h>
#endif


NS_ASSUME_NONNULL_BEGIN

@class RTKDFUUpgrade;

/// `RTKDFUUpgradeDelegate` defines methods to be called by an `RTKDFUUpgrade` object to report events and progress during upgrading.
///
/// You should set your  `RTKDFUUpgradeDelegate` conformed object to `RTKDFUUpgrade` delegate before call `-prepareForUpgrade:` or any upgrade methods.
@protocol RTKDFUUpgradeDelegate <NSObject>
@optional

/// Tells the delegate that upgrade is able to be started.
///
/// - Parameter task: The upgrade task reporting this event.
///
/// As a result of  ``RTKDFUUpgrade/prepareForUpgrade`` invocation,  an ``RTKDFUUpgrade`` object calls this method when preparation process succeed.
/// When this method get called, you can access device inforamtion related to upgrade by ``RTKDFUUpgrade/deviceInfo``, and you can call one of upgrade methods to start upgrade procedure.
- (void)DFUUpgradeDidReadyForUpgrade:(RTKDFUUpgrade *)task;

/// Tells the delegate that upgrade could not be started.
///
/// - Parameter task: The upgrade task reporting this event.
/// - Parameter error: An error object containing information about the preparation failure.
///
/// As a result of  ``RTKDFUUpgrade/prepareForUpgrade``: invocation,  an ``RTKDFUUpgrade`` may call this method if preparation process fail.
/// You can not call any upgrade method to start upgrade procedure after this method get called.
- (void)DFUUpgrade:(RTKDFUUpgrade *)task couldNotUpgradeWithError:(NSError *)error;

/// Tells the delegate that upgrade is about to send image bytes.
///
/// - Parameter task: The upgrade task reporting this event.
/// - Parameter connection: The device connection upon which upgrade is performing.
/// - Parameter continuationHandler: The block must be called when delegate finishs its work.
///
/// A DFU delegate can use this method to perform any necessary actions just before sending image bytes. For example, delegate may perform updating connection parameter for a faster connection.
- (void)DFUUpgrade:(RTKDFUUpgrade *)task
isAboutToSendImageBytesTo:(RTKProfileConnection *)connection
   withContinuationHandler:(void(^)(void))continuationHandler;

/// Tell the delegate that the new progress of image byte sending.
///
/// - Parameter task: The upgrade task reporting this event.
/// - Parameter connection: The device connection upon which upgrade is performing.
/// - Parameter length: The bytes count of image did send to remote device.
/// - Parameter image: The image that is current upgrading.
///
/// To get the total bytes count of image, call `image.data.length`.
- (void)DFUUpgrade:(RTKDFUUpgrade *)task
        withDevice:(RTKProfileConnection *)connection
 didSendBytesCount:(NSUInteger)length
           ofImage:(RTKOTAUpgradeBin *)image;


/// Tell the delegate that an `RTKDFUUpgrade` is about to send a new image.
///
/// - Parameter task: The upgrade task reporting this event.
/// - Parameter connection: The device connection upon which upgrade is performing.
/// - Parameter image: The image that is about to be upgraded.
- (void)DFUUpgrade:(RTKDFUUpgrade *)task
        withDevice:(RTKProfileConnection *)connection
     willSendImage:(RTKOTAUpgradeBin *)image;

/// Tell the delegate that an `RTKDFUUpgrade` did finish sending a image.
///
/// - Parameter task: The upgrade task reporting this event.
/// - Parameter connection: The device connection upon which upgrade is performing.
/// - Parameter image: The image that just be sent.
- (void)DFUUpgrade:(RTKDFUUpgrade *)task
        withDevice:(RTKProfileConnection *)connection
didCompleteSendImage:(RTKOTAUpgradeBin *)image;


/// Tell the delegate that an `RTKDFUUpgrade` did activate sent images.
///
/// - Parameter task: The upgrade task reporting this event.
/// - Parameter connection: The device connection upon which upgrade is performing.
/// - Parameter images: Images that just be activated.
///
/// Sent image works for next device boot only if be successfully activated .
- (void)DFUUpgrade:(RTKDFUUpgrade *)task
        withDevice:(RTKProfileConnection *)connection
   didActivateImages:(NSSet<RTKOTAUpgradeBin*>*)images;


/// Tell the delegate that an `RTKDFUUpgrade` did complete upgrade one device and begin to upgrade companion device.
///
/// - Parameter task: The upgrade task reporting this event.
///
/// If the remote device to be upgraded is a member of RWS bud pair, `RTKDFUUpgrade` will automatically discover and upgrade the companion device.
- (void)DFUUpgradeDidFinishFirstDeviceAndPrepareCompanionDevice:(RTKDFUUpgrade *)task;

/// Tell the delegate that an `RTKDFUUpgrade` is about to upgrade the companion device.
///
/// - Parameter task: The upgrade task reporting this event.
/// - Parameter connection: The device connection upon which upgrade is performing. The connection associate with the companion device.
/// - Parameter companionInfo: The device information related to upgrade of the companion device.
///
/// The `connection` parameter typically is different from the ``RTKDFUUpgrade/deviceConnection`` property value. Use the  `companionInfo` parameter to get the information of companion device. Soon after this method get called,  `RTKDFUUpgrade` will report progress of images send to the companion device.
- (void)DFUUpgrade:(RTKDFUUpgrade *)task
willUpgradeCompanionDevice:(RTKProfileConnection *)connection
        deviceInfo:(RTKOTADeviceInfo *)companionInfo;


@required

/// Tell the `delegate` that upgrade did complete successfully or unsuccessfully.
///
/// - Parameter task: The upgrade task reporting this event.
/// - Parameter error: An error object that indicating upgrade failure, or nil indicating upgrade success.
///
/// Check if error parameter value is nil to determine if upgrade succeed. In general, device will reboot to use new images, result in a disconnection.
- (void)DFUUpgrade:(RTKDFUUpgrade *)task didFinishUpgradeWithError:(nullable NSError *)error;

@end


/// An object that manages device upgrade task.
///
/// An (concreate) `RTKDFUUpgrade` object communicates with an remote device to upgrade it. The device can be a `GATT` profile connected device (respresented as a `CBPeripheral` instance), or `iAP` profile connected device (represented as an `EAAccessory` instance). When upgrade a GATT device, you call ``RTKDFUUpgrade/initWithPeripheral:`` initializer, and an `RTKDFUUpgradeGATT` subclass  instance is actually returned. An `RTKDFUUpgradeIAP` subclass object is actually returned when call ``RTKDFUUpgrade/initWithAccessory:`` for upgrading a iAP device.
///
/// If you have an `RTKDFUUpgrade` object at hand for upgrade, call ``RTKDFUUpgrade/prepareForUpgrade`` prior to calling any  upgrade methods, and wait for ``RTKDFUUpgradeDelegate/DFUUpgradeDidReadyForUpgrade:`` and ``RTKDFUUpgradeDelegate/DFUUpgrade:couldNotUpgradeWithError:`` get called on your delegate object. You can call `-upgrade:` methods to start upgrading only after ``RTKDFUUpgradeDelegate/DFUUpgradeDidReadyForUpgrade:`` get called. In principle, every `-upgrade:` invocation should be preceded by a ``RTKDFUUpgradeDelegate/DFUUpgradeDidReadyForUpgrade:`` invocation.
///
/// When the delegate ``RTKDFUUpgradeDelegate/DFUUpgradeDidReadyForUpgrade:`` get called, you can access `deviceInfo` to fetch upgrade related information of the device.
///
/// If the remote device to be upgraded is a member of RWS bud pair, `RTKDFUUpgrade` will automatically discover and upgrade the companion device if the companion device is online (engaged). You call  ``RTKDFUUpgrade/upgradeWithImages:`` to upgrade a single device, call ``RTKDFUUpgrade/upgradeWithImagesForPrimaryBud:imagesForSecondaryBud:`` to upgrade a RWS pair devices. The `images` or `primaryImages` and  `secondaryImages` should be appropriate for device, `RTKDFUUpgrade` may complain of image mismatch, or old images. You can also call ``RTKDFUUpgrade/upgradeWithBinaryFileAtPath:`` with a image file path,  `RTKDFUUpgrade` will parse and extract available images for upgrade.
///
/// For devices that support bank switch feature, `RTKDFUUpgrade` may select a subset of passed images applicable for next upgrade. You can call APIs of ``RTKOTADeviceInfo`` object to know this information.
///
/// `RTKDFUUpgrade` will report upgrade progress and event by calling ``RTKDFUUpgradeDelegate`` methods on your delegate while in upgrading. `RTKDFUUpgrade` conforms to `NSProgressReporting` protocol to return a overall progress object.
///
/// Everytime upgrade complete successfully or unsuccessfully, `RTKDFUUpgrade` report by calling your delegate ``RTKDFUUpgradeDelegate/DFUUpgrade:didFinishUpgradeWithError:``. When `RTKDFUUpgrade` object is upgrading in progress, you can call ``RTKDFUUpgrade/cancelUpgrade`` to request cancel upgrade, your delegate ``RTKDFUUpgradeDelegate/DFUUpgrade:didFinishUpgradeWithError:`` get called when canceling completes.
///
/// You can create multiple `RTKDFUUpgrade` instances for different devices, and upgrade them concurrently.
@interface RTKDFUUpgrade : NSObject <NSProgressReporting>

/// Initializes `RTKDFUUpgrade` object with a GATT peripheral.
///
/// - Parameter peripheral: The device that is about to be upgraded.
///
/// Use this initializer for GATT device (represented by `CBPeripheral` instance). The returned object is actually of `RTKDFUUpgradeGATT` type.
- (instancetype)initWithPeripheral:(CBPeripheral *)peripheral;

/// Initialize `RTKDFUUpgrade` object with a iAP device.
///
/// - Parameter accessory: The device that is about to be upgraded.
///
/// Use this initializer for iAP device (represented by `EAAccessory` instance). The returned object is actually of `RTKDFUUpgradeIAP` type.
- (instancetype)initWithAccessory:(EAAccessory *)accessory;

/// Initialize `RTKDFUUpgrade` object with a iAP device which support the specified protocol.
///
/// - Parameter accessory: The device that is about to be upgraded.
///
/// Use this initializer for iAP device (represented by `EAAccessory` instance). The returned object is actually of `RTKDFUUpgradeIAP` type.
- (instancetype)initWithAccessory:(EAAccessory *)accessory communicationProtocol:(NSString *)protocol;


/// Initialize `RTKDFUUpgrade` object with a iAP device and existed message communication.
///
/// - Parameter accessory: The device that is about to be upgraded.
/// - Parameter msgTransport: An already created message communication object.
///
/// Use this initializer for iAP device (represented by `EAAccessory` instance). The returned object is actually of `RTKDFUUpgradeIAP` type.
- (instancetype)initWithAccessory:(EAAccessory *)accessory existedMessageTransport:(RTKPacketTransport *)msgTransport;


/// Initialize `RTKDFUUpgrade` object with a general device connection object and profile manager.
///
/// - Parameter connection: The DFU profile connection which associate with device is about to be upgraded. Should be an instance of `RTKDFUConnectionUponGATT` or `RTKDFUConnectionUponiAP` .
/// - Parameter manager: The manager object which manage the profile connection with remote device.
///
/// The returned object type is based on which connection class is used.
- (instancetype)initWithDeviceConnection:(RTKProfileConnection *)connection profileManager:(RTKProfileConnectionManager *)manager;


/// Return the profile connection object associated with the device which this `RTKDFUUpgrade` will upgrade.
///
/// The returned object may be an `RTKDFUConnectionUponGATT` class or `RTKDFUConnectionUponiAP` class. You can make request manually with device by calling methods on this returned instance.
///
/// This property return a nil value when the underlying `CBCentralManager` is not available. It's sure to return a non-nil value when the delegate's ``RTKDFUUpgradeDelegate/DFUUpgradeDidReadyForUpgrade:`` gets called.
@property (readonly, nullable) RTKProfileConnection *deviceConnection;


/// The assigned delegate object to receive upgrade progress and result.
///
/// A DFU upgrade calls `RTKDFUUpgradeDelegate` declared methods on its `delegate` using main queue.
@property (nonatomic, weak) id<RTKDFUUpgradeDelegate> delegate;


/// Start preparation process for next upgrade.
///
/// While an `RTKDFUUpgrade` performing preparation, it may make app connected with remote device if not connected. It calls the ``RTKDFUUpgradeDelegate/DFUUpgradeDidReadyForUpgrade:`` on its delegate if the preparation is successful  or ``RTKDFUUpgradeDelegate/DFUUpgrade:couldNotUpgradeWithError:`` if preparation fails.
///
/// You should call this method before calling any upgrade methods.
- (void)prepareForUpgrade;


// MARK: - Access upgrade state

/// Return the related information about the device to upgrade.
///
/// Once your delegate ``RTKDFUUpgradeDelegate/DFUUpgradeDidReadyForUpgrade:`` gets called, you can access this property to fetch upgrade-related information.
///
/// For a RWS pair of devices, this property return the information of the device that is passed to initializer. Once ``RTKDFUUpgradeDelegate/DFUUpgrade:willUpgradeCompanionDevice:deviceInfo:`` method gets called, you can fetch the information of companion device  by this `deviceInfo` parameter.
@property (nonatomic, nullable, readonly) RTKOTADeviceInfo *deviceInfo;


/// Return the image which is being sent currently.
///
/// Return `nil` if no image is being sent currently.
@property (readonly, weak, nullable) RTKOTAUpgradeBin *upgradingImage;


// MARK: - Upgrade setting

/// The default value is `RTKOTAUpgradeMode_default`
@property RTKOTAUpgradeMode upgradeMode;


/// Set a new key for encrypting the image bytes.
///
/// - Parameter encryptionKey: The  new key used for bytes encryption. The length should be 32 bytes.
///
/// If encyption is supported by the remote device which can be determined by ``RTKOTABaseDeviceInfo/AESEnable`` , an `RTKDFUUpgrade` will encrypt image bytes before sending to device. The used key should be equal to device.  A default key is used if not set a new one. You should set this property value only when upgrade is not in progress.
- (void)setEncryptionKey:(NSData * _Nonnull)encryptionKey;


/// Set a new retry number when buffer check fails.
///
/// When the device uses **Buffer Check** manner to receive image bytes, an `RTKDFUUpgrade` will retry sending the same bytes if previous buffer check failed, until the ``RTKDFUUpgrade/retryCountWhenBufferCheckFail`` reaches. You should set this property value only when upgrade is not in progress.
///
/// The default value is `2`.
@property (nonatomic) NSUInteger retryCountWhenBufferCheckFail;


/// A boolean value that controls when upgrade completion method get called.
///
/// Deivce usually reboot once, be upgraded successfully or be reset, resulting in a disconnection. This property direct an `RTKDFUUpgrade` whether to wait for disconnection when upgrade device successfully or reset, before calling ``RTKDFUUpgradeDelegate/DFUUpgrade:didFinishUpgradeWithError:`` on its delegate. You should set this property value only when upgrade is not in progress.
///
/// The default value is `YES`.
@property BOOL shouldWaitForDisconnectionBeforeReportCompletion;


/// A boolean value that indicates if older version image is allowed for upgrade.
///
/// You should set this property value only when upgrade is not in progress. The default value is `NO`. (You could choose whether or not to use a strict check mechanism)
@property BOOL olderImageAllowed;


/// A boolean value that indicates whether all upgrade images should be newer than current images.
///
/// You should set this property value only when upgrade is not in progress. The default value is `NO`. （If @c olderImageAllowed is `NO`, `usingStrictImageCheckMechanism` is `NO` , it will compare image versions based on image priorities）
@property BOOL usingStrictImageCheckMechanism;


/// A boolean value that indicates whether to check the consistency of the feature info containing in the SOC and the upgrade file.
///
/// You should set this property value only when upgrade is not in progress. The default value is `NO`.
@property BOOL checkFeatureInfo;


/// Set the minimum battery level for upgrade.
///
/// When upgrading, the device should have battery level greater than or equal to `batteryLevelLimit`, then it could be upgraded. The default value is `30`. The value ``RTKDFUBatteryLevelInvalid`` means not checking the battery level.
@property RTKDFUBatteryLevel batteryLevelLimit;


/// when the upgradeMode is `RTKOTAUpgradeMode_updateVPData`, you should set the active VPID. (AT)
@property uint16_t activeVPID;


/// A boolean value that indicates whether the upgrade files are reordered by users.
///
///You should set this property value before upgrade. The default value is NO.
@property BOOL hasReorderedFiles;

// MARK: - Upgrade control

/// A boolean value that indicates whether an upgrade task is in progress.
@property (readonly) BOOL upgradeInProgress;


/// Start the upgrade with the specified images.
///
/// - Parameter images: An array that contains images available for upgrade. The images may contain images applying to Bank 0 and Bank 1 when the device supports "Dual Bank".
///
/// You should call ``RTKDFUUpgrade/prepareForUpgrade`` and wait for the ``RTKDFUUpgradeDelegate/DFUUpgradeDidReadyForUpgrade:`` getting called on the delegate, before calling this method.
/// This method returns immediately without waiting for tasks to finish. While upgrading, an `RTKDFUUpgrade` calls ``RTKDFUUpgradeDelegate/DFUUpgrade:withDevice:didSendBytesCount:ofImage:`` on its delegate to report progress and call ``RTKDFUUpgradeDelegate/DFUUpgrade:didFinishUpgradeWithError:`` on its delegate to report completion.
///
/// For devices that support *Dual Bank* feature, only images applying to the current unused bank will be sent to device. Which means, you can contain all images applying to both Bank 0 and Bank 1 in the `images` parameter, the actual available images will be selected from all images and be sent to device.
///
/// An `RTKDFUUpgrade` will verify the applicability of `images` parameter. Hence, if the `images` contains any images not match the remote device, or if any one in `images` is old, the `RTKDFUUpgrade` calls  ``RTKDFUUpgradeDelegate/DFUUpgrade:didFinishUpgradeWithError:`` with a non-nil error on its delegate.
///
/// You should not call this method to upgrade a pair of RWS devices.
- (void)upgradeWithImages:(NSArray <RTKOTAUpgradeBin*> *)images;


/// Start upgrade with specified images for primary and secondary devices.
///
/// - Parameter imagesForPrimary: An array containing images available to upgrade to primary device. The images may contain images applying to Bank 0 and Bank 1 when the device supports "Dual Bank".
/// - Parameter imagesForSecondary: An array containing images available to upgrade to secondary device. The images may contain images applying to Bank 0 and Bank 1 when the device supports "Dual Bank".
///
/// You should call ``RTKDFUUpgrade/prepareForUpgrade`` and wait for the ``RTKDFUUpgradeDelegate/DFUUpgradeDidReadyForUpgrade:`` getting called on the delegate, before calling this method.
/// This method returns immediately without waiting for tasks to finish. While upgrading, an `RTKDFUUpgrade` calls ``RTKDFUUpgradeDelegate/DFUUpgrade:withDevice:didSendBytesCount:ofImage:`` on its delegate to report progress and call ``RTKDFUUpgradeDelegate/DFUUpgrade:didFinishUpgradeWithError:`` on its delegate to report completion. An `RTKDFUUpgrade` will call  ``RTKDFUUpgradeDelegate/DFUUpgradeDidFinishFirstDeviceAndPrepareCompanionDevice:`` on its delegate once it completes upgrading first device and call ``RTKDFUUpgradeDelegate/DFUUpgrade:willUpgradeCompanionDevice:deviceInfo:`` on its delegate when it is just about to upgrade the secondary device.
///
/// For devices that support *Dual Bank* feature, only images applying to the current unused bank will be sent to device. Which means, you can contain all images applying to both Bank 0 and Bank 1 in the `primaryImages` and `secondaryImages` parameter, the actual available images will be selected from all images and be sent to device.
///
/// An `RTKDFUUpgrade` will verify applicability of `primaryImages` and `secondaryImages` parameters. If the `primaryImages` and `secondaryImages` contain any images not match the remote device, or if  any image of `primaryImages` or `secondaryImages` is old, `RTKDFUUpgrade` will call ``RTKDFUUpgradeDelegate/DFUUpgrade:didFinishUpgradeWithError:`` with a non-nil error on its delegate.
///
/// You should call this method only to upgrade a RWS pair of devices.
- (void)upgradeWithImagesForPrimaryBud:(NSArray <RTKOTAUpgradeBin*> *)imagesForPrimary imagesForSecondaryBud:(NSArray <RTKOTAUpgradeBin*> *)imagesForSecondary;


/// Start upgrade using images extracted from the specifed file.
///
/// - Parameter path: The path to a file which can read and extract image objects for upgrade.
///
/// The file specified by `path` should be a valid MP binary format or MP Pack format. Images extracted from file should be applicable for device, which means, you can pass a file that containing images for single device when upgrade a single device, pass a file that containing primary and secondary images for RWS pair when upgrade a pair of RWS devices. Refer to <doc:UpgradeFiles> to get a knowledge of available file formats.
///
/// Before calling this method, you should call ``RTKDFUUpgrade/prepareForUpgrade`` and wait for the ``RTKDFUUpgradeDelegate/DFUUpgradeDidReadyForUpgrade:`` getting called on its delegate.
///
/// Just like ``RTKDFUUpgrade/upgradeWithImages:`` and ``RTKDFUUpgrade/upgradeWithImagesForPrimaryBud:imagesForSecondaryBud:``, `RTKDFUUpgrade` calls methods on its delegate to report progress and result.
- (void)upgradeWithBinaryFileAtPath:(NSString *)path;


/// Cancel an outstanding upgrade task.
///
/// When there is a outstanding upgrade task, you can call this method to cancel upgrade. This method returns immediately, marking the task as being canceled. Once a task is marked as being canceled,  ``RTKDFUUpgradeDelegate/DFUUpgrade:didFinishUpgradeWithError:`` will be sent to the task delegate, passing an error in the domain `RTKOTADomain` with the code  `RTKOTAErrorUserCancelled`.
///
/// You should not call this method if there is no outstanding upgrade task.
- (void)cancelUpgrade;

@end


/// A concrete subclass of `RTKDFUUpgrade` which applying for GATT profile connected device.
///
/// This class overrides ``deviceConnection`` and returns an ``RTKDFUConnectionUponGATT`` instance.
@interface RTKDFUUpgradeGATT : RTKDFUUpgrade


/// A boolean value that represents whether user prefers to upgrade using OTA mode.
///
/// When the connected device both support upgrading silently and switching to OTA mode, this value determines which method to be used for upgrade. This value will not take effect when the device supports either method.
///
/// The default value is `NO`.
@property BOOL prefersUpgradeUsingOTAMode;

@end


/// A concrete `RTKDFUUpgrade` subclass which applying for iAP profile connected device.
///
/// @discussion This class overrides ``deviceConnection`` and return an ``RTKDFUConnectionUponiAP`` instance.
@interface RTKDFUUpgradeIAP : RTKDFUUpgrade
@end

NS_ASSUME_NONNULL_END
