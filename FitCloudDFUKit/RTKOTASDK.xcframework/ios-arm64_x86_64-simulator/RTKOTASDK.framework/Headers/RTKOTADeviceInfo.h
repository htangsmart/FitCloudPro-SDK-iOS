//
//  RTKOTADeviceInfo.h
//  RTKOTASDK
//
//  Created by jerome_gu on 2020/3/9.
//  Copyright © 2022 Realtek. All rights reserved.
//

#import <Foundation/Foundation.h>

#ifdef RTK_SDK_IS_STATIC_LIBRARY
#import "libRTKLEFoundation.h"
#import "RTKOTAUpgradeBin.h"
#import "RTKOTAInstalledBin.h"
#else
#import <RTKLEFoundation/RTKLEFoundation.h>
#import <RTKOTASDK/RTKOTAUpgradeBin.h>
#import <RTKOTASDK/RTKOTAInstalledBin.h>
#endif

/// Values that indicate comunication protocol a device may implement.
typedef NS_ENUM(NSUInteger, RTKOTAProtocolType) {
    /// Old type for Bumblebee, GATT and SPP are supported.
    RTKOTAProtocolType_NA           =   0x0000,
    /// For Bumblebee, GATT is supported.
    RTKOTAProtocolType_Bumblebee    =   0x0010,
    /// For Bumblebee, SPP is supported.
    RTKOTAProtocolType_Bumblebee2   =   0x0011,
    RTKOTAProtocolType_Bee          =   0x0012,
    RTKOTAProtocolType_Ali          =   0x0013,
    RTKOTAProtocolType_Watch        =   0x0014,
    RTKOTAProtocolType_0015         =   0x0015,
    
    RTKOTAProtocolTypeGATTSPP       =   RTKOTAProtocolType_NA,
    RTKOTAProtocolTypeGATT          =   RTKOTAProtocolType_Bumblebee,
    RTKOTAProtocolTypeSPP           =   RTKOTAProtocolType_Bumblebee2,
};


/// Values that represent the ear bud information about the remote device.
typedef NS_ENUM(NSUInteger, RTKOTAEarbud) {
    /// The earbud info is not known.
    RTKOTAEarbudUnkown,
    /// The earbud is primary bud.
    RTKOTAEarbudPrimary,
    /// The earbud is secondary bud.
    RTKOTAEarbudSecondary,
    /// The earbud is a single bud.
    RTKOTAEarbudSingle,
};


/// Values that mark the order of the currently upgraded buds.
typedef NS_ENUM(NSUInteger, RTKOTABudFlag) {
    /// The earbud info is not known.
    RTKOTABudUnkown,
    /// The earbud is first bud.
    RTKOTABudFirst,
    /// The earbud is second bud.
    RTKOTABudSecond,
};


/// Values that represent the bank info about the remote device.
typedef NS_ENUM(NSInteger, RTKOTABankType) {
    /// The bank info is not valid.
    RTKOTABankTypeInvalid   =   -1,
    /// A single bank.
    RTKOTABankTypeSingle    = 0x00,
    /// The primary Bank in a dual bank case.
    RTKOTABankTypeBank0,
    /// The secondary Bank in a dual bank case.
    RTKOTABankTypeBank1,
};

/// Values that represent the encryption method used for image byte encryption.
typedef NS_ENUM(NSInteger, RTKOTAImageDataEncryptionMethod) {
    /// Encrypt first 16 bytes of a image byte packet.
    RTKOTAImageDataEncryptionMethod_first16Bytes,
    /// Encrypt all bytes of a image byte packet.
    RTKOTAImageDataEncryptionMethod_allBytes,
};


NS_ASSUME_NONNULL_BEGIN

/// A collection of information about the device to be upgraded.
///
/// Use an  `RTKOTADeviceInfo` object to access information about configurations of the device and how to upgrade the device. You get an  `RTKOTADeviceInfo` object when succeed in calling  ``RTKDFURoutine/getOTAInformationWithCompletionHandler:`` on an `RTKDFURoutine` conformed object. Do not create `RTKOTADeviceInfo` objects directly.
///
/// An `RTKDFUUpgrade` uses information of this class object when upgrading device.
@interface RTKOTABaseDeviceInfo : NSObject

