//
//  RTKCharacteristicOperate.h
//  RTKLEFoundation
//
//  Created by jerome_gu on 2021/11/2.
//  Copyright © 2022 Realtek. All rights reserved.
//

#ifndef RTKCharacteristicOperate_h
#define RTKCharacteristicOperate_h

#import <CoreBluetooth/CoreBluetooth.h>

NS_ASSUME_NONNULL_BEGIN

/// An interface for objects that receive characteristic readed value.
///
/// You register your protocol conforming object to an ``RTKConnectionUponGATT`` object. The ``RTKConnectionUponGATT`` object call methods to report readed value or report failure if characteristic value can not read.
@protocol RTKCharacteristicRead <NSObject>

/// Returns the characteristic which to be read.
@property (readonly) CBCharacteristic *readCharacteristic;

/// Called by an ``RTKConnectionUponGATT`` to notify that characteristic value is readed.
- (void)characteristicDidReadValue:(CBCharacteristic *)characteristic;

/// Called by an ``RTKConnectionUponGATT`` to notify that characteristic value can not be readed.
- (void)characteristicCannotReadValue:(CBCharacteristic *)characteristic withError:(NSError *)error;

@end


/// An interface for objects that receive characteristic value notification.
///
/// You register your protocol conforming object to an ``RTKConnectionUponGATT`` object. The `RTKConnectionUponGATT` object automatically enable the charactersitic notification, and call methods to report characteristic value notification result. When the characterisitc notification is enabled, the `RTKConnectionUponGATT` call method to notify about the notificaiton.
@protocol RTKCharacteristicNotificationRecept <NSObject>

/// Returns the characteristic from which to receive notification.
@property (readonly) CBCharacteristic *notifyCharacteristic;

/// Called by an `RTKConnectionUponGATT` to notify that characteristic notification state did change.
- (void)characteristicDidUpdateNotificationState:(CBCharacteristic *)characteristic;

/// Called by an `RTKConnectionUponGATT` to notify that characteristic notification state can not update.
- (void)characteristicDidFailToUpdateNotificationState:(CBCharacteristic *)characteristic withError:(NSError *)error;

/// Called by an `RTKConnectionUponGATT` to notify that characteristic value did update.
- (void)characteristicDidUpdateValue:(CBCharacteristic *)characteristic;

@end


/// An interface for objects that receive characteristic value write result.
///
/// You register your protocol conforming object to an `RTKConnectionUponGATT` object. If the characteristic is written with WriteWithResponse type, and write response did receive, the `RTKConnectionUponGATT` call method to notify about the result.
@protocol RTKCharacteristicWrite <NSObject>

/// Returns the characteristic that you want the write result.
@property (readonly) CBCharacteristic *writeCharacteristic;

/// Called by `RTKConnectionUponGATT` to notify that characteristic value dis write to new value.
- (void)characteristicDidWriteValue:(CBCharacteristic *)characteristic;

/// Called by `RTKConnectionUponGATT` to notify that characteristic value can not be wrote.
- (void)characteristicDidFailToWriteValue:(CBCharacteristic *)characteristic error:(NSError *)error;


/// Called by an `RTKConnectionUponGATT` to notify that the peripheral is ready again to write without response.
- (void)isReadyToWriteWithoutResponse;

@end


NS_ASSUME_NONNULL_END

#endif /* RTKCharacteristicOperate_h */
