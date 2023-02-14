//
//  FitCloudManufacturer.h
//  FitCloudKit
//
//  Created by pcjbird on 2023/2/14.
//  Copyright © 2023 Zero Status. All rights reserved.
//

#import <Foundation/Foundation.h>


/**
 * @brief FitCloud 厂商信息
 */
@interface FitCloudManufacturer : NSObject

+ (instancetype _Nullable)new NS_UNAVAILABLE;
- (instancetype _Nullable)init NS_UNAVAILABLE;

/**
 * @brief mac地址
 */
@property(nonatomic, strong, readonly) NSString* _Nullable macAddr;

/**
 * @brief 是否为下一代厂商名称
 */
@property(nonatomic, readonly) BOOL nextManufacturerName;

/**
 * @brief 是否允许同时连接通话蓝牙
 */
@property(nonatomic, readonly) BOOL allowConnectWithBT;


/**
 * @brief 从广播数据获取厂商信息
 * @param advertisementData 广播数据
 * @return FitCloud 厂商信息, 如果不是FitCloud设备返回nil
 */
+(FitCloudManufacturer* _Nullable) manufacturerWithAdvertisementData:(NSDictionary* _Nonnull)advertisementData;

@end

