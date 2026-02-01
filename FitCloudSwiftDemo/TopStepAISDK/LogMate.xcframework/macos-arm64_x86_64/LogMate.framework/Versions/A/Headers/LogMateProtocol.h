//
//  LogMateProtocol.h
//  LogMate
//
//  Created by pcjbird on 2025/11/23.
//  Copyright © 2025 Zero Status. All rights reserved.
//

#ifndef LogMateProtocol_h
#define LogMateProtocol_h
#import <Foundation/Foundation.h>
#import <LogMate/LogMateLevel.h>

NS_ASSUME_NONNULL_BEGIN

/// the loggable protocol
@protocol LoggableProtocol <NSObject>

/// implement to log the message
/// - Parameters:
///   - message: the log message
///   - level: the log level
///   - subsystem: the log subsystem
///   - category: the log category
- (void)onLogMessage:(NSString *)message
               level:(LogMateLevel)level
           subsystem:(nullable NSString *)subsystem
            category:(nullable NSString *)category;

@end

NS_ASSUME_NONNULL_END


#endif /* LogMateProtocol_h */
