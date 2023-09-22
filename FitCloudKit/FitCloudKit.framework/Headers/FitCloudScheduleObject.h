//
//  FitCloudScheduleObject.h
//  FitCloudKit
//
//  Created by pcjbird on 1/8/21.
//  Copyright © 2021 Zero Status. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "FitCloudKitDefines.h"

/**
 * @brief 日程
 */
@interface FitCloudScheduleObject : NSObject<NSCoding>

/**
 * @brief 类型 (有效值 0～22)
 */
@property (nonatomic, assign) FITCLOUDSCHEDULE scheduleType;

/**
 * @brief 日程日期信息
 */
@property (nonatomic, strong) NSDateComponents* fire;

/**
 * @brief 日程循环周期
 */
@property (nonatomic, assign) FITCLOUDSCHEDULECYCLE cycle;

/**
 * @brief 标签/描述
 */
@property (nonatomic, strong) NSString*  label;

/**
 * @brief 是否开启
 */
@property (nonatomic, assign) BOOL       on;

@end

