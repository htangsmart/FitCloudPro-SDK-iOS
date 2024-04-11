//
//  FitCloudHTMSingleObject.h
//  FitCloudKit
//
//  Created by pcjbird on 4/10/24.
//  Copyright © 2024 Zero Status. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <FitCloudKit/FitCloudKitDefines.h>

NS_ASSUME_NONNULL_BEGIN

/// 健康定时监测独立设置（Health Timing Monitoring Single Settings）
@interface FitCloudHTMSingleObject : NSObject<NSCoding>

/// 类型
@property(nonatomic, assign) FITCLOUDINTEVALHEALTHMONITORINGITEM item;

/// 是否开启
@property(nonatomic, assign) BOOL on;

/// 监测开始时间（零点开始的偏移分钟数）
@property(nonatomic, assign) UInt16 begin;

/// 监测结束时间（零点开始的偏移分钟数）
@property(nonatomic, assign) UInt16 end;

/// 监测间隔，单位：分钟
@property(nonatomic, assign) UInt16 interval;

@end

NS_ASSUME_NONNULL_END
