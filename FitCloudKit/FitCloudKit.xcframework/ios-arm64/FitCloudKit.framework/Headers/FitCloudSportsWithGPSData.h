//
//  FitCloudSportsWithGPSData.h
//  FitCloudKit
//
//  Created by pcjbird on 2021/10/15.
//  Copyright © 2021 Zero Status. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// 手表 GPS 互联运动数据
@interface FitCloudSportsWithGPSData : NSObject

/// 本次运动启动时间
@property(nonatomic, strong, readonly) NSDate* begin;

/// 步数
@property(nonatomic, readonly) NSInteger steps;

/// 卡路里，单位：小卡 (cal)
@property(nonatomic, readonly) NSInteger calorie;

/// 心率
@property(nonatomic, readonly) UInt8  heartRate;

@end

NS_ASSUME_NONNULL_END
