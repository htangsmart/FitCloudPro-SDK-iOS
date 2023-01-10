//
//  FitCloudCustomLabelsObject.h
//  FitCloudKit
//
//  Created by pcjbird on 2023/1/10.
//  Copyright © 2023 Zero Status. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface FitCloudCustomLabelsObject : NSObject

+ (instancetype _Nullable)new NS_UNAVAILABLE;
- (instancetype _Nullable)init NS_UNAVAILABLE;

@property (nonatomic, strong, readonly) NSString* _Nullable label1;

@property (nonatomic, strong, readonly) NSString* _Nullable label2;

@property (nonatomic, strong, readonly) NSString* _Nullable label3;


/**
 * @brief 创建自定义标签
 * @param label1 自定义标签1，最大长度64字节
 * @param label2 自定义标签2，最大长度64字节
 * @param label3 自定义标签3，最大长度64字节
 * @param allowTrim 是否允许根据长度自动截取标签
 * @return 自定义标签, 如果不符合规则可能创建失败返回nil
 */
+(FitCloudCustomLabelsObject* _Nullable) createWithLabel1:(NSString*_Nullable)label1 label2:(NSString*_Nullable)label2 label3:(NSString* _Nullable)label3 allowTrim:(BOOL)allowTrim;

@end

NS_ASSUME_NONNULL_END
