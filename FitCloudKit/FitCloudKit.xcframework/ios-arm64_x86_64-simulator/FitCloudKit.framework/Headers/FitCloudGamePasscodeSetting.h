//
//  FitCloudGamePasscodeSetting.h
//  FitCloudKit
//
//  Created by pcjbird on 2022/3/2.
//  Copyright © 2022 Zero Status. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <FitCloudKit/FitCloudKitDefines.h>

/**
 * @brief 游戏锁设置
 */
@interface FitCloudGamePasscodeSetting : NSObject<NSCoding>

+ (instancetype _Nullable)new NS_UNAVAILABLE;
- (instancetype _Nullable)init NS_UNAVAILABLE;

/**
 * @brief Passcode操作
*/
@property(nonatomic, readonly) FITCLOUDGAMEPASSCODEOP op;

/**
 * @brief passcode, （长度为六位，必须为数字）
*/
@property(nonatomic, strong, readonly) NSString* _Nullable passcode;

/**
 * @brief 游戏锁开始时间（零点开始的偏移分钟数）
 */
@property(nonatomic, readonly) UInt16 begin;

/**
 * @brief 游戏锁结束时间（零点开始的偏移分钟数）
 */
@property(nonatomic, readonly) UInt16 end;


/**
 * @brief 创建游戏锁设置
 * @param op 操作
 * @param passcode 密码（长度为六位，必须为数字）
 * @param begin 游戏锁开始时间（零点开始的偏移分钟数）
 * @param end 游戏锁结束时间（零点开始的偏移分钟数）
 * @return 锁屏设置, 如果不符合规则可能创建失败返回nil
 */
+(FitCloudGamePasscodeSetting* _Nullable) settingWithOP:(FITCLOUDGAMEPASSCODEOP)op passcode:(NSString*_Nonnull)passcode begin:(UInt16) begin end:(UInt16) end;

@end

