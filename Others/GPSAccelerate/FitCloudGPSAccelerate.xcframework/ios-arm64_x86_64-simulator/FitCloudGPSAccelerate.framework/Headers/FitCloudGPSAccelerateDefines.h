//
//  FitCloudGPSAccelerateDefines.h
//  FitCloudGPSAccelerate
//
//  Created by pcjbird on 4/8/24.
//

#ifndef FitCloudGPSAccelerateDefines_h
#define FitCloudGPSAccelerateDefines_h
#import <Foundation/Foundation.h>

/// the GPS accelerate error domain
#define GPSACCELERATEERRORDOMAIN @"GPSACCELERATEERRORDOMAIN"

/// the GPS accelerate error
typedef NS_ENUM(NSInteger, GPSACCELERATEERROR)
{
    ///unknown error
    GPSACCELERATEERROR_UNKNOWN = 10000,
    
    ///bad http staus code
    GPSACCELERATEERROR_BADHTTPSTATUSCODE = 10001,
    
    /// the smart watch device is not ready
    GPSACCELERATEERROR_DEVICENOTREADY = 10002,
    
    /// the smart watch device does not support the feature
    GPSACCELERATEERROR_DEVICENOTSUPPORT = 10003,
    
    /// the smart watch device is busy now
    GPSACCELERATEERROR_DEVICEBUSY = 10004,
    
    /// the smart watch device not allow transfer the GPS file now
    GPSACCELERATEERROR_NOTALLOWTRANSFERNOW = 10005,
    
    /// the gps file is good, it is unnecessary to update.
    GPSACCELERATEERROR_UNNECESSARY = 10006,
};

/// the gps accelerate result
typedef NS_ENUM(NSInteger, GPSACCELERATERESULT)
{
    /// success
    GPSACCELERATERESULT_SUCCESS = 0,
    
    /// the gps file is good, it is unnecessary to update.
    GPSACCELERATERESULT_UNNECESSARY = 1,
    
    /// failure
    GPSACCELERATERESULT_FAILURE = 2,
};

#endif /* FitCloudGPSAccelerateDefines_h */
