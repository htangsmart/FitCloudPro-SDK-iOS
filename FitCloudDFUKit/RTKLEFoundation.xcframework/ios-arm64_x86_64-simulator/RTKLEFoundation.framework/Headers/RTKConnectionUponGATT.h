//
//  RTKConnectionUponGATT.h
//  RTKBTFoundation
//
//  Created by jerome_gu on 2021/10/18.
//  Copyright © 2022 Realtek. All rights reserved.
//

#import <CoreBluetooth/CoreBluetooth.h>

#ifdef RTK_SDK_IS_STATIC_LIBRARY
#import "RTKProfileConnection.h"
#import "RTKCharacteristicOperate.h"
#else
#import <RTKLEFoundation/RTKProfileConnection.h>
#import <RTKLEFoundation/RTKCharacteristicOperate.h>
#endif

NS_ASSUME_NONNULL_BEGIN

@class RTKConnectionUponGATT;

/// Methods that an ``RTKConnectionUponGATT`` calls on its delegate to report events.
@protocol RTKConnectionUponGATTDelegate <RTKProfileConnectionDelegate>
@optional

/// Tells the delegate that the `GATT` peripheral that a connection link with did change its name.
///
/// - Parameter connection: The connection object that sends this notification.
- (void)GATTConnectionDidUpdatePeripheralName:(RTKConnectionUponGATT *)connection;

/// Tells the delegate that the masured rssi value changes of GATT peripheral that a connection link with.
///
/// - Parameter connection: The connection object that sends this notification.
/// - Parameter RSSI: The RSSI, in decibels, of the peripheral.
/// - Parameter error: The reason the ``RTKConnectionUponGATT/readPeripheralRSSI`` call failed, or nil if no error occurred.
- (void)GATTConnection:(RTKConnectionUponGATT *)connection didReadPeripheralRSSI:(NSNumber *)RSSI error:(nullable NSError *)error;

@end


/// A concrete device connection that communicates with a GATT peripheral.
///
/// For communicating with peripheral, this object set itself as the delegate of the `CBPeripheral` object. So if you create this object, you should not set peripheral's delegate, nor call any `CBPeripheral` methods that will make communication with device. If you really need to, you should ensure the delegate methods of this connection be called correctly.
@interface RTKConnectionUponGATT : RTKProfileConnection <CBPeripheralDelegate>


// MARK: - Matching options for discovery or detection

/// Returns a list of service uuids that one service is contained that a qualified LE peripheral is advertising.
///
/// An ``RTKProfileConnectionManager`` may use this value when scaning for peripherals, a peripheral adverising
///
/// When subclass this class, you typically override this method and return a meaningful list.
@property (readonly, class, nullable) NSArray <CBUUID *> *serviceUUIDsInADV;


/// Returns an array of service uuids that can be used to identfier peripherals.
///
/// An ``RTKProfileConnectionManager`` may uses this property for retrieving connected device or observing connection events.
///
/// When you subclass this class, you typically override this method and return a meaningful value.
@property (readonly, class, nullable) NSArray <CBUUID *> *interestedServiceUUIDs;


/// Initializes the connection object with a peripheral object.
///
/// The peripheral does not need to be in connected state.
///
/// After call this method, you shall not call any methods of the peripheral object.
- (instancetype)initWithPeripheral:(CBPeripheral *)peripheral;


/// Returns the GATT peripheral object that this connection links.
@property (readonly) CBPeripheral *peripheral;


/// The delegate object that you want to receive peripheral events.
@property (weak, nonatomic, nullable) id<RTKConnectionUponGATTDelegate> delegate;


/// Start monitoring the measured `RSSI` of the connected peripheral.
///
/// When a new RSSI value is measured, this connection calls ``RTKConnectionUponGATTDelegate/GATTConnection:didReadPeripheralRSSI:error:`` on its delegate object.
- (void)readPeripheralRSSI;

/// Communicate with the device to get the state of its battery level.
///
/// - Parameter handler: The block to be invoked when the task completes.
- (void)getBatteryLevelWithCompletionHandler:(nullable void(^)(BOOL success, NSError *error, RTKBatteryLevel level))handler;

@end



@interface RTKConnectionUponGATT (AttributeDiscovery)

/// Start discovering a GATT service which has the specified UUID.
///
/// - Parameter serviceUUID: The UUID which the service to be discovered uses.
/// - Parameter handler: The completion handler to be invoked when task finishes.
///
/// If the discovery succeeds, you use ``serviceWithID:`` to obtain the service object. `5` seconds is used as time out interval.
- (void)discoverServiceWithID:(CBUUID *)serviceUUID withCompletionHandler:(void(^)(BOOL success, NSError *_Nullable error))handler;

