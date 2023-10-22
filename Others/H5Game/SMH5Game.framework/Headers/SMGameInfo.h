//
//  SMGameInfo.h
//  SMH5Game
//
//  Created by Developer on 2022/8/2.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, SMGameType) {
    SMGameTypeCocos = 1,
    SMGameTypeH5,
};

/**
 游戏信息类
 */
@interface SMGameInfo : NSObject

/// 游戏id
@property (nonatomic, assign) NSInteger gameId;

/// 游戏类型
@property (nonatomic, assign) SMGameType gameType;

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

@end
