//
//  RTKLEProfile.h
//  RTKLEFoundation
//
//  Created by jerome_gu on 2019/4/10.
//  Copyright © 2022 Realtek. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>

#ifdef RTK_SDK_IS_STATIC_LIBRARY
#import "RTKLEPeripheral.h"
#else
#import <RTKLEFoundation/RTKLEPeripheral.h>
#endif


NS_ASSUME_NONNULL_BEGIN

@class RTKLEProfile;


/**
 * The RTKLEProfileDelegate protocol defines methods that a delegate of a RTKLEProfile object must adopt to receive scan and connection events.
 */
@protocol RTKLEProfileDelegate <NSObject>
@required

/**
 * Invoked when the underlying central manager’s state did update.
 *
 * @param profile The profile that did find central manager state changed.
 * @discussion Commands should only be issued when the underlying central manager state is @c CBCentralManagerStatePoweredOn
 */
- (void)profileManagerDidUpdateState:(RTKLEProfile *)profile;

@optional

/**
 * Invoked when the Profile discovers a peripheral while scanning.
 *
 * @discussion Depend on the concrete Profile class, only interested peripheral is discovered. The discovered peripheral is typically a subclass of RTKLEPeripheral, which may provide more methods to operate with peripheral.
 */
- (void)profile:(RTKLEProfile *)profile didDiscoverPeripheral:(RTKLEPeripheral *)peripheral;


/**
 * Invoked when a connection is successfully created with a peripheral.
 *
 * @discussion You typically implement this method to perform specific operation.
 */
- (void)profile:(RTKLEProfile *)profile didConnectPeripheral:(RTKLEPeripheral *)peripheral;

/**
 * Invoked when the central manager fails to create a connection with a peripheral.
 *
 * @discussion Unlike the CBCentralManager, this connect methods of RTKLEProfile will time out. When connection time out, the error parameter has a RTKErrorTimeout code.
 */
- (void)profile:(RTKLEProfile *)profile didFailToConnectPeripheral:(RTKLEPeripheral *)peripheral error:(nullable NSError *)error;

/**
 * Invoked when an existing connection with a peripheral is torn down.
 */
- (void)profile:(RTKLEProfile *)profile didDisconnectPeripheral:(RTKLEPeripheral *)peripheral error:(nullable NSError *)error;

@end



/**
 * RTKLEProfile objects are used to manage scanning, connecting to peripherals.
 *
 * @discussion Before you call any methods, the underlying @c CBCentralManager object should be in @c CBManagerStatePoweredOn state.
 */
DEPRECATED_MSG_ATTRIBUTE("This class is only used for legacy compatibility. Use RTKProfileConnectionManager class instead")
@interface RTKLEProfile : NSObject <CBCentralManagerDelegate> {
    @protected
    CBCentralManager *_centralManager;
}

- (instancetype)initWithDelegate:(nullable id <RTKLEProfileDelegate>)delegate;

/**
 * The underlying central manager in use.
 */
@property (readonly) CBCentralManager *centralManager;


/**
 * The delegate that will receive scaning and connection events.
 */
@property (weak) id <RTKLEProfileDelegate> delegate;

/**
 * Internal use.
 */
@property (nullable, readonly) NSMutableArray <RTKLEPeripheral*> *managedPeripherals;

/**
 * Return a list of advertising service UUIDs which this RTKLEProfile is interested in.
 *
 * @discussion When in scaning, only discovered peripheral which is advertising specified services is reported.
 * This is a template method, which means you should override it in subclass. Default return nil.
 */
+ (nullable NSArray<CBUUID *> *)advertiseServiceUUIDs;

/**
 * The class used to create peripheral instance.
 *
 * @discussion This class should be a subclass of RTKLEPeripheral.
 */
+ (Class)concretePeripheralClass;


// Scan expected peripheral nearby.

/// Used internal.
@property (readonly) NSMapTable *scanedPeripherals;

/**
 *  Indicates whether is currently scanning.
 */
@property (readonly) BOOL isScaning;

/**
 * Scan for interested peripherals.
 *
 * @discussion RTKLEProfile only report scaned peripherals which pass some rule. A common rule check if the peripheral is advertising service specified by return value of -advertiseServiceUUIDs method.
 */
- (void)scanForPeripherals;

/**
 * Other than -scanForPeripherals, will report a scaned peripheral event each time it receive an advertisement.
 */
- (void)scanForPeripheralsWithDuplicateReport;

/**
 * Stop scaning.
 */
- (void)stopScan;


/* Deprecated */
/*
- (void)addPeripheral:(RTKLEPeripheral *)peripheral;
- (void)removePeripheral:(RTKLEPeripheral *)peripheral;
- (void)removeAllPeripherals;

- (void)touch:(RTKLEPeripheral *)peripheral;
*/

/**
 * Return all known RTKLEPeripheral instances  whose underlying CBPeripheral is equal to the peripheral passed in.
 */
- (NSArray <RTKLEPeripheral*> *)peripheralsUsingCBPeripheral:(CBPeripheral *)peripheral;

/**
 * Instantiate a RTKLEPeripheral object which have a underlying CBPeripheral equal to the pass in peripheral.
 * @discussion The return peripheral object is managed by the RTKLEProfile.
 */
- (nullable RTKLEPeripheral *)instantiatePeripheralWithCBPeripheral:(CBPeripheral *)peripheral;


/**
 * Returns a list of the RTK peripherals connected to the system whose services match the profile.
 */
- (NSArray <RTKLEPeripheral*> *)retrieveConnectedPeripherals;

@end



#define RTKDistantInterval 31536000.

@interface RTKLEProfile (Connection)

/**
 * Establishes a connection to a peripheral with 10s timeout interval.
 
 */
- (void)connectTo:(RTKLEPeripheral *)peripheral;

/**
 * Establishes a connection to a peripheral.
 * When connection estabilished successfully, its delegate -profile:didConnectPeripheral will be invoked. otherwise -profile:didFailToConnectPeripheral is invoked.
 */
- (void)connectTo:(RTKLEPeripheral *)peripheral withTimeout:(NSTimeInterval)timeout;

/**
 * Cancels an active or pending local connection to a peripheral.
 */
- (void)cancelConnectionWith:(RTKLEPeripheral *)peripheral;

/**
 * Cancels active or pending local connections to all peripheral.
 */
- (void)cancelAllPeripheralConnections;


/* Protected */
- (void)_connectTo:(RTKLEPeripheral *)peripheral withTimeout:(NSTimeInterval)timeout completionHandler:(nullable RTKLECompletionBlock)handler;
- (void)_cancelConnectionWith:(RTKLEPeripheral *)peripheral;

- (void)validatePeripheralAndOpen:(RTKLEPeripheral *)peripheral withCompletion:(RTKLECompletionBlock)handler;

@end

NS_ASSUME_NONNULL_END
