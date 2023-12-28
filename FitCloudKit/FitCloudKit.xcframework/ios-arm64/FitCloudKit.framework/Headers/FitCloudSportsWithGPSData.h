//
//  FitCloudSportsWithGPSData.h
//  FitCloudKit
//
//  Created by pcjbird on 2021/10/15.
//  Copyright © 2021 Zero Status. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 *@brief 手表GPS互联运动数据
 */
@interface FitCloudSportsWithGPSData : NSObject

/**
 * @brief 本次运动启动时间
 */
@property(nonatomic, strong, readonly) NSDate* begin;

/**
 * @brief 步数
 */
@property(nonatomic, readonly) NSInteger steps;


/**
 * @brief 心率
 */
@property(nonatomic, readonly) UInt8  heartRate;

@end

NS_ASSUME_NONNULL_END
