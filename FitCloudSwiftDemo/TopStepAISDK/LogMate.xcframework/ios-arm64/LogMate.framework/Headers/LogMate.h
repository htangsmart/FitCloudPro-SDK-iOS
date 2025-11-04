//
//  LogMate.h
//  LogMate
//
//  Created by pcjbird on 12/8/23.
//

#import <Foundation/Foundation.h>
#import <LogMate/LogMateProtocol.h>

//! Project version number for LogMate.
FOUNDATION_EXPORT double LogMateVersionNumber;

//! Project version string for LogMate.
FOUNDATION_EXPORT const unsigned char LogMateVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <LogMate/PublicHeader.h>

/// logmate string
#define LOGMATE_STRING(emoji, target, format, ...) [NSString stringWithFormat:@"[%@%@] %s (line %d) " format, emoji, target, __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__]


