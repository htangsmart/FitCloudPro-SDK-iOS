//
//  FitCloudGPSEpoTimestamp.h
//  FitCloudKit
//
//  Created by pcjbird on 7/21/23.
//  Copyright © 2023 Zero Status. All rights reserved.
//

#import <Foundation/Foundation.h>

/// GPS epo 时间戳
@interface FitCloudGPSEpoTimestamp : NSObject

/// 周数
@property(nonatomic, readonly) NSInteger weekNum;

/// 周余数，单位：秒
@property(nonatomic, readonly) NSInteger timeOfWeek;


///从 NSDate获取 GPS epo 时间戳
+ (FitCloudGPSEpoTimestamp* _Nullable) fromDate:(NSDate*_Nonnull) date;

///从 GPS Hours 获取 GPS epo 时间戳
+ (FitCloudGPSEpoTimestamp* _Nullable) fromGPSHours:(NSInteger) gpsHours;


///从 gps file 获取 GPS epo 时间戳
+ (FitCloudGPSEpoTimestamp*_Nullable) fromGPSFile:(NSString*_Nonnull) gpsFilePath;

/// 有效期
-(NSDate*_Nonnull)expireDate;

@end

