//
//  FitCloudSportsWithGPSCurrentStatus.h
//  FitCloudKit
//
//  Created by pcjbird on 2021/11/10.
//  Copyright © 2021 Zero Status. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <FitCloudKit/FitCloudKitDefines.h>
NS_ASSUME_NONNULL_BEGIN

/**
 *@brief 手表GPS互联运动APP手表端端当前运动状态
 */
@interface FitCloudSportsWithGPSCurrentStatus : NSObject

/**
 * @brief 本次运动启动时间
 */
@property(nonatomic, strong) NSDate* begin;

/**
 * @brief 运动类型
 */
@property(nonatomic, assign) FITCLOUDSPORTSWITHGPS sports;

/**
 * @brief 运动状态
 */
@property(nonatomic, assign) FITCLOUDSPORTSWITHGPSSTATUS status;

/**
 * @brief 运动启动方式
 */
@property(nonatomic, assign) FITCLOUDSPORTSWITHGPSSTARTFROM startMethod;

@end

NS_ASSUME_NONNULL_END
