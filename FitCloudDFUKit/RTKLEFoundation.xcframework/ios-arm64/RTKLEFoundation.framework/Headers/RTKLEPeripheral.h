//
//  RTKLEPeripheral.h
//  RTKLEFoundation
//
//  Created by jerome_gu on 2019/1/7.
//  Copyright © 2022 Realtek. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>

#ifdef RTK_SDK_IS_STATIC_LIBRARY
#import "RTKBTGeneralDefines.h"
#import "RTKPeripheralCharacteristicOperation.h"
#else
#import <RTKLEFoundation/RTKBTGeneralDefines.h>
#import <RTKLEFoundation/RTKPeripheralCharacteristicOperation.h>
#endif


typedef NS_ENUM(NSUInteger, RTKLEPeripheralValidState) {
    RTKLEPeripheralValidStateUnknown,
    RTKLEPeripheralValidStateEvaluating,
    RTKLEPeripheralValidStateInvalid,
    RTKLEPeripheralValidStateValid,
};


NS_ASSUME_NONNULL_BEGIN

@class RTKLEProfile;
@class RTKLEPeripheral;

/**
 * A protocol defines methods for a RTKLEPeripheralDelegate implemented object to receive pripheral events.
 *
 * @discussion This protocol only provides methods for reporting Name and RSSI update events, sub-protocols may define additional methods for report more events.
 */
@protocol RTKLEPeripheralDelegate <NSObject>
@optional
/**
 * Invoked when peripheral name updated.
 */
- (void)RTKPeripheralDidUpdateName:(RTKLEPeripheral *)peripheral;

/**
 * Invoked when peripheral RSSI updated.
 */
- (void)RTKPeripheralDidUpdateRSSI:(RTKLEPeripheral *)peripheral;

@end


/*!
 *  @class RTKLEPeripheral
 *  Realtek wrapper of CBPeripheral.
 *
 *  @discussion The CBPeer class is an abstract base class that defines common behavior for objects representing Realtek remote devices. Use this class for Realtek SDK context. Do not confuse with CBPeripheral.
 */
DEPRECATED_MSG_ATTRIBUTE("This class is only used for legacy compatibility. Use RTKConnectionUponGATT class instead")
@interface RTKLEPeripheral : NSObject <CBPeripheralDelegate> {
    @protected
    RTKLEPeripheralValidState _validState;
    CBPeripheral *_CBPeripheral;
}

/**
 * CoreBluetooth Peripheral instance related.
 */
@property (readonly, nonnull) CBPeripheral *CBPeripheral;

/**
 * Peripheral name. Identical to CBPeripheral.name
 */
@property (readonly, nullable) NSString *name;

/**
 * Designated initializer
 * @param peripheral The underlying CBPeripheral.
 */
- (instancetype)initWithCBPeripheral:(CBPeripheral *)peripheral profile:(RTKLEProfile *)profile;


@property (weak, nonatomic, nullable) id<RTKLEPeripheralDelegate> delegate;

/**
 * The peripheral advertisement data. Retrived when scan.
 */
@property (readonly, nullable) NSDictionary<NSString *, id> *advertisement;

/**
 * The last peripheral RSSI.
 * @discussion When RSSI monitoring is on going, this value is updated periodically.
 */
@property (readonly) NSInteger RSSI;

/**
 * Start monitor RSSI.
 */
- (void)startMonitorRSSI;

/**
 * Stop monitor RSSI.
 */
- (void)stopMonitorRSSI;

/**
 * The profile which this peripheral belong to.
 */
@property (nonatomic, weak, readonly) RTKLEProfile *profile;

@end


@interface RTKLEPeripheral(Validation)

/**
 * Indicate whether the peripheral conform Profile Service Spec. i.e have specified service & characterisitc.
 */
@property (readonly) RTKLEPeripheralValidState validState;

/**
 * The interval as a hint when wait for validate completion.
 * Default to 5 secound. The actual timeout interval may not be same with the passed value.
 */
@property (nonatomic) NSTimeInterval validateTimeoutInterval;

- (void)validateConformanceWithCompletion:(RTKLECompletionBlock)handler;

@end


@interface RTKLEPeripheral(Open)

/**
 * Whether peripheral is ready for operation.
 */
@property (readonly) BOOL isOpen;

- (void)openWithCompletion:(RTKLECompletionBlock)handler;
- (void)closeWithCompletion:(RTKLECompletionBlock)handler;

@end






@interface RTKLEPeripheral(Private)
- (void)_setScanAdvertisementData:(NSDictionary<NSString *, id> *)data;
- (void)_setScanRSSI:(NSInteger)rssi;
@end


/**
 * Interface related to ATT Discovery
 */
@interface RTKLEPeripheral(Discovery)

/**
 * Asynchronously discover Attribute(Service & Characteristics)
 * @param dict NSDictionary containing Service UUIDs and Characteristic UUIDs to discover. Example: @{@"000002FD-3C17-D293-8E48-14FE2E4DA212": @[@"FFE0", @"FFE1"]}
 * @param handler Invoked when all Service and Characteristics specified in dict discovered, or timeout error (5s).
 */
- (void)discoverCharacteristicsWithIDDictionary:(NSDictionary *)dict completionHandler:(void(^)(BOOL, NSError *_Nullable))handler;

- (void)discoverService:(NSString *)serviceID containingCharacteristics:(nullable NSArray <NSString*>*)characteristicIDs completionHandler:(void(^)(BOOL, NSError *_Nullable))handler;

- (void)discoverService:(NSString *)serviceID containingCharacteristics:(nullable NSArray <NSString*>*)characteristicIDs timeout:(NSTimeInterval)timeout completionHandler:(void(^)(BOOL, NSError *_Nullable))handler;

- (void)_clearDiscoveryCache;


- (nullable CBService *)serviceWithID:(NSString *)serviceID;

/**
 * Return the Characteristic already discovered.
 */
- (nullable CBCharacteristic *)characteristicOfID:(NSString *)charID inService:(NSString *)serviceID;



- (void)handleConnectionEvent;

- (void)handleDisconnectionEventWithError:(nullable NSError *)err;

@end


#pragma mark - Deprecated

/**
 * Add or remove Characteristic value event dispatch destination.
 */
@interface RTKLEPeripheral(CharacteristicReadWrite)
/* 注册Characteristic读和写的事件通知 */
- (void)registerCharacteristicReader:(id <RTKPeripheralCharacteristicRead>)reader;
- (void)unregisterCharacteristicReader:(id <RTKPeripheralCharacteristicRead>)reader;
- (void)registerCharacteristicWriter:(id <RTKPeripheralCharacteristicWrite>)writer;
- (void)unregisterCharacteristicWriter:(id <RTKPeripheralCharacteristicWrite>)writer;

@end

@interface RTKLEPeripheral (CBPeripheralDelegate)

- (void)addCBPeripheralDelegate:(id <CBPeripheralDelegate>)delegate;
- (void)removeCBPeripheralDelegate:(id <CBPeripheralDelegate>)delegate;

@end


NS_ASSUME_NONNULL_END
