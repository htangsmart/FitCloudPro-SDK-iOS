//
//  LogMateMacros.h
//  LogMate
//
//  Created by pcjbird on 2025/11/23.
//  Copyright © 2025 Zero Status. All rights reserved.
//

#ifndef LogMateMacros_h
#define LogMateMacros_h

#import <Foundation/Foundation.h>


/// Creates a formatted log string with emoji, target, version, function and line information
/// - Parameters:
///   - emoji: The emoji prefix for the log
///   - target: The target identifier for the log
///   - ver: The version string for the log
///   - fmt: The format string
///   - ...: The format arguments
#define MAGIC_LOG_STRING(emoji, target, ver, fmt, ...)                                                    \
    [NSString stringWithFormat:@"[%@%@ %@] %s (line %d) " fmt,                                            \
                                    emoji,                                                                \
                                    target,                                                               \
                                    ver,                                                                  \
                                    __PRETTY_FUNCTION__,                                                  \
                                    __LINE__,                                                             \
                                    ##__VA_ARGS__]

#endif /* LogMateMacros_h */
