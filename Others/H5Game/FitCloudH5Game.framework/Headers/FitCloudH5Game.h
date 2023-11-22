//
//  FitCloudH5Game.h
//  FitCloudH5Game
//
//  Created by pcjbird on 2023-10-19.
//

#import <Foundation/Foundation.h>
#import <FitCloudH5Game/FitCloudH5GameItem.h>
#import <FitCloudH5Game/FitCloudH5GameBannerItem.h>
#import <FitCloudH5Game/FitCloudH5GameGroup.h>
#import <UIKit/UIKit.h>

//! Project version number for FitCloudH5Game.
FOUNDATION_EXPORT double FitCloudH5GameVersionNumber;

//! Project version string for FitCloudH5Game.
FOUNDATION_EXPORT const unsigned char FitCloudH5GameVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <FitCloudH5Game/PublicHeader.h>

typedef NS_ENUM(NSInteger, FITCLOUDH5GAMELANG) {
    FITCLOUDH5GAMELANG_ZH = 0,  // 中文
    FITCLOUDH5GAMELANG_EN = 1,  // 英文
    FITCLOUDH5GAMELANG_JP = 2,  // 日文
};

/// GSensor数据
/// - Note: [[NSNotificationCenter defaultCenter] postNotificationName:GSENSOR_DATA_NOTIFICATION object:@{@"xGravity": @(xGravity), @"yGravity": @(yGravity), @"zGravity": @(zGravity)}];
#define GSENSOR_DATA_NOTIFICATION @"GSENSOR_DATA_NOTIFICATION"

/// 游戏请求打开 GSensor 通知
#define REQUEST_OPEN_GSENSOR_NOTIFICATION @"REQUEST_OPEN_GSENSOR_NOTIFICATION"

/// 游戏请求关闭 GSensor 通知
#define REQUEST_CLOSE_GSENSOR_NOTIFICATION @"REQUEST_CLOSE_GSENSOR_NOTIFICATION"


@interface FitCloudH5Game : NSObject

#pragma mark 版本信息

/// SDK版本号
+(NSString*) sdkVersion;

/// SDK Build 版本号
+(NSString*) sdkBuild;

# pragma mark 注册

/// 注册服务
/// - Parameters:
///   - apikey: 授权密钥
///   - name: 渠道名称
/// - Note: 在使用游戏服务功能之前，必须先调用此方法
+ (void)registerApiKey:(NSString *)apikey
                  name:(NSString *)name;


# pragma mark 设置游戏语言

/// 设置游戏语言
/// - Parameters:
///   - lang: 游戏语言
+ (void)setGameLang:(FITCLOUDH5GAMELANG)lang;

#pragma mark 设置游戏用户信息

/// 设置游戏用户信息
/// - Parameters:
///   - userId: 用户Id
///   - userName: 用户名
///   - avatarUrl: 头像Url地址
+ (void) setUserId:(NSString*) userId userName:(NSString*)userName avatarUrl:(NSString*)avatarUrl;

#pragma mark 获取Banner游戏列表

/// 获取Banner游戏列表
/// - Parameters:
///   - macAddr: 设备mac地址，格式不包含冒号
///   - completion: 结果回调
+ (void)fetchBannersWithMacAddr:(NSString*)macAddr completion:(void (^)(NSArray<FitCloudH5GameBannerItem *> *result, NSError *error))completion;

#pragma mark 获取所有游戏分组

/// 获取所有游戏分组
/// - Parameters:
///   - macAddr: 设备mac地址，格式不包含冒号
///   - completion: 结果回调
+ (void)fetchGroupsWithMacAddr:(NSString*) macAddr completion:(void(^)(NSArray<FitCloudH5GameGroup*>* result, NSError *error)) completion;

#pragma mark 当用户看到体感游戏入口时上报

/// 当用户看到体感游戏入口时上报
+ (void)reportWhenExposureMotionGameEntrance;

#pragma mark 进入游戏

/// 进入游戏
/// - Parameters:
///   - game: 游戏
///   - fromVC: 视图控制器
///   - completion: 结果回调
+ (void) enterGame:(FitCloudH5GameItem*)game fromVC:(UIViewController*)fromVC completion:(void(^)(BOOL success, NSError *error)) completion;

@end
