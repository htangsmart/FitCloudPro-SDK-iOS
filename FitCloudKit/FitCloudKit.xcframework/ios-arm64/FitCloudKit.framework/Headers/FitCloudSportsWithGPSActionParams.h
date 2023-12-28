//
//  FitCloudSportsWithGPSActionParams.h
//  FitCloudKit
//
//  Created by pcjbird on 2021/10/15.
//  Copyright © 2021 Zero Status. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <FitCloudKit/FitCloudKitDefines.h>

/**
 *@brief 手表GPS互联运动启动/结束参数
 */
@interface FitCloudSportsWithGPSActionParams : NSObject

/**
 * @brief 运动类型
 */
@property(nonatomic, assign) FITCLOUDSPORTSWITHGPS sports;

/**
 * @brief 操作行为，开始/结束/暂停/恢复
 */
@property(nonatomic, assign) FITCLOUDSPORTSWITHGPSACTION action;

/**
 * @brief 本次运动启动时间
 */
@property(nonatomic, strong) NSDate* begin;

/**
 * @brief 本次运动已运动时间
 */
@property(nonatomic, assign) NSInteger sportsTimeInSeconds;

@end


