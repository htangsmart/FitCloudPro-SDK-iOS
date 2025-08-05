//
//  FitCloudFirmwareVersionObject.h
//  FitCloudKit
//
//  Created by pcjbird on 2018/5/25.
//  Copyright © 2018 年 Zero Status. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "FitCloudKitDefines.h"
#import <FitCloudKit/FitCloudSecureCoding.h>

/// 手表软硬件版本信息
@interface FitCloudFirmwareVersionObject : NSObject <FitCloudSecureCoding>

/// 项目的编号
@property(nonatomic, strong, readonly) NSString *projectNo;

/// 手表底层 patch 版本号
@property(nonatomic, strong, readonly) NSString *patchVersion;

/// flash 文件版本号
@property(nonatomic, strong, readonly) NSString *flashVersion;

/// 手表固件版本号
@property(nonatomic, strong, readonly) NSString *firmwareVersion;

/// 固件版本时间序号
@property(nonatomic, strong, readonly) NSString *sequenceNo;

/// 手表表盘支持的页面
@property(nonatomic, readonly) FITCLOUDSCREENDISPLAY screenDisplaySupported;

/// 手表硬件支持的功能，手机 APP 根据该项判断在手机 APP 上是否显示或使用该功能
@property(nonatomic, readonly) FITCLOUDHARDWARE hardwareSupported;

/// 是否禁止自定义屏幕显示
@property(nonatomic, readonly) BOOL disableCustomScreenDisplay;

/// 是否显示邮件提醒开关选项
@property(nonatomic, readonly) BOOL allowShowMailReminder;

/// 是否显示 Telegram&Viber 提醒开关选项
@property(nonatomic, readonly) BOOL allowShowTelegramAndViberReminder;

/// 距离卡路里是否使用新算法
@property(nonatomic, readonly) BOOL newAlgorithmWithDistanceCalories;

/// 是否显示心率预警选项
@property(nonatomic, readonly) BOOL allowHRAlarm;

/// 是否显示血压预警选项
@property(nonatomic, readonly) BOOL allowBPAlarm;

/// 是否显示新增的消息提醒 (Twitter/LinkedIn/Messenger/Instagram/Snapchat/Skype)
/// - Note: 补丁：当该标志位为 true 时，allowShowMailReminder/allowShowTelegramAndViberReminder 强制为 true
@property(nonatomic, readonly) BOOL allowShowAdditionalReminder;

/// 是否支持表盘升级
@property(nonatomic, readonly) BOOL allowWatchFaceUpgrade;

/// 是否支持勿扰模式 (Do Not Disturb Mode)
@property(nonatomic, readonly) BOOL allowDNDMode;

/// 是否支持获取最新的测量数据 (Latest Measurement Data)
@property(nonatomic, readonly) BOOL allowRetrieveLatestMeasurementData;

/// 是否支持 TP 升级功能
@property(nonatomic, readonly) BOOL allowTP;

/// 是否使用新的睡眠数据格式
@property(nonatomic, readonly) BOOL newSleepDataFormat;

/// 是否为假心电
@property(nonatomic, readonly) BOOL isFakeECG;

/// 是否支持常用联系人
@property(nonatomic, readonly) BOOL allowFavContacts;

/// 是否支持防护提醒
@property(nonatomic, readonly) BOOL allowProtectionReminder;

/// 是否支持设置健康监测间隔时间，指手表定时自动监测健康数据，并非单次实时监测
@property(nonatomic, readonly) BOOL allowSetHealthMonitorInterval;

/// 是否支持设置久坐提醒间隔时间
@property(nonatomic, readonly) BOOL allowSetLSRInterval;

/// 是否支持天气预报 (该手表支持实时天气 + 未来几天的天气预报)
@property(nonatomic, readonly) BOOL allowWeatherForecast;

/// 是否支持洗手提醒
@property(nonatomic, readonly) BOOL allowHandWashReminder;

/// 是否支持将天气推送开关的状态状态同步给手表，当该标志位为 true 时，app 可以将当前天气推送开关的状态同步给手表
@property(nonatomic, readonly) BOOL allowWeatherPushSwitchStatusSync;

/// 是否支持锁屏密码
@property(nonatomic, readonly) BOOL allowLockScreenPassword;