/// The protocol type this device implement.
@property (readonly) RTKOTAProtocolType protocolType;

/// Returns the DFU implementation version number of a device.
@property (readonly) NSUInteger OTAVersion;

/// The security version of the device.
@property (readonly) NSUInteger securityVersion;


/// Returns the size in bytes of temp buffer section used for upgrade.
///
/// The value unit is 4k.
@property (readonly) NSUInteger tempBufferSize;


/// Returns which bank the device used currently.
///
/// A device which could be able to be upgraded supports either *Bank Switching* or *Temp area memory* manner, can be determined by this property value. If the value is `RTKOTABankTypeSingle`, the device uses *Temp area memory*. If this value is `RTKOTABankTypeBank0` or `RTKOTABankTypeBank1` , device uses *Bank Switching* manner. When upgrading a *Bank Switching* device, images bytes will be saved at the bank current not used.
@property (readonly) RTKOTABankType activeBank;

/// Returns the bank that is currently running the boot patch image.
///
/// The valid value can be `RTKOTABankTypeBank0` or `RTKOTABankTypeBank1`.
@property (readonly) RTKOTABankType activeBootPatchBank;

/// Returns the bank that is currently running the secure app/secure app data  image.
///
/// The valid value can be  `RTKOTABankTypeSingle`, `RTKOTABankTypeBank0` or `RTKOTABankTypeBank1`.
@property (readonly) RTKOTABankType activeSecureAppBank;

/// Returns a boolean value that indicating whether *Buffer Check* mechanism is enabled by device.
///
/// This is used for image bytes transmission.
@property (readonly) BOOL bufferCheckEnable;


/// Returns a boolean value that indicating whether *AES encryption* is supported by device.
///
/// This is used for image bytes transmission.
@property (readonly) BOOL AESEnable;


/// Returns the encryption mode that controls how bytes are encrypted when they are sent to device.
///
/// This is used for image bytes transmission.
@property (readonly) RTKOTAImageDataEncryptionMethod encryptionMode;


@property (readonly) BOOL copyImage;


/// Returns a boolean value that indicating whether device can receive multiple images at a time.
///
/// This is used for image bytes transmission.
@property (readonly) BOOL updateMultiImages;


/// Returns a boolean value that indicating whether the device supports normal OTA.
///
/// This is used for image bytes transmission.
@property (readonly) BOOL supportNormalOTA;


/// Indicates whether the device can upgrade VP. (For AT)
///
/// If this value is `YES`,  you could set `upgradeMode` to `RTKOTAUpgradeMode_updateVPData`.
@property (nonatomic, readonly) BOOL canUpdateVP;


/// Indicates whether the device can upgrade in VP ID mode. (For AT)
///
/// If this value is `YES`,  you could set `upgradeMode` to `RTKOTAUpgradeMode_updateVPData`.
@property (nonatomic, readonly) BOOL canUpdateVPID;


/// Returns the offset of DFU Header.
@property (readonly) NSUInteger headerOffset;


/* RWS Upgrade related properties */

/// Returns a boolean value indicating whether the device is one of RWS pair.
///
/// If this property value is `YES` , to start upgrade, you call ``RTKDFUUpgrade/upgradeWithImagesForPrimaryBud:imagesForSecondaryBud:`` or ``RTKDFUUpgrade/upgradeWithBinaryFileAtPath:`` with file containing images for both primary and secondary bud.
@property (readonly) BOOL isRWSMember;


/// Returns the bud type of a device.
///
/// If  ``RTKOTADeviceInfo/isRWSMember`` returns `YES`, the value of this property should be either `RTKOTAEarbudPrimary` or `RTKOTAEarbudSecondary` .
@property (readonly) RTKOTAEarbud budType;


