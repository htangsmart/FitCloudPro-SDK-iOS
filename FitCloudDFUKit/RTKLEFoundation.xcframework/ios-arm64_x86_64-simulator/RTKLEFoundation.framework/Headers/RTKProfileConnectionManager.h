//
//  RTKProfileConnectionManager.h
//  RTKBTFoundation
//
//  Created by jerome_gu on 2021/10/18.
//  Copyright © 2022 Realtek. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>
#import <ExternalAccessory/ExternalAccessory.h>

#ifdef RTK_SDK_IS_STATIC_LIBRARY
#import "RTKProfileConnection.h"
#else
#import <RTKLEFoundation/RTKProfileConnection.h>
#endif

NS_ASSUME_NONNULL_BEGIN

@class RTKProfileConnectionManager;

/// Methods that a delegate of an ``RTKProfileConnectionManager`` object must adopt to receive connection related events.
@protocol RTKProfileConnectionManagerDelegate <NSObject>
@required

/// Tells the delegate that `GATT` service availablity state did update.
///
/// - Parameter manager: The manager that reports this event.
///
/// When this method get called, whether GATT service is available can be determined by ``RTKProfileConnectionManager/GATTAvailable``.
- (void)profileManagerDidUpdateGATTAvailability:(RTKProfileConnectionManager *)manager;

@optional

/// Tells the delegate that a connection with a qualified device that is connected just now.
///
/// - Parameter manager: The manager that reports this event.
/// - Parameter connection: The connection that a device is connected with manager.
///
/// This method will get called, if the manager is listening connection events, which is started by call ``RTKProfileConnectionManager/startMonitoringNewConnectionWithAccessory`` or ``RTKProfileConnectionManager/startMonitoringNewConnectionWithPeripheral``. If a qualified `GATT` peripheral is connected, the connection is of ``RTKConnectionUponGATT`` type. If a qualified iAP accessory is connected, the connection is of ``RTKConnectionUponiAP`` type.
- (void)profileManager:(RTKProfileConnectionManager *)manager
didDetectNewConnectedConnection:(RTKProfileConnection *)connection;


/// Tells the delegate that a connection with a qualified device that is discovered just now while scanning.
///
/// - Parameter manager: The manager that reports this event.
/// - Parameter connection: The connection that a device is connected with manager.
/// - Parameter advertisementData: A dictionary containing any advertisement data.
/// - Parameter RSSI: The current received signal strength indicator (RSSI) of the peripheral, in decibels.
///
/// While an `RTKProfileConnectionManager` is scanning, it calls this method to report new scanned peripehral.
- (void)profileManager:(RTKProfileConnectionManager *)manager
didDiscoverPeripheralOfConnection:(RTKProfileConnection *)connection
     advertisementData:(NSDictionary<NSString *, id> *)advertisementData
                  RSSI:(NSNumber *)RSSI;

@end



/// A generic object that you use to scan, detect connections with interested remote devices.
///
/// An ``RTKProfileConnectionManager`` creates connection objects (represented by ``RTKProfileConnection`` objects) and report to you when it did discover GATT devices or detect new iAP connected devices if those deivce is interested by this manager.
///
/// If you already have a `EAAccessory` instance or `CBPeripheral` instance, call ``RTKProfileConnectionManager/instantiateConnectionWithPeripheral:`` or ``RTKProfileConnectionManager/instantiateConnectionWithAccessory:`` respectively to obtain a corresponding connection object.
///
/// You should retain the device connection objects with which you want to interact with further.
///
/// To communicate with remote device with which a connection object connect, call ``RTKProfileConnection/activateWithCompletionHandler:`` methods and wait till the connection is active.
///
/// Before call any methods using `GATT`, ``GATTAvailable`` should returns `YES` .
///
/// When the manager discovers new peripherals, detects new connections or finish activate connections, it calls methods defined by ``RTKProfileConnectionManagerDelegate`` on its delegate object.
@interface RTKProfileConnectionManager : NSObject <CBCentralManagerDelegate>


/// Initializes the profile manager with a specified delegate.
///
/// - Parameter delegate: The delegate that receives connection-related events.
///
/// After this method returns, ``RTKProfileConnectionManagerDelegate/profileManagerDidUpdateGATTAvailability:`` may be called on its delegate as the underlying central manager is power on.
- (instancetype)initWithDelegate:(nullable id <RTKProfileConnectionManagerDelegate>)delegate NS_DESIGNATED_INITIALIZER;


/// The delegate that will receive connection discovery and other events.
@property (weak) id <RTKProfileConnectionManagerDelegate> delegate;


/// Returns a central manager which used internal.
///
/// Protected used in subclass.
@property (readonly) CBCentralManager *centralManager;


/// Returns a boolean value that indicates if GATT service is available.
///
/// You call methods to interact with GATT devices only when this property value is `YES`.
@property (readonly) BOOL GATTAvailable;


#pragma mark - Register class for connection

/// Provide a concrete ``RTKConnectionUponGATT`` subclass for creating connections for GATT peripherals.
///
/// The default used class is ``RTKConnectionUponGATT``.
- (void)registerConnectionClassForInstantiateGATTPeripheral:(Class)connectionClass;


/// Provide a concrete ``RTKConnectionUponiAP`` subclass for creating connections for iAP accessories.
///
/// The default used class is ``RTKConnectionUponiAP``.
- (void)registerConnectionClassForInstantiateiAPAccessory:(Class)connectionClass;


#pragma mark - LE Perpheral Scanning

/// Indicates whether the manager is currently scanning.
@property (readonly) BOOL isScaning;

