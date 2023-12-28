//
//  RTKMultiDFUPeripheral.h
//  RTKOTASDK
//
//  Created by jerome_gu on 2019/4/16.
//  Copyright © 2022 Realtek. All rights reserved.
//

#ifdef RTK_SDK_IS_STATIC_LIBRARY
#import "RTKDFUPeripheral.h"
#else
#import <RTKOTASDK/RTKDFUPeripheral.h>
#endif


NS_ASSUME_NONNULL_BEGIN

@class RTKOTAProfile;
@class RTKMultiDFUPeripheral;

/**
 * The RTKMultiDFUPeripheralDelegate protocol defines several methods additional to RTKDFUPeripheralDelegate to notify the send event.
 */
@protocol RTKMultiDFUPeripheralDelegate <RTKDFUPeripheralDelegate>
@optional
/// Tells the delegate that SDK will send a new image bytes.
- (void)DFUPeripheral:(RTKMultiDFUPeripheral *)peripheral willSendImage:(RTKOTAUpgradeBin *)image;

/// Tells the delegate that SDK did send an image bytes.
- (void)DFUPeripheral:(RTKMultiDFUPeripheral *)peripheral didSendImage:(RTKOTAUpgradeBin *)image;

/// Tells the delegate that SDK did activate several images.
- (void)DFUPeripheral:(RTKMultiDFUPeripheral *)peripheral didActiveImages:(NSArray<RTKOTAUpgradeBin*>*)images;

@end


/**
 * A subclass of RTKDFUPeripheral that can upgrade multiple images at a time.
 *
 * @discussion There are more than one upgrade method for multiple image upgrade. So SDK may upgrade one new image after the previous did active and reboot, or send multiple images to peripheral and active them all a time, it's determined by the peripheral capability.
 */
DEPRECATED_MSG_ATTRIBUTE("This class is only used for legacy compatibility. Use RTKDFUUpgrade class instead")
@interface RTKMultiDFUPeripheral : RTKDFUPeripheral

/**
 * The delegate object specified to receive peripheral events.
 */
@property (nonatomic, weak) id <RTKMultiDFUPeripheralDelegate> delegate;

/// The images in upgrading currently.
@property (readonly, nullable) NSArray <RTKOTAUpgradeBin*> *upgradeImages;

/**
 * Start upgrade with multiple images.
 *
 * @param yesOrNo If upgrade using normal upgrade procedure (OTA mode).
 *
 * @discussion RTKMultiDFUPeripheral object will call RTKMultiDFUPeripheralDelegate methods on delegate object to notify the sending event. When all images did complete upgrade or an error encoutered, -[RTKDFUPeripheralDelegate DFUPeripheral: didFinishWithError:] is called on delegate object.
 */
- (void)upgradeImages:(NSArray <RTKOTAUpgradeBin*> *)images inOTAMode:(BOOL)yesOrNo;

/// Set a new timeout value when wait for reconnect to peripheral before report a upgrade failue.
- (void)setReconnectTimeForSilent:(NSTimeInterval)timeout;

/**
 * Sort the files in the package
 * @discussion it is necassary to call this method before starting upgrade if pre_platform or pre_upperstack is included in the package, otherwise it is optional
 */
- (NSMutableArray *)reorderFiles:(NSArray <RTKOTAUpgradeBin*> *)images;
@end

NS_ASSUME_NONNULL_END
