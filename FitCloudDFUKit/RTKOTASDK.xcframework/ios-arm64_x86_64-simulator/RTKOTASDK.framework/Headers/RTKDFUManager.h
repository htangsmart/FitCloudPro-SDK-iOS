//
//  RTKDFUManager.h
//  RTKOTASDK
//
//  Created by jerome_gu on 2021/10/21.
//  Copyright © 2022 Realtek. All rights reserved.
//

#ifdef RTK_SDK_IS_STATIC_LIBRARY
#import "libRTKLEFoundation.h"
#import "RTKOTADeviceInfo.h"
#else
#import <RTKLEFoundation/RTKLEFoundation.h>
#import <RTKOTASDK/RTKOTADeviceInfo.h>
#endif

NS_ASSUME_NONNULL_BEGIN


/// A profile manager that manage connection with devices that are about to be upgraded.
///
/// The `RTKDFUManager` class provides two scan methods for scaning for device in OTA mode and scaning for companion device.
/// Don't call ``RTKLEFoundation/RTKProfileConnectionManager/scanForPeripherals:`` which is inherited from ``RTKLEFoundation/RTKProfileConnectionManager`` on this class instance to scan for nearby devices, this class only support scan for OTA mode device and companion device.
@interface RTKDFUManager : RTKProfileConnectionManager


/// Scan for device in OTA mode of the given device that is in normal mode.
///
/// - Parameter connection: The connection with device for which to scan its in OTA mode device object.
/// - Parameter deviceInfo: The object containing information of this device when scanning.
/// - Parameter handler: The completion handler to call when the expected device is found or time out occurs.
///
/// Although there is only one physical device, SDK uses two `RTKConnectionUponGATT` objects to represents normal mode device and OTA mode device. When a device switches to OTA mode, call this method to discover the device in OTA mode. When the device in OTA mode is discovered, the `handler` block is invoked with `otaModeDevice` parameter set to object that represents the device in OTA mode.
///
/// The default interval of time out is 10 seconds.
- (void)scanForOTAModeDeviceConnectionOfDeviceConnection:(RTKConnectionUponGATT *)connection
                                          withDeviceInfo:(RTKOTADeviceInfo *)deviceInfo
                                       completionHandler:(void (^)(BOOL success, NSError *__nullable error, RTKConnectionUponGATT *otaModeDevice))handler;

/// - Parameter timeOut: Customize the interval of time out.
- (void)scanForOTAModeDeviceConnectionOfDeviceConnection:(RTKConnectionUponGATT *)connection
                                          withDeviceInfo:(RTKOTADeviceInfo *)deviceInfo
                                                 timeOut:(NSTimeInterval)timeOut
                                       completionHandler:(void (^)(BOOL success, NSError *__nullable error, RTKConnectionUponGATT *otaModeDevice))handler;


/// Scan for companion device of the given device.
///
/// - Parameter connection: The connection of a device of which to scan the companion device.
/// - Parameter deviceInfo: The object containing information of this given device.
/// - Parameter handler: The completion handler to call when the expected device is found or time out occurs.
///
/// While upgrading a RWS pair devices, call this method to scan for the companion device when finish upgrade the first device.
///
/// The default interval of time out is 10 seconds.
- (void)scanForCompanionDeviceConnectionOfDeviceConnection:(RTKProfileConnection *)connection
                                            withDeviceInfo:(RTKOTADeviceInfo *)deviceInfo
                                         completionHandler:(void (^)(BOOL success, NSError *__nullable error, RTKProfileConnection *companion))handler;

@end

NS_ASSUME_NONNULL_END
