//
//  RTKProfileConnection.h
//  RTKLEFoundation
//
//  Created by jerome_gu on 2021/10/18.
//  Copyright © 2022 Realtek. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <ExternalAccessory/ExternalAccessory.h>
#import <CoreBluetooth/CoreBluetooth.h>

#ifdef RTK_SDK_IS_STATIC_LIBRARY
#import "RTKBTGeneralDefines.h"
#else
#import <RTKLEFoundation/RTKBTGeneralDefines.h>
#endif

NS_ASSUME_NONNULL_BEGIN

/// Constants that indicate status of an ``RTKProfileConnection``
typedef NS_ENUM(NSUInteger, RTKProfileConnectionStatus) {
    RTKProfileConnectionStatusInactive,     ///< The profile connection is inactive.
    RTKProfileConnectionStatusActivating,   ///< The profile conneciton is activating.
    RTKProfileConnectionStatusActive,       ///< The profile connection is active.
    RTKProfileConnectionStatusDeactivating, ///< The profile connection is deactivating.
};


@class RTKProfileConnection;

/// Methods used by an ``RTKProfileConnection`` to request connecting or disconnecting a LE device that the connection object manages.
@protocol RTKProfileConnectionPerformer <NSObject>

/// Request a performer to initiate connection with the device of the provided connection.
///
/// - Parameter connection: The connection object that manages a device which to be connect.
/// - Parameter interval: The duration before the request times out.
/// - Parameter handler: A block to be called when connection with the device is established or timeout fires.
///
/// If the device is already connected, the handler is called immediately.
- (void)requestConnectDeviceOf:(RTKProfileConnection *)connection
                   withTimeout:(NSTimeInterval)interval
             completionHandler:(nullable RTKLECompletionBlock)handler;

/// Request a performer to initiate disconnection with the device of the provided connection.
///
/// - Parameter connection: The connection object that manages a device which to be connect.
/// - Parameter interval: The duration before the request times out.
/// - Parameter handler: A block to be called when connection with the device is dismissed or timeout fires.
///
/// If the device is already disconnected, the handler is called immediately.
- (void)requestDisconnectDeviceOf:(RTKProfileConnection *)connection
                      withTimeout:(NSTimeInterval)interval
                completionHandler:(nullable RTKLECompletionBlock)handler;

@end


/// Methods for receiving notifications of a profile connection.
@protocol RTKProfileConnectionDelegate <NSObject>
@optional

/// Tells the delegate object that the device the conenction manages is disconnected.
///
/// - Parameter connection: The connection which manages a specific device.
/// - Parameter error: An error object created when the disconnection occurs.
- (void)profileConnection:(RTKProfileConnection *)connection deviceDidBeDisconnected:(nullable NSError *)error;

/// Tells the delegate object that the connecting to the device the connection manages fails.
///
/// - Parameter connection: The connection which manages a specific device.
/// - Parameter error: An error object created when the failure occurs.
- (void)profileConnection:(RTKProfileConnection *)connection deviceFailedToConnect:(nullable NSError *)error;

/// Tells the delegate object that the connection did receive a new message.
///
/// - Parameter connection: The connection which manages a specific device.
/// - Parameter msgData: The new received message data.
- (void)profileConnection:(RTKProfileConnection *)connection didReceiveMessage:(NSData *)msgData;

@end


