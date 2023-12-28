//
//  RTKDFUPeripheral.h
//  RTKOTASDK
//
//  Created by jerome_gu on 2019/4/16.
//  Copyright © 2022 Realtek. All rights reserved.
//

#ifdef RTK_SDK_IS_STATIC_LIBRARY
#import "libRTKLEFoundation.h"
#import "RTKOTAPeripheral.h"
#import "RTKOTAUpgradeBin.h"
#else
#import <RTKLEFoundation/RTKLEFoundation.h>
#import <RTKOTASDK/RTKOTAPeripheral.h>
#import <RTKOTASDK/RTKOTAUpgradeBin.h>
#endif


/*!
 * Values represents the phase during a image upgrade.
 */
typedef enum : NSUInteger {
    RTKDFUPhaseNone,                ///< The peripheral is not upgrading.
    RTKDFUPhaseSending,             ///< The peripheral is receiving image bytes.
    RTKDFUPhaseActivating,          ///< The peripheral is activating received images for execute later.
    RTKDFUPhaseResetting,           ///< The peripehral is resetting. Usual happened after an upgrade error encountered.
    RTKDFUPhaseCanceling,           ///< The peripheral is canceling upgrade.
    RTKDFUPhaseReconnecting,        ///< App is reconnecting to peripheral in order to send more images.
    RTKDFUPhaseEncounterError,      ///< Upgrade is broken down for error encountered.
    RTKDFUPhaseCanceled,            ///< Upgrade is canceled.
} RTKDFUPhase;


NS_ASSUME_NONNULL_BEGIN


@class RTKDFUPeripheral;

/**
 * @protocol RTKDFUPeripheralDelegate
 *
 * RTKDFUPeripheralDelegate defines additional methods for report progress when upgrading.
 *
 * @discussion The protocol also defines methods for delegate to control upgrade behavior.
 */
@protocol RTKDFUPeripheralDelegate <RTKLEPeripheralDelegate>
@required

/**
 * Tell the delegate that upgrade did complete successfully or unsuccessfully.
 *
 * @param peripheral The peripheral current in upgrade.
 * @param err  The reason when upgrade failed.
 * @discussion Upgrade succeed or not can be determined by check if error is nil.
 */
- (void)DFUPeripheral:(RTKDFUPeripheral *)peripheral didFinishWithError:(nullable NSError *)err;

@optional

/**
 * Tell the delegate that the image sending progress did changed.
 *
 * @param peripheral The peripheral current in upgrade.
 * @param length The byte size of current upgrading image did send to remote device.
 * @param totalLength The totoal byte size of current upgrading image to send to remote device.
 * @discussion The totalLength size may not equal to image file size.
 */
- (void)DFUPeripheral:(RTKDFUPeripheral *)peripheral didSend:(NSUInteger)length totalToSend:(NSUInteger)totalLength;

/**
 * Ask the delegate whether active image when finish send image bytes.
 *
 * @param peripheral The peripheral current in upgrade.
 * @discussion In general, if all image bytes send to remote device, SDK will active image to make it available for next boot. If you want to delay activating image, implement this method and return NO. If return NO, @c -sendActiveResetToNormalMessage should be call later to complete upgrade flow, otherwise the behaviour is undefined.
 */
- (BOOL)DFUPeripheralShouldActiveImageWhenCompleteSend:(RTKDFUPeripheral *)peripheral;

- (BOOL)DFUPeripheral:(RTKDFUPeripheral *)peripheral shouldWaitForDisconnectionOnCompleteSend:(RTKOTAUpgradeBin *)image DEPRECATED_MSG_ATTRIBUTE("use -DFUPeripheralShouldWaitForDisconnectionAfterActiveImage: instead");

/**
 * Ask the delegate wether wait for LE disconnection with the device before call -DFUPeripheral:didFinishWithError: method.
 *
 * @discussion Delegate should return NO if want -DFUPeripheral:didFinishWithError: method get called immediately after active image. default is YES
 */
- (BOOL)DFUPeripheralShouldWaitForDisconnectionAfterActiveImage:(RTKDFUPeripheral *)peripheral;

@end



@class RTKOTAProfile;

/**
 * @class RTKDFUPeirpheral
 * Represents a remote device is about to upgrade firmware.
 *
 * @discussion
 * The \c RTKDFUPeirpheral class provides programatic intefaces for start or cancel firmware upgrade. Instead of creating a RTKDFUPeripheral object manually, it's better to retrieve a instance by call \c RTKOTAProfile methods. Before start upgrade (e.g. \c -upgradeImage:), you should call the \code [RTKOTAProfile connectTo:] \endcode and pass this \c RTKDFUPeripheral instance and wait for connection event. RTKDFUPeirpheral object will call \c RTKDFUPeripheralDelegate protocol methods on delegate to report progress update and completion event.
 *
 * @see RTKOTAPeripheral
 */
DEPRECATED_MSG_ATTRIBUTE("This class is only used for legacy compatibility. Use RTKDFUUpgrade class instead")
@interface RTKDFUPeripheral : RTKLEPeripheral {
    @protected
    RTKOTAUpgradeBin *_upgradingImage;
}

/**
 * The delegate object specified to receive upgrade events.
 */
@property (nonatomic, weak) id <RTKDFUPeripheralDelegate> delegate;

/**
 * Return a RTKOTAPeripheral object which has APIs exposes OTA related information of the remote device.
 */
@property (nonatomic, readonly) RTKOTAPeripheral *OTAPeripheral;

/**
 * The current phase of upgrade task.
 */
@property (nonatomic, readonly) RTKDFUPhase phase;

/**
 * The image which peripheral is upgrading currently.
 *
 * @discussion Return nil if upgrade is not in progress.
 */
@property (readonly, nullable) RTKOTAUpgradeBin *upgradingImage;

/**
 * Set key for encryption when upgrade.
 *
 * @discussion If not set, a default key is used.
 */
- (void)setEncryptKey:(NSData * _Nonnull)encryptKey;


- (instancetype)initWithCBPeripheral:(CBPeripheral *)peripheral OTAPeripheral:(nullable RTKOTAPeripheral *)OTAPeri profile:(RTKOTAProfile *)profile;

/**
 * Start firmware upgrade with a image object.
 */
- (void)upgradeImage:(RTKOTAUpgradeBin *)image includedInImages:(NSArray <RTKOTAUpgradeBin*> *)images;

/**
 * Cancel ongoing upgrade.
 */
- (void)cancelUpgrade;

/**
 * Set to change the retry number on buffer check fail.
 *
 * @discussion Default value is 2.
 */
@property (nonatomic) NSUInteger retryCountWhenBufferCheckFail;

/**
 * Set Channel Connection Parameters.
 *
 * @discussion Unit: ms
 */
-(void)setConnectionParametersWithMinInterval:(uint16_t)intervalMin maxInterval:(uint16_t)intervalMax latency:(uint16_t)latency supervisionTimeout:(uint16_t)timeout;


/**
 * Used in a particular case.
 */
- (void)sendActiveResetToNormalMessage;

@end

NS_ASSUME_NONNULL_END
