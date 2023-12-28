//
//  RTKAccessorySessionTransport.h
//  RTKBTFoundation
//
//  Created by jerome_gu on 2020/3/3.
//  Copyright © 2022 Realtek. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <ExternalAccessory/ExternalAccessory.h>

#ifdef RTK_SDK_IS_STATIC_LIBRARY
#import "RTKPacketTransport.h"
#else
#import <RTKLEFoundation/RTKPacketTransport.h>
#endif

NS_ASSUME_NONNULL_BEGIN

/// A concrete transport that use *iAP* to communicate with remote accessory.
///
/// An ``RTKAccessorySessionTransport`` object uses the protocol string to commucate with accessory. There can be only one accessory session transport object at a time for a given accessory and protocol combination.
/// The transport uses 1024 as MTU. As no acknowledgement is used, this transport sends packet unreliably.
/// The transport creates an internal thread for executing communication tasks. The transport does not have a `basingOnTransport`.
@interface RTKAccessorySessionTransport : RTKPacketTransport

/// The protocol to use when communicating with the accessory.
///
/// This protocol must be one that the accessory understands. All communications with the accessory are expected to use this protocol.
@property (nonatomic, readonly) NSString *protocolString;

/// Initialize the communication object with specific accessory and protocol.
///
/// - Parameter accessory: The accessory with which you want to communicate.
/// - Parameter protocolString: The protocol to use when communicating with the accessory.
- (instancetype)initWithAccessory:(EAAccessory *)accessory forProtocol:(nonnull NSString *)protocolString;

/// The accessory with which you want to communicate.
@property (nonatomic, readonly) EAAccessory *accessory;

@end

NS_ASSUME_NONNULL_END
