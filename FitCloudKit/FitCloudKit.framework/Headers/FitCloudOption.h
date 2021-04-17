//
//  FitCloudOption.h
//  FitCloudKit
//
//  Created by pcjbird on 2018/5/19.
//  Copyright © 2018年 Zero Status. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <FitCloudKit/FitCloudKitDefines.h>

/**
 * @brief FitCloudKit选项
 */
@interface FitCloudOption : NSObject

/**
 * @brief 是否为调试模式, 调试模式会打印较为详细的日志, 默认为非调试模式
 */
@property(nonatomic, assign) BOOL  debugMode;

/**
 * @brief 扫描超时时间，默认10s
 */
@property(nonatomic, assign) NSTimeInterval secsScanTimeOut;

/**
 * @brief 命令执行超时时间，默认10s
 */
@property(nonatomic, assign) NSTimeInterval secsCommandTimeOut;

/**
 * @brief 蓝牙包传输间隔，默认0.015s=15ms
 */
@property(nonatomic, assign) NSTimeInterval secsPacketUnitInterval;

/**
 * @brief 是否应该自动扫描连接， 默认否
 */
@property(nonatomic, assign) BOOL    shouldAutoConnect;

/**
 * @brief 手表语言偏好，默认：FITCLOUDLANGUAGE_NOTSET
 */
@property(nonatomic, assign) FITCLOUDLANGUAGE watchPreferLang;

/**
 * @brief 是否优先使用系统的本地化语言设置，这将影响同步给手表的语言设置， 默认否
 * @note: 当您手动修改了APP的语言设置时，由于系统限制，无法优先系统的本地化语言设置。
*/
@property(nonatomic, assign) BOOL    preferSystemLocale;

/**
 * @brief 默认选项
 */
+ (instancetype)defaultOption;

@end
