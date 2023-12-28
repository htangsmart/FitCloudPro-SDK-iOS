//
//  FitCloudGameSkinObject.h
//  FitCloudKit
//
//  Created by pcjbird on 2021/6/16.
//  Copyright © 2021 Zero Status. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <FitCloudKit/FitCloudKitDefines.h>

/**
 * @brief 游戏皮肤
*/
@interface FitCloudGameSkinObject : NSObject<NSCoding>

/**
 * @brief 位置索引，从1开始
*/
@property(nonatomic, readonly) NSInteger index;

/**
 * @brief 游戏类型
*/
@property(nonatomic, readonly) FITCLOUDGAME category;

/**
 * @brief 游戏皮肤编号
*/
@property(nonatomic, readonly) NSInteger skinNo;

/**
 * @brief 最大可推送文件的大小，单位：kB
 */
@property(nonatomic, readonly) NSInteger maxAllowPushBinFileSize;

@end

