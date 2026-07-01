//
//  FitCloudLockScreenSetting.h
//  FitCloudKit
//
//  Created by pcjbird on 2021/1/7.
//  Copyright © 2021 Zero Status. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <FitCloudKit/FitCloudSecureCoding.h>

/**
 * @brief 锁屏设置（Lock Screen Setting）
*/
@interface FitCloudLockScreenSetting : NSObject<FitCloudSecureCoding>

+ (instancetype _Nullable)new NS_UNAVAILABLE;
- (instancetype _Nullable)init NS_UNAVAILABLE;

/// YES 锁定屏幕，NO 解锁屏幕
@property(nonatomic, readonly) BOOL toLock;

/// 锁定/解锁屏幕的密码（密码长度取决于设备，若设备未定义则默认为六位数字，值得注意的是，密码只能包含数字，不能包含字母或特殊字符。）
@property(nonatomic, strong, readonly) NSString* _Nullable password;

/// 创建锁屏设置
/// - Parameters:
///   - toLock: YES 锁定屏幕，NO 解锁屏幕
///   - password: 锁定/解锁屏幕的密码（密码长度取决于设备，若设备未定义则默认为六位数字，值得注意的是，密码只能包含数字，不能包含字母或特殊字符。）
/// - Returns: 锁屏设置，如果不符合规则可能创建失败返回 nil
+(FitCloudLockScreenSetting* _Nullable) settingWithIsToLock:(BOOL)toLock password:(NSString*_Nonnull)password;

@end


