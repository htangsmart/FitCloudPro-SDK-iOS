//
//  LogMateProtocol.h
//  LogMate
//
//  Created by pcjbird on 12/8/23.
//

#ifndef LogMateProtocol_h
#define LogMateProtocol_h
#import <Foundation/Foundation.h>
#import <LogMate/LogMateLevel.h>

/// the loggable protocol
@protocol LoggableProtocol <NSObject>

/// implement to log the message
/// - Parameters:
///   - message: the log message
///   - level: the log level
///   - subsystem: the log subsystem
///   - category: the log category
-(void) onLogMateMessage:(NSString*)message level:(LOGMATELEVEL)level subsystem:(NSString*)subsystem category:(NSString*)category;

@end

#endif /* LogMateProtocol_h */
