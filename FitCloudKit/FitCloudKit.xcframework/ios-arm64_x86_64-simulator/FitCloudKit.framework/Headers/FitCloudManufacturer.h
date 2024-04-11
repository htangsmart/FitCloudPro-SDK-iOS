//
//  FitCloudManufacturer.h
//  FitCloudKit
//
//  Created by pcjbird on 2023/2/14.
//  Copyright © 2023 Zero Status. All rights reserved.
//

#import <Foundation/Foundation.h>

/// FitCloud 厂商信息
@interface FitCloudManufacturer : NSObject

/// mac地址，如果厂商自定义了广播数据，这里返回nil
@property(nonatomic, strong, readonly, nullable) NSString* macAddr;

/// 是否为下一代厂商名称
@property(nonatomic, readonly) BOOL nextManufacturerName;

/// 是否允许同时连接通话蓝牙
@property(nonatomic, readonly) BOOL allowConnectWithBT;

/// 厂商是否自定义了广播数据
@property(nonatomic, readonly) BOOL isCustomizedAdvData;

/// 从广播数据获取厂商信息
/// - Parameters:
///   - advertisementData: 广播数据
/// - Returns:
///  FitCloud 厂商信息, 如果不是FitCloud设备返回nil
+(FitCloudManufacturer* _Nullable) manufacturerWithAdvertisementData:(NSDictionary* _Nonnull)advertisementData;


+ (instancetype _Nullable)new NS_UNAVAILABLE;
- (instancetype _Nullable)init NS_UNAVAILABLE;

@end

