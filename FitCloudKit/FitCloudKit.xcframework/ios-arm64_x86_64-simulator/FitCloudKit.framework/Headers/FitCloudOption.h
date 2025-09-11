//
//  FitCloudOption.h
//  FitCloudKit
//
//  Created by pcjbird on 2018/5/19.
//  Copyright © 2018 年 Zero Status. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <FitCloudKit/FitCloudKitDefines.h>

/// FitCloudKit Initialize Option
@interface FitCloudOption : NSObject

/// Whether it is in debug mode.
///
/// > Important: Debug mode will print logs to the Xcode console, otherwise logs will be received by the FitCloudCallback. Default is non-debug mode.
@property(nonatomic, assign) BOOL debugMode;

/// The scan timeout time in seconds
///
/// > Important: The default value is 10s
@property(nonatomic, assign) NSTimeInterval secsScanTimeOut;

/// The connect timeout time in seconds
///
/// > Important: The default value is 5s
///
/// When you initially attempt to manually connect to the peripheral, a connection timeout in seconds is applied. If this timeout is reached, a connection failure error will be returned. Subsequently, the SDK will attempt to reconnect silently.
@property(nonatomic, assign) NSTimeInterval secsConnectTimeOut;

/// The command timeout time in seconds
///
/// > Important: The default value is 10s
@property(nonatomic, assign) NSTimeInterval secsCommandTimeOut;

/// The pairing request confirm timeout time in seconds
///
/// > Important: The default value is 20s
@property(nonatomic, assign) NSTimeInterval secsPairingRequestConfirmTimeOut;

/// Bluetooth packet transmission interval, in milliseconds
///
/// > Important: The default value is 20ms, and minimum interval should not be less than 15ms.
@property(nonatomic, assign) NSInteger milliSecsPacketUnitInterval;

/// Whether should automatically reconnect to the last paired watch device when the app launch
///
/// > Important: The default value is NO.
@property(nonatomic, assign) BOOL shouldAutoReconnectWhenAppLaunch;

/// The watch device language preference.
///
/// > Important: The default value is `FITCLOUDLANGUAGE_NOTSET`
@property(nonatomic, assign) FITCLOUDLANGUAGE watchPreferLang;

/// Whether to prioritize syncing the iOS system language to the watch device.
///
/// > Important: The default value is NO. When you manually change the app's localization language settings, it is not possible to prioritize syncing the iOS system language to the watch due to Apple's Per-App Language Settings.
@property(nonatomic, assign) BOOL preferSyncSystemLang;

/// Whether to automatically synchronize the iOS system time to the watch device when connected to the watch.
///
/// > Important: The default value is YES.
@property(nonatomic, assign) BOOL autoSyncSystemTime;

/// Whether to automatically synchronize the user language to the watch device when connected to the watch.
///
/// > Important: The default value is YES.
@property(nonatomic, assign) BOOL autoSyncUserLanguage;

/// Whether prefer to use WriteWithoutResponse
///
/// > Important: The default value is NO.
@property(nonatomic, assign) BOOL preferWriteWithoutResponse;

/// Preferred document saving path, relative to NSDocumentDirectory.
///
/// > Important: The default value is empty string. The path must be relative to NSDocumentDirectory and does not support saving to other directories.
@property(nonatomic, copy) NSString *preferredDocSavingRelativePath;

/// Whether to only scan and discover Bluetooth devices from known manufacturers.
///
/// > Important: The default value is YES.
@property(nonatomic, assign) BOOL onlyDiscoverKnownManufacturers;

/// The default initialize option.
+ (instancetype)defaultOption;

@end
