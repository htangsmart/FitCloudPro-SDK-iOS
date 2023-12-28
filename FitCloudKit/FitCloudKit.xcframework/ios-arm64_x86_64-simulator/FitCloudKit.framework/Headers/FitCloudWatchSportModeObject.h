//
//  FitCloudWatchSportModeObject.h
//  FitCloudKit
//
//  Created by pcjbird on 2021/9/30.
//  Copyright © 2021 Zero Status. All rights reserved.
//
#import <Foundation/Foundation.h>
#import <FitCloudKit/FitCloudKitDefines.h>

/**
 * @brief 手表运动模式
*/
@interface FitCloudWatchSportModeObject : NSObject

/**
 * @brief 运动模式类型
 */
@property(nonatomic, readonly) FITCLOUDSPORTSTYPE sport;

/**
 * @brief 是否支持推送
 */
@property(nonatomic, readonly) BOOL canPush;

@end

