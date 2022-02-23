//
//  FitCloudWatchLaunchVibrateSetting.h
//  FitCloudKit
//
//  Created by pcjbird on 2022/2/23.
//  Copyright © 2022 Zero Status. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <FitCloudKit/FitCloudKitDefines.h>

/**
 * @brief 手表启动震动设置
 */
@interface FitCloudWatchLaunchVibrateSetting : NSObject

/**
 * @brief 是否开启
 */
@property(nonatomic, assign) BOOL on;

/**
 * @brief 震动时长选项
 */
@property(nonatomic, assign) FITCLOUDWATCHLAUNCHVIBRATEDURATION duration;

@end