/// Returns a boolean value indicating whether the device is in engaged with companion device.
///
/// If this value is `YES` , when you call upgrade methods on an `RTKDFUUpgrade` object, both the pair of devices will be upgraded at a time.
@property (readonly) BOOL engaged;


/// Indicates whether this device has received images right now, but not be activated.
@property (readonly) BOOL upgradedCurrently;


/// Indicates whether this device supports test mode.
@property (readonly) BOOL supportTest;

/// Indicates whether the first or second bud is being upgraded.
@property (readonly) RTKOTABudFlag budFlag;

/// Indicates whether the current link is GATT Over BREDR.
@property (readonly) BOOL GATTOverBREDR;

@end


/// An `RTKOTABaseDeviceInfo` subclass containing additional informations of the device.
///
/// An `RTKDFUUpgrade` object creates this object when be ready for upgrading a device.
@interface RTKOTADeviceInfo : RTKOTABaseDeviceInfo


/// Returns the address value of a device.
@property (readonly) BDAddressType bdAddress;


/// Returns the address value of the companion device.
///
/// Returns `BDAddressNull` if the device is not a member of RWS pair.
@property (readonly) BDAddressType companionBDAddress;


/// Returns a list of images that is installed in remote device.
///
/// You can use this property to access what type and what version of images are installed at connected device.
@property (readonly) NSArray <RTKOTAInstalledBin*> *bins;


/// Returns the buffer size for sending image bytes.
///
 /// The value is `0` if the value is not determined.
@property (readonly) NSUInteger maxBufferSize;


/// Returns a list of images that is installed in the inactive bank.
///
/// You can use this property to access what type and what version of images are installed in the inactive bank.
@property (readonly) NSArray <RTKOTAInstalledBin*> *inactiveBins;

@end


@interface RTKOTADeviceInfo (ImageVerification)

/// Check the images and return a boolean value that indicates if those images are valid to be upgraded to device.
///
/// This method will check if the image is older version.
- (BOOL)isAvailableForUpgradeOfImages:(NSArray <RTKOTAUpgradeBin*> *)images
                 usingStrictMechanism:(BOOL)usingStrict
                             inVPMode:(BOOL)isVPmode
                       withActiveVPID:(uint16_t)VPID
                          returnError:(NSError **)error;


/// Check the images and return a boolean value that indicates if those images are valid to be upgraded to device.
///
/// - Parameter images: The images to be checked. The images could be returned by calling `RTKOTAUpgradeBin` image extract methods.
/// - Parameter yesOrNo: Indicating whether old image is allowed.
/// - Parameter usingStrict: Indicating whether to use a strict check policy (It is meaningful only when old image is not allowed)
/// - Parameter isVPMode: Indicating whether the `upgradeMode` is `RTKOTAUpgradeMode_updateVPData`
/// - Parameter VPID: The active VPID of VP image (It is meaningful only when the upgradeMode is `RTKOTAUpgradeMode_updateVPData`)
/// - Parameter error: A `NSError` object pointer used to return a error object if the check fails.
///
/// - Returns `YES` if the passed images could be upgraded, `NO` otherwise.
///
/// This method check each member of `images`, confirming if each image matches the device and passes the version rule. If check failed, this method returns `NO`, and the `error` pointer is set to a error object describing the cause.
///
/// Before calling upgrade methods to start upgrade, you can call this method to check if your images are able to be upgraded. If you call upgrade methods with unavailable images, `RTKDFUUpgrade` will report upgrade failure immediately.
///
/// Use this method for device that is not a member of RWS pair.
- (BOOL)isAvailableForUpgradeOfImages:(NSArray <RTKOTAUpgradeBin*> *)images
                 checkingImageVersion:(BOOL)yesOrNo
                 usingStrictMechanism:(BOOL)usingStrict
                             inVPMode:(BOOL)isVPMode
                       withActiveVPID:(uint16_t)VPID
                          returnError:(NSError **)error;


