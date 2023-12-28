//
//  RTKOTAInstalledBin.h
//  RTKLEFoundation
//
//  Created by jerome_gu on 2020/5/25.
//  Copyright © 2022 Realtek. All rights reserved.
//

#ifdef RTK_SDK_IS_STATIC_LIBRARY
#import "RTKOTABin.h"
#else
#import <RTKOTASDK/RTKOTABin.h>
#endif

/// Values that indicate which bank an image resides.
typedef NS_ENUM(NSUInteger, RTKOTABinBankInfo) {
    RTKOTABinBankInfo_Unknown,
    /// Binary reside at *Bank 0*
    RTKOTABinBankInfo_Bank0,
    /// Binary reside at *Bank 1*
    RTKOTABinBankInfo_Bank1,
    /// Binary reside at *Single Bank* (Not a dual bank enviroment)
    RTKOTABinBankInfo_Standalone,
};

NS_ASSUME_NONNULL_BEGIN

/// A concrete `RTKOTABin` class represents a binary installed in a device.
@interface RTKOTAInstalledBin : RTKOTABin

/// Indicates which bank this image is installed in, or should be upgraded in.
@property (readonly) RTKOTABinBankInfo bankState;

/// The maximum length of thie image section in SOC.
///
/// When `0` is returned, the section size is undefined
@property (readonly) NSUInteger sectionSize;

@end

NS_ASSUME_NONNULL_END
