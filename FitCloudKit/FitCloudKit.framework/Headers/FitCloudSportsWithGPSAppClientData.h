//
//  FitCloudSportsWithGPSAppClientData.h
//  FitCloudKit
//
//  Created by pcjbird on 2021/10/15.
//  Copyright © 2021 Zero Status. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 *@brief 手表GPS互联运动APP端当前运动信息
 */
@interface FitCloudSportsWithGPSAppClientData : NSObject

/**
 * @brief 本次运动启动时间
 */
@property(nonatomic, strong) NSDate* begin;

/**
 * @brief 距离，单位：厘米(cm)
 */
@property(nonatomic, assign) NSInteger distance;

/**
 * @brief 已运动时间，单位：秒(s)
 */
@property(nonatomic, assign) NSInteger sportsTimeInSeconds;

@end

NS_ASSUME_NONNULL_END