//
//  FitCloudOption.h
//  FitCloudKit
//
//  Created by pcjbird on 2018/5/19.
//  Copyright © 2018年 Zero Status. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <FitCloudKit/FitCloudKitDefines.h>

/// FitCloudKit选项
@interface FitCloudOption : NSObject

/// 是否为调试模式, 调试模式会打印较为详细的日志, 默认为非调试模式
@property(nonatomic, assign) BOOL  debugMode;

/// 扫描超时时间，默认10s
@property(nonatomic, assign) NSTimeInterval secsScanTimeOut;

/// 命令执行超时时间，默认10s
@property(nonatomic, assign) NSTimeInterval secsCommandTimeOut;


/// 蓝牙包传输间隔，单位：毫秒，默认20ms
/// >Important: 最小不得小于15ms
@property(nonatomic, assign) NSInteger milliSecsPacketUnitInterval;


/// 是否应该自动扫描连接， 默认否
@property(nonatomic, assign) BOOL    shouldAutoConnect;

/// 手表语言偏好，默认：FITCLOUDLANGUAGE_NOTSET
@property(nonatomic, assign) FITCLOUDLANGUAGE watchPreferLang;

/// 是否优先使用系统的本地化语言设置，这将影响同步给手表的语言设置， 默认否
/// >Important: 当您手动修改了APP的语言设置时，由于系统限制，无法优先系统的本地化语言设置。
@property(nonatomic, assign) BOOL    preferSystemLocale;

/// 是否自动同步系统时间，默认为YES
@property(nonatomic, assign) BOOL autoSyncSystemTime;

/// 是否自动同步系统语言，默认YES
@property(nonatomic, assign) BOOL autoSyncSystemLang;

/// 是否优先使用WriteWithoutResponse，默认为NO
@property(nonatomic, assign) BOOL preferWriteWithoutResponse;

/// 首选文档保存路径，相对于NSDocumentDirectory的路径，默认为 ""
/// >Important: 必须是相对于NSDocumentDirectory的路径，不支持保存到其他的目录
@property(nonatomic, copy) NSString* preferredDocSavingRelativePath;

/// 默认选项
+ (instancetype)defaultOption;

@end
