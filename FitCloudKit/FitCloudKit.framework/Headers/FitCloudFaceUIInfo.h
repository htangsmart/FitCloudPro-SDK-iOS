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
@interface FitCloudFaceUIInfo : NSObject

/**
 * @brief UI文件编号
*/
@property(nonatomic, readonly) UInt8 uiFileNo;

/**
 * @brief UI版本序号
*/
@property(nonatomic, readonly) UInt8 uiFileVersionSeqNo;

/**
 * @brief preserved
 */
@property(nonatomic, readonly) UInt8 totalFaceCount;

/**
 * @brief 当前首页序号
*/
@property(nonatomic, readonly) UInt8 activeFaceIndex;

/**
 * @brief preserved
*/
@property(nonatomic, readonly) UInt8 upgradeSupportFaceCount;

@end

