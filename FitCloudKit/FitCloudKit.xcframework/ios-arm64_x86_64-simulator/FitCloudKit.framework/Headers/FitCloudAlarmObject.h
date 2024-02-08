//
//  FitCloudAlarmObject.h
//  FitCloudKit
//
//  Created by pcjbird on 2018/5/23.
//  Copyright © 2018年 Zero Status. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "FitCloudKitDefines.h"

/**
 * @brief 闹钟
 */
@interface FitCloudAlarmObject : NSObject<NSCoding>


/// 有效值0～7，为-1时SDK自动编号
@property(nonatomic, assign) NSInteger alarmId;

/**
 * @brief 闹钟日期信息
 */
@property (nonatomic, strong) NSDateComponents* fire;

/**
 * @brief 闹钟循环周期
 */
@property (nonatomic, assign) FITCLOUDALARMCYCLE cycle;

/**
 * @brief 标签/描述
 */
@property (nonatomic, strong) NSString*  label;

/**
 * @brief 是否开启
 */
@property (nonatomic, assign) BOOL       on;

@end
