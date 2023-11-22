//
//  SMGameServices.h
//  SMH5Game
//
//  Created by Developer on 2022/8/2.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, SMGameLanguage) {
    SMGameLanguageZH,  // 中文
    SMGameLanguageEN,  // 英文
    SMGameLanguageJP,  // 日文
};

@class SMBannerGameInfo, SMGameListModel, SMGameInfo, SMGameChannelUserInfo, SMGameUser;

/**
 * @brief 游戏服务类
 */
@interface SMGameServices : NSObject


/**
 * @brief 申请的服务授权密钥
 */
@property (nonatomic, copy, readonly) NSString *apikey;

/**
 * @brief 开发者申请服务授权密钥时对应的第三方名称
 */
@property (nonatomic, copy, readonly) NSString *name;


/**
 * @brief 注册服务
 *
 * @param apikey  授权密钥
 * @param name    渠道名称
 *
 * @discussion 在使用游戏服务功能之前，必须先调用此方法
 */
+ (void)registerApiKey:(NSString *)apikey
                  name:(NSString *)name;

/**
 * @return 游戏服务类单例
 */
+ (instancetype)sharedServices;

/**
 * @brief 游戏服务端地址
 */
@property (nonatomic, copy, readonly) NSString *serverUrl;

/**
 * @brief 游戏服务端环境（0为开发环境，1为生产环境）
 */
@property (nonatomic, readonly) int serverEnv;


#pragma mark - 游戏服务功能

/**
 * @brief 当前用户信息
 *
 * @discussion 为空时表示游客模式
 */
@property (nonatomic, strong) SMGameChannelUserInfo *channelUserInfo;

/**
 * @brief 游戏语言
 *
 * @discussion 默认为zh中文
 */
@property (nonatomic, assign) SMGameLanguage currentLanguage;

/**
 * @brief 是否开启陀螺仪数据展示
 *
 * @discussion 默认关闭不展示
 */
@property (nonatomic, assign) BOOL sensorLogEnabled;


/**
 * @brief 获取游戏用户信息
 *
 * @param completion 完成回调
 */
- (void)getGameUserWithCompletion:(void (^)(SMGameUser *user, NSError *error))completion;

/**
 * @brief 获取游戏列表
 *
 * @param completion 完成回调
 *
 * @discussion 获取配置的所有游戏
 */
- (void)getGameListWithCompletion:(void (^)(NSArray<SMGameInfo *> *result, NSError *error))completion;

/**
 * @brief 获取游戏列表
 *
 * @param includeGameIds 有效的游戏id（需要获取的游戏集合，英文逗号分隔）
 * @param completion 完成回调
 *
 * @discussion 通过指定游戏id获取对应游戏列表
 */
- (void)getGameListByIncludeGameIds:(NSString *)includeGameIds
                     withCompletion:(void (^)(NSArray<SMGameInfo *> *result, NSError *error))completion;

/**
 * @brief 获取分类游戏列表
 *
 * @param completion 完成回调
 *
 * @discussion 获取配置的所有包含分类信息的游戏列表
 */
- (void)getTagGameListWithCompletion:(void (^)(NSArray<SMGameListModel *> *result, NSError *error))completion;

/**
 * @brief 获取分类游戏列表
 *
 * @param includeGameIds 有效的游戏id（需要获取的游戏集合，英文逗号分隔）
 * @param completion 完成回调
 *
 * @discussion 通过指定游戏id获取对应包含分类信息的游戏列表
 */
- (void)getTagGameListByIncludeGameIds:(NSString *)includeGameIds
                        withCompletion:(void (^)(NSArray<SMGameListModel *> *result, NSError *error))completion;

/**
 * @brief 获取Banner游戏列表
 *
 * @param completion 完成回调
 *
 * @discussion 获取配置的所有Banner游戏列表
 */
- (void)getGameBannerListWithCompletion:(void (^)(NSArray<SMBannerGameInfo *> *result, NSError *error))completion;


/**
* @brief 游戏入口曝光上报
*
* @discussion App每次展示游戏入口时调用
*/
- (void)exposureReport;

/**
* @brief 游戏上报
*
* @param gameId 游戏id
*
* @discussion SDK内部调用
*/
- (void)gameReport:(NSInteger)gameId;

@end
