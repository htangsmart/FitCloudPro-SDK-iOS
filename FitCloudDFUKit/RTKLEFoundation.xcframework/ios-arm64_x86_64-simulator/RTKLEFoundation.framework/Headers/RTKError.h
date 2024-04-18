//
//  RTKError.h
//  RTKLEFoundation
//
//  Created by jerome_gu on 2019/1/21.
//  Copyright © 2022 Realtek. All rights reserved.
//

#ifndef RTKError_h
#define RTKError_h

#import <Foundation/Foundation.h>

extern NSExceptionName const RTKInvalidCallException;

extern NSErrorDomain const RTKBTErrorDomain;

/// RTKBTErrorDomain Error code
typedef NS_ENUM(NSUInteger, RTKErrorCode) {
    // MARK: - deprecated error code begin
    RTKErrorNotAvailable = 100,
    RTKErrorTimeout,        ///< Generic operation timeout, 
    RTKErrorBusy,           /* Generic busy error */  // to be removed
    RTKErrorUnavailable,
    RTKErrorInvalidParameter,
    
    RTKErrorConnectionTimeout,                      // Connect to a LE peripheral time out.
    
    RTKErrorCharacteristicNotifyEnableFail,
    RTKErrorPeripheralDisconnection,
    RTKErrorPeripheralNotConnected,
    
    /* Attribute discovery */
    RTKErrorATTDiscoveryFail,
    RTKErrorATTNotExist,
    RTKErrorATTDiscoveryBusy,                       // Attemp to discovery service while there is already a pending discovery
    RTKErrorATTDiscoveryTimeout,
    RTKErrorATTInsufficient,
    
    RTKErrorPeripheralTransmissionUnresponsive,
    RTKErrorPeripheralInProgressAlready,
    
    RTKErrorScanForPeripheralTimeout,
    // MARK: - deprecated error code end
    
    RTKErrorAttemptTimeout = RTKErrorTimeout,             ///< Attempt failed due to time out.
    
    RTKErrorInvalidOperation,                       ///< The operation can not be performed.
    RTKErrorTransportBusy,                          ///< The transport is busy with some task..
    
    RTKErrorDeviceConnectionFail,               ///< Connect to device failed.
    RTKErrorDeviceValidation,                   ///< Validate device failed.
    RTKErrorDeviceActivation,                   ///< Activate device for communication failed.
    
    RTKErrorGATTAttributeDiscoveryBusy,             ///< Cannot start discover as there is a discovery to be completed.
    RTKErrorGATTAttributeDiscoveryTimeout = RTKErrorATTDiscoveryTimeout,    ///< Time out when wait for discovery expected service and characteristic.
    RTKErrorGATTAttributeStale,                                             ///< This GATT attribute is stale, should be re discovered again.
    RTKErrorIAPProtocolNotSupport,                              ///< The device does not contain expected communication protocol.
    
    RTKErrorConnectionActivateBusy,                             ///< An activation process is already on progress.
    RTKErrorConnectionNotActive,                                ///< The profile connection is not active for subsequent action.
    
    RTKErrorOperationWaitTimeout = RTKErrorTimeout,             ///< Time out when wait for operation to complete.
    RTKErrorCharacteristicWriteBusy,                            ///< A characteristic write can not be performed because a previous writing has not finished.
    RTKErrorDeviceNotConnected  = RTKErrorPeripheralNotConnected,   ///< Opeartion can not be peformed as device is not connected.
    RTKErrorDataLengthExceed,               ///< The data length exceed the upper limit.
    RTKErrorNoMoreEvent = RTKErrorPeripheralTransmissionUnresponsive,             ///< Wait for data send from device failed.
    
    RTKErrorBatchDataSendReceptionBusy = RTKErrorPeripheralInProgressAlready,        ///< Cannot start a send or recept task because a previous task has not finished.
    RTKErrorAccessorySessionNotOpen,      ///< Communication session with iAP accessory is not open.
    RTKErrorOperationNotSupport,
    RTKErrorAccessoryDisconnected,          ///< Th accessory is disconnected unexpected.
    
    RTKErrorGATTAttributeLack,          ///< Operation fails due to required GATT attribute not exist
    
    RTKErrorTransportBecomeUnavailable,     ///< The transport is now unable to transfer data.
} ;



@interface NSError (RTKBT)

@property (readonly) BOOL isLinkloss;


// FIXME: iPhone 蓝牙开关关闭时，错误也是 Error Domain=CBErrorDomain Code=7 "The specified device has disconnected from us." UserInfo={NSLocalizedDescription=The specified device has disconnected from us.
@property (readonly) BOOL isDisconnectByPeer;

@end


#endif /* RTKError_h */
