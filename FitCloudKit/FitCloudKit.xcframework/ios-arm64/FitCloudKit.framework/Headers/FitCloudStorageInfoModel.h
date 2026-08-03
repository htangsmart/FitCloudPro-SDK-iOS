//
//  FitCloudStorageInfoModel.h
//  FitCloudKit
//
//  Created by pcjbird on 2026-08-01.
//  Copyright © 2026 Zero Status. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <FitCloudKit/FitCloudKitDefines.h>

NS_ASSUME_NONNULL_BEGIN

/// Device storage information model
@interface FitCloudStorageInfoModel : NSObject

/// Storage type (internal flash storage or SD card)
@property(nonatomic, readonly) FitCloudDeviceStorageType storageType;

/// Total space in bytes
@property(nonatomic, readonly) NSInteger totalSpace;

/// Remaining space in bytes
@property(nonatomic, readonly) NSInteger remainingSpace;

/// Number of songs stored on the device
@property(nonatomic, readonly) NSInteger songCount;

/// Number of audio recordings stored on the device
@property(nonatomic, readonly) NSInteger recordingCount;

/// Unavailable initializer.
- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
