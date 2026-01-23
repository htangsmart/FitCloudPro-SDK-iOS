//
//  FitCloudKitConnectRecord.h
//  FitCloudKit
//
//  Created by pcjbird on 2018/8/2.
//  Copyright © 2018 年 Zero Status. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <FitCloudKit/FitCloudSecureCoding.h>

NS_ASSUME_NONNULL_BEGIN

/// A record of watch connection and pairing information
@interface FitCloudKitConnectRecord : NSObject <FitCloudSecureCoding, NSCopying>

/// The name of the watch
@property(nonatomic, strong) NSString *name;

/// Whether it uses next generation manufacturer name
@property(nonatomic, assign) BOOL isNextManufacturerName;

/// Whether to allow simultaneous connection with Bluetooth calling
@property(nonatomic, assign) BOOL allowConnectWithBT;

/// The UUID of the watch
@property(nonatomic, strong, nullable) NSUUID *uuid;

/// The MAC address of the watch. Returns nil if manufacturer has custom advertisement data
@property(nonatomic, strong, nullable) NSString *macAddr;

/// The device product type,  defined by `FitCloudDeviceProductType`
@property(nonatomic, strong, nullable) NSNumber* productType;

/// the device chip vendor, defined by 'FITCLOUDCHIPVENDOR'
@property(nonatomic, strong, nullable) NSNumber* chipVendor;

/// The last connection time
@property(nonatomic, strong) NSDate *lastConnectTime;

/// Whether the watch should automatically reconnect
@property(nonatomic, assign) BOOL shouldAutoReconnect;

/// The bound user ID
@property(nonatomic, strong, nullable) NSString *bindUserId;

/// The time when user binding occurred
@property(nonatomic, strong, nullable) NSDate *userBindTime;

/// Whether the watch has been unbound
@property(nonatomic, assign) BOOL isAlreadyUnbind;

/// The project number
/// - Returns:
/// The project number string, e.g. "51B2"
@property(nonatomic, strong, nullable) NSString *formatedProjNo;

/// Short firmware version
/// - Returns:
/// Short firmware version string, e.g. "1.08"
@property(nonatomic, strong, nullable) NSString *formatedFirmwareVersion;

/// The UI version
@property(nonatomic, strong, nullable) NSString *uiVersion;

/// The screen resolution
@property(nonatomic, strong, nullable) NSValue *screenResolution;

/// The screen shape
/// - 0: Rectangle
/// - 1: Circle
/// - nil: Unknown
@property(nonatomic, strong, nullable) NSNumber *screenShape;

/// The manufacturer data from advertisement data
@property(nonatomic, strong, nullable) NSString *advDataManufacturerData;

/// The advertisement data
@property(nonatomic, strong, nullable) NSString *advData;

/// The user-specified AI conversation model
/// - Returns: A numeric value representing the AI conversation model type as defined in FITCLOUDAICONVERSATIONMODEL.
///           When nil or FITCLOUDAICONVERSATIONMODEL_UNSPECIFIED is returned, it indicates no specific model has been set.
@property(nonatomic, strong, nullable) NSNumber *specifiedAiConversationModel;

/// The user-specified AI agent for advertisement flash
/// - Returns: A numeric value representing the AI agent type for advertisement flash.
///           When nil, it indicates no specific agent has been set.
@property(nonatomic, strong, nullable) NSNumber *specifiedAdFlashAiAgent;

@end

NS_ASSUME_NONNULL_END
