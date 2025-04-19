//
//  FitCloudAllConfigObject.h
//  FitCloudKit
//
//  Created by pcjbird on 2018/5/27.
//  Copyright © 2018年 Zero Status. All rights reserved.
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
#import <FitCloudKit/FitCloudSecureCoding.h>

NS_ASSUME_NONNULL_BEGIN

/// 手表所有配置信息（用于手表绑定时一次性获取）
@interface FitCloudAllConfigObject : NSObject <FitCloudSecureCoding>

/// 手表软硬件版本信息
@property(nonatomic, strong, nullable) FitCloudFirmwareVersionObject *firmware;

/// 消息通知设置
@property(nonatomic, assign) FITCLOUDMN mnSetting;

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

@end

NS_ASSUME_NONNULL_END
