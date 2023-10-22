//
//  FitCloudH5GameItem.h
//  FitCloudH5Game
//
//  Created by pcjbird on 2023-10-19.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// 游戏类型
typedef NS_ENUM (NSInteger, FITCLOUDH5GAMETYPE)
{
    FITCLOUDH5GAMETYPE_COCOS = 1,
    FITCLOUDH5GAMETYPE_H5 = 2,
};

/// 游戏信息
@interface FitCloudH5GameItem : NSObject

/// 游戏id
@property (nonatomic, assign) NSInteger gameId;

/// 游戏类型
@property (nonatomic, assign) FITCLOUDH5GAMETYPE gameType;

/// 游戏版本
@property (nonatomic, assign) NSInteger version;

/// 游戏名
@property (nonatomic, copy)   NSString *name;

/// 游戏背景图
@property (nonatomic, copy)   NSString *background;

/// 游戏标题
@property (nonatomic, copy)   NSString *title;

/// 游戏简介
@property (nonatomic, copy)   NSString *introduction;

/// 游戏标签（多个标签用英文逗号分隔）
@property (nonatomic, copy)   NSString *tags;

/// 游戏banner图片（多张图片用英文逗号分隔）
@property (nonatomic, copy)   NSString *urls;

/// 游戏资源下载地址
@property (nonatomic, copy)   NSString *resourceUrl;

/// 是否横屏游戏
@property (nonatomic, assign) BOOL landscape;

/// 游戏手表按键模式
@property (nonatomic, assign) int keyboard;

/// 是否为免费
@property (nonatomic, assign) BOOL free;

/// 价格
@property (nonatomic, copy)   NSString *price;

@end

NS_ASSUME_NONNULL_END
