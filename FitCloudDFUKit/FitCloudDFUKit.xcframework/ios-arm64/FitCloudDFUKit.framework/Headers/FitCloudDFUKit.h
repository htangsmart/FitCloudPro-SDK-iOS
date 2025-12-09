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
//  构建版本：
//      pcjbird    2025-12-09  Version:1.3.4-beta.3 Build:20251209001

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import <CoreBluetooth/CoreBluetooth.h>
#import <FitCloudDFUKit/FitCloudDFUErrorCode.h>
#import <FitCloudDFUKit/FitCloudDFULogLevel.h>

NS_ASSUME_NONNULL_BEGIN

/// 芯片供应商类型
typedef NS_ENUM(NSInteger, FITCLOUDDFUCHIPVENDOR) {
    FITCLOUDDFUCHIPVENDOR_UNKNOWN = 0, // 未知
    FITCLOUDDFUCHIPVENDOR_REALTEK = 1, // Realtek
    FITCLOUDDFUCHIPVENDOR_NORDIC = 2,  // Nordic
};

/// FitCloud 固件升级代理协议
@protocol FitCloudDFUDelegate <NSObject>
@optional
/// 成功启动 DFU 时的回调
- (void)OnStartDFUSuccess;

/// 启动 DFU 失败时的回调
/// - Parameters:
///   - error: 错误信息
- (void)OnStartDFUFailureWithError:(NSError *)error;

/// 升级进度变化时的回调
/// - Parameters:
///   - progress: 升级进度百分比 (0~100)
///   - index: 当前镜像索引，下标从 0 开始
///   - total: 所有镜像数量
- (void)OnDFUProgress:(CGFloat)progress imageIndex:(NSInteger)index total:(NSInteger)total;

/// 意外终止时的回调
/// - Parameters:
///   - error: 错误信息
- (void)OnAbortWithError:(NSError *)error;

/// 升级完成时的回调
/// - Parameters:
///   - speed: 速度，单位：kB/s
- (void)OnDFUFinishWithSpeed:(CGFloat)speed;

/// 日志信息回调
/// - Parameters:
///   - message: 日志信息
///   - level: 日志等级
- (void)OnDFULogMessage:(NSString *)message level:(FCDFUKLogLevel)level NS_SWIFT_NAME(onDFULogMessage(_:level:));

@end

/// FitCloud 固件升级类
@interface FitCloudDFUKit : NSObject

#pragma mark 版本信息

/// 获取 SDK 版本号
+ (NSString *)sdkVersion;

/// 获取 SDK Build 版本号
+ (NSString *)sdkBuild;

#pragma mark 公共方法

/// 设置是否为调试模式
/// - Parameters:
///   - debugMode: 是否开启调试模式，默认为 NO
+ (void)setDebugMode:(BOOL)debugMode;

/// 设置代理对象
/// - Parameters:
///   - delegate: 代理对象
+ (void)setDelegate:(id<FitCloudDFUDelegate>)delegate;

/// 开始固件升级
/// - Parameters:
///   - peripheral: 固件升级的蓝牙外设
///   - firmware: 新版本固件文件路径，注意是 file path, 不是 file url
///   - chipVendor: 芯片供应商
///   - silentMode: 是否为静默模式，普通固件升级使用非静默模式，UI 升级/表盘升级使用静默模式
+ (void)startWithPeripheral:(CBPeripheral *)peripheral firmware:(NSString *)firmware chipVendor:(FITCLOUDDFUCHIPVENDOR)chipVendor silentMode:(BOOL)silentMode;

/// 开始固件升级
/// - Parameters:
///   - peripheral: 固件升级的蓝牙外设
///   - firmware: 新版本固件文件路径，注意是 file path, 不是 file url
///   - chipVendor: 芯片供应商
///   - silentMode: 是否为静默模式，普通固件升级使用非静默模式，UI 升级/表盘升级使用静默模式
///   - reportSuccessBeforeDisconnect: 是否在断开连接前回调升级成功
+ (void)startWithPeripheral:(CBPeripheral *)peripheral firmware:(NSString *)firmware chipVendor:(FITCLOUDDFUCHIPVENDOR)chipVendor silentMode:(BOOL)silentMode reportSuccessBeforeDisconnect:(BOOL)reportSuccessBeforeDisconnect;

/// 终止固件升级
+ (void)abortIfNeeded;

@end

NS_ASSUME_NONNULL_END
