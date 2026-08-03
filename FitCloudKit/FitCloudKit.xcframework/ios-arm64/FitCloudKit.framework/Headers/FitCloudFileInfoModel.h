//
//  FitCloudFileInfoModel.h
//  FitCloudKit
//
//  Created by pcjbird on 2026-08-01.
//  Copyright © 2026 Zero Status. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// Device file information model
@interface FitCloudFileInfoModel : NSObject

/// File name
@property(nonatomic, copy, readonly) NSString *fileName;

/// File size in bytes
@property(nonatomic, readonly) NSInteger fileSize;

/// Unavailable initializer.
- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
