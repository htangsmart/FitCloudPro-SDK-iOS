//
//  RTKOTAImage.h
//  RTKOTASDK
//
//  Created by jerome_gu on 2019/1/28.
//  Copyright © 2022 Realtek. All rights reserved.
//

#import <Foundation/Foundation.h>

#ifdef RTK_SDK_IS_STATIC_LIBRARY
#import "RTKOTABin.h"
#else
#import <RTKOTASDK/RTKOTABin.h>
#endif

/// Values that represent which bank image reside in a remote device.
typedef NS_ENUM(NSUInteger, RTKOTAUpgradeBank) {
    RTKOTAUpgradeBank_Unknown,          ///< The bank info is not determined.
    RTKOTAUpgradeBank_SingleOrBank0,    ///< The image reside in single bank or Bank 0.
    RTKOTAUpgradeBank_Bank1,            ///< The image reside in Bank 1.
};


NS_ASSUME_NONNULL_BEGIN

/// A concrete `RTKOTABin` subclass represents a binary which is about to be upgraded to a remote device.
///
/// An `RTKOTAUpgradeBin` provides several class methods for extract image information from a `NSData` or file. For extracted successfully, the data format should be MP Pack format or MP Bin format.
@interface RTKOTAUpgradeBin : RTKOTABin

/// The OTA Version which this binary object is created in accordance with.
@property (readonly) NSUInteger otaVersion;

/// The security version of this binary object.
@property (readonly) NSUInteger secVersion;

/// The identifier of this binary.
@property (readonly) NSUInteger imageId;

/// The raw bytes of the binary.
@property (readonly) NSData *data;

@property (readonly) uint32_t SHA256Offset;

@property (readonly) uint32_t pubKeyHash;

@property (readonly) uint16_t VPID;

@property (readonly) NSData *imageFeature;

@property (readonly) NSUInteger ICType;

- (instancetype)initWithPureData:(NSData *)data;


/// Indicates which bank this image is about be installed at.
///
/// This is available for dual bank SOC.
@property (readonly) RTKOTAUpgradeBank upgradeBank;


/// Parse and return a list of `RTKOTAUpgradeBin` objects form a MPPack file.
///
/// The archive file which path locate should be a valid MPPack file format or MP binary format.
+ (nullable NSArray <RTKOTAUpgradeBin*> *)imagesExtractedFromMPPackFilePath:(NSString *)path error:(NSError *__nullable *__nullable)errPtr;

+ (nullable NSArray <RTKOTAUpgradeBin*> *)imagesExtractFromMPPackFilePath:(NSString *)path error:(NSError *__nullable *__nullable)errPtr  DEPRECATED_MSG_ATTRIBUTE("use +imagesExtractedFromMPPackFilePath:error: instead");

/// Parse and return a list of `RTKOTAUpgradeBin` objects form a MPPack file data.
///
/// The archive file data should be a valid MPPack file format or MP binary format.
+ (nullable NSArray <RTKOTAUpgradeBin*> *)imagesExtractedFromMPPackFileData:(NSData *)data error:(NSError *__nullable *__nullable)errPtr;

+ (nullable NSArray <RTKOTAUpgradeBin*> *)imagesExtractFromMPPackFileData:(NSData *)data error:(NSError *__nullable *__nullable)errPtr DEPRECATED_MSG_ATTRIBUTE("use +imagesExtractedFromMPPackFileData:error: instead");


/// Parse and return 2 list of `RTKOTAUpgradeBin` objects for RWS buds  form a CombineMPPack file.
///
/// The archive file which path locate should be a valid CombineMPPack file format.
+ (nullable NSError*)extractCombinePackFileWithFilePath:(NSString *)path toPrimaryBudBins:(NSArray <RTKOTAUpgradeBin*> *_Nullable*_Nullable)primaryBinsRef secondaryBudBins:(NSArray <RTKOTAUpgradeBin*> *_Nullable*_Nullable)secondaryBinsRef;

/// Parse and return 2 list of `RTKOTAUpgradeBin` objects for RWS buds  form a CombineMPPack file data.
///
/// The fileData should be a valid CombineMPPack file format.
+ (nullable NSError*)extractCombinePackFileWithData:(NSData *)fileData toPrimaryBudBins:(NSArray <RTKOTAUpgradeBin*> *_Nullable*_Nullable)primaryBinsRef secondaryBudBins:(NSArray <RTKOTAUpgradeBin*> *_Nullable*_Nullable)secondaryBinsRef;

@end


NS_ASSUME_NONNULL_END
