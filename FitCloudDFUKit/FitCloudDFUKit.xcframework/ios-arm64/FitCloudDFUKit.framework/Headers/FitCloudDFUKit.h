//
//  FitCloudDFUKit.h
//  FitCloudDFUKit
//
//  Created by pcjbird on 2019/4/4.
//  Copyright © 2019 Zero Status. All rights reserved.
//
//  框架名称:FitCloudDFUKit.xcframework
//  框架功能:The iOS framework for the FitCloudPro smartwatch, which is responsible for encapsulating features such as watch firmware DFU, UI DFU, watchface DFU, watch sports DFU, music Push, and more.
//          FitCloudPro 智能手表的 iOS 框架，负责手表固件升级/UI 升级/表盘升级/运动推送/音乐推送等功能的封装。
//
//  构建版本:
//      pcjbird    2024-09-30  Version:1.3.1 Build:20240930001


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

/**
 * @brief 开始固件升级
 * @param peripheral 固件升级的蓝牙外设
 * @param firmware 新版本固件文件路径,注意是 file path, 不是 file url
 * @param chipVendor 芯片供应商
 * @param silentMode 是否为静默模式，普通固件升级使用非静默模式，UI升级/表盘升级使用静默模式
 * @param reportSuccessBeforeDisconnect 是否在断开连接前回调升级成功
 */
+(void) startWithPeripheral:(CBPeripheral *) peripheral firmware:(NSString*)firmware chipVendor:(FITCLOUDDFUCHIPVENDOR)chipVendor silentMode:(BOOL)silentMode reportSuccessBeforeDisconnect:(BOOL)reportSuccessBeforeDisconnect;

/// 终止固件升级
+(void) abortIfNeeded;

@end

NS_ASSUME_NONNULL_END
