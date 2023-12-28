//
//  FitCloudGPSData.h
//  FitCloudKit
//
//  Created by pcjbird on 7/20/23.
//  Copyright © 2023 Zero Status. All rights reserved.
//

#import <Foundation/Foundation.h>

/// GPS数据
@interface FitCloudGPSData : NSObject

/// 时区，示例：东8区为 8， 西8区为 -8
@property(nonatomic, readonly) NSInteger timezone;

/// 经度    东为正，西为负
@property(nonatomic, readonly) Float32 longitude;

/// 纬度   东为正，西为负
@property(nonatomic, readonly) Float32 latitude;

+ (instancetype _Nullable)new NS_UNAVAILABLE;
- (instancetype _Nullable)init NS_UNAVAILABLE;


/// 初始化 GPS数据
/// - Parameters:
///   - longtitude: 经度，东为正，西为负
///   - latitude: 纬度，东为正，西为负
///   - timezone: 时区，示例：东8区为 8， 西8区为 -8
+(FitCloudGPSData*_Nullable) dataWithLongitude:(Float32)longtitude latitude:(Float32)latitude timezone:(NSInteger)timezone;

@end

