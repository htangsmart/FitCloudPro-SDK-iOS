//
//  FitCloudPersonalizedReminderObject.h
//  FitCloudKit
//
//  Created by pcjbird on 4/26/24.
//  Copyright © 2024 Zero Status. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "FitCloudKitDefines.h"

NS_ASSUME_NONNULL_BEGIN

/// 个性化提醒 (Personalized reminder object)
@interface FitCloudPersonalizedReminderObject : NSObject

/// Id, 其中内置Id定义参见：FITCLOUDBUILTINPERSONALIZEDREMINDER 定义
/// 自定义 Id 从 100 开始
@property(nonatomic, readonly) UInt8 reminderId;

/// 提醒类型
@property(nonatomic, readonly) FITCLOUDPERSONALIZEDREMINDERTYPE reminderType;

/// 是否开启
@property(nonatomic, assign) BOOL on;

/// 循环周期，重复
@property(nonatomic, assign) FITCLOUDPERSONALIZEDREMINDERCYCLE cycle;

/// 提醒时间类型
@property(nonatomic, assign) FITCLOUDPERSONALIZEDREMINDTIMETYPE remindTimeType;

/// 如果为时间段类型，该字段表示时间段开始时间(距离0点的分钟数)，单位：分钟
@property(nonatomic, assign) UInt16 begin;

/// 如果为时间段类型，该字段表示时间段结束时间(距离0点的分钟数)，单位：分钟
@property(nonatomic, assign) UInt16 end;

/// 如果为时间段类型，该字段表示提醒时间间隔，单位：分钟
@property(nonatomic, assign) UInt16 interval;

/// 是否开启午休免打扰
@property(nonatomic, assign) BOOL skipDuringLunchBreak;

/// 午休开始时间 (距离0点的分钟数)，单位：分钟
@property(nonatomic, assign) UInt16 lunchBreakBegin;

/// 午休结束时间 (距离0点的分钟数)，单位：分钟
@property(nonatomic, assign) UInt16 lunchBreakEnd;

/// 如果为时间点提醒类型，提醒时间点数组，时间点为距离0点的分钟数，单位：分钟
@property(nonatomic, strong, nullable) NSArray<NSNumber*>* remindMoments;

/// 提醒名称，最长为30字节，超过自动截取
@property(nonatomic, strong) NSString* name;

/// 提醒备注，最长为60字节，超过自动截取
@property(nonatomic, strong) NSString* notes;


/// 创建内置类型个性化提醒
/// - Parameters:
///   - builtInReminderId: 内置类型提醒Id，请传入合法的内置Id，否则创建失败
/// - Returns:
/// 个性化提醒
+(instancetype _Nullable) createBuiltInReminderWith:(FITCLOUDBUILTINPERSONALIZEDREMINDER) builtInReminderId;

/// 创建内置类型个性化提醒
/// - Parameters:
///   - index: 自定义个性化提醒编号，从0开始，数量必须小于手表支持的自定义个性化提醒的数量, @see FITCLOUDDEVICECAPACITY_CUSTOMIZEDPERSONALIZEDREMINDERFEATURE
/// - Returns:
/// 个性化提醒
+(instancetype _Nullable) createCustomReminderWithIndex:(NSInteger) index;


+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
