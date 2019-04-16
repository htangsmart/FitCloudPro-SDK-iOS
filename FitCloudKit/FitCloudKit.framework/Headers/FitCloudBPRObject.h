//
//  FitCloudBPRObject.h
//  FitCloudKit
//
//  Created by pcjbird on 2018/5/27.
//  Copyright © 2018年 Zero Status. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * @brief 血压参考范围设置（Blood Pressure Reference）
 */
@interface FitCloudBPRObject : NSObject<NSCoding>

/**
 *@brief 舒张压
 */
@property(nonatomic, assign) UInt8 diastolic;

/**
 *@brief 收缩压
 */
@property(nonatomic, assign) UInt8 systolic;

/**
 * @brief 是否启用以上设定的值(舒张压/收缩压)参与手环血压算法的运算
 */
@property(nonatomic, assign) BOOL   on;

@end
