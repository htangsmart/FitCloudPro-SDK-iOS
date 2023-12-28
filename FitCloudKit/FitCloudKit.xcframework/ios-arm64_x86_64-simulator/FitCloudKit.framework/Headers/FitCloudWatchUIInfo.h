//
//  FitCloudWatchUIInfo.h
//  FitCloudKit
//
//  Created by pcjbird on 5/28/20.
//  Copyright © 2020 Zero Status. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * @brief FitCloud 手表UI信息
*/
@interface FitCloudWatchUIInfo : NSObject

/**
 * @brief UI文件编号
*/
@property(nonatomic, readonly) UInt16 uiFileNo;

/**
 * @brief UI文件版本序号
*/
@property(nonatomic, readonly) UInt16 uiFileVersionSeqNo;

/**
 * @brief 当前表盘编号，仅当支持表盘推送时有效
*/
@property(nonatomic, readonly) UInt16 watchfaceIndex;

@end

