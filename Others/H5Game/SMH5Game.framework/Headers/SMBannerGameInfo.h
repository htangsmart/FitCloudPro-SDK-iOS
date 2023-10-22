//
//  SMBannerGameInfo.h
//  SMH5Game
//
//  Created by Anting Li on 2023/8/26.
//

#import <Foundation/Foundation.h>
#import "SMGameInfo.h"

@interface SMBannerGameInfo : NSObject

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
@property (nonatomic, strong) SMGameInfo *game;

@end
