//
//  FitCloudH5GameBannerItem.h
//  FitCloudH5Game
//
//  Created by pcjbird on 2023-10-19.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class FitCloudH5GameItem;

/// banner
@interface FitCloudH5GameBannerItem : NSObject

/// 游戏id
@property (nonatomic, assign) NSInteger gameId;

/// 游戏名
@property (nonatomic, copy)   NSString *gameName;

/// banner图片
@property (nonatomic, copy)   NSString *bannerImage;

/// banner名称
@property (nonatomic, copy)   NSString *bannerName;

/// banner标题
@property (nonatomic, copy)   NSString *bannerTitle;

/// 游戏数据
@property (nonatomic, strong) FitCloudH5GameItem *game;

@end

NS_ASSUME_NONNULL_END
