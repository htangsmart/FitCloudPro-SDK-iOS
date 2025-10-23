//
//  LogMateLevel.h
//  LogMate
//
//  Created by pcjbird on 12/8/23.
//

#ifndef LogMateLevel_h
#define LogMateLevel_h
#import <Foundation/Foundation.h>

/// The log level
typedef NS_ENUM(NSInteger, LOGMATELEVEL)
{
    /// verbose
    LOGMATELEVEL_VERBOSE = 0,
    
    /// debug
    LOGMATELEVEL_DEBUG = 1,
    
    /// info
    LOGMATELEVEL_INFO = 2,
    
    /// warning
    LOGMATELEVEL_WARNING = 3,
    
    /// error
    LOGMATELEVEL_ERROR = 4,
    
    /// fatal
    LOGMATELEVEL_FATAL = 5,
    
};

#endif /* LogMateLevel_h */
