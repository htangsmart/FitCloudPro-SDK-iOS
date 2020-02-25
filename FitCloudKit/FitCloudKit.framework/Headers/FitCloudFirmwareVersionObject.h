//
//  FitCloudFirmwareVersionObject.h
//  FitCloudKit
//
//  Created by pcjbird on 2018/5/25.
//  Copyright © 2018年 Zero Status. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "FitCloudKitDefines.h"

/**
 * @brief 手环软硬件版本信息
 */
@interface FitCloudFirmwareVersionObject : NSObject<NSCoding>

/**
 * @brief 项目的编号
 */
@property(nonatomic, strong, readonly) NSString* projectNo;

/**
 * @brief 手环底层patch版本号
 */
@property(nonatomic, strong, readonly) NSString* patchVersion;

/**
 * @brief flash文件版本号
 */
@property(nonatomic, strong, readonly) NSString* flashVersion;

/**
 * @brief 手环固件版本号
 */
@property(nonatomic, strong, readonly) NSString* firmwareVersion;

/**
 * @brief 固件版本时间序号
 */
@property(nonatomic, strong, readonly) NSString* sequenceNo;

/**
 * @brief 手环表盘支持的页面
 */
@property(nonatomic, readonly)FITCLOUDSCREENDISPLAY screenDisplaySupported;

/**
 * @brief 手环硬件支持的功能，手机APP根据该项判断在手机APP上是否显示或使用该功能
 */
@property(nonatomic, readonly) FITCLOUDHARDWARE hardwareSupported;

/**
 * @brief 是否禁止自定义屏幕显示
 */
@property(nonatomic, readonly) BOOL disableCustomScreenDisplay;

/**
 * @brief 是否显示邮件提醒开关选项
 */
@property(nonatomic, readonly) BOOL allowShowMailReminder;

/**
 * @brief 是否显示Telegram&Viber提醒开关选项
 */
@property(nonatomic, readonly) BOOL allowShowTelegramAndViberReminder;

/**
 * @brief 距离卡路里是否使用新算法
 */
@property(nonatomic, readonly) BOOL newAlgorithmWithDistanceCalories;

/**
 * @brief 是否显示心率预警选项
 */
@property(nonatomic, readonly) BOOL allowHRAlarm;

/**
 * @brief 是否显示血压预警选项
 */
@property(nonatomic, readonly) BOOL allowBPAlarm;

/**
 * @brief 是否显示新增的消息提醒(Twitter/LinkedIn/Messenger/Instagram/Snapchat/Skype)
 */
@property(nonatomic, readonly) BOOL allowShowAdditionalReminder;

/**
 * @brief 是否支持表盘升级
*/
@property(nonatomic, readonly) BOOL allowWatchFaceUpgrade;

/**
 * @brief 是否支持勿扰模式(Do Not Disturb Mode)
*/
@property(nonatomic, readonly) BOOL allowDNDMode;

/**
 * @brief 是否支持获取最新的测量数据(Latest Measurement Data)
*/
@property(nonatomic, readonly) BOOL allowRetrieveLatestMeasurementData;

/**
 * @brief 是否支持TP升级功能
*/
@property(nonatomic, readonly) BOOL allowTP;

/**
 * @brief 是否使用新的睡眠数据格式
*/
@property(nonatomic, readonly) BOOL newSleepDataFormat;

/**
 * @brief 是否为假心电
*/
@property(nonatomic, readonly) BOOL isFakeECG;

@end
