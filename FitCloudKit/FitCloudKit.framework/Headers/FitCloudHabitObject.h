//
//  FitCloudHabitObject.h
//  FitCloudKit
//
//  Created by pcjbird on 2022/11/23.
//  Copyright © 2022 Zero Status. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <FitCloudKit/FitCloudKitDefines.h>

NS_ASSUME_NONNULL_BEGIN

@interface FitCloudHabitObject : NSObject<NSCoding>

+ (instancetype _Nullable)new NS_UNAVAILABLE;
- (instancetype _Nullable)init NS_UNAVAILABLE;

/**
 * @brief 循环周期
 */
@property (nonatomic, readonly) FITCLOUDHABITCYCLE cycle;

/**
 * @brief 关联功能
 */
@property (nonatomic, readonly) FITCLOUDHABITASSOCIATEDFEATURE associatedFeature;

/**
 * @brief 提前n分钟提醒，单位：分钟
 */
@property (nonatomic, readonly) UInt8 aheadRemindInMinute;

/**
 * @brief 提醒时长，单位：秒
 */
@property (nonatomic, readonly) UInt8 remindDurationInSecond;


/**
 * @brief 开始时间
 */
@property (nonatomic, strong, readonly) NSDateComponents* habitBegin;

/**
 * @brief 习惯时长，单位：分钟
 */
@property (nonatomic, readonly) UInt16 habitDurationInMinutes;

/**
 * @brief 当前状态
 */
@property (nonatomic, readonly) FITCLOUDHABITSTATUS status;

/**
 * @brief 达标天数，单位：天
 */
@property (nonatomic, readonly) UInt8 achievementDays;


/**
 * @brief 最长连续达标天数，单位：天
 */
@property (nonatomic, readonly) UInt8 maxContinuousAchievementDays;

/**
 * @brief 任务(目标)天数，单位：天
 */
@property (nonatomic, readonly) UInt8 targetDays;

/*
 * @brief 一周内达标情况
 */
@property (nonatomic, readonly) FITCLOUDHABITACHIEVEMENT achievementLastWeek;

/**
 * @brief 最新达标日期的月份
 */
@property(nonatomic, readonly) UInt8 lastAchievementMonth;

/**
 * @brief 最新达标日
 */
@property(nonatomic, readonly) UInt8 lastAchievementDay;

/**
 * @brief 习惯名称规则
 */
@property (nonatomic, readonly) FITCLOUDHABITNAMERULE nameRule;

/**
 * @brief 自定义名称，非自定义名称时为空
 */
@property (nonatomic, strong, readonly) NSString* _Nullable customName;

/**
 * @brief 创建习惯养成
 * @param cycle 循环
 * @param associatedFeature 关联功能
 * @param aheadRemindInMinute 提前n分钟提醒，单位：分钟
 * @param remindDurationInSecond 提醒时长，单位：秒
 * @param habitBegin 开始时间
 * @param habitDurationInMinutes 习惯时长，单位：分钟
 * @param status 当前状态
 * @param achievementDays 达标天数，单位：天
 * @param maxContinuousAchievementDays 最长连续达标天数，单位：天
 * @param targetDays 任务(目标)天数，单位：天
 * @param achievementLastWeek 一周内达标情况
 * @param lastAchievementMonth 最新达标日期的月份
 * @param lastAchievementDay 最新达标日
 * @param nameRule 习惯名称规则
 * @param customName 自定义名称，非自定义名称时为空
 * @param allowNameTrim 是否允许根据长度自动截取名字
 * @param error 错误返回
 * @return 习惯养成, 如果不符合规则可能创建失败返回nil
 */
+(FitCloudHabitObject* _Nullable) createWithCycle:(FITCLOUDHABITCYCLE)cycle
                                associatedFeature:(FITCLOUDHABITASSOCIATEDFEATURE)associatedFeature
                                      aheadRemind:(UInt8)aheadRemindInMinute
                                   remindDuration:(UInt8)remindDurationInSecond
                                       habitBegin:(NSDateComponents*)habitBegin
                                    habitDuration:(UInt16)habitDurationInMinutes
                                           status:(FITCLOUDHABITSTATUS)status
                                      achievement:(UInt8)achievementDays
                         maxContinuousAchievement:(UInt8)maxContinuousAchievementDays
                                       targetDays:(UInt8)targetDays
                              achievementLastWeek:(FITCLOUDHABITACHIEVEMENT) achievementLastWeek
                             lastAchievementMonth:(UInt8) lastAchievementMonth
                               lastAchievementDay:(UInt8) lastAchievementDay
                                         nameRule:(FITCLOUDHABITNAMERULE)nameRule
                                       customName:(NSString* _Nullable)customName
                                    allowNameTrim:(BOOL)allowNameTrim
                                            error:(NSError ** _Nullable)error;
@end

NS_ASSUME_NONNULL_END