/// 是否需要定制查找 iPhone 的响铃
@property(nonatomic, readonly) BOOL shouldCustomFindiPhoneRing;

/// 是否支持日程提醒
@property(nonatomic, readonly) BOOL allowScheduleReminder;

/// 是否支持 Hike&Youtube 提醒
@property(nonatomic, readonly) BOOL allowHikeAndYoutubeReminder;

/// 是否支持多表盘推送
@property(nonatomic, readonly) BOOL allowMultiWatchfacePush;

/// 是否支持表盘模块化
@property(nonatomic, readonly) BOOL allowWatchfaceModular;

/// 是否为新的 GUI 结构
@property(nonatomic, readonly) BOOL isNewGUIArchitecture;

/// 是否支持游戏皮肤推送
@property(nonatomic, readonly) BOOL allowGameSkinPush;

/// 是否支持 Apple Music、Zoom & Tiktok 提醒
@property(nonatomic, readonly) BOOL allowAppleMusicZoomAndTiktokReminder;

/// 是否支持扫码连接
@property(nonatomic, readonly) BOOL allowQRCodeConnect;

/// 是否支持获取屏幕分辨率信息
@property(nonatomic, readonly) BOOL allowRetrieveScreenResolution;

/// 是否支持收款码推送功能
@property(nonatomic, readonly) BOOL allowMoneyReceiveQRCode;

/// 是否支持名片推送功能
@property(nonatomic, readonly) BOOL allowBusinessCardQRCode;

/// 是否支持获取单个游戏最高三条游戏记录
@property(nonatomic, readonly) BOOL withSingleGameTop3GameRecord;

/// 是否禁用在 App 上表盘模块化
@property(nonatomic, readonly) BOOL disableWatchfaceModularInApp;

/// 是否支持核酸码推送功能
@property(nonatomic, readonly) BOOL allowNucleicAcidQRCode;

/// 是否支持习惯养成功能
@property(nonatomic, readonly) BOOL allowHabits;

/// 是否支持更多的二维码传输，收款码：Paytm 收款码/PhonePe 收款码/GPay 收款码/BHTM 收款码，名片：Email 名片/Phone 名片/LinkedIn 名片
@property(nonatomic, readonly) BOOL showAdditionalQRCodeTransfer;

/// 是否音乐推送
@property(nonatomic, readonly) BOOL allowMusicPush;

/// 是否支付宝 Iot（阿里云 Iot）
@property(nonatomic, readonly) BOOL allowAliot;

/// 是否支持自定义标签
@property(nonatomic, readonly) BOOL withCustomLabels;

/// 是否指定支持的收款码和名片，仅支持的收款码和名片才应该在 App 上展示推送入口
@property(nonatomic, readonly) BOOL specifySupportedMoneyReceiveAndBusinessQRCode;

/// 是否支持省电模式
@property(nonatomic, readonly) BOOL withPowerSavingMode;

/// 是否支持 app 设置省电模式时间段
@property(nonatomic, readonly) BOOL allowPowerSavingModePeriod;

/// 是否支持创维光伏
@property(nonatomic, readonly) BOOL withSkyworthPV;

/// 是否支持定制二维码功能
@property(nonatomic, readonly) BOOL canCustomizeQRCode;

/// 是否支持板球比赛
@property(nonatomic, readonly) BOOL withCricketMatch;

/// 是否支持 GPS 更新 epo 功能
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

/// 是否支持超过 10 个常用联系人
@property(nonatomic, readonly) BOOL allowHugeCountFavContacts;

/// 是否支持相册推送功能
@property(nonatomic, readonly) BOOL allowPhotoPush;

/// 是否支持电子书推送功能
@property(nonatomic, readonly) BOOL allowEBookPush;

/// 是否支持电子卡包功能，传音 Infinix 项目
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

/// 是否支持新 OTA
@property(nonatomic, readonly) BOOL withNewOTA;

/// 是否支持大模型
@property(nonatomic, readonly) BOOL withLLM;

/// 是否支持个性化提醒 (高级提醒)
@property(nonatomic, readonly) BOOL withPersonalizedReminder;

