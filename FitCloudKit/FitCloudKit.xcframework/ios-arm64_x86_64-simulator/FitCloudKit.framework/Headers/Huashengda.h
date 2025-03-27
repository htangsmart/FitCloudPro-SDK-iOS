//
//  Huashengda.h
//  FitCloudKit
//
//  Created by pcjbird on 3/27/25.
//  Copyright © 2025 Zero Status. All rights reserved.
//

#ifndef Huashengda_h
#define Huashengda_h
#import <Foundation/Foundation.h>

/// 华盛达智能手表应用枚举
///
/// - Note: 每个应用都有其对应的功能编号
typedef NS_ENUM(NSUInteger, HuashengdaWatchApp) {
    HuashengdaWatchAppUnknown = 0,                   // 未知
    HuashengdaWatchAppDailyData = 1,                 // 天数据
    HuashengdaWatchAppHeartRate = 2,                 // 心率
    HuashengdaWatchAppAlarmClock = 3,                // 闹钟
    HuashengdaWatchAppGame = 4,                      // 游戏
    HuashengdaWatchAppSleep = 5,                     // 睡眠
    HuashengdaWatchAppDateTime = 6,                  // 日期时间
    HuashengdaWatchAppICE = 7,                       // ICE
    HuashengdaWatchAppHabit = 8,                     // 习惯
    HuashengdaWatchAppSportRecord = 9,               // 运动记录
    HuashengdaWatchAppBloodPressure = 10,            // 血压
    HuashengdaWatchAppBloodOxygen = 11,              // 血氧
    HuashengdaWatchAppCalculator = 12,               // 计算器
    HuashengdaWatchAppWeather = 13,                  // 天气
    HuashengdaWatchAppStopwatch = 14,                // 秒表
    HuashengdaWatchAppMusic = 15,                    // 音乐
    HuashengdaWatchAppBrightnessSettings = 16,       // 亮屏调节
    HuashengdaWatchAppScreenOffClock = 17,           // 息屏时钟
    HuashengdaWatchAppWatchFaceToggleSettings = 18,  // 切换表盘
    HuashengdaWatchAppScreenOnDurationSettings = 19, // 亮屏时长
    HuashengdaWatchAppWristDurationSettings = 20,    // 翻腕亮屏时长
    HuashengdaWatchAppLanguageSettings = 21,         // 修改的语言
    HuashengdaWatchAppDNDSettings = 22,              // 勿扰
    HuashengdaWatchAppVibrationSettings = 23,        // 震动
    HuashengdaWatchAppHealthCheck = 24,              // 健康检测
    HuashengdaWatchAppUnitSettings = 25,             // 单位设置
    HuashengdaWatchAppDateSettings = 26,             // 日期设置
    HuashengdaWatchAppTimeSettings = 27,             // 时间设置
    HuashengdaWatchAppBattery = 28,                  // 电池
    HuashengdaWatchAppDrinkWater = 29,               // 喝水
    HuashengdaWatchAppSedentary = 30,                // 久坐
    HuashengdaWatchAppWearingHabitSettings = 31,     // 左右手佩戴习惯设置
    HuashengdaWatchAppPowerOff = 32                  // 关机
};

#endif /* Huashengda_h */
