//
//  FitCloudPowerSavingSetting.h
//  FitCloudKit
//
//  Created by pcjbird on 3/27/23.
//  Copyright © 2023 Zero Status. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// 省电模式设置(Power Saving Mode Settings)
@interface FitCloudPowerSavingSetting : NSObject<NSCoding>

/// 是否开启
@property(nonatomic, assign) BOOL on;

/// 开始时间（零点开始的偏移分钟数）, 仅支持省电模式时间段时有效 @see allowPowerSavingModePeriod
@property(nonatomic, assign) UInt16 begin;

/// 结束时间（零点开始的偏移分钟数）, 仅支持省电模式时间段时有效 @see allowPowerSavingModePeriod
@property(nonatomic, assign) UInt16 end;

@end

NS_ASSUME_NONNULL_END
