//
//  FitCloudContactObject.h
//  FitCloudKit
//
//  Created by pcjbird on 2020/3/24.
//  Copyright © 2020 Zero Status. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface FitCloudContactObject : NSObject<NSCoding>

+ (instancetype _Nullable)new NS_UNAVAILABLE;
- (instancetype _Nullable)init NS_UNAVAILABLE;

/**
 * @brief 手机号码
 */
@property (nonatomic, strong, readonly) NSString* _Nullable phone;

/**
 * @brief 名字
 */
@property (nonatomic, strong, readonly) NSString* _Nullable name;

/**
 * @brief 创建联系人
 * @param name 名字，长度不得超过32字节，且不能为空
 * @param phone 手机号，长度不得超过20字节，且不能为空
 * @return 联系人, 如果不符合规则可能创建失败返回nil
 */
+(FitCloudContactObject* _Nullable) createWithName:(NSString*_Nonnull)name phone:(NSString*_Nonnull)phone;


/**
 * @brief 创建联系人
 * @param name 名字，长度不得超过32字节，且不能为空，当allowNameTrim为TRUE时可自动截取
 * @param phone 手机号，长度不得超过20字节，且不能为空
 * @param allowNameTrim 是否允许根据长度自动截取名字
 * @return 联系人, 如果不符合规则可能创建失败返回nil
 */
+(FitCloudContactObject* _Nullable) createWithName:(NSString*_Nonnull)name phone:(NSString*_Nonnull)phone allowNameTrim:(BOOL)allowNameTrim;
@end

