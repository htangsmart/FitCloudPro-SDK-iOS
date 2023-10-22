//
//  SMGameChannelUserInfo.h
//  SMH5Game
//
//  Created by Developer on 2022/8/4.
//

#import <Foundation/Foundation.h>

@interface SMGameChannelUserInfo : NSObject

/**
 * @brief 第三方自己的用户id
 */
@property (nonatomic, copy) NSString *userId;

/**
 * @brief 第三方自己的用户名称
 */
@property (nonatomic, copy) NSString *userName;

/**
 * @brief 第三方自己的用户头像URL地址
 */
@property (nonatomic, copy) NSString *portrait;

/**
 * @brief 第三方用户信息的初始化方法
 *
 * @param userId   第三方自己的用户id
 * @param userName 第三方自己的用户名称
 * @param portrait 第三方自己的用户头像URL地址
 *
 * @return         用户信息对象
 */
+ (instancetype)userWithUserId:(NSString *)userId
                      userName:(NSString *)userName
                      portrait:(NSString *)portrait;

@end



@interface SMGameUser : NSObject <NSCopying, NSSecureCoding>

/**
 * @brief 十米游戏用户id
 */
@property (nonatomic, copy) NSString *userId;
/**
 * @brief 十米游戏用户名称
 */
@property (nonatomic, copy) NSString *userName;
/**
 * @brief 十米游戏用户头像
 */
@property (nonatomic, copy) NSString *portrait;
/**
 * @brief 十米游戏用户token
 */
@property (nonatomic, copy) NSString *userToken;
/**
 * @brief 十米游戏校验token
 */
@property (nonatomic, copy) NSString *otpToken;

@end
