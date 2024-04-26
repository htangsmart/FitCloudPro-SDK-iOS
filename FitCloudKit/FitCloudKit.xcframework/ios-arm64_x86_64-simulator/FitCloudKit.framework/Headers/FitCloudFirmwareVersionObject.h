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
 * @note 补丁：当该标志位为true时，allowShowMailReminder/allowShowTelegramAndViberReminder强制为true
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

/**
 * @brief 是否支持常用联系人
*/
@property(nonatomic, readonly) BOOL allowFavContacts;

/**
 * @brief 是否支持防护提醒
*/
@property(nonatomic, readonly) BOOL allowProtectionReminder;

/**
 * @brief 是否支持设置健康监测间隔时间，指手表定时自动监测健康数据，并非单次实时监测
*/
@property(nonatomic, readonly) BOOL allowSetHealthMonitorInterval;

/**
 * @brief 是否支持设置久坐提醒间隔时间
*/
@property(nonatomic, readonly) BOOL allowSetLSRInterval;

/**
 * @brief 是否支持天气预报(该手表支持实时天气 + 未来几天的天气预报)
*/
@property(nonatomic, readonly) BOOL allowWeatherForecast;

/**
 * @brief 是否支持洗手提醒
*/
@property(nonatomic, readonly) BOOL allowHandWashReminder;

/**
 * @brief 是否支持将天气推送开关的状态状态同步给手表，当该标志位为true时，app可以将当前天气推送开关的状态同步给手表
*/
@property(nonatomic, readonly) BOOL allowWeatherPushSwitchStatusSync;

/**
 * @brief 是否支持锁屏密码
 */
@property(nonatomic, readonly) BOOL allowLockScreenPassword;

/**
 * @brief 是否需要定制查找iPhone的响铃
 */
@property(nonatomic, readonly) BOOL shouldCustomFindiPhoneRing;

/**
 * @brief 是否支持日程提醒
 */
@property(nonatomic, readonly) BOOL allowScheduleReminder;

/**
 * @brief 是否支持Hike&Youtube提醒
 */
@property(nonatomic, readonly) BOOL allowHikeAndYoutubeReminder;

/**
 * @brief 是否支持多表盘推送
 */
@property(nonatomic, readonly) BOOL allowMultiWatchfacePush;

/**
 * @brief 是否支持表盘模块化
 */
@property(nonatomic, readonly) BOOL allowWatchfaceModular;

/**
 * @brief 是否为新的GUI结构
 */
@property(nonatomic, readonly) BOOL isNewGUIArchitecture;

/**
 * @brief 是否支持游戏皮肤推送
 */
@property(nonatomic, readonly) BOOL allowGameSkinPush;

/**
 * @brief 是否支持Apple Music、Zoom & Tiktok 提醒
 */
@property(nonatomic, readonly) BOOL allowAppleMusicZoomAndTiktokReminder;

/**
 * @brief 是否支持扫码连接
 */
@property(nonatomic, readonly) BOOL allowQRCodeConnect;

/**
 * @brief 是否支持获取屏幕分辨率信息
 */
@property(nonatomic, readonly) BOOL allowRetrieveScreenResolution;

/**
 * @brief 是否支持收款码推送功能
 */
@property(nonatomic, readonly) BOOL allowMoneyReceiveQRCode;

/**
 * @brief 是否支持名片推送功能
 */
@property(nonatomic, readonly) BOOL allowBusinessCardQRCode;

/**
 * @brief 是否支持获取单个游戏最高三条游戏记录
 */
@property(nonatomic, readonly) BOOL withSingleGameTop3GameRecord;

/**
 * @brief 是否禁用在App上表盘模块化
 */
@property(nonatomic, readonly) BOOL disableWatchfaceModularInApp;

/**
 * @brief 是否支持核酸码推送功能
 */
@property(nonatomic, readonly) BOOL allowNucleicAcidQRCode;

/**
 * @brief 是否支持习惯养成功能
 */
@property(nonatomic, readonly) BOOL allowHabits;


/**
 * @brief 是否支持更多的二维码传输，收款码：Paytm收款码/PhonePe收款码/GPay收款码/BHTM收款码，名片：Email名片/Phone名片/LinkedIn名片
 */
