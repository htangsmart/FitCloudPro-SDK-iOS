//
//  FitCloudAllConfigObject.h
//  FitCloudKit
//
//  Created by pcjbird on 2018/5/27.
//  Copyright © 2018 年 Zero Status. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <FitCloudKit/FitCloudFirmwareVersionObject.h>
#import <FitCloudKit/FitCloudKitDefines.h>
#import <FitCloudKit/FitCloudHTMObject.h>
#import <FitCloudKit/FitCloudHTMSingleObject.h>
#import <FitCloudKit/FitCloudLSRObject.h>
#import <FitCloudKit/FitCloudDRObject.h>
#import <FitCloudKit/FitCloudBPRObject.h>
#import <FitCloudKit/FitCloudWWUObject.h>
#import <FitCloudKit/FitCloudHRAlarmObject.h>
#import <FitCloudKit/FitCloudBPAlarmObject.h>
#import <FitCloudKit/FitCloudDNDSetting.h>
#import <FitCloudKit/FitCloudWomenHealthSetting.h>
#import <FitCloudKit/FitCloudPRObject.h>
#import <FitCloudKit/FitCloudHandWashRemindObject.h>
#import <FitCloudKit/FitCloudScreenSetting.h>
#import <FitCloudKit/FitCloudVibrateSetting.h>
#import <FitCloudKit/FitCloudPowerSavingSetting.h>
#import <FitCloudKit/FitCloudCapacity.h>
#import <FitCloudKit/FitCloudWatchfaceCapabilities.h>
#import <FitCloudKit/FitCloudAudioRecordingCapabilities.h>
#import <FitCloudKit/FitCloudSecureCoding.h>
#import <FitCloudKit/FitCloudNotificationApps.h>

NS_ASSUME_NONNULL_BEGIN

/// 手表所有配置信息（用于手表绑定时一次性获取）
@interface FitCloudAllConfigObject : NSObject <FitCloudSecureCoding>

/// 手表软硬件版本信息
@property(nonatomic, strong, nullable) FitCloudFirmwareVersionObject *firmware;

/// 启用的消息通知应用
@property(nonatomic, strong, readonly) NSSet<FitCloudNotificationApp> *enabledNotificationApps;

/// 手表表盘所有功能项显示状态设置
@property(nonatomic, assign) FITCLOUDSCREENDISPLAY sdSetting;

/// 手表偏好
@property(nonatomic, assign) FITCLOUDPREFER prefer;

/// 健康定时监测设置
@property(nonatomic, strong, nullable) FitCloudHTMObject *htmSetting;

/// 健康定时监测独立设置
@property(nonatomic, strong, nullable) NSArray<FitCloudHTMSingleObject *> *htmSingleSettings;

/// 久坐提醒设置
@property(nonatomic, strong, nullable) FitCloudLSRObject *lsrSetting;

/// 喝水提醒设置
@property(nonatomic, strong, nullable) FitCloudDRObject *drSetting;

/// 血压参考范围及私人模式开关设置
@property(nonatomic, strong, nullable) FitCloudBPRObject *bprSetting;

/// 抬腕唤醒设置
@property(nonatomic, strong, nullable) FitCloudWWUObject *wwuSetting;

/// 心率预警设置
@property(nonatomic, strong, nullable) FitCloudHRAlarmObject *hrAlarmSetting;

/// 血压预警设置
@property(nonatomic, strong, nullable) FitCloudBPAlarmObject *bpAlarmSetting;

/// 勿扰模式设置
@property(nonatomic, strong, nullable) FitCloudDNDSetting *dndSetting;

/// 女性设置
@property(nonatomic, strong, nullable) FitCloudWomenHealthSetting *womenHealthSetting;

/// 防护提醒设置
@property(nonatomic, strong, nullable) FitCloudPRObject *prSetting;

/// 洗手提醒设置
@property(nonatomic, strong, nullable) FitCloudHandWashRemindObject *hwrSetting;

/// 屏幕设置
@property(nonatomic, strong, nullable) FitCloudScreenSetting *screenSetting;

/// 振动设置
@property(nonatomic, strong, nullable) FitCloudVibrateSetting *vibrateSetting;

/// 省电模式设置
@property(nonatomic, strong, nullable) FitCloudPowerSavingSetting *powerSavingSetting;

/// 设备能力信息，仅当支持查询设备能力的手表有效
@property(nonatomic, strong, nullable) NSArray<FitCloudCapacity *> *deviceCapacities;

/// 每分钟运动动态心率的数量
@property(nonatomic, strong, nullable) NSNumber *exerciseBPMDataPerMinute;

/// 天气映射客户编号
@property(nonatomic, strong, nullable) NSNumber *weatherMapVendorId;

/// 锁屏密码长度
@property(nonatomic, strong, nullable) NSNumber *lockScreenPasswordLength;

/// 设备支持的 AI 解决方案供应商位掩码，可同时包含多个供应商。
/// 未上报能力项 0x26 时，功能位 77 开启则默认支持火山，否则返回 None。
/// 明确上报 0 表示无支持的供应商，不触发默认回退。
/// 使用 `supportedAISolutionVendors & FitCloudAISolutionVendorStarBurst` 判断是否支持火山。
@property(nonatomic, readonly) FitCloudAISolutionVendor supportedAISolutionVendors;

/// Supported exercise/resting heart rate alerts.
/// Capability 0x2A takes precedence, including an explicit zero (no supported alerts).
/// If absent, falls back to firmware.allowHRAlarm and firmware.withHRLowAlarm.
@property(nonatomic, readonly) FitCloudHeartRateAlertCapabilities supportedHeartRateAlerts;

/// 表盘扩展能力。
@property(nonatomic, strong, readonly, nullable) FitCloudWatchfaceCapabilities *watchfaceCapabilities;

/// 表盘旋转角度。
@property(nonatomic, readonly) FitCloudWatchfaceRotation watchfaceRotation;

/// 录音扩展能力与要求。
@property(nonatomic, strong, readonly, nullable) FitCloudAudioRecordingCapabilities *audioRecordingCapabilities;

@end

NS_ASSUME_NONNULL_END
