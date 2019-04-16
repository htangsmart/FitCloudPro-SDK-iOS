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
@property(nonatomic, strong) NSString* projectNo;

/**
 * @brief 手环底层patch版本号
 */
@property(nonatomic, strong) NSString* patchVersion;

/**
 * @brief flash文件版本号
 */
@property(nonatomic, strong) NSString* flashVersion;

/**
 * @brief 手环固件版本号
 */
@property(nonatomic, strong) NSString* firmwareVersion;

/**
 * @brief 固件版本时间序号
 */
@property(nonatomic, strong) NSString* sequenceNo;

/**
 * @brief 手环表盘支持的页面
 */
@property(nonatomic, assign)FITCLOUDSCREENDISPLAY screenDisplaySupported;

/**
 * @brief 手环硬件支持的功能，手机APP根据该项判断在手机APP上是否显示或使用该功能
 */
@property(nonatomic, assign) FITCLOUDHARDWARE hardwareSupported;

/**
 * @brief 是否禁止自定义屏幕显示
 */
@property(nonatomic, assign) BOOL disableCustomScreenDisplay;

/**
 * @brief 是否显示邮件提醒开关选项
 */
@property(nonatomic, assign) BOOL allowShowMailReminder;

/**
 * @brief 是否显示Telegram&Viber提醒开关选项
 */
@property(nonatomic, assign) BOOL allowShowTelegramAndViberReminder;

@end