/// 是否支持查询设备当前语言设置
@property(nonatomic, readonly) BOOL allowQueryDeviceLanguage;

/// 是否支持紧急联系人功能
@property(nonatomic, readonly) BOOL withEmergencyContact;

/// 计步数据 item 是否支持运动时长
@property(nonatomic, readonly) BOOL shouldStepItemWithDuration;

/// 是否支持静息心率
@property(nonatomic, readonly) BOOL withRestingHR;

/// 是否支持情侣功能
@property(nonatomic, readonly) BOOL withLoversFeature;

/// 是否可以直接 DFU，而不进入 DFU 模式
@property(nonatomic, readonly) BOOL canDirectDFUWithoutEnterDFUMode;

/// 是否支持芯与物 GPS
///
/// 芯与物是一家芯片设计公司，https://www.icoe-tech.com/
@property(nonatomic, readonly) BOOL withICOEGPS;

/// 是否支持设置 24 小时天气信息
@property(nonatomic, readonly) BOOL with24HrWeather;

/// 是否将运动 ITEM 间隔值解析成运动 ITEM 的数据长度
@property(nonatomic, readonly) BOOL useWorkoutRecordIntervalAsItemDataLength;

/// 大模型类型
@property(nonatomic, readonly) LLMTYPE llmType;

/// 是否应该隐藏心率加强测量
@property(nonatomic, readonly) BOOL shouldHideEnhancedHeartRateMeasurement;

/// 是否支持穆斯林朝拜功能
@property(nonatomic, readonly) BOOL withMuslimPrayer;

/// 是否支持删除表盘功能
@property(nonatomic, readonly) BOOL allowDeleteWatchface;

/// 是否支持查询其他固件模块版本信息 (如 GPS 固件版本、4G Modem 固件版本等)
@property(nonatomic, readonly) BOOL allowQueryOtherModuleFirmwareVersion;

/// 是否支持地图导航快照功能
@property(nonatomic, readonly) BOOL withMapNaviSnapshot;

/// 是否支持拍照预览功能
@property(nonatomic, readonly) BOOL withCameraPreview;

/// 是否支持显示气压
@property(nonatomic, readonly) BOOL withBarometricPressure;

/// 是否支持查询传音 (Infinix) 手表设备信息
///
/// 包含以下信息：
/// - 序列号 (EUID, Equipment Unique Identifier)
/// - 设备型号
/// - 是否支持 4G 网络
@property(nonatomic, readonly) BOOL allowQueryTranssionInfinixDeviceInfo;

/// 是否使用手表计算的运动总结数据
///
/// 当该属性为 `true` 时，App 应该使用手表计算的运动总结数据，而不是自行计算
@property(nonatomic, readonly) BOOL shouldUseWorkoutSummaryDataCalculatedOnWatch;

/// 是否支持切换耳机仓鼠标起始点预设
@property(nonatomic, readonly) BOOL allowSwitchMouseStartPointPresetForEarphoneCase;

/// 是否支持统计手表 APP 使用次数
@property(nonatomic, readonly) BOOL allowCountWatchAppUsage;

/// 是否支持统计手表 APP 使用时长
@property(nonatomic, readonly) BOOL allowCountWatchAppDuration;

/// 是否支持 AI 问答模型选择
@property(nonatomic, readonly) BOOL allowSelectAIModel;

/// 是否支持传音 Oraimo 穆斯林朝拜功能
@property(nonatomic, readonly) BOOL withOraimoMuslimPrayer;

/// 是否支持家长模式
@property(nonatomic, readonly) BOOL withParentalControl;

/// 是否支持统计手表游戏游玩次数
@property(nonatomic, readonly) BOOL allowCountWatchGamePlay;

/// 是否支持查询手表支持的语言
@property(nonatomic, readonly) BOOL allowQueryWatchSupportedLanguages;

/// 是否支持世界时钟
@property(nonatomic, readonly) BOOL withWorldClock;

/// 是否支持情绪功能
@property(nonatomic, readonly) BOOL withEmotion;

/// 是否支持节日祝福
@property(nonatomic, readonly) BOOL withFestivalWish;

/// 是否支持上课模式
@property(nonatomic, readonly) BOOL withClassroomMode;

@end
