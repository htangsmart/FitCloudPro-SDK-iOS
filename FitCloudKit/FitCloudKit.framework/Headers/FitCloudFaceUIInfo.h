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
@property(nonatomic, readonly) UInt16 uiFileNo;

/**
 * @brief UI版本序号
*/
@property(nonatomic, readonly) UInt16 uiFileVersionSeqNo;

/**
 * @brief 当前首页序号
*/
@property(nonatomic, readonly) UInt16 activeFaceIndex;


@end

