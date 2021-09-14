//
//  FitCloudScreenResolution.h
//  FitCloudKit
//
//  Created by pcjbird on 2021/9/8.
//  Copyright © 2021 Zero Status. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * @brief 手表屏幕分辨率相关信息
*/
@interface FitCloudScreenResolution : NSObject<NSCoding>

/**
 * @brief lcd标志
 */
@property(nonatomic, readonly) UInt8 lcd;

/**
 * @brief 屏幕形状是否为圆形
 */
@property(nonatomic, readonly) BOOL round;


/**
 * @brief 屏幕宽度
 */
@property(nonatomic, readonly) UInt16 width;

/**
 * @brief 屏幕高度
 */
@property(nonatomic, readonly) UInt16 height;


/**
 * @brief 圆角大小
 */
@property(nonatomic, readonly) UInt8 cornerRadius;

@end

