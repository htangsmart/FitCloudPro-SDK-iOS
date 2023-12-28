//
//  FitCloudDFULogLevel.h
//  FitCloudDFUKit
//
//  Created by pcjbird on 2019/4/4.
//  Copyright © 2019 Zero Status. All rights reserved.
//

#ifndef FitCloudDFULogLevel_h
#define FitCloudDFULogLevel_h

typedef NS_ENUM(NSInteger, FCDFUKLogLevel) {
    FCDFUKLogLevel_Debug = 0,
    FCDFUKLogLevel_Verbose,
    FCDFUKLogLevel_Info,
    FCDFUKLogLevel_Warning,
    FCDFUKLogLevel_Error,
    FCDFUKLogLevel_Exception,
    FCDFUKLogLevel_Abort,
    FCDFUKMinLogLevel = FCDFUKLogLevel_Debug,
    FCDFUKMaxLogLevel = FCDFUKLogLevel_Abort,
    FCDFUKMuteLogLevel = NSIntegerMax
};

#endif /* FitCloudDFULogLevel_h */
