//
//  FitCloudFaceUIInfo.h
//  FitCloudKit
//
//  Created by pcjbird on 9/29/19.
//  Copyright © 2019 Zero Status. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import <FitCloudKit/FitCloudKitDefines.h>

/**
 * @brief 表盘模块
 */
@interface FitCloudWatchfaceModule : NSObject

/// 模块当前样式
@property(nonatomic, readonly) WATCHFACEMODULESTYLE currentStyle;

/// 最大支持的样式数量
@property(nonatomic, readonly) UInt16 maxStyleCount;


/// x坐标
@property(nonatomic, readonly) UInt16 x;

/// y坐标
@property(nonatomic, readonly) UInt16 y;

/// 宽度
@property(nonatomic, readonly) UInt16 width;

/// 高度
@property(nonatomic, readonly) UInt16 height;


@end

///表盘位
@interface FitCloudWatchfaceSlot : NSObject

/// 位置类型
@property(nonatomic, readonly) WATCHFACESLOTTYPE slotType;

/// 当前表盘位置表盘编号
@property(nonatomic, readonly) UInt32 watchfaceNo;

/// 当前表盘位置表盘版本号
@property(nonatomic, readonly) UInt16 watchfaceVersion;

/// 最大可推送表盘的大小，单位：kB
@property(nonatomic, readonly) NSInteger maxAllowPushBinFileSize;

/// 当前表盘位置表盘包含的组件
///
/// 仅当 allowWatchfaceModular 为 TRUE 且 allowMultiWatchfacePush 为 TRUE 时有效
@property(nonatomic, strong, readonly) NSArray<FitCloudWatchfaceModule*>* watchfaceModules;

/// 该表盘位是否隐藏
@property(nonatomic, readonly) BOOL hidden;

/// 位置类型描述
-(NSString *)slotDescription;

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
@property(nonatomic, readonly) UInt32 watchfaceNo;

/**
 * @brief 当前表盘版本号
 * @Note 当 allowWatchFaceUpgrade 为 TRUE 且 allowMultiWatchfacePush 为 TRUE 时无效
*/
@property(nonatomic, readonly) UInt16 watchfaceVersionNo;

/**
 * @brief 当前显示的表盘所在的位置
 * @Note 仅当 allowWatchFaceUpgrade 为 TRUE 且 allowMultiWatchfacePush 为 TRUE 时有效
*/
@property(nonatomic, readonly) UInt16 slotIndexOfCurrentWatchface;

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
 *       9.280*240方
 *       10.200*320方
 *       11.368*448方
 *       12.320*390方
 *       13.172*320方
 *       14.454*454圆
 *       15.128*220方
 *       16.160*80方
 *       17.128*128方
 *       18.167*320方
 *       19.80*160方
 *       20.320*380方
 *       21.240*286方
 *       22.466*466圆
 *       23.240*296方
 *       24.410*502方
 *       25.416*416圆
 *       26.240*288方
 *       27:340*340圆
 *       28:228*460方
 *       29:390*390圆
 *       30.390*450方
 *       31.286*240方
 *       32.192*490方
 *       33.320*172方
 *       34.385*320方
 *       35.480*480圆
 *       36.194*368方
 *       37.360*360方
 *       38.296*240方
*/
@property(nonatomic, readonly) UInt8 lcd;

/// 表盘生成工具版本
@property(nonatomic, readonly, strong) NSString* toolVersion;

/// 表盘位列表
/// @Note 仅当 allowWatchFaceUpgrade 为 TRUE 且 allowMultiWatchfacePush 为 TRUE 时有效
@property(nonatomic, readonly, strong) NSArray<FitCloudWatchfaceSlot*>*slots;


/// 当前表盘是否为圆形表盘
-(BOOL) isRound;

/// 当前表盘分辨率
-(CGSize) screenResolution;

@end

