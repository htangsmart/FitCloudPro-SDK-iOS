//
//  RTKLPBError.h
//  LocalPlayback
//
//  Created by jerome_gu on 2022/3/1.
//  Copyright © 2022 jerome_gu. All rights reserved.
//

#import <Foundation/Foundation.h>

/// The error domain of errors reported by the `RTKLocalPlaybackSDK`.
extern NSErrorDomain const RTKLPBErrorDomain;

/// Errors reported by `RTKLocalPlaybackSDK`.
typedef enum : NSUInteger {
    /// Device does not have the expected GATT Service (or attribute is not configured as expected).
    RTKLPBError_GATTServiceConformance,
    /// Not a valid request send to device.
    RTKLPBError_notARequest,
    /// File check fails.
    RTKLPBError_fileCheckFail,
    /// Buffer check fails.
    RTKLPBError_bufferCheckFail,
    /// Validation fails due to CRC check failure.
    RTKLPBError_validateDueToCRCCheck,
    /// Validation fails due to length not equal.
    RTKLPBError_validateDueToLength,
    /// Other errors.
    RTKLPBError_otherError,
} RTKLPBErrorCode;
