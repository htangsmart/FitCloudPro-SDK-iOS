//
//  FitCloudVibrateSetting.h
//  FitCloudKit
//
//  Created by pcjbird on 2021/8/24.
//  Copyright © 2021 Zero Status. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * @brief 振动设置
 */
@interface FitCloudVibrateSetting : NSObject<NSCoding>

/**
 * @brief 当前震动百分比
 */
@property(nonatomic, assign) UInt8 currentVibrate;

/**
 * @brief 振动支持的档位个数，如果为0，则不支持该设置，隐藏该设置
 */
@property(nonatomic, assign) UInt8 vibrateSupportedLevelCount;

/**
 * @brief 第0档振动百分比
 */
@property(nonatomic, assign) UInt8 vibrateForLevel0;

/**
 * @brief 第1档振动百分比
 */
@property(nonatomic, assign) UInt8 vibrateForLevel1;

/**
 * @brief 第2档振动百分比
 */
@property(nonatomic, assign) UInt8 vibrateForLevel2;

/**
 * @brief 第3档振动百分比
 */
@property(nonatomic, assign) UInt8 vibrateForLevel3;

/**
 * @brief 第4档振动百分比
 */
@property(nonatomic, assign) UInt8 vibrateForLevel4;

@end

