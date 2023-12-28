//
//  RTKOTAPeripheral.h
//  RTKOTASDK
//
//  Created by jerome_gu on 2019/4/16.
//  Copyright © 2022 Realtek. All rights reserved.
//

#ifdef RTK_SDK_IS_STATIC_LIBRARY
#import "libRTKLEFoundation.h"
#import "RTKOTADeviceInfo.h"
#import "RTKOTAInstalledBin.h"
#else
#import <RTKLEFoundation/RTKLEFoundation.h>
#import <RTKOTASDK/RTKOTADeviceInfo.h>
#import <RTKOTASDK/RTKOTAInstalledBin.h>
#endif

NS_ASSUME_NONNULL_BEGIN

@class RTKOTAPeripheral;

/**
 * @protocol RTKOTAPeripheralDelegate
 *
 * RTKOTAPeripheralDelegate define methods to notify information determination event.
 */
@protocol RTKOTAPeripheralDelegate <RTKLEPeripheralDelegate>

/**
 * Invoked when RTKOTAClient has determined information about OTA.
 */
- (void)OTAPeripheral:(RTKOTAPeripheral *)peripheral didDetermineInfoWithError:(nullable NSError*)error;

@end


/**
 * @class RTKOTAPeripheral
 *
 * Represents a remote LE device, exposing OTA upgrade related information.
 *
 * @discussion An @c RTKOTAPeripheral object exposes information(i.e. BDAddress) about a LE device which is able to be DFU upgraded. You get information of installed binarys by @c bins property, which provide image type and version info.
 * To determine whether the remote device can be upgraded in normal mode, you call @c -canEnterOTAMode. And if silent upgrade can be used can be determined by @c -canUpgradeSliently.
 *
 * This class does not provide methods to start upgrade procudure, it's a responsibility of a @c DFUPeripehral object. Call @code -[RTKOTAProfile translatePeripheral:toDFUPeripheralWithCompletion:] @endcode to get a DFUPeripheral for normal upgrade, and call @code -[RTKOTAProfile DFUPeripheralOfOTAPeripheral:] @endcode to get a DFUPeripheral for silent upgrade.
 *
 * @note All methods and properties of this class are available only when @c RTKOTAPeripheral object is connected to RTKOTAProfile.
 *
 * @see RTKDFUPeripheral
 */
DEPRECATED_MSG_ATTRIBUTE("This class is only used for legacy compatibility. Use RTKDFUUpgrade or RTKDFURoutine class instead")
@interface RTKOTAPeripheral : RTKLEPeripheral


/**
 * Indicates if the remote device information has determined.
 *
 * @discussion Other APIs should not be called if the value is NO. A success connection by call <code>-[RTKOTAProfile connectTo:]</code> will set this value to YES.
 */
@property (readonly) BOOL infoSettled;

/// Not available
@property (readonly) BOOL isBBpro;

/**
 * The delegate object specified to receive peripheral events.
 */
@property (nonatomic, weak) id <RTKOTAPeripheralDelegate> delegate;

/// The version number which the remote device implemented.
@property (readonly) NSUInteger OTAVersion;

/// @warning Not available
@property (readonly) NSUInteger securityVersion;

/**
 * Return the BDAddress value of this device.
 */
@property (readonly) BDAddressType bdAddress;

/**
 * Return the BDAddress of the companion device.
 *
 * @discussion If the remote device have a companion device, this value return the companion device @b BDAddress. If does not, return a zero value.
 */
@property (readonly) BDAddressType pairedBDAddress;

/// The version of Application image type in remote device.
/// @warning Not available in newer implementation.
@property (readonly) uint16_t appVersion;

/// The version of Patch image type in remote device.
/// @warning Not available in newer implementation.
@property (readonly) uint16_t patchVersion;

/// The Link Key of the LE Connection with remote device.
/// @warning Not available in newer implementation.
@property (readonly, nullable) NSString *linkKey;

/// The memory size used for temp buffer.
@property (readonly) NSUInteger tempBufferSize;

/// The bank used currently.
/// @discussion Return @b RTKOTABankTypeBank0 or @b RTKOTABankTypeBank1 when dual-bank feature is supported, otherwise @b RTKOTABankTypeSingle is returned.
@property (readonly) RTKOTABankType activeBank;

/// The used bank of Application image type in remote device.
/// @warning Not available in newer implementation.
@property (readonly) NSUInteger appFreeBank;

/// The used bank of Application image type in remote device.
/// @warning Not available in newer implementation.
@property (readonly) NSUInteger patchFreeBank;

/// Indicates whether buffer check is supported on the remote device .
@property (readonly) BOOL bufferCheckEnable;

/// Indicates whether AES encryption is supported on the remote device .
@property (readonly) BOOL AESEnable;

/// The encryption mode used when sending image.
@property (readonly) RTKOTAImageDataEncryptionMethod encryptionMode;

/// Indicate whether Copy image is supported.
@property (readonly) BOOL copyImage;

/// Indicate whether Upgrade multiple images is supported.
@property (readonly) BOOL updateMultiImages;

/// Indicates whether this peripheral is a one bud of RWS bud
@property (readonly) BOOL isRWS;

/// Indicates which bud type the remote device is.
@property (readonly) RTKOTAEarbud budType;

/// Indicates whether the device is in engaged with companion device.
@property (readonly) BOOL notEngaged;

/// Indicate whether this peripheral have received images right now, but not active.
@property (readonly) BOOL upgradedCurrently;

/// For SDK internal use.
@property (readonly) uint32_t imageIndicator;

/// For SDK internal use.
//@property (readonly) RTKOTAProtocolType protocolType;
@property (readonly) uint16_t protocolType;

/**
 * Return a list of image binary informations resides in remote device.
 *
 * @discussion Use this property to get  a knowledge of binarys installed in the device, such as image type and version.
 */
@property (readonly) NSArray <RTKOTAInstalledBin*> *bins;

/**
 * Indicates whether the device can upgrade using normal upgrade procedure.
 *
 * @discussion If this value is YES, call @c -enterOTAMode to make the device transition to a running mode dedicated to Upgrade.
 */
@property (readonly) BOOL canEnterOTAMode;

/**
 * Indicates whether the device can upgrade using silent upgrade procedure.
 *
 * @discussion If this value is @c YES, DFU upgrade can be start in current runing mode.  Call @code -[RTKOTAProfile DFUPeripheralOfOTAPeripheral] @endcode to obtain a @c RTKDFUPeripheral instance for Upgrade.
 */
@property (readonly) BOOL canUpgradeSliently;


/**
 * Request peripheral to make a transition to OTA runing mode.
 *
 * @discussion Typically, you should not call this method to start a transition. Instead, call @code -[RTKOTAProfile translatePeripheral:toDFUPeripheralWithCompletion:] @endcode to start the transition.
 */
- (void)enterOTAMode;

/**
 * Indicates whether the device can upgrade VP. (For AT)
 *
 * @discussion If this value is YES,  you could set  @c isVPMode.
 */
@property (readonly) BOOL canUpdateVP;

/**
 * Request peripheral to upgrade in VP mode.
 *
 * @discussion You should set it after OTAPeripheral information has been parsed.
 */
@property (nonatomic) BOOL isVPMode;

@end



@interface RTKOTAPeripheral (DualBank)

/**
 * Return a list of inactive image binary informations resides in remote device.
 *
 * @discussion @c inactiveBins represents a list of images which is not in use currently.
 */
@property (readonly, nullable) NSArray <RTKOTAInstalledBin*> *inactiveBins;

@end


NS_ASSUME_NONNULL_END