/// Scans for nearby LE GATT peripherals.
///
/// When the manager discovers a LE GATT device with requirements meet, it calls ``RTKProfileConnectionManagerDelegate/profileManager:didDiscoverPeripheralOfConnection:advertisementData:RSSI:`` on its delegate.
///
/// The ``GATTAvailable`` should be `YES` when call this method.
- (void)scanForPeripherals;


/// Scans for nearby LE GATT peripherals without duplicate filtering.
///
/// The profile manager report discovery events each time it receives an advertising packet from the peripheral. Use this method only if necessary.
///
/// The ``GATTAvailable`` should be `YES` when call this method.
- (void)scanForPeripheralsAndReportRepeatedly;


/// Stop scaning for LE GATT peripherals.
///
/// The ``GATTAvailable`` should be `YES` when call this method.
- (void)stopScan;


#pragma mark - New connected connection detect

/// Begins to receive notifications of connection or disconnection events of qualified iAP accessories.
///
/// The profile manager calls ``RTKProfileConnectionManagerDelegate/profileManager:didDetectNewConnectedConnection:`` on its delegate if a qualified accessory is connected.
- (void)startMonitoringNewConnectionWithAccessory;


/// Stops receiving notifications of connection or disconnection events of qualified iAP accessories.
- (void)stopMonitoringNewConnectionWithAccessory;


/// Begins to receive notifications of connection or disconnection events of qualified GATT peripherals.
///
/// The profile manager calls ``RTKProfileConnectionManagerDelegate/profileManager:didDetectNewConnectedConnection:`` on its delegate object if a qualified GATT peripheral is connected.
///
/// The ``GATTAvailable`` should be `YES` when call this method.
- (void)startMonitoringNewConnectionWithPeripheral;


/// Stops receiving notifications of connection or disconnection events of qualified `GATT` peripherals.
///
/// The ``GATTAvailable`` should be `YES` when call this method.
- (void)stopMonitoringNewConnectionWithPeripheral;



#pragma mark - Connection retrieve

/// Returns a list of the device connections each represents a connection with a qualified GATT peripheral that is connected to the system.
///
/// The ``GATTAvailable`` should be `YES` when call this method.
- (NSArray <RTKProfileConnection*> *)retrieveConnectedPeripheralConnections;


/// Returns a list of the device connection objects each represents a connection with a qualified iAP accessory that is connected to the system.
- (NSArray <RTKProfileConnection*> *)retrieveConnectedAccessoryConnections;


#pragma mark - Instantiate connection

/// Returns a connection object which represents the connection with the specific GATT peripheral.
///
/// - Parameter peripheral: A `CBPeripheral` instance created somewhere else.
/// - Returns a device connection that is managed by this manager. Returns `nil` if the device connection cannot be created.
///
/// The return peripheral object has class or subclass of ``RTKConnectionUponGATT``.
///
/// The ``GATTAvailable`` should be `YES` when call this method.
- (nullable RTKProfileConnection *)instantiateConnectionWithPeripheral:(CBPeripheral *)peripheral;


/// Creates and returns a connection object which represents connection with the specific iAP accessory.
///
/// - Parameter accessory: An `EAAccessory` instance created somewhere else.
/// - Returns a device connection that is managed by this manager. Returns `nil` if the device connection cannot be created.
///
/// The return peripheral object has class or subclass of ``RTKConnectionUponiAP``.
- (nullable RTKProfileConnection *)instantiateConnectionWithAccessory:(EAAccessory *)accessory;


#pragma mark - Managed connection fetch

/// Returns a `boolean` value that indicates whether the specific device connection is managed by this manager.
- (BOOL)manageConnection:(RTKProfileConnection *)connection;


/// Returns a list of ``RTKProfileConnection`` instances each manages connection with a specific GATT peripheral.
///
/// - Returns a empty set if there is no profile connection with this peripheral that is managed by this manager.
- (NSSet <RTKProfileConnection*> *)managedConnectionsWithPeripheral:(CBPeripheral *)peripheral;


/// Returns a list of ``RTKProfileConnection`` instances which connects with a specific iAP accessory.
///
/// - Returns a empty set if there is no profile connection with this accessory that is managed by this manager.
- (NSSet <RTKProfileConnection*> *)managedConnectionsWithAccessory:(EAAccessory *)accessory;


// MARK: - Device connection state observation

/// Waits for a device to be connected for up to the specified timeout.
///
/// - Parameter connection: The connection which manages the device to be connected.
/// - Parameter interval: The amount of time within which device should be connected.
/// - Parameter handler: The block to be called when the device is connected within timeout, or timeout occurs.
///
/// Currently, this is only used for LE peripherals.
- (void)waitForDeviceBeConnectedOf:(RTKProfileConnection *)connection
                           timeout:(NSTimeInterval)interval
                 completionHandler:(RTKLECompletionBlock)handler;


/// Stops waiting for connection event of connection which is previously waited.
- (void)cancelWaitForDeviceBeConnectedOf:(RTKProfileConnection *)connection;


/// Waits for a device to be disconnected for up to the specified timeout.
///
/// - Parameter connection: The connection which manages device that be waited for disconnection.
/// - Parameter interval: The amount of time within which device should be connected.
/// - Parameter handler: The block to be called when the device is disconnected within timeout, or timeout occurs.
- (void)waitForDeviceBeDisconnectedOf:(RTKProfileConnection *)connection
                              timeout:(NSTimeInterval)interval
                    completionHandler:(RTKLECompletionBlock)handler;


/// Stops waiting for disconnection event iof connection which is previously waited.
- (void)cancelWaitForDeviceBeDisconnectedOf:(RTKProfileConnection *)connection;

@end

NS_ASSUME_NONNULL_END
