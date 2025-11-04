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

/// 表盘模块组件
@interface FitCloudWatchfaceModule : NSObject

/// 模块当前样式
@property(nonatomic, readonly) WATCHFACEMODULESTYLE currentStyle;

/// 最大支持的样式数量
@property(nonatomic, readonly) UInt16 maxStyleCount;

/// x 坐标
@property(nonatomic, readonly) UInt16 x;

/// y 坐标
@property(nonatomic, readonly) UInt16 y;

/// 宽度
@property(nonatomic, readonly) UInt16 width;

/// 高度
@property(nonatomic, readonly) UInt16 height;

@end

/// 表盘位
@interface FitCloudWatchfaceSlot : NSObject

/// 位置索引
@property(nonatomic, readonly) NSUInteger slotIndex;

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
@property(nonatomic, strong, readonly) NSArray<FitCloudWatchfaceModule *> *watchfaceModules;

/// 该表盘位是否隐藏
@property(nonatomic, readonly) BOOL hidden;

/// 位置类型描述
- (NSString *)slotDescription;

@end

/// FitCloud 表盘 UI 信息
@interface FitCloudWatchfaceUIInfo : NSObject

/// UI 文件编号
@property(nonatomic, readonly) UInt16 uiFileNo;

/// UI 文件版本序号
@property(nonatomic, readonly) UInt16 uiFileVersionSeqNo;

/// 当前表盘编号
@property(nonatomic, readonly) UInt32 watchfaceNo;

/// 当前表盘版本号
///
/// - Note: 当 allowWatchFaceUpgrade 为 TRUE 且 allowMultiWatchfacePush 为 TRUE 时无效
@property(nonatomic, readonly) UInt16 watchfaceVersionNo;

/// 当前显示的表盘所在的位置
///
/// - Note: 仅当 allowWatchFaceUpgrade 为 TRUE 且 allowMultiWatchfacePush 为 TRUE 时有效
@property(nonatomic, readonly) UInt16 slotIndexOfCurrentWatchface;

/// LCD 像素与形状
///
/// ## Note: 支持以下分辨率和形状：
/// ```
/// 0: 240*240 方
/// 1: 240*240 圆
/// 2: 320*320 方
/// 3: 360*360 圆
/// 4: 320*385 方
/// 5: 320*360 方
/// 6: 240*284 方
/// 7: 240*280 方
/// 8: 348*442 方
/// 9: 280*240 方
/// 10: 200*320 方
/// 11: 368*448 方
/// 12: 320*390 方
/// 13: 172*320 方
/// 14: 454*454 圆
/// 15: 128*220 方
/// 16: 160*80 方
/// 17: 128*128 方
/// 18: 167*320 方
/// 19: 80*160 方
/// 20: 320*380 方
/// 21: 240*286 方
/// 22: 466*466 圆
/// 23: 240*296 方
/// 24: 410*502 方
/// 25: 416*416 圆
/// 26: 240*288 方
/// 27: 340*340 圆
/// 28: 228*460 方
/// 29: 390*390 圆
/// 30: 390*450 方
/// 31: 286*240 方
/// 32: 192*490 椭圆
/// 33: 320*172 方
/// 34: 385*320 方
/// 35: 480*480 圆
/// 36: 194*368 方
/// 37: 360*360 方
/// 38: 296*240 方
/// 39: 240*320 方
/// 40: 184*276 方
/// 41: 160*86 方
/// 42: 402*402 方
/// 43: 128*160 方
/// ```
@property(nonatomic, readonly) UInt8 lcd;

/// 表盘生成工具版本
@property(nonatomic, readonly, strong) NSString *toolVersion;

/// 表盘位列表
/// @Note 仅当 allowWatchFaceUpgrade 为 TRUE 且 allowMultiWatchfacePush 为 TRUE 时有效
@property(nonatomic, readonly, strong) NSArray<FitCloudWatchfaceSlot *> *slots;

/// 当前表盘是否为圆形表盘
- (BOOL)isRound;

/// 当前表盘分辨率
- (CGSize)screenResolution;

@end
