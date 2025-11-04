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

/// 图片base64
@property (nonatomic, strong) NSString *imageBase64;

///
@property (nonatomic, strong) NSString *prompt;

@end

NS_ASSUME_NONNULL_END
