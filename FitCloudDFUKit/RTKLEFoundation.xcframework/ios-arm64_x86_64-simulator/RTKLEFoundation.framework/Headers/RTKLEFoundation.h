//
//  RTKLEFoundation.h
//  RTKLEFoundation
//
//  Created by jerome_gu on 2019/1/7.
//  Copyright © 2022 Realtek. All rights reserved.
//
#import <Foundation/Foundation.h>

//! Project version number for RTKLEFoundation.
FOUNDATION_EXPORT double RTKLEFoundationVersionNumber;

//! Project version string for RTKLEFoundation.
FOUNDATION_EXPORT const unsigned char RTKLEFoundationVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <RTKLEFoundation/PublicHeader.h>

#import <RTKLEFoundation/RTKBTGeneralDefines.h>

#import <RTKLEFoundation/RTKProfileConnectionManager.h>
#import <RTKLEFoundation/RTKProfileConnection.h>
#import <RTKLEFoundation/RTKConnectionUponGATT.h>
#import <RTKLEFoundation/RTKConnectionUponiAP.h>
#import <RTKLEFoundation/RTKOperationWaitor.h>
#import <RTKLEFoundation/RTKCharacteristicOperate.h>
#import <RTKLEFoundation/RTKCharacteristicTRXTransport.h>

#import <RTKLEFoundation/RTKPacket.h>
#import <RTKLEFoundation/RTKPacketTransport.h>

#import <RTKLEFoundation/RTKActionAttempt.h>

#import <RTKLEFoundation/RTKPackageIDGenerator.h>
#import <RTKLEFoundation/RTKBTLogMacros.h>
#import <RTKLEFoundation/RTKError.h>

#import <RTKLEFoundation/RTKAccessorySessionTransport.h>

#import <RTKLEFoundation/RTKBatchDataSendReception.h>

/* UI */
//#import <RTKLEFoundation/RTKScanPeripheralViewController.h>

//#import <RTKLEFoundation/RTKFile.h>
//#import <RTKLEFoundation/RTKFileBrowseViewController.h>

/* Utilities */

#import <RTKLEFoundation/NSData+KKAES.h>
#import <RTKLEFoundation/NSData+CRC16.h>
#import <RTKLEFoundation/NSData+String.h>
#import <RTKLEFoundation/NSData+Generation.h>

#import <RTKLEFoundation/RTKProvisioningProfileExpirationCheck.h>

// Legacy APIs,
// deprecated, not recommended for new usage
#import <RTKLEFoundation/RTKLEPeripheral.h>
#import <RTKLEFoundation/RTKLEProfile.h>

#import <RTKLEFoundation/RTKPeripheralCharacteristicOperation.h>
#import <RTKLEFoundation/RTKLEPackage.h>
#import <RTKLEFoundation/RTKPackageCommunication.h>
#import <RTKLEFoundation/RTKCharacteristicReadWrite.h>
#import <RTKLEFoundation/RTKCommunicationDataReceiver.h>
#import <RTKLEFoundation/RTKCommunicationDataSender.h>

#import <RTKLEFoundation/RTKAttemptAction.h>

#import <RTKLEFoundation/RTKPackageIDGenerator.h>

#import <RTKLEFoundation/RTKAccessoryManager.h>
#import <RTKLEFoundation/RTKAccessory.h>
