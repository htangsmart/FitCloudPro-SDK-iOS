//
//  RTKOTASDK.h
//  RTKOTASDK
//
//  Created by jerome_gu on 2019/1/28.
//  Copyright © 2022 Realtek. All rights reserved.
//

#import <TargetConditionals.h>
#if TARGET_OS_IOS
#import <UIKit/UIKit.h>

//! Project version number for RTKOTASDK.
FOUNDATION_EXPORT double RTKOTASDKVersionNumber;

//! Project version string for RTKOTASDK.
FOUNDATION_EXPORT const unsigned char RTKOTASDKVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <RTKOTASDK/PublicHeader.h>
#else
#endif

#import <RTKOTASDK/RTKOTADeviceInfo.h>

// Binaries to be upgrade or installed in device
#import <RTKOTASDK/RTKOTABin.h>
#import <RTKOTASDK/RTKOTAInstalledBin.h>
#import <RTKOTASDK/RTKOTAUpgradeBin.h>
#import <RTKOTASDK/RTKOTAUpgradeBin+Available.h>

#import <RTKOTASDK/RTKOTAError.h>

#import <RTKOTASDK/RTKDFUUpgrade.h>
#import <RTKOTASDK/RTKDFURoutine.h>
#import <RTKOTASDK/RTKDFUConnectionUponGATT.h>
#import <RTKOTASDK/RTKDFUConnectionUponiAP.h>
#import <RTKOTASDK/RTKDFUManager.h>

// Legacy APIs for compability, not recommended to be use.
#import <RTKOTASDK/RTKOTAProfile.h>
#import <RTKOTASDK/RTKOTAPeripheral.h>
#import <RTKOTASDK/RTKDFUPeripheral.h>
#import <RTKOTASDK/RTKMultiDFUPeripheral.h>
