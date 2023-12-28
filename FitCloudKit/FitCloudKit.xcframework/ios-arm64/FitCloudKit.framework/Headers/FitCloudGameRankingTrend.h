//
//  FitCloudGameRankingTrend.h
//  FitCloudKit
//
//  Created by pcjbird on 2022/6/15.
//  Copyright © 2022 Zero Status. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <FitCloudKit/FitCloudKitDefines.h>

NS_ASSUME_NONNULL_BEGIN

/**
 *@brief 游戏趋势
 */
@interface FitCloudGameRankingTrend : NSObject

/**
 *@brief 游戏类型
 */
@property(nonatomic, readonly) FITCLOUDGAME game;

/**
 *@brief 游戏排名
 */
@property(nonatomic, readonly) Byte ranking;

/**
 *@brief 趋势
 */
@property(nonatomic, readonly) FITCLOUDGAMERANDINGTREND trend;


/**
 * @brief 创建游戏趋势
 * @param game 游戏类型
 * @param ranking 游戏排名
 * @param trend 趋势
 * @return 游戏趋势
 */
+ (instancetype) createWith:(FITCLOUDGAME)game ranking:(Byte)ranking trend:(FITCLOUDGAMERANDINGTREND)trend;


+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
