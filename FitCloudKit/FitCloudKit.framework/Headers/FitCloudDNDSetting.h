//
//  FitCloudDNDSetting.h
//  FitCloudKit
//
//  Created by pcjbird on 11/13/19.
//  Copyright © 2019 Zero Status. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * @brief 勿扰模式设置（Do Not Disturb Mode Setting）
*/
@interface FitCloudDNDSetting : NSObject<NSCoding>

/**
 * @brief 是否开启(总开关)，当总开关为YES时，全时段勿扰，当总开关为NO时，根据时段开关及勿扰时段确定勿扰设置
 */
@property(nonatomic, assign) BOOL on;

/**
 * @brief 时段开关，YES表示开启时段勿扰，NO表示关闭时段勿扰 (当总开关为NO时有效)
*/
@property(nonatomic, assign) BOOL dndPeriodOn;

/**
 * @brief 开始时间（零点开始的偏移分钟数）
 */
@property(nonatomic, assign) UInt16 periodBegin;

/**
 * @brief 结束时间（零点开始的偏移分钟数）
 */
@property(nonatomic, assign) UInt16 periodEnd;

@end


