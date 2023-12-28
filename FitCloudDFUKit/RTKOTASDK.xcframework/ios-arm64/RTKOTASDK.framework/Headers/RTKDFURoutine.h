//
//  RTKDFURoutine.h
//  RTKOTASDK
//
//  Created by jerome_gu on 2020/3/9.
//  Copyright © 2022 Realtek. All rights reserved.
//

#import <Foundation/Foundation.h>

#ifdef RTK_SDK_IS_STATIC_LIBRARY
#import "RTKOTADeviceInfo.h"
#else
#import <RTKOTASDK/RTKOTADeviceInfo.h>
#endif

/// An integer value that represents image identifier.
typedef uint16_t RTKImageId;

/// An integer value that represents image version number.
typedef uint32_t RTKImageVersion;

/// An integer value that represents image key information.
typedef uint32_t RTKImageKey;

/// Represents an invalid `RTKImageVersion` value.
#define RTKImageVersionInvalid  0xffffffff

/// Constants that represent upgrade method.
typedef NS_ENUM(uint8_t, RTKOTAUpgradeMode) {
    /// Use normal upgrade method
    RTKOTAUpgradeMode_default =   0x00,
    /// Use OTA temp section for upgrade
    RTKOTAUpgradeMode_OTATempSection,
    /// Upgrade Voice Prompt data
    RTKOTAUpgradeMode_updateVPData,
};

typedef NS_OPTIONS(uint32_t, RTKDFUTestFlag) {
    RTKDFUTestFlag_AES = 1 << 0,
    RTKDFUTestFlag_Stress = 1 << 1,
    RTKDFUTestFlag_CopyFail = 1 << 2,
    RTKDFUTestFlag_SkipFail = 1 << 3,
    RTKDFUTestFlag_BufferCheckDisable = 1 << 4,
};

/// Constants that determine which bank a image exist.
typedef NS_ENUM(uint8_t, RTKOTABinBankExistState) {
    /// Binary not exist at device
    RTKOTABinBankExistState_notExist,
    /// Binary exist at free bank
    RTKOTABinBankExistState_existAtFreeBank,
    /// Binary exist at active bank
    RTKOTABinBankExistState_existAtActiveBank,
    /// Binary exist at both bank
    RTKOTABinBankExistState_exist,
};

/// Constants that indicate result of a buffer check request.
typedef NS_ENUM(uint8_t, RTKOTAImageBufferCheckResult) {
    /// Buffer check result unkown, this is a invalid value.
    RTKOTAImageBufferCheckResult_invalid,
    /// Buffer check passed
    RTKOTAImageBufferCheckResult_success,
    /// Buffer check failed for CRC check failure.
    RTKOTAImageBufferCheckResult_crcError,
    /// Buffer check failed for length error.
    RTKOTAImageBufferCheckResult_lengthError,
    /// Buffer check failed for other errors.
    RTKOTAImageBufferCheckResult_otherError,
};

/// Constants that indicate result of a validate image request.
typedef NS_ENUM(uint8_t, RTKOTAImageValidateResult) {
    /// Image validate result invalid.
    RTKOTAImageValidateResult_invalid,
    /// Image validation result is success.
    RTKOTAImageValidateResult_success,
    /// Image validation failed for image check failure.
    RTKOTAImageValidateResult_checkFail,
    /// Image validation failed for other errors.
    RTKOTAImageValidateResult_otherFail,
};

/// Structure containing a image id and check value.
typedef struct __attribute__((packed)) {
    RTKImageId imageId;
    uint8_t checkBytes[32];
} RTKImageInfo_t;

/// Structure containing a image id and version value.
typedef struct __attribute__((packed)) {
    RTKImageId imageId;
    RTKImageVersion version;
} RTKImageVersionInfo_t;

typedef struct __attribute__((packed)) {
    RTKImageId imageId;
    uint32_t size;
} RTKImageSectionSizeInfo_t;

/// Structure containing a image id and key hash value.
typedef struct __attribute__((packed)) {
    RTKImageId imageId;
    RTKImageKey key;
} RTKImageKeyInfo_t;

/// An unsigned integer value represents battery charge level of one device.
///
/// The value ranges from 0 to 100. Besides, `RTKDFUBatteryLevelInvalid` is a special value which indicates level value is not valid.
typedef uint8_t RTKDFUBatteryLevel;

/// A constant value describes battery level is not valid.
extern const RTKDFUBatteryLevel RTKDFUBatteryLevelInvalid;


NS_ASSUME_NONNULL_BEGIN

/// A protocol that defines methods to retrieve informations about upgrade of a device and send images to upgrade a device.
///
/// @discussion This protocol defines common methods for upgrade, `RTKDFUConnectionUponGATT` and `RTKDFUConnectionUponiAP` class conform to it and implement all those methods. Those methods are expected to be used internal in SDK.
///
/// All those methods execute asynchronously and receive a block parameter as completion handler to be called when request is complete. The completion handler takes at least two parameters, `success` indicates whether this request is successful or fail, `error` indicates why the request failed.
///
/// You can pass `nil` to completion handler if you don't care about completion.
@protocol RTKDFURoutine <NSObject>