/**
 * Asynchronously discover Attribute(Service & Characteristics)
 * 
 * @param dict NSDictionary containing Service UUIDs and Characteristic UUIDs to discover. Example: @{@"000002FD-3C17-D293-8E48-14FE2E4DA212": @[@"FFE0", @"FFE1"]}
 * @param handler Invoked when all Service and Characteristics specified in dict discovered, or timeout error (5s).
 */
//- (void)discoverCharacteristicsWithIDDictionary:(NSDictionary *)dict completionHandler:(void(^)(BOOL success, NSError *_Nullable error))handler;


/// Discovers the specified service and its containing charactersitics.
///
/// - Parameter serviceID: The UUID string which identifies the type of service you want to discover.
/// - Parameter characteristicIDs: An list of UUID strings that each represents a UUID that identifies the type of characteristic you want to discover.
/// - Parameter handler: The block to be called when discovery complete successfully or unsuccessfully.
///
/// This method executes asynchronously. When the service and all characteristics you want to discover is all discovered, it calls handler block with success set to `YES` and error set to `nil`. You can access discovered service and characteristic through ``RTKConnectionUponGATT/serviceWithID:`` and ``RTKConnectionUponGATT/characteristicOfID:inService:`` methods. If the service or any characteristic is not discovered within a specific time, it calls the handler block with success set to `NO` and error set to a `NSError` object whose domain is ``RTKBTErrorDomain`` and code is ``RTKErrorCode/RTKErrorGATTAttributeDiscoveryTimeout``. The default timeout interval is `5` seconds.
- (void)discoverService:(NSString *)serviceID containingCharacteristics:(nullable NSArray <NSString*>*)characteristicIDs withCompletionHandler:(void(^)(BOOL success, NSError *_Nullable error))handler;


/// Discovers the specified service and its containing charactersitics within a specific timeout interval.
///
/// - Parameter serviceID: The UUID string which identifies the type of service you want to discover.
/// - Parameter characteristicIDs: An list of UUID strings that each represents a UUID that identifies the type of characteristic you want to discover.
/// - Parameter handler: The block to be called when discovery complete successfully or unsuccessfully.
///
/// This method executes asynchronously. When the service and all characteristics you want to discover is all discovered, it calls handler block with success set to `YES` and error set to `nil`. You can access discovered service and characteristic through ``RTKConnectionUponGATT/serviceWithID:`` and ``RTKConnectionUponGATT/characteristicOfID:inService:`` methods. If the service or any characteristic is not discovered within a specific time, it calls the handler block with success set to `NO` and error set to a `NSError` object whose domain is ``RTKBTErrorDomain`` and code is ``RTKErrorCode/RTKErrorGATTAttributeDiscoveryTimeout``.
- (void)discoverService:(NSString *)serviceID containingCharacteristics:(nullable NSArray <NSString*>*)characteristicIDs timeout:(NSTimeInterval)timeout withCompletionHandler:(void(^)(BOOL success, NSError *_Nullable error))handler;


/// Returns the discovered service object which is identifiered by the specific service UUID.
///
/// - Returns `nil` if the service is not discovered.
- (nullable CBService *)serviceWithID:(NSString *)serviceID;


/// Returns the discovered characteristic object which is identifiered by the specific characteristic UUID and service UUID.
///
/// - Returns `nil` if the characteristic is not discovered.
- (nullable CBCharacteristic *)characteristicOfID:(NSString *)charID inService:(NSString *)serviceID;

@end


@interface RTKConnectionUponGATT(CharacteristicReadWrite)

/// Makes an ``RTKCharacteristicRead`` conformed object to receive notification when the specific characteristic value did read successfully or unsuccessfully.
- (void)registerCharacteristicReader:(id <RTKCharacteristicRead>)reader;

/// Stops an ``RTKCharacteristicRead`` conformed object to receive notification when the specific characteristic value did read successfully or unsuccessfully.
- (void)unregisterCharacteristicReader:(id <RTKCharacteristicRead>)reader;

/// Makes an ``RTKCharacteristicNotificationRecept`` conformed object to receive notification when the specific characteristic updates its notification state or its value.
- (void)registerCharacteristicNotificationReceptor:(id <RTKCharacteristicNotificationRecept>)receptor;

/// Stops an ``RTKCharacteristicNotificationRecept`` conformed object to receive notification when the specific characteristic updates its notification state or its value.
- (void)unregisterCharacteristicNotificationReceptor:(id <RTKCharacteristicNotificationRecept>)receptor;

/// Makes an ``RTKCharacteristicWrite`` conformed object to receive notification when receives the specific characteristic value write response.
- (void)registerCharacteristicWriter:(id <RTKCharacteristicWrite>)writer;

/// Stops an ``RTKCharacteristicWrite`` conformed object to receive notification when receives the specific characteristic value write response.
- (void)unregisterCharacteristicWriter:(id <RTKCharacteristicWrite>)writer;

@end


NS_ASSUME_NONNULL_END
