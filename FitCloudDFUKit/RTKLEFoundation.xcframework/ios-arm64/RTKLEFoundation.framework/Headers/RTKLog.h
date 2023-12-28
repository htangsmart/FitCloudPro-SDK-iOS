//
//  RTKLog.h
//  RTKLEFoundation
//
//  Created by jerome_gu on 2019/1/21.
//  Copyright © 2022 Realtek. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// Represents available facilities to indicate the log message destination.
typedef NS_ENUM(NSUInteger, RTKLogFacility) {
    RTKLogFacilityDefault, ///< Direct logs to NSLog function.
    RTKLogFacilityCocoaLumberjack  __attribute((availability(ios,unavailable))) __attribute((availability(macos,unavailable))), ///< Direct logs to CocoaLumberjack. Not support
    RTKLogFacilityCustom,  ///< Direct logs to a custom C function which can be set by calling -setLogger: method.
};


/// Log level used by `RTKLog` facility.
typedef NS_ENUM(NSUInteger, RTKLogLevel) {
    RTKLogLevelOff       = 0,   ///< Log will not print.
    RTKLogLevelError,           ///< Error level logs will print.
    RTKLogLevelWarning,         ///< Warning and Error level logs will print.
    RTKLogLevelInfo,            ///< Warning, Error and Info level logs will print.
    RTKLogLevelDebug,           ///< Warning, Error, Info and Debug level logs will print.
    RTKLogLevelVerbose,         ///< All level logs will print.
};


/// `RTKLog` is a logging facility used by Realtek SDKs to print log messages.
///
/// `RTKLog` provides several public APIs to control the facility log level and logging destination.
@interface RTKLog : NSObject

/// Set the logging direction.
///
/// If set to ``RTKLogFacility/RTKLogFacilityCustom``, a custom logger C function should be provided by ``RTKLog/setLogger:`` firstly.
+ (void)setFacility:(RTKLogFacility)facility;

/// Provides a logging function pointer to receive log messages.
+ (void)setLogger:(void(*)(NSString*))logFunc;

/// Set log level of this logging system.
+ (void)setLogLevel:(RTKLogLevel)level;


/// Log method used internal.
///
/// Don't use it directly.
+ (void)_logWithLevel:(RTKLogLevel)level format:(NSString *)format, ...;

/// Log a message to Realtek logging facility.
+ (void)logWithLevel:(RTKLogLevel)level format:(NSString *)format arguments:(va_list)argList;

@end

NS_ASSUME_NONNULL_END
