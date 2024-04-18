//
//  FitCloudDFUKit.h
//  FitCloudDFUKit
//
//  Created by pcjbird on 2019/4/4.
//  Copyright © 2019 Zero Status. All rights reserved.
//
//  框架名称:FitCloudDFUKit.framework
//  框架功能:iOS framework for FitCloud Smart Bracelet Device Firmware Upgrade, which is responsible for the upgrade of bracelet firmware. FitCloud智能手环固件升级的iOS框架，负责手环固件升级等功能的封装。
//  修改记录:
//     pcjbird    2024-04-18  Version:1.3.1-beta.19 Build:202404180001
//                            1.Realtek音乐推送支持
//                            2.Realtek电子书/相册推送支持
//                            3.重命名日志回调函数
//                            4.新增终止固件升级功能
//                            5.更新Realtek固件升级SDK，支持8773型号芯片
//                            6.更新Realtek固件升级SDK，解决蓝牙关闭不及时回调错误的问题
//
//     pcjbird    2022-12-30  Version:1.3.0 Build:202212300001
//                            1.更新错误码翻译
//                            2.升级Realtek固件升级程序调用方式
//                            3.新增越南语
//
//     pcjbird    2022-06-30  Version:1.2.9 Build:202206300001
//                            1.升级Realtek固件升级程序，修复固件升级依旧慢的问题
//
//     pcjbird    2022-06-06  Version:1.2.8 Build:202206060001
//                            1.升级Realtek固件升级程序，修复固件升级慢的问题
//
//     pcjbird    2022-06-01  Version:1.2.7 Build:202206010001
//                            1.修正OnStartDFUSuccess没有回调的问题
//
//     pcjbird    2022-01-26  Version:1.2.6 Build:202201260001
//                            1.升级Realtek固件升级程序，修复固件升级有可能报错的问题
//                            2.升级Realtek固件升级程序，支持8763E平台
//                            3.新增印地语
//
//     pcjbird    2021-12-18  Version:1.2.5 Build:202112180001
//                            1.升级Realtek固件升级程序，修复固件升级慢的问题
//
//     pcjbird    2021-08-23  Version:1.2.4 Build:202108230001
//                            1.修正表盘推送可能失败的问题
//
//     pcjbird    2021-08-04  Version:1.2.3 Build:202108040001
//                            1.修正iOS11.4系统固件升级失败的问题
//
//     pcjbird    2021-06-04  Version:1.2.2 Build:202106040001
//                            1.Nordic固件升级支持
//
//     pcjbird    2021-02-25  Version:1.2.1 Build:202102250001
//                            1.升级Realtek固件升级程序，支持8762D平台
//
//     pcjbird    2020-09-28  Version:1.2.0 Build:202009280001
//                            1.新增土耳其语/乌克兰语
//
//     pcjbird    2020-08-14  Version:1.1.9 Build:202008140001
//                            1.新增克罗地亚语/阿尔巴尼亚语
//
//     pcjbird    2020-07-10  Version:1.1.8 Build:202007100001
//                            1.修正繁体中文翻译
//
//     pcjbird    2019-11-22  Version:1.0.7 Build:201911220001
//                            1.新增斯洛伐克语
//
//     pcjbird    2019-11-21  Version:1.0.6 Build:201911210001
//                            1.支持非连接状态的外设固件升级
//                            2.提升升级过程可靠性
//
//     pcjbird    2019-10-18  Version:1.0.5 Build:201910180001
//                            1.修正UI文件升级过程有可能无法进入静默模式的问题
//
//     pcjbird    2019-10-16  Version:1.0.4 Build:201910160001
//                            1.修正iOS13闪退的问题
//
//     pcjbird    2019-09-30  Version:1.0.3 Build:201909300001
//                            1.支持UI文件升级
//
//     pcjbird    2019-04-04  Version:1.0.0 Build:201904040001
//                            1.首次发布SDK版本
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import <CoreBluetooth/CoreBluetooth.h>
#import <FitCloudDFUKit/FitCloudDFUErrorCode.h>
#import <FitCloudDFUKit/FitCloudDFULogLevel.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * @brief 芯片供应商
 */
typedef NS_ENUM(NSInteger, FITCLOUDDFUCHIPVENDOR)
{
    FITCLOUDDFUCHIPVENDOR_UNKNOWN = 0,                //未知
    FITCLOUDDFUCHIPVENDOR_REALTEK = 1,                //Realtek
    FITCLOUDDFUCHIPVENDOR_NORDIC = 2,                 //Nordic
};

/**
 * @brief FitCloud 固件升级代理
 */
@protocol FitCloudDFUDelegate <NSObject>
@optional
/**
 * @brief 成功启动DFU回调
 */
-(void) OnStartDFUSuccess;

/**
 * @brief 启动DFU失败
 * @param error 错误信息
 */
-(void) OnStartDFUFailureWithError:(NSError*)error;

/**
 * @brief 升级进度回调
 * @param progress 升级进度百分比(0~100)
 * @param index 当前镜像索引，下标从0开始
 * @param total 所有镜像数量
 */
-(void) OnDFUProgress:(CGFloat)progress imageIndex:(NSInteger)index total:(NSInteger)total;

/**
 * @brief 意外终止回调
 * @param error 错误信息
 */
-(void) OnAbortWithError:(NSError*)error;

/**
 * @brief 升级完成回调
 * @param speed 速度, 单位：kB/s
 */
-(void) OnDFUFinishWithSpeed:(CGFloat)speed;

/**
 *@brief 日志信息回调
 *@param message 日志信息
 *@param level 日志等级
 */
-(void) OnDFULogMessage:(NSString*)message level:(FCDFUKLogLevel)level NS_SWIFT_NAME(onDFULogMessage(_:level:));

@end

/**
 * @brief FitCloud 固件升级
 */
@interface FitCloudDFUKit : NSObject

#pragma mark 版本信息

/**
 * @brief SDK版本号
 */
+(NSString*) sdkVersion;

/**
 * @brief SDK Build 版本号
 */
+(NSString*) sdkBuild;

#pragma mark 公共方法

/**
 * @brief 设置是否为调试模式,默认为NO
 */
+(void) setDebugMode:(BOOL)debugMode;

/**
 * @brief 设置代理
 * @param delegate 代理
 */
+(void) setDelegate:(id<FitCloudDFUDelegate>)delegate;

/**
 * @brief 开始固件升级
 * @param peripheral 固件升级的蓝牙外设
 * @param firmware 新版本固件文件路径,注意是 file path, 不是 file url
 * @param chipVendor 芯片供应商
 * @param silentMode 是否为静默模式，普通固件升级使用非静默模式，UI升级/表盘升级使用静默模式
 */
+(void) startWithPeripheral:(CBPeripheral *) peripheral firmware:(NSString*)firmware chipVendor:(FITCLOUDDFUCHIPVENDOR)chipVendor silentMode:(BOOL)silentMode;

/// 终止固件升级
+(void) abortIfNeeded;

@end

NS_ASSUME_NONNULL_END