#pragma mark - Information retrieve

/// Request to retrieve upgrade related information of the connected device.
///
/// - Parameter handler: The completion handler to call when the request is complete.
///
/// If the request completes successfully, the info parameter of the completion handler block contains the information about upgrade of the connected device.
- (void)getOTAInformationWithCompletionHandler:(nullable void(^)(BOOL success, NSError *__nullable error, RTKOTABaseDeviceInfo *__nullable info))handler;


/// Request to retrieve the protocol number of the connected device.
///
/// - Parameter handler: The completion handler to call when the request is complete.
///
/// If the request completes successfully, the protocol parameter of the completion handler block indicates the protocol number of the connected device.
- (void)getProtocolTypeWithCompletionHandler:(nullable void(^)(BOOL success, NSError *__nullable error, RTKOTAProtocolType protocol))handler;


/// Request to retrieve bluetooth device address of the connected device and companion device.
///
/// - Parameter handler: The completion handler to call when the request is complete.
///
/// If the request completes successfully, the addr parameter of the completion handler block indicates the BDAddress of connected device, the companionAddr parameter indicates the BDAddress of the companion device if it has one.
- (void)getBDAddressWithCompletionHandler:(nullable void(^)(BOOL success, NSError *error, BDAddressType addr, BDAddressType companionAddr))handler;


/// Request device to get battery charge level.
///
/// - Parameter handler: The completion handler to call when the request is complete.
///
/// If the device is not RWS device, the `secondaryBattery` parameter of the completion handler block is `RTKDFUBatteryLevelInvalid`.
- (void)getBatteryLevelWithCompletionHandler:(nullable void(^)(BOOL success, NSError *error, RTKDFUBatteryLevel battery, RTKDFUBatteryLevel secondaryBattery))handler;


// TODO: describe the relationship of -getImageVersionsWithCompletionHandler: and -getImageVersionsOfActiveBank:withCompletionHandler:

/// Request to retrieve image versions installed on the connected device through characteristics.
///
/// - Parameter handler: The completion handler to call when the request is complete.
///
/// If the request completes successfully, the count parameter of the completion handler block indicates count of `infos` array, the `infos` is a pointer to an array containing image version informations.
- (void)getImageVersionsWithCompletionHandler:(nullable void(^)(BOOL success, NSError *error, NSUInteger count, RTKImageVersionInfo_t infos[_Nullable]))handler;

- (void)getImageSectionSizeWithCompletionHandler:(nullable void(^)(BOOL success, NSError *error, NSUInteger count, RTKImageSectionSizeInfo_t infos[_Nullable]))handler;


/// Request to retrieve image versions of active bank or free bank through command.
///
/// - Parameter isActiveBank: A boolean value indicates if images is current active.
/// - Parameter handler: The completion handler to call when the request is complete.
///
/// @discussion If the request completes successfully, the count parameter of the completion handler block indicates count of `infos` array, the `infos` is a pointer to an array containing image version informations.
- (void)getImageVersionsOfActiveBank:(BOOL)isActiveBank withCompletionHandler:(nullable void(^)(BOOL success, NSError *error, NSUInteger count, RTKImageVersionInfo_t infos[_Nullable]))handler;


/// Request to get each image feature installed on the connected device and check the consistency of the feature containing in the upgrade images.
///
/// - Parameter images: The upgrade files.
/// - Parameter handler: The completion handler to call when the request is complete.
///
/// If the request completes successfully, the `isConsistent` parameter of the completion handler block indicates the consistency.
- (void)checkFeatureInfoConsistencyOfImages:(NSArray <RTKOTAUpgradeBin*> *)images withCompletionHandler:(nullable void(^)(BOOL success, NSError *err, BOOL isConsistent))handler;


#pragma mark - DFU procedure operations

/// Request to retrieve the upgrade state of a given image on the connected device.
///
/// - Parameter imageId: The identifier of a image.
/// - Parameter handler: The completion handler to call when the request is complete.
///
/// If the request completes successfully, the `FWVersion` parameter of the completion handler block indicates firmware version, the `totalOffset` indicates how much bytes did received by device, the `bufferOffset` indicates how much bytes did received on a buffer.
- (void)getImageStateWithId:(RTKImageId)imageId withCompletionHandler:(nullable void(^)(BOOL success, NSError *__nullable error, NSUInteger FWVersion, NSUInteger totalOffset, NSUInteger bufferOffset))handler;

/// Request the connected device to enable Buffer Check functionality for upgrade images.
///
/// - Parameter handler: The completion handler to call when the request is complete.
///
/// If the request completes successfully, the `maxBufferSize` parameter of the completion handler block indicates the size of the Buffer, the `MTU` indicates the maximum transmission size for send image bytes.
- (void)enableBufferCheckWithCompletionHandler:(nullable void(^)(BOOL success, NSError *__nullable error, NSUInteger maxBufferSize, NSUInteger MTU))handler;


