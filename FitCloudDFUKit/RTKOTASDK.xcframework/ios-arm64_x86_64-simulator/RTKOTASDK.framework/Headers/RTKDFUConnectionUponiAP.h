//
//  RTKDFUConnectionUponiAP.h
//  RTKOTASDK
//
//  Created by jerome_gu on 2021/10/19.
//  Copyright © 2022 Realtek. All rights reserved.
//

#ifdef RTK_SDK_IS_STATIC_LIBRARY
#import "libRTKLEFoundation.h"
#import "RTKDFURoutine.h"
#else
#import <RTKLEFoundation/RTKLEFoundation.h>
#import <RTKOTASDK/RTKDFURoutine.h>
#endif

NS_ASSUME_NONNULL_BEGIN

/// A concrete subclass of  `RTKDFUConnectionUponiAP` which communicate with a remote iAP profile connected device to perform upgrade related procedure.
///
/// The `RTKDFUConnectionUponiAP` conforms to ``RTKDFURoutine`` protocol, providing interfaces to interact with device for upgrade. In addition, `RTKDFUConnectionUponiAP` defines method to request device to perform role swapping.
@interface RTKDFUConnectionUponiAP : RTKConnectionUponiAP <RTKDFURoutine>


/// Initializes the receiver with an accessory and existed communication for message exchange.
///
/// - Parameter accessory: The iAP connected accessory that is about to be upgrade.
/// - Parameter msgTransport: A transport object already created for message exchange.
///
/// For a iAP profile connected device, only one message communication object can communicate with it. If multiple objects exchange messages with device, they should use a shared message communication. Use this initializer to pass a message communication alrady created somewhere.
- (instancetype)initWithAccessory:(EAAccessory *)accessory existMessageTransport:(RTKPacketTransport *)msgTransport;


/// Set the transport object used by `RTKDFUConnectionUponiAP` to exchange messages.
@property RTKPacketTransport *messageTransport;


/// Request the receiver to peform a role swap procedure.
///
/// - Parameter handler: The completion handler to call when the request is complete.
///
/// Typically, a successful role swapping does not result in ACL link disconnection.
- (void)requestRoleSwapWithCompletionHandler:(nullable RTKLECompletionBlock)handler;

@end

NS_ASSUME_NONNULL_END
