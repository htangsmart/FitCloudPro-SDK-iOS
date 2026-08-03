//
//  FitCloudManufacturer.h
//  FitCloudKit
//
//  Created by pcjbird on 2023/2/14.
//  Copyright © 2023 Zero Status. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// Manufacturer information.
@interface FitCloudManufacturer : NSObject

/// MAC address. Returns `nil` if the manufacturer customized the advertisement data.
@property(nonatomic, strong, readonly, nullable) NSString* macAddr;

/// Whether the manufacturer name is a next-generation one.
@property(nonatomic, readonly) BOOL isNextManufacturerName;

/// Whether simultaneous connection with call Bluetooth is allowed.
@property(nonatomic, readonly) BOOL allowConnectWithBT;

/// Whether the manufacturer customized the advertisement data.
@property(nonatomic, readonly) BOOL isCustomizedAdvData;

/// Main project number.
@property(nonatomic, strong, nullable, readonly) NSString* mainProjNo;

/// Sub-project number.
@property(nonatomic, strong, nullable, readonly) NSString* subProjNo;

/// Retrieves manufacturer information from the specified advertisement data.
/// - Parameters:
///   - advertisementData: The advertisement data dictionary containing manufacturer information.
/// - Returns:
///   A `FitCloudManufacturer` instance if the device is a FitCloud device, or `nil` otherwise.
+(FitCloudManufacturer* _Nullable) manufacturerWithAdvertisementData:(NSDictionary* _Nonnull)advertisementData;


+ (instancetype _Nullable)new NS_UNAVAILABLE;
- (instancetype _Nullable)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END

