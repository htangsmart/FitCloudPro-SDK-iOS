//
//  FitCloudMedal.h
//  FitCloudKit
//
//  Created by pcjbird on 2023-09-22.
//  Copyright © 2023 Zero Status. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <FitCloudKit/FitCloudKitDefines.h>

NS_ASSUME_NONNULL_BEGIN

@interface FitCloudMedal : NSObject

///  勋章成就等级
@property(nonatomic, readonly) FITCLOUDMEDALACHIEVEMENTLEVEL achievementLevel;

/// 勋章名称编号
/// 0  (首次达成目标)首次达成步数、距离卡路里任意目标
/// 1  (首次运动)首次任意运动>=30 分钟
/// 2  (睡眠充足)首次睡眠达 8 小时
/// 3 (连续一周达成目标)步数、距离、卡路里任意目标
/// 4 (坚持一周运动) 坚持一周每天一次任意运动>=30分钟
/// 5 (一周充足睡眠) 一周坚持每天睡眠达6小时>=5天
/// 6 (200%完成目标) 超越目标200%
/// 7 (400%完成目标) 超越目标400%
/// 8 (一月七月挑战) 一月至少日常达标>=14次
/// 9 (一月七月挑战) 七月至少日常达标>=14次
/// 10 (二月八月挑战) 二月至少运动>=420分钟
/// 11 (二月八月挑战) 八月至少运动>=420分钟
/// 12 (三月九月挑战) 三月至少步数>=120,000步
/// 13 (三月九月挑战) 九月至少步数>=120,000步
/// 14 (四月十月挑战) 四月每天至少消耗260kcal>=14天
/// 15 (四月十月挑战) 十月每天至少消耗260kcal>=14天
/// 16 (五月十一月挑战) 五月挑战累计完成目标>=60公里
/// 17 (五月十一月挑战) 十一月挑战累计完成目标>=60公里
/// 18 (六月十二月挑战) 六月坚持睡眠达8小时>=14天
/// 19 (六月十二月挑战) 十二月坚持睡眠达8小时>=14天
/// 20 (骑行等级) 骑行5公里
/// 21 (骑行等级) 骑行10公里
/// 22 (骑行等级) 骑行20公里
/// 23 (骑行等级) 骑行40公里
/// 24 (骑行等级) 骑行80公里
/// 25 (骑行等级) 骑行160公里
/// 26 (骑行等级) 骑行320公里
/// 27 (骑行等级) 骑行640公里
/// 28 (骑行等级) 骑行1280公里
/// 29 (跑步等级) 跑步5公里
/// 30 (跑步等级) 跑步10公里
/// 31 (跑步等级) 跑步20公里
/// 32 (跑步等级) 跑步40公里
/// 33 (跑步等级) 跑步80公里
/// 34 (跑步等级) 跑步160公里
/// 35 (跑步等级) 跑步320公里
/// 36 (跑步等级) 跑步640公里
/// 37 (跑步等级) 跑步1280公里
/// 38 (步行等级) 步行8000步
/// 39 (步行等级) 步行16000步
/// 40 (步行等级) 步行32000步
/// 41 (步行等级) 步行64000步
/// 42 (步行等级) 步行128000步
/// 43 (步行等级) 步行256000步
/// 44 (步行等级) 步行512000步
/// 45 (步行等级) 步行1024000步
/// 46 (步行等级) 步行2048000步
/// 47 (锻炼时间) 锻炼30分钟
/// 48 (锻炼时间) 锻炼60分钟
/// 49 (锻炼时间) 锻炼120分钟
/// 50 (锻炼时间) 锻炼240分钟
/// 51 (锻炼时间) 锻炼480分钟
/// 52 (锻炼时间) 锻炼960分钟
/// 53 (锻炼时间) 锻炼1920分钟
/// 54 (锻炼时间) 锻炼3840分钟
/// 55 (锻炼时间) 锻炼7680分钟
/// 56 (100次达成目标) 累计达标100次
/// 57 (100次运动) 累计运动100次
/// 58 (充足睡眠100天) 每天睡眠8小时累计100天
@property(nonatomic, readonly) UInt8                          achievementNameId;

/// 成就达标日期
@property(nonatomic, readonly, strong) NSDate*                achievementDate;

/// 创建勋章
/// - Parameters:
///   - level: 勋章等级
///   - nameId: 名称Id
///   - date: 达标日期
/// - Returns:
///   勋章
+(FitCloudMedal*) medalWithLevel:(FITCLOUDMEDALACHIEVEMENTLEVEL)level nameId:(UInt8)nameId date:(NSDate*)date;

@end

NS_ASSUME_NONNULL_END