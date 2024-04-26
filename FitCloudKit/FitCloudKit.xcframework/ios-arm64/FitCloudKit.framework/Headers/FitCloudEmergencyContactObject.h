//
//  FitCloudEmergencyContactObject.h
//  FitCloudKit
//
//  Created by pcjbird on 4/20/24.
//  Copyright © 2024 Zero Status. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

///紧急联系人
@interface FitCloudEmergencyContactObject : NSObject<NSCoding>

+ (instancetype _Nullable)new NS_UNAVAILABLE;
- (instancetype _Nullable)init NS_UNAVAILABLE;

/// 手机号码
@property (nonatomic, strong, readonly) NSString* _Nullable phone;

/// 名字
@property (nonatomic, strong, readonly) NSString* _Nullable name;

/// 创建紧急联系人
/// - Parameters:
///   - name: 名字，长度不得超过32字节，且不能为空
///   - phone: 手机号，长度不得超过20字节，且不能为空
/// - Returns:
/// 紧急联系人, 如果不符合规则可能创建失败返回nil
+(FitCloudEmergencyContactObject* _Nullable) createWithName:(NSString*_Nonnull)name phone:(NSString*_Nonnull)phone;


/// 创建紧急联系人
/// - Parameters:
///   - name: 名字，长度不得超过32字节，且不能为空，当allowNameTrim为TRUE时可自动截取
///   - phone: 手机号，长度不得超过20字节，且不能为空
///   - allowNameTrim: 是否允许根据长度自动截取名字
/// - Returns:
/// 紧急联系人, 如果不符合规则可能创建失败返回nil
+(FitCloudEmergencyContactObject* _Nullable) createWithName:(NSString*_Nonnull)name phone:(NSString*_Nonnull)phone allowNameTrim:(BOOL)allowNameTrim;

@end

NS_ASSUME_NONNULL_END
