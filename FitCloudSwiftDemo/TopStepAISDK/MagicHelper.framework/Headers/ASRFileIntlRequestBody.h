//
//  ASRFileIntlRequestBody.h
//  MagicHelper
//
//  Created by ymz on 2024/7/26.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ASRFileIntlRequestBody : NSObject

/// 请求id，有默认值，调用方也可自定,该值也会在结果回调中返回
@property (nonatomic, strong) NSString *qid;

/// 语种 支持的语种见文档
@property (nonatomic, strong) NSString *language;

/// 音频文件路径
@property (nonatomic, strong, nullable) NSString *path;

/// 文件数据
@property (nonatomic, strong, nullable) NSData *data;

@end

NS_ASSUME_NONNULL_END
