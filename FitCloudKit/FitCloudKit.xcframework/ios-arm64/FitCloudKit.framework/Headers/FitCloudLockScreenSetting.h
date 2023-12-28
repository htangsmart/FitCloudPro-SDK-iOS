//
//  FitCloudLockScreenSetting.h
//  FitCloudKit
//
//  Created by pcjbird on 2021/1/7.
//  Copyright © 2021 Zero Status. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * @brief 锁屏设置（Lock Screen Setting）
*/
@interface FitCloudLockScreenSetting : NSObject<NSCoding>

+ (instancetype _Nullable)new NS_UNAVAILABLE;
- (instancetype _Nullable)init NS_UNAVAILABLE;

/**
 * @brief YES 锁定屏幕，NO 解锁屏幕
*/
@property(nonatomic, readonly) BOOL toLock;

/**
 * @brief 锁定/解锁屏幕的密码（长度为六位，必须为数字）
*/
@property(nonatomic, strong, readonly) NSString* _Nullable password;

/**
 * @brief 创建锁屏设置
 * @param toLock YES 锁定屏幕，NO 解锁屏幕
 * @param password 锁定/解锁屏幕的密码（长度为六位，必须为数字）
 * @return 锁屏设置, 如果不符合规则可能创建失败返回nil
 */
+(FitCloudLockScreenSetting* _Nullable) settingWithIsToLock:(BOOL)toLock password:(NSString*_Nonnull)password;

@end


