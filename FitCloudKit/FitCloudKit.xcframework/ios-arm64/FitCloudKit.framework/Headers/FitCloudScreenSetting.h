//
//  FitCloudScreenSetting.h
//  FitCloudKit
//
//  Created by Oscar on 2021/8/19.
//  Copyright © 2021 Zero Status. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * @brief 亮屏时长
 */
@interface FitCloudBrightScreenDuration: NSObject<NSCoding>

/**
 * @brief 当前亮屏时长，单位 s
 */
@property(nonatomic, assign) UInt8 currentDuration;

/**
 * @brief 亮屏时长支持的档位个数，如果为0，则不支持该设置，隐藏该设置
 */
@property(nonatomic, assign) UInt8 durationSupportedLevelCount;

/**
 * @brief 第一档亮屏时长，单位 s
 */
@property(nonatomic, assign) UInt8 durationForLevel1;

/**
 * @brief 第二档亮屏时长，单位 s
 */
@property(nonatomic, assign) UInt8 durationForLevel2;

/**
 * @brief 第三档亮屏时长，单位 s
 */
@property(nonatomic, assign) UInt8 durationForLevel3;

/**
 * @brief 第四档亮屏时长，单位 s
 */
@property(nonatomic, assign) UInt8 durationForLevel4;

/**
 * @brief 第五档亮屏时长，单位 s
 */
@property(nonatomic, assign) UInt8 durationForLevel5;

@end

/**
 * @brief 抬腕亮屏时长
 */
@interface FitCloudWristBrightScreenDuration: NSObject<NSCoding>

/**
 * @brief 当前抬腕亮屏时长，单位 s
 */
@property(nonatomic, assign) UInt8 currentDuration;

/**
 * @brief 抬腕亮屏时长支持的档位个数，如果为0，则不支持该设置，隐藏该设置
 */
@property(nonatomic, assign) UInt8 durationSupportedLevelCount;

/**
 * @brief 第一档抬腕亮屏时长，单位 s
 */
@property(nonatomic, assign) UInt8 durationForLevel1;

/**
 * @brief 第二档抬腕亮屏时长，单位 s
 */
@property(nonatomic, assign) UInt8 durationForLevel2;

/**
 * @brief 第三档抬腕亮屏时长，单位 s
 */
@property(nonatomic, assign) UInt8 durationForLevel3;

/**
 * @brief 第四档抬腕亮屏时长，单位 s
 */
@property(nonatomic, assign) UInt8 durationForLevel4;

/**
 * @brief 第五档抬腕亮屏时长，单位 s
 */
@property(nonatomic, assign) UInt8 durationForLevel5;

@end

/**
 * @brief 长时间亮屏时长，一般为几分钟到几十分钟，在正常亮屏时间到后保持半暗状态至长时间亮屏时间结束后灭屏，一般在非AMOLED项目使用
 */
@interface FitCloudLongBrightScreenDuration: NSObject<NSCoding>

/**
 * @brief 当前长时间亮屏时长，单位 s
 */
@property(nonatomic, assign) UInt8 currentDuration;

/**
 * @brief 长时间亮屏时长支持的档位个数，如果为0，则不支持该设置，隐藏该设置
 */
@property(nonatomic, assign) UInt8 durationSupportedLevelCount;

/**
 * @brief 长时间亮屏开关
 */
@property(nonatomic, assign) BOOL longBrightScreenOn;

/**
 * @brief 第一档长时间亮屏时长，单位 min
 */
@property(nonatomic, assign) UInt8 durationForLevel1;

/**
 * @brief 第二档长时间亮屏时长，单位 min
 */
@property(nonatomic, assign) UInt8 durationForLevel2;

/**
 * @brief 第三档长时间亮屏时长，单位 min
 */
@property(nonatomic, assign) UInt8 durationForLevel3;

/**
 * @brief 第四档长时间亮屏时长，单位 min
 */
@property(nonatomic, assign) UInt8 durationForLevel4;

/**
 * @brief 第五档长时间亮屏时长，单位 min
 */
@property(nonatomic, assign) UInt8 durationForLevel5;

@end

/**
 * @brief 常亮屏设置
 * @note 常亮屏是指屏幕亮屏时间到后不灭屏，保持在半暗状态一直亮着，一般在AMOLED屏幕下使用
 */
@interface FitCloudScreenKeepBrightSetting: NSObject<NSCoding>

/**
 * @brief 是否支持常亮屏
 */
@property(nonatomic, assign) BOOL allowKeepScreenBright;

/**
 * @brief 常亮屏是否开启
 */
@property(nonatomic, assign) BOOL keepScreenBrightOn;

@end

/**
 * @brief 屏幕亮度
 */
@interface FitCloudScreenBrightness: NSObject<NSCoding>

/**
 * @brief 当前屏幕亮度百分比
 */
@property(nonatomic, assign) UInt8 currentBrightness;

/**
 * @brief 亮度支持的档位个数，如果为0，则不支持该设置，隐藏该设置
 */
@property(nonatomic, assign) UInt8 brightnessSupportedLevelCount;

/**
 * @brief 第一档亮度百分比
 */
@property(nonatomic, assign) UInt8 brightnessForLevel1;

/**
 * @brief 第二档亮度百分比
 */
@property(nonatomic, assign) UInt8 brightnessForLevel2;

/**
 * @brief 第三档亮度百分比
 */
@property(nonatomic, assign) UInt8 brightnessForLevel3;

/**
 * @brief 第四档亮度百分比
 */
@property(nonatomic, assign) UInt8 brightnessForLevel4;

/**
 * @brief 第五档亮度百分比
 */
@property(nonatomic, assign) UInt8 brightnessForLevel5;

@end

/**
 * @brief 屏幕设置
 */
@interface FitCloudScreenSetting : NSObject<NSCoding>

/**
 * @brief 亮屏时长
 */
@property(nonatomic, strong) FitCloudBrightScreenDuration* brightScreenDuration;

/**
 * @brief 抬腕亮屏时长
 */
@property(nonatomic, strong) FitCloudWristBrightScreenDuration* wristBrightScreenDuration;

/**
 * @brief 长时间亮屏时长
 */
@property(nonatomic, strong) FitCloudLongBrightScreenDuration* longBrightScreenDuration;

/**
 * @brief 常亮屏设置
 */
@property(nonatomic, strong) FitCloudScreenKeepBrightSetting* screenKeepBrightSetting;

/**
 * @brief 屏幕亮度
 */
@property(nonatomic, strong) FitCloudScreenBrightness* screenBrightness;

@end