@property(nonatomic, readonly) BOOL showAdditionalQRCodeTransfer;


/**
 * @brief 是否音乐推送
 */
@property(nonatomic, readonly) BOOL allowMusicPush;

/**
 * @brief 是否支付宝Iot（阿里云Iot）
 */
@property(nonatomic, readonly) BOOL allowAliot;


/**
 * @brief 是否支持自定义标签
 */
@property(nonatomic, readonly) BOOL withCustomLabels;


/**
 * @brief 是否指定支持的收款码和名片，仅支持的收款码和名片才应该在App上展示推送入口
 */
@property(nonatomic, readonly) BOOL specifySupportedMoneyReceiveAndBusinessQRCode;


/// 是否支持省电模式
@property(nonatomic, readonly) BOOL withPowerSavingMode;

/// 是否支持app设置省电模式时间段
@property(nonatomic, readonly) BOOL allowPowerSavingModePeriod;

/// 是否支持创维光伏
@property(nonatomic, readonly) BOOL withSkyworthPV;

/// 是否支持定制二维码功能
@property(nonatomic, readonly) BOOL canCustomizeQRCode;

/// 是否支持板球比赛
@property(nonatomic, readonly) BOOL withCricketMatch;

/// 是否支持GPS更新epo功能
@property(nonatomic, readonly) BOOL withGPSEpo;

/// 是否支持体感游戏
@property(nonatomic, readonly) BOOL withMotionSensingGame;

/// 是否支持勋章
@property(nonatomic, readonly) BOOL withMedals;

/// 是否支持获取支持的日程类型
@property(nonatomic, readonly) BOOL canGetSupportedSchedules;

/// 是否支持获取设备最近一周习惯达标情况和最新达标日期
@property(nonatomic, readonly) BOOL canGetLatestHabitAchievement;

/// 是否可以设置公制重量偏好
@property(nonatomic, readonly) BOOL withMetricWeightPreferFixed;

/// 是否支持导航诱导
@property(nonatomic, readonly) BOOL naviGuideSupported;

/// 是否支持小睡功能
@property(nonatomic, readonly) BOOL withSnooze;

/// 是否支持快速眼动
@property(nonatomic, readonly) BOOL withREM;

/// 心率监测时间段是否支持跨天
@property(nonatomic, readonly) BOOL allowHeartRateMonitoringAcrossDays;

/// 是否支持超过10个常用联系人
@property(nonatomic, readonly) BOOL allowHugeCountFavContacts;

/// 是否支持相册推送功能
@property(nonatomic, readonly) BOOL allowPhotoPush;

/// 是否支持电子书推送功能
@property(nonatomic, readonly) BOOL allowEBookPush;

/// 是否支持电子卡包功能，传音Infinix项目
@property(nonatomic, readonly) BOOL withECard;

/// 是否支持查询设备能力
@property(nonatomic, readonly) BOOL allowQueryDeviceCapacities;

/// 运动训练数据是否包含应该展示的数据的配置信息
@property(nonatomic, readonly) BOOL withDisplayConfigInWorkoutData;

/// 是否支持独立定时健康监测设置
@property(nonatomic, readonly) BOOL allowSingleHTMSettings;

/// 是否支持心率过低报警
@property(nonatomic, readonly) BOOL withHRLowAlarm;

/// 是否支持不常用内容数据设置指令
@property(nonatomic, readonly) BOOL withUncommonValueCommand;

/// 是否支持新OTA
@property(nonatomic, readonly) BOOL withNewOTA;

/// 是否支持文心一言
@property(nonatomic, readonly) BOOL withERNIEBot;

/// 是否支持个性化提醒(高级提醒)
@property(nonatomic, readonly) BOOL withPersonalizedReminder;

/// 是否支持查询设备当前语言设置
@property(nonatomic, readonly) BOOL allowQueryDeviceLanguage;

/// 是否支持紧急联系人功能
@property(nonatomic, readonly) BOOL withEmergencyContact;

/// 计步数据item是否支持运动时长
@property(nonatomic, readonly) BOOL shouldStepItemWithDuration;

/// 是否支持静息心率
@property(nonatomic, readonly) BOOL withRestingHR;

@end
