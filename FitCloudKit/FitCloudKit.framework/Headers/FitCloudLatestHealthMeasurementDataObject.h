//
//  FitCloudLatestMeasurementDataObject.h
//  FitCloudKit
//
//  Created by pcjbird on 2019/11/18.
//  Copyright © 2019 Zero Status. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>

/**
 * @brief 手环最新的测量数据
*/
@interface FitCloudLatestHealthMeasurementDataObject : NSObject<NSCoding>

/**
 * @brief 心率
*/
@property(nonatomic, readonly) UInt8 bpm;

/**
 * @brief 血氧
*/
@property(nonatomic, readonly) UInt8 SpO2;

/**
 *@brief 舒张压
 */
@property(nonatomic, readonly) UInt8 diastolic;

/**
 *@brief 收缩压
 */
@property(nonatomic, readonly) UInt8 systolic;


/**
 * @brief 腕温，单位：摄氏度
 */
@property(nonatomic, readonly) CGFloat  wrist;

/**
 * @brief 体温，单位：摄氏度
 */
@property(nonatomic, readonly) CGFloat  body;

/**
 * @brief 压力指数
 */
@property(nonatomic, readonly) UInt8 stressIndex;

@end


