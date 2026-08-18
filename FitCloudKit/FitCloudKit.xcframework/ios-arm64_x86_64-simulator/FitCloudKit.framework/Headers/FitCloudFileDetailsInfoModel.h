//
//  FitCloudFileDetailsInfoModel.h
//  FitCloudKit
//
//  Created by pcjbird on 2026-08-18.
//  Copyright © 2026 Zero Status. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// Device file details information model
@interface FitCloudFileDetailsInfoModel : NSObject

/// File name
@property(nonatomic, copy, readonly) NSString *fileName;

/// File size in bytes
@property(nonatomic, readonly) NSInteger fileSize;

/// File CRC16 checksum
@property(nonatomic, readonly) NSInteger crc;

/// File index in the storage
@property(nonatomic, readonly) NSInteger fileIndex;

/// Unavailable initializer.
- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;


@end

NS_ASSUME_NONNULL_END
