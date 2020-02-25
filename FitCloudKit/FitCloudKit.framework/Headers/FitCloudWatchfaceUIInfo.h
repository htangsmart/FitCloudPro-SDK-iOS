//
//  FitCloudFaceUIInfo.h
//  FitCloudKit
//
//  Created by pcjbird on 9/29/19.
//  Copyright © 2019 Zero Status. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
* @brief FitCloud 表盘UI信息
*/
@interface FitCloudWatchfaceUIInfo : NSObject

/**
 * @brief UI文件编号
*/
@property(nonatomic, readonly) UInt16 uiFileNo;

/**
 * @brief UI文件版本序号
*/
@property(nonatomic, readonly) UInt16 uiFileVersionSeqNo;

/**
 * @brief 当前表盘编号
*/
@property(nonatomic, readonly) UInt16 watchfaceIndex;

/**
 * @brief 当前表盘版本号
*/
@property(nonatomic, readonly) UInt16 watchfaceVersionNo;

/**
 * @brief LCD像素与形状
 * @Note 0: 240*240方
 *       1: 240*240圆
 *       2: 320*320方
 *       3: 360*360圆
 *       4: 320*385方
*/
@property(nonatomic, readonly) UInt8 screenSolution;

/**
 * @brief 表盘生成工具版本
*/
@property(nonatomic, readonly, strong) NSString* toolVersion;


@end

