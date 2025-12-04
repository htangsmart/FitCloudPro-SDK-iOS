//
//  RecognitionImageBody.h
//  MagicHelper
//
//  Created by wolf wang on 2025/7/25.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface RecognitionImageBody : NSObject

/// 请求id,请求方自定
@property (nonatomic, strong) NSString *qid;

/// 用户id
@property (nonatomic, strong) NSString *userId;

/// 最大token数， 默认200，最大2000
@property (nonatomic, assign) NSInteger max_tokens;

/// 是否返回流
@property (nonatomic, assign) BOOL stream;

/// 图片本地路径
@property (nonatomic, strong, nullable) NSString *imageFilePath;

/// 图片数据（imageFilePath, imageData二选一设置，同时设置优先使用imageData）
@property (nonatomic, strong, nullable) NSData *imageData;

/// 提示语
@property (nonatomic, strong) NSString *prompt;

/// 目标语言（zh, zh-CN两种格式都可以）
@property (nonatomic, strong) NSString *targetLanguage;

@end

NS_ASSUME_NONNULL_END
