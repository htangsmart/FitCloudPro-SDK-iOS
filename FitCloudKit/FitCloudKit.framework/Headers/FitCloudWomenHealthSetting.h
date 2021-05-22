//
//  FitCloudWomenHealthSetting.h
//  FitCloudKit
//
//  Created by pcjbird on 2020/5/22.
//  Copyright © 2020 Zero Status. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <FitCloudKit/FitCloudKitDefines.h>

@interface FitCloudWomenHealthSetting : NSObject<NSCoding>

/**
 * @brief 模式
*/
@property(nonatomic, readonly) WOMENHEALTHMODE mode;

/**
 * @brief 提前几天提醒，单位：天
*/
@property(nonatomic, readonly) UInt8 advanceDaysToRemind;

/**
 * @brief 提醒时间，相对零点的分钟偏移数
 */
@property(nonatomic, readonly) UInt16 offsetMinutesInDayOfRemind;

/**
 * @brief 经期长度，单位：天
*/
@property(nonatomic, readonly) UInt8 mensesDuration;

/**
 * @brief 月经周期长度，单位：天
*/
@property(nonatomic, readonly) UInt8 menstrualCycle;

/**
 * @brief 最近一次经期，格式：yyyy-MM-dd
*/
@property(nonatomic, readonly, strong) NSString* recentMenstruationBegin;

/**
 * @brief 不为0时表示月经结束日期距离月经开始日期的天数
 */
@property(nonatomic, readonly) UInt8 daysOfFinishSinceMensesBegin;

/**
 * @brief 孕期提醒方式
*/
@property(nonatomic, readonly) PREGNANCYREMINDTYPE pregancyRemindType;


+(FitCloudWomenHealthSetting*) settingwithMode:(WOMENHEALTHMODE)mode advanceDaysToRemind:(UInt8)advanceDaysToRemind offsetMinutesInDayOfRemind:(UInt16)offsetMinutesInDayOfRemind mensesDuration:(UInt8)mensesDuration menstrualCycle:(UInt8)menstrualCycle recentMenstruationBegin:(NSString*)recentMenstruationBegin daysOfFinishSinceMensesBegin:(UInt8)daysOfFinishSinceMensesBegin pregancyRemindType:(PREGNANCYREMINDTYPE)pregancyRemindType;

@end


