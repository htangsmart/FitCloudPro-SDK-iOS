//
//  RTKBTLogMacros.h
//  RTKLEFoundation
//
//  Created by jerome_gu on 2019/1/8.
//  Copyright © 2022 Realtek. All rights reserved.
//

#ifndef RTKBTLogMacros_h
#define RTKBTLogMacros_h

#ifdef RTK_SDK_IS_STATIC_LIBRARY
#import "RTKLog.h"
#else
#import <RTKLEFoundation/RTKLog.h>
#endif

/* Handy Macros for print log to RTKLog facility */
#define RTKLogError(fmt, ...)   [RTKLog _logWithLevel:RTKLogLevelError format: (fmt), ## __VA_ARGS__]
#define RTKLogWarn(fmt, ...)    [RTKLog _logWithLevel:RTKLogLevelWarning format: (fmt), ## __VA_ARGS__]
#define RTKLogInfo(fmt, ...)    [RTKLog _logWithLevel:RTKLogLevelInfo format: (fmt), ## __VA_ARGS__]
#define RTKLogDebug(fmt, ...)   [RTKLog _logWithLevel:RTKLogLevelDebug format: (fmt), ## __VA_ARGS__]
#define RTKLogVerbose(fmt, ...) [RTKLog _logWithLevel:RTKLogLevelVerbose format: (fmt), ## __VA_ARGS__]

#endif /* RTKBTLogMacros_h */
