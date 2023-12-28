//
//  RTKPeripheralCharacteristicOperation.h
//  RTKLEFoundation
//
//  Created by jerome_gu on 2019/1/7.
//  Copyright © 2022 Realtek. All rights reserved.
//

#ifndef RTKPeripheralCharacteristicOperation_h
#define RTKPeripheralCharacteristicOperation_h

#import <CoreBluetooth/CoreBluetooth.h>

NS_ASSUME_NONNULL_BEGIN

DEPRECATED_MSG_ATTRIBUTE("This protocol is only used for legacy compatibility. Use RTKCharacteristicRead or RTKCharacteristicNotificationRecept instead")
@protocol RTKPeripheralCharacteristicRead <NSObject>
@property (readonly, nonatomic) CBCharacteristic *readCharacteristic;
- (void)didUpdateValueForCharacteristic:(CBCharacteristic *)characteristic;
- (void)didUpdateNotificationStateForCharacteristic:(CBCharacteristic *)characteristic;
@end

DEPRECATED_MSG_ATTRIBUTE("This protocol is only used for legacy compatibility. Use RTKCharacteristicWrite instead")
@protocol RTKPeripheralCharacteristicWrite <NSObject>
@property (readonly, nonatomic) CBCharacteristic *writeCharacteristic;
- (void)didWriteValueForCharacteristic:(CBCharacteristic *)characteristic error:(nullable NSError *)error;
@end


NS_ASSUME_NONNULL_END

#endif /* RTKPeripheralCharacteristicOperation_h */
