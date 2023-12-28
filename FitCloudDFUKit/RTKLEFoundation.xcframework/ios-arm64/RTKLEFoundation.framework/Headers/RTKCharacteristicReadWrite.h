//
//  RTKCharacteristicReadWrite.h
//  RTKLEFoundation
//
//  Created by jerome_gu on 2019/1/10.
//  Copyright © 2022 Realtek. All rights reserved.
//
#import <CoreBluetooth/CoreBluetooth.h>

#ifdef RTK_SDK_IS_STATIC_LIBRARY
#import "RTKLEPeripheral.h"
#import "RTKPackageCommunication.h"
#import "RTKPeripheralCharacteristicOperation.h"
#else
#import <RTKLEFoundation/RTKLEPeripheral.h>
#import <RTKLEFoundation/RTKPackageCommunication.h>
#import <RTKLEFoundation/RTKPeripheralCharacteristicOperation.h>
#endif


NS_ASSUME_NONNULL_BEGIN

DEPRECATED_MSG_ATTRIBUTE("This class is only used for legacy compatibility. Use RTKCharacteristicTRXTransport class instead")
@interface RTKCharacteristicReadWrite : RTKPackageCommunication <RTKPeripheralCharacteristicRead, RTKPeripheralCharacteristicWrite>

- (instancetype)initWithPeripheral:(RTKLEPeripheral*)peripheral read:(nullable CBCharacteristic *)readCharacteristic write:(nullable CBCharacteristic *)writeCharacteristic;

@property (class, readonly) BOOL writeReliably;

@end

@interface RTKCharacteristicReadWriteWithoutResponse : RTKCharacteristicReadWrite

@end

@interface RTKCharacteristicReadWriteArbitrarily : RTKCharacteristicReadWrite

@end


NS_ASSUME_NONNULL_END