/// Check the images and return a boolean value that indicates if those images are valid to be upgraded to device.
- (BOOL)isAvailableForUpgradeOfImagesForPrimaryBud:(NSArray <RTKOTAUpgradeBin*> *)imagesForPrimary
                             imagesForSecondaryBud:(NSArray <RTKOTAUpgradeBin*> *)imagesForSecondary
                              usingStrictMechanism:(BOOL)usingStrict
                                          inVPMode:(BOOL)isVPmode
                                    withActiveVPID:(uint16_t)VPID
                                       returnError:(NSError **)error;


/// Check the images and return a boolean value that indicates if those images are valid to be upgraded to device.
///
/// - Parameter imagesForPrimary: The images for primary bud to be checked. The images could be returned by calling @c RTKOTAUpgradeBin image extract methods.
/// - Parameter imagesForSecondary: The images for secondary bud to be checked. The images could be returned by calling @c RTKOTAUpgradeBin image extract methods.
/// - Parameter error: A @c NSError object pointer used to return a error object if the check fails.
///
/// - Returns `YES` if the passed images could be upgraded, `NO` otherwise.
///
/// This method check each image of `primaryImages` and `secondaryImages` , confirming if each image matches the device and passes the version rule. If check failed, this method returns `NO`, and the `error` pointer is set to a error object describing the cause.
///
/// Before calling upgrade methods to start upgrade, you can call this method to check if your images are able to be upgraded. If you call upgrade methods with unavailable images, `RTKDFUUpgrade` will report upgrade failure immediately.
- (BOOL)isAvailableForUpgradeOfImagesForPrimaryBud:(NSArray <RTKOTAUpgradeBin*> *)imagesForPrimary
                             imagesForSecondaryBud:(NSArray <RTKOTAUpgradeBin*> *)imagesForSecondary
                              checkingImageVersion:(BOOL)yesOrNo
                              usingStrictMechanism:(BOOL)usingStrict
                                          inVPMode:(BOOL)isVPmode
                                    withActiveVPID:(uint16_t)VPID
                                       returnError:(NSError **)error;


/// Compare the bank information of the images and device, select and return the applicable images for upgrade.
///
/// - Parameter images: The images to be selected. Should pass  the `-isAvailableForUpgradeOfImages:` method. The images could be returned by calling one of the `RTKOTAUpgradeBin` image extracting methods.
///
/// For a device supporting "Dual Bank" feature, and images applying to both Bank are provided, only images for current unused bank will be actually sent to this device. This method returns those available images.
/// For a device not supporting "Dual Bank", the images you passed should not applying to "Dual Bank" device.
///
/// Typically, this method returns a subset of the passed `images` .
- (NSArray <RTKOTAUpgradeBin*> *)applicableImagesSelectedFromImages:(NSArray <RTKOTAUpgradeBin*> *)images;


/// Compare the bank information and bud type of the images and device, select and return the applicable images for upgrade.
///
/// - Parameter imagesForPrimary: The images for primary bud to be selected. Should pass `-isAvailableForUpgradeOfImagesForPrimaryBud:imagesForSecondaryBud:` method. The images could be returned by calling `RTKOTAUpgradeBin` image extract methods.
/// - Parameter imagesForSecondary: The images for secondary bud to be selected. Should pass `-isAvailableForUpgradeOfImagesForPrimaryBud:imagesForSecondaryBud:` method. The images could be returned by calling `RTKOTAUpgradeBin` image extract methods.
///
/// Additional to what `-applicableImagesSelectedFromImages:` does, this method considers what bud type this device is, and returns only images applying to this bud type.
///
/// Typically, this method returns a subset of the passed `primaryImages` or `secondaryImages` .
- (NSArray <RTKOTAUpgradeBin*> *)applicableImagesSelectedFromImagesForPrimaryBud:(NSArray <RTKOTAUpgradeBin*> *)imagesForPrimary
                                                           imagesForSecondaryBud:(NSArray <RTKOTAUpgradeBin*> *)imagesForSecondary;

@end

NS_ASSUME_NONNULL_END
