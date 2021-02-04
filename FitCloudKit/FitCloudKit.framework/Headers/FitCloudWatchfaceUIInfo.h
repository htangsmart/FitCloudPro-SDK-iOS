//
//  FitCloudFaceUIInfo.h
//  FitCloudKit
//
//  Created by pcjbird on 9/29/19.
//  Copyright © 2019 Zero Status. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <FitCloudKit/FitCloudKitDefines.h>

/**
 * @brief FitCloud 表盘 Item
 */
@interface FitCloudWatchfaceItem : NSObject

/**
 * @brief 标志
 */
@property(nonatomic, readonly) WATCHFACEITEMFLAG flag;

/**
 * @brief 编号
 */
@property(nonatomic, readonly) UInt16 watchfaceIndex;

/**
 * @brief 版本
 */
@property(nonatomic, readonly) UInt16 watchfaceVersion;

@end

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
 *       5.320*360方
 *       6.240*284方
 *       7.240*280方
 *       8.348*442方
*/
@property(nonatomic, readonly) UInt8 screenSolution;

/**
 * @brief 表盘生成工具版本
*/
@property(nonatomic, readonly, strong) NSString* toolVersion;

/**
 * @brief 表盘列表
 * @Note 仅当 allowWatchFaceUpgrade 为 TRUE 且 allowMultiWatchfacePush 为 TRUE 时有效
*/
@property(nonatomic, readonly, strong) NSArray<FitCloudWatchfaceItem*>*items;

@end

