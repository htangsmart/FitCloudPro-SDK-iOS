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

/**
 * @brief 手环所有配置信息（用于手环绑定时一次性获取）
 */
@interface FitCloudAllConfigObject : NSObject<NSCoding>

/**
 * @brief 手环软硬件版本信息
 */
@property(nonatomic, strong)FitCloudFirmwareVersionObject* firmware;

/**
 * @brief 消息通知设置
 */
@property(nonatomic, assign)FITCLOUDMN mnSetting;

/**
 * @brief 手环表盘所有功能项显示状态设置
 */
@property(nonatomic, assign)FITCLOUDSCREENDISPLAY sdSetting;

/**
 * @brief 手环偏好
 */
@property(nonatomic, assign)FITCLOUDPREFER prefer;

/**
 * @brief 健康定时监测设置
 */
@property(nonatomic, strong)FitCloudHTMObject* htmSetting;

/**
 * @brief 健康定时监测独立设置
 */
@property(nonatomic, strong)NSArray<FitCloudHTMSingleObject*>* htmSingleSettings;

/**
 * @brief 久坐提醒设置
 */
@property(nonatomic, strong)FitCloudLSRObject* lsrSetting;

/**
 * @brief 喝水提醒设置
 */
@property(nonatomic, strong)FitCloudDRObject* drSetting;

/**
 * @brief 血压参考范围及私人模式开关设置
 */
@property(nonatomic, strong)FitCloudBPRObject* bprSetting;

/**
 * @brief 抬腕唤醒设置
 */
@property(nonatomic, strong)FitCloudWWUObject* wwuSetting;
    
/**
 * @brief 心率预警设置
 */
@property(nonatomic, strong)FitCloudHRAlarmObject* hrAlarmSetting;

/**
 * @brief 血压预警设置
 */
@property(nonatomic, strong)FitCloudBPAlarmObject* bpAlarmSetting;
    
/**
 * @brief 勿扰模式设置
 */
@property(nonatomic, strong)FitCloudDNDSetting* dndSetting;

/**
 * @brief 女性设置
 */
@property(nonatomic, strong)FitCloudWomenHealthSetting* womenHealthSetting;


/**
 * @brief 防护提醒设置
 */
@property(nonatomic, strong)FitCloudPRObject* prSetting;

/**
 * @brief 洗手提醒设置
 */
@property(nonatomic, strong)FitCloudHandWashRemindObject* hwrSetting;

/**
 * @brief 屏幕设置
 */
@property(nonatomic, strong)FitCloudScreenSetting* screenSetting;

/**
 * @brief 振动设置
 */
@property(nonatomic, strong) FitCloudVibrateSetting* vibrateSetting;

/// 省电模式设置
@property(nonatomic, strong) FitCloudPowerSavingSetting* powerSavingSetting;

/// 设备能力信息，仅当支持查询设备能力的手表有效
@property(nonatomic, strong) NSArray<FitCloudCapacity*>* deviceCapacities;

@end