/// Request to upgrade a specific image to connected device.
///
/// - Parameter headerData: The header bytes of the specific image to send.
/// - Parameter mode: The mode to used for upgarde.
/// - Parameter encrypt: Whether encrypt parameter data.
/// - Parameter key: The key for encryption.
/// - Parameter handler: The completion handler to call when the request complete.
- (void)startUpgradeWithImageHeaderData:(NSData *)headerData
                          upgradeMode:(RTKOTAUpgradeMode)mode
                       encryptParameter:(BOOL)encrypt
                          encryptionKey:(nullable NSData *)key
                  completionHandler:(nullable RTKLECompletionBlock)handler;


/// Notify device to receive image bytes.
///
/// - Parameter imageId: The image which is about to be sent.
/// - Parameter len: The size of this image already sent.
/// - Parameter handler: The completion handler to call when the request is complete.
- (void)beginReceiveImage:(RTKImageId)imageId withSendedLength:(NSUInteger)len completionHandler:(nullable RTKLECompletionBlock)handler;

/// Returns the maximum length in byte for sending image bytes.
@property (readonly) NSUInteger maximumImageSliceSendSize;


/// Send a fragment of image bytes to connected device.
///
/// - Parameter dataSlice: The bytes fragment which is about to be sent. This data should have length not larger than `maximumImageSliceSendSize`.
/// - Parameter handler: The completion handler to call when the request is complete.
- (void)sendImageSlice:(NSData *)dataSlice withCompletionHandler:(nullable RTKLECompletionBlock)handler;


/// Check the sent data in current buffer.
///
/// - Parameter bufferData: The bytes in current buffer to be checked.
/// - Parameter handler: The completion handler to call when the request is complete.
- (void)checkBufferCRCOf:(NSData *)bufferData withCompletionHandler:(nullable void(^)(BOOL success, NSError *__nullable error, RTKOTAImageBufferCheckResult result))handler;


/// Validate the image just sent.
///
/// - Parameter imageId: The image which is validated.
/// - Parameter interval: The time out interval when waiting for this method completion.
/// - Parameter handler: The completion handler to call when the request is complete.
- (void)validateImage:(RTKImageId)imageId timeoutInterval:(NSTimeInterval)interval withCompletionHandler:(nullable void(^)(BOOL success, NSError *__nullable error, RTKOTAImageValidateResult result))handler;


/// Send a fragment of image bytes to connected device.
///
/// - Parameter imageId: The image which is validated.
/// - Parameter isLast: A boolean value indicates if the last send image is the last one.
/// - Parameter interval: The time out interval when waiting for this method completion.
/// - Parameter handler: The completion handler to call when the request is complete.
- (void)validateImage:(RTKImageId)imageId isLastImage:(BOOL)isLast timeoutInterval:(NSTimeInterval)interval withCompletionHandler:(nullable void(^)(BOOL success, NSError *__nullable error, RTKOTAImageValidateResult result))handler;


/// Activate sent images and make device reboot.
///
/// - Parameter handler: The completion handler to call when the request is complete.
///
/// Typically, the device will reboot and make current connection disconnected.
- (void)activateImagesAndResetWithCompletionHandler:(nullable RTKLECompletionBlock)handler;


/// Stop upgrade procedure.
///
/// - Parameter handler: The completion handler to call when the request is complete.
///
/// The connected device may reboot to make overal reset.
- (void)stopDFUAndResetWithCompletionHandler:(nullable RTKLECompletionBlock)handler;


/// Request to retrieve existence state of given images on the connected device.
///
/// - Parameter count: The count of the @c images array.
/// - Parameter images: A array containing image identifier and check value.
/// - Parameter handler: The completion handler to call when the request is complete.
///
/// This method may fail if remote device does not support this request.
- (void)getExistenceOfImagesCount:(NSUInteger)count imageInfos:(RTKImageInfo_t *)images withCompletionHandler:(nullable void(^)(BOOL success, NSError *error, RTKOTABinBankExistState stateArr[_Nullable]))handler;


/// Request to copy the specific image to free bank on the connected device.
///
/// - Parameter imageId: The identifier of a image.
/// - Parameter handler: The completion handler to call when the request is complete.
///
/// You use this method only when connected device supports *Dual Bank* feature.
- (void)copyExistImageOfId:(RTKImageId)imageId toFreeBankWithCompletionHandler:(nullable void(^)(BOOL success, NSError *err))handler;

- (void)copyExistImageOfId:(RTKImageId)imageId timeoutInterval:(NSTimeInterval)interval toFreeBankWithCompletionHandler:(void (^)(BOOL, NSError * _Nonnull))handler;


/// Request to enter stress test mode.
///
/// - Parameter handler: The completion handler to call when the request is complete.
///
/// You use this method to upgrade older version images and this method needs the connected device supports test mode(`[RTKOTADeviceInfo supportTest]`).
- (void)setModeToStressTestWithCompletionHandler:(nullable RTKLECompletionBlock)handler;
@end

NS_ASSUME_NONNULL_END
