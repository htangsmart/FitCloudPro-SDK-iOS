//
//  RTKOTAError.h
//  RTKLEFoundation
//
//  Created by jerome_gu on 2019/1/30.
//  Copyright © 2022 Realtek. All rights reserved.
//

#ifndef RTKOTAError_h
#define RTKOTAError_h

#import <Foundation/Foundation.h>

/// The domain for OTA errors.
extern NSErrorDomain const RTKOTAErrorDomain;

/// Error codes defined within `RTKOTAErrorDomain` domain.
typedef NS_ENUM(NSInteger, RTKOTAErrorCode) {
    // MARK: - deprecated error code begin
    RTKOTAErrorUnknown,                                     ///< Unknown error
    
    RTKOTAErrorCommunicationNotOpen,                        ///< Operation cannot be executed because of communication not open.
    
    RTKOTAErrorScaningBusy,                                 ///< There is a pending scan task, you may retry later.
    RTKOTAErrorScanForPeripheralTimeout,                    ///< Cannot discover a specific peripheral within a specific duration.
    
    RTKOTAErrorServiceNotDetermined,                        ///< Service (and containing characterisitc) is not discovered or not installed.
    
    RTKOTAErrorOTAInfoReadTimeOut,                          ///< Read OTA device information time out.
    
    RTKOTAErrorOTAServiceInconsistency,                     ///< The info readed from peripheral is inconsisitent, OTA upgrade can't be started.
    
    RTKOTAErrorOTAModePeripheralScanning,                   ///< Scan for peripheral in OTA mode fail.
    RTKOTAErrorPeripheralReconnection,                      ///< Reconnect to peripheral failed while upgrade silently.
    
    RTKOTAErrorDFUImageMismatch,                            ///< Image is not match with SOC
    ///
    RTKOTAErrorDFUDisconnectionWait,                        ///< Wait for LE disconnection failed during upgrade.
    
    RTKOTAErrorDFUConnParameterUpdateFailure,               ///< Connection Parameter Update Failed
    
    RTKOTAErrorAdvDataNotComplete,                          ///< Adv Data does not have enough info
    RTKOTAErrorDFUNoAvailableImage,
    RTKOTAErrorDFUUpgradeMethodUnavailable,
    RTKOTAErrorDFUSendImageVersion,                        ///< Send image version failed
    
    // MARK: - deprecated error code end
    
    
    RTKOTAErrorBluetoothNotAvailable,                       ///< Bluetooth service is not available currently.
    RTKOTAErrorImageVersionCharacteristic,                  ///< The image version characteristic configuration does not match  image indication.
    RTKOTAErrorDeviceBatteryLevelLow,                       ///< The device battery level is too low to upgrade.
    RTKOTAErrorGATTServiceConformance,                      ///< A specific GATT service is invalid or not exsit in device.
    RTKOTAErrorDeviceInfoLack,                              ///< No device info exist. Should get device information first.
    RTKOTAErrorServiceLack,                                 ///< Required service to perform task is not exist.
    
    // File parse errors
    RTKOTAErrorBinFileNotExist,                             ///< The specified file does not exist.
    RTKOTAErrorBinFileFormatInvalid,                        ///< The passed in bin file format is invalid.
    
    RTKOTAErrorUserCancelled,                               ///< User (app) canceled upgrade.
    RTKOTAErrorNoAvailableImage,                            ///< No availble images for upgrade.
    RTKOTAErrorImageMismatch,                               ///< Image is not match with SOC
    RTKOTAErrorImageOld,                                    ///< The images to upgrade cannot be older than device installed.
    
    /* Message exchange failure */
    RTKOTAErrorDFUGetImageInfo,                             ///< Get target image info failed.
    RTKOTAErrorDFUStartDFU,                                 ///< Send start DFU message failed.
    RTKOTAErrorDFUEnableBufferCheck,                        ///< Enable buffer check failed.
    RTKOTAErrorDFURequestReceiveFailure,                    ///< Request peripheral to receive image failed.
    RTKOTAErrorDFUImageSendFail,                            ///< Send image data failed.
    RTKOTAErrorDFUBufferCheckFail,                          ///< Buffer check failed.
    RTKOTAErrorDFUValidate,                                 ///< Image validate failed.
    RTKOTAErrorDFUActive,                                   ///< Image active failed.
    RTKOTAErrorDFUReset,                                    ///< Image reset failed.
    RTKOTAErrorDFUCopyImage,                                ///< Copy image failed. (used in dual bank)
    RTKOTAErrorDFUImageExistState,                          ///< Get image exist state failed.
    RTKOTAErrorDFUGetImageVersion,                          ///< Get image version failed.
    RTKOTAErrorDFUCheckKey,                                 ///<Check key failed.
    
    RTKOTAErrorRequestBusy,                                 ///< Already have a pending request.
    RTKOTAErrorNotRealRequest,                              ///< Not a request while call send request.
    
    RTKOTAErrorDeviceRespondOperationFail,                  ///< Device responds with code not success
    RTKOTAErrorDeviceInfoGetFail,                           ///< Can not retrieve device info.
    RTKOTAErrorDeviceAddressGetFail,                        ///< Can not retrieve device address
    
    RTKOTAErrorDeviceConnection,                            ///< Connect to device failed.
    RTKOTAErrorDeviceNotSupport,                            ///< This operation is not support.
    RTKOTAErrorDeviceBankInfoUnknown,                       ///< Can not process without bank info.
    RTKOTAErrorRequiredAttributeNotExist,                   ///< GATT attribute not exist for perform operation.
    RTKOTAErrorDeviceDataInvalid,                           ///< The data received from device is not valid.
    RTKOTAErrorAttributeReadFailure,                        ///< Wait for reading characteristic value time out.
    RTKOTAErrorOTAModeEnter,                                ///< Request device to switch to OTA mode fail.
    RTKOTAErrorIncorrectBud,                                ///< The currently connected bud to be upgraded is incorrect.
    
    RTKOTAErrorCompanionDiscovery,                          ///< Discover for companion device fail.
    RTKOTAInvalidCallException,                             ///< Invalid method call.
};

#endif /* RTKOTAError_h */
