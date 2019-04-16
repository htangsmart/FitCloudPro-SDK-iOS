//
//  FitCloudUserProfileObject.h
//  FitCloudKit
//
//  Created by pcjbird on 2018/5/25.
//  Copyright © 2018年 Zero Status. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "FitCloudKitDefines.h"

/**
 * @brief 用户Profile
 */
@interface FitCloudUserProfileObject : NSObject<NSCoding>

/**
 * @brief 性别
 */
@property(nonatomic, assign) FITCLOUDGENDER  gender;

/**
 * @brief 年龄(0~127)
 */
@property(nonatomic, assign) UInt8   age;

/**
 * @brief 身高(单位cm，精确到0.5cm, 范围 0.0~256cm)
 */
@property(nonatomic, assign) float height;

/**
 * @brief 体重(单位kg, 精确到0.5kg,范围 0.0~512kg)
 */
@property(nonatomic, assign) float weight;

@end
