//
//  FitCloudAlarmObject.h
//  FitCloudKit
//
//  Created by pcjbird on 2018/5/23.
//  Copyright © 2018年 Zero Status. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "FitCloudKitDefines.h"

/// 闹钟
@interface FitCloudAlarmObject : NSObject<NSCoding>


/// 有效值0～7，为-1时SDK自动编号
@property(nonatomic, assign) NSInteger alarmId;

/// 闹钟日期信息
@property (nonatomic, strong) NSDateComponents* fire;

/// 闹钟循环周期
@property (nonatomic, assign) FITCLOUDALARMCYCLE cycle;

/// 标签/描述
///
/// >Important: 不得超过32字节
@property (nonatomic, strong) NSString*  label;

/// 是否开启
@property (nonatomic, assign) BOOL       on;

@end
