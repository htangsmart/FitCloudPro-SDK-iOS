//
//  LogMateLevel.h
//  LogMate
//
//  Created by pcjbird on 2025/11/23.
//  Copyright © 2025 Zero Status. All rights reserved.
//

#ifndef LogMateLevel_h
#define LogMateLevel_h
#import <Foundation/Foundation.h>

/// The severity levels used by LogMate.
typedef NS_ENUM(NSInteger, LogMateLevel)
{
    /// The most detailed level, used for tracing execution flow.
    LogMateLevelVerbose = 0,
    
    /// Detailed diagnostic information, useful during development.
    LogMateLevelDebug = 1,
    
    /// General informational messages that highlight progress.
    LogMateLevelInfo = 2,
    
    /// Potentially harmful situations that may require attention.
    LogMateLevelWarn = 3,
    
    /// Error events that might still allow the application to continue.
    LogMateLevelError = 4,
    
    /// Critical errors that may cause the application to terminate.
    LogMateLevelFatal = 5,

    /// The lowest possible severity level.
    LogMateLevelMin = LogMateLevelVerbose,  

    /// The highest possible severity level.
    LogMateLevelMax = LogMateLevelFatal,

    /// A special level that disables all logging output.
    LogMateLevelMute = NSIntegerMax,
    
};

#endif /* LogMateLevel_h */
