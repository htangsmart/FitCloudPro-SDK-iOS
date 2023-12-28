//
//  RTKOTAProfile.h
//  RTKOTASDK
//
//  Created by jerome_gu on 2019/4/16.
//  Copyright © 2022 Realtek. All rights reserved.
//

#ifdef RTK_SDK_IS_STATIC_LIBRARY
#import "libRTKLEFoundation.h"
#import "RTKOTAPeripheral.h"
#import "RTKMultiDFUPeripheral.h"
#else
#import <RTKLEFoundation/RTKLEFoundation.h>
#import <RTKOTASDK/RTKOTAPeripheral.h>
#import <RTKOTASDK/RTKMultiDFUPeripheral.h>
#endif


NS_ASSUME_NONNULL_BEGIN


typedef NS_ENUM(uint8_t, RTKOTAAdvbud) {
    RTKOTAAdvbudSingle,
    RTKOTAAdvbudPrimary,
    RTKOTAAdvbudSecondary,
};


/**
 * A RTKOTAProfile object used for manage peripherals that are about to be upgraded.
 *
 * @discussion A RTKOTAProfile is a concrete subclass of RTKLEProfile, with APIs to create RTKOTAPeripheral instance and return RTKDFUPeripheral instances.
 *
 * To upgrade a remote device, you typically have a known CBPeripheral object represents a remote device to upgrade, call -instantiatePeripheralWithCBPeripheral: with the known CBPeripheral to get an RTKOTAPeripheral object.
 *
 *  Normal upgrade flow:
 *  1. Having an RTKOTAPeripheral instance which did be connected by RTKOTAProfile;
 *  2. Call @code -[RTKOTAProfile translatePeripheral:toDFUPeripheralWithCompletion:] @endcode to get a @c RTKDFUPeripheral instance to upgrade;
 *  3. Call @code -[RTKOTAProfile connectTo:] @endcode with  @c RTKDFUPeripheral instance retured in Step 2;
 *  4. When @c RTKOTAProfile report connection event, now you can start upgrade images by call @c RTKDFUPeripheral methods.
 *
 *   Silent upgrade flow:
 *   1. Having an RTKOTAPeripheral instance which did be connected by RTKOTAProfile;
 *   2. Call @code -[RTKOTAProfile DFUPeripheralOfOTAPeripheral:] @endcode with @c RTKOTAPeripheral object to return a @c RTKDFUPeripheral object for upgrade;
 *   3. Call @code -[RTKOTAProfile connectTo:] @endcode with  @c RTKDFUPeripheral instance retured in Step 2;
 *   4. When @c RTKOTAProfile report connection event, now you can start upgrade images by call @c RTKDFUPeripheral methods.
 */
DEPRECATED_MSG_ATTRIBUTE("This class is only used for legacy compatibility. Use RTKDFUUpgrade or RTKDFUManager class instead")
@interface RTKOTAProfile : RTKLEProfile

/// Instantiate OTAPeripheral from a known CBPeripheral object.
/// You typically already have a CBPeripheral to upgrade within your CBCentralManager.
- (nullable RTKOTAPeripheral*)OTAPeripheralFromCBPeripheral:(CBPeripheral *)peripheral DEPRECATED_MSG_ATTRIBUTE("use -instantiatePeripheralWithCBPeripheral: instead");

/**
 * Create and return an RTKDFUPeripheral object for silent upgrade.
 *
 * @note You still need to call @code -[RTKOTAProfile connectTo:] @endcode with the returned @c RTKDFUPeripheral object and wait for connection event, before you can start upgrade procedure.
 *
 * @returns A non-nil @c RTKDFUPeripheral object is returned if this peripheral support silent upgrade, otherwise nil is returned.
 */
- (nullable RTKDFUPeripheral*)DFUPeripheralOfOTAPeripheral:(RTKOTAPeripheral *)peripheral;


/// Synonymous with @c -[RTKOTAProfile @c connectTo:].
- (void)connectToDFUPeripheral:(RTKDFUPeripheral *)peripheral;


/**
 * Request the remote device transition to a dedicated upgrade running mode for normal upgrade.
 *
 * @discussion This is a asynchronous method. When the transition complete, the handler parameter get called with a RTKDFUPeripheral object.
 *
 * @note When handler get called with an @c RTKDFUPeripheral object., you still need to call @code -[RTKOTAProfile connectTo:] @endcode to start connection with it, before you can start upgrade procedure.
 */
- (void)translatePeripheral:(RTKOTAPeripheral*)peripheral toDFUPeripheralWithCompletion:(void(^)(BOOL success, NSError *_Nullable err, RTKDFUPeripheral *_Nullable peripheral))handler;


/**
 * Scan for companion peripheral of the passed in peripheral object.
 *
 * @discussion In cases of RWS earbuds,image upgrade involve upgrading two buds. When the first bud did finish upgrade, you call this method to discover the other bud. And if the second @c RTKOTAPeripheral instance is retrieved, you start upgrade it the same way as the first one.
 *
 * @note Only used for RWS upgrade.
 */
- (void)scanCompanionPeripheralOf:(RTKOTAPeripheral *)peripheral withCompletionHandler:(void(^)(BOOL success, NSError*_Nullable err, RTKOTAPeripheral *_Nullable targetPeripheral))handler;

@end



@interface RTKOTAProfile (Protect)

/* Protected */
- (void)_scanDFUPerpheralOf:(RTKOTAPeripheral*)peripheral withCompletion:(void(^)(BOOL success, NSError *_Nullable err, RTKDFUPeripheral *_Nullable peripheral))handler;

@end


NS_ASSUME_NONNULL_END
