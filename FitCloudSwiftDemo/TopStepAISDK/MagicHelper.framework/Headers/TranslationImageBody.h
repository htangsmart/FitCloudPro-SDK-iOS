//
//  TranslationImageBody.h
//  MagicHelper
//
//  Created by ymz on 2025/8/15.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TranslationImageBody : NSObject

/// 请求id,请求方自定
@property (nonatomic, strong) NSString *qid;

/// 用户id
@property (nonatomic, strong) NSString *userId;


/// 最大token数， 默认200，最大2000
@property (nonatomic, assign) NSInteger max_tokens;

/// 图片路径
@property (nonatomic, strong, nullable) NSString *imageFilePath;

/// 图片数据（imageFilePath, imageData二选一设置，同时设置优先使用imageData）
@property (nonatomic, strong, nullable) NSData *imageData;

/// 目标语言
@property (nonatomic, strong) NSString *targetLanguage;


@end

NS_ASSUME_NONNULL_END