/// An abstract base class that represents a application profile connection to a remote device which manage communication with it.
///
/// In contrast to a `CBPeripheral` connection, the ``RTKProfileConnection`` does not indicate a live connected state with a remote device. It represents a relationship between the local app and a remote device in the perspective of an application profile, no matter whether the device is now connected to this phone or not.
///
/// Typically, an ``RTKProfileConnection`` subclass object has knowledge of a paricular profile and implements the profile client role. You use ``RTKProfileConnection`` (or subclass) objects for communicating with a connected device using particular profile protocol, such as obtaining device state, initiates device actions.
///
/// The communication may takes place upon `GATT` profile which you uses ``RTKConnectionUponGATT`` , or upon iAP profile which you uses ``RTKConnectionUponiAP`` . Call ``RTKProfileConnection/connectionWithPeripheral:`` to create a connection object which manages connection with a GATT peripheral. Call ``RTKProfileConnection/connectionWithAccessory:`` to create a connection object which manages connection with an iAP accessory.
///
/// You call ``RTKProfileConnection/activateWithCompletionHandler:`` to make a connection to be active. A connection object should be active before receives any methods that making a real application communication. The device should be connected before begins activating. When activating method is called, the connection first verify profile compliance of the connected device.
///
/// You can call ``RTKProfileConnection/sendMessageData:withCompletionHandler:`` to send a custom data to remote device if the profile supports.
@interface RTKProfileConnection : NSObject

/// Creates and returns a connection object that links with a specified GATT peripheral.
///
/// The peripheral does not need to be now connected. Should be override.
+ (instancetype)connectionWithPeripheral:(CBPeripheral *)peripheral;

/// Creates and returns a connection object that links with a known iAP accessory.
///
/// The accessory does not need to be now connected. Should be override.
+ (instancetype)connectionWithAccessory:(EAAccessory *)accessory;


/// Returns the name of the linked remote device.
@property (readonly, nullable) NSString *deviceName;


/// Returns the remote device this connection object links.
///
/// This property may be of `CBPeripheral` class or `EAAccessory` class.
@property (readonly) id device;


/// Returns a `boolean` value that indicates whether a connection is estabilished with remote device.
@property (readonly) BOOL deviceIsConnected;

/// An object this `RTKProfileConnection` request to perform connection operations.
@property (weak, nullable) id<RTKProfileConnectionPerformer> connectionPerformer;


/// The delegate object that listens for change notification of profile connection open state.
///
/// Subclass may notifies more events through this property.
@property (weak, nullable, nonatomic) id<RTKProfileConnectionDelegate> delegate;


/// Indicates whether the device connection is active for interact with.
///
/// This property is `KVO`-applicable.
@property (readonly) RTKProfileConnectionStatus status;


#define RTKDistantInterval 31536000.

/// The duration used for waiting a connection to be completed.
///
/// The default value is `10` seconds. You should not set this property while this connection is in period of activating.
@property NSTimeInterval connectWaitInterval;

/// Activate the connection for further communication.
///
/// - Parameter handler: A nullable block that will be called when open completion successfully or unsuccessfully.
///
/// If the connection is already active, the handler block is invoked immediately.
- (void)activateWithCompletionHandler:(nullable RTKLECompletionBlock)handler;

/// Deactivate the device connection to stop interacting with it.
///
/// - Parameter handler: A nullable block that will be called when close completion successfully or unsuccessfully.
///
/// If a connection is already inactive, the handler block is invoked immediately.
- (void)deactivateWithCompletionHandler:(nullable RTKLECompletionBlock)handler;

/// Send a custom data to the connected remote device.
///
/// - Parameter data: The data to be send.
/// - Parameter handler: The block to be called when message send successfully or unsuccessfully.
///
/// The method is available only if a subclass object supports sending custom data, if not, the handler block is called with error code set to ``RTKErrorCode/RTKErrorOperationNotSupport`` .
- (void)sendMessageData:(NSData *)data withCompletionHandler:(nullable void(^)(BOOL success, NSError *_Nullable error))handler;

@end


@interface RTKProfileConnection (Protect)

/// Be notified that the device is disconnected.
///
/// This is a override pointer for subclass to responds to connection change. Don't call this method directly. If you override this method in subclass, you need to call this method on super class.
- (void)onDeviceDidDisconnectWithError:(nullable NSError *)error;


/// Be notified that connecting to the device failed.
///
/// This is a override pointer for subclass to responds to connection change. Don't call this method directly. If you override this method in subclass, you need to call this method on super class.
- (void)onDeviceFailedToConnectWithError:(nullable NSError *)error;

@end

NS_ASSUME_NONNULL_END
