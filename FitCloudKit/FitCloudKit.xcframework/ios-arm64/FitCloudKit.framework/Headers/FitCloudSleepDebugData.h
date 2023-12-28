//
//  FitCloudSleepDebugDataItem.h
//  FitCloudKit
//
//  Created by pcjbird on 7/2/20.
//  Copyright © 2020 Zero Status. All rights reserved.
//

#import <Foundation/Foundation.h>



@interface FitCloudSleepDebugData : NSObject

/**
 * @brief 日期
 */
@property(nonatomic, strong, readonly) NSDate*  date;

/**
 * @brief 间隔，单位: 分钟
 */
@property(nonatomic, readonly) NSInteger interval;

/**
 * @brief 数量
*/
@property(nonatomic, readonly)NSInteger count;

/**
 * @brief 原始动作数量明细
 */
@property(nonatomic, strong, readonly) NSArray<NSNumber*>* items;

@end


