//
//  FitCloudCapacity.h
//  FitCloudKit
//
//  Created by pcjbird on 1/15/24.
//  Copyright © 2024 Zero Status. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <FitCloudKit/FitCloudKitDefines.h>
#import <FitCloudKit/FitCloudSecureCoding.h>

NS_ASSUME_NONNULL_BEGIN

/// Capacity
@interface FitCloudCapacity : NSObject<FitCloudSecureCoding,NSCopying>

/// the capacity
@property(nonatomic, readonly) FITCLOUDDEVICECAPACITY capacity;

/// 原始设备能力值，含义由 capacity 决定：可能是数量、位掩码或枚举编码。
@property(nonatomic, readonly) NSInteger value;

@end

NS_ASSUME_NONNULL_END
