//
//  SkyworthPVPowerStationObject.h
//  FitCloudKit
//
//  Created by pcjbird on 5/31/23.
//  Copyright © 2023 Zero Status. All rights reserved.
//

#import <Foundation/Foundation.h>

/// 创维光伏电站
@interface SkyworthPVPowerStationObject : NSObject

/// 电站序号(编号)
@property(nonatomic, readonly) NSInteger stationNo;

/// 站点名称
@property(nonatomic, readonly, strong) NSString* _Nullable stationName;

/// 数据是否有效
@property(nonatomic, readonly) BOOL valid;

/// 是否故障
@property(nonatomic, readonly) BOOL isFaulty;

/// 今日发电量，数据为实际当日发电量乘以十的结果
@property(nonatomic, readonly) NSInteger todayEnergyOutput;

/// 累计发电量，数据为实 际累计发 电量乘以十的结果
@property(nonatomic, readonly) NSInteger totalEnergyOutput;

/// 等效植树（一种环保行为，表示通过其他方式代替植树所起到的环境保护作用）
@property(nonatomic, readonly) NSInteger equivalentPlanting;

/// 站长
@property(nonatomic, readonly, strong) NSString* _Nullable stationMaster;

/// 更新时间
@property(nonatomic, readonly, strong) NSDate* _Nullable lastUpdate;

+ (instancetype _Nullable)new NS_UNAVAILABLE;
- (instancetype _Nullable)init NS_UNAVAILABLE;

/// 创建光伏电站
/// - Parameters:
///   - stationNo: 电站序号(编号)
///   - stationName: 站点名称，最长36字节，超过自动截断
///   - valid: 数据是否有效
///   - isFaulty: 是否故障
///   - todayEnergyOutput: 今日发电量, 单位：度数,  最多支持1位小数
///   - totalEnergyOutput: 累计发电量, 单位：度数,  最多支持1位小数
///   - equivalentPlanting: 等效植树（一种环保行为，表示通过其他方式代替植树所起到的环境保护作用）
///   - stationMaster: 站长，最长12字节，超过自动截断
///   - lastUpdate: 最后跟新时间
/// - Returns: 光伏电站
+(SkyworthPVPowerStationObject*_Nonnull) withStationNo:(NSInteger)stationNo stationName:(NSString*_Nonnull)stationName valid:(BOOL)valid isFaulty:(BOOL)isFaulty todayEnergyOutput:(CGFloat)todayEnergyOutput totalEnergyOutput:(CGFloat)totalEnergyOutput equivalentPlanting:(NSInteger)equivalentPlanting stationMaster:(NSString*_Nonnull)stationMaster lastUpdate:(NSDate*_Nonnull)lastUpdate;

@end


