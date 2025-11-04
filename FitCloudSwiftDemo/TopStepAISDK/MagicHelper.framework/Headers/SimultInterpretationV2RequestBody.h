//
//  SimultInterpretationV2RequestBody.h
//  MagicHelper
//
//  Created by ymz on 2025/10/18.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface SimultInterpretationV2RequestBody : NSObject

/// 请求id，有默认值，调用方也可自定,该值也会在结果回调中返回
@property (nonatomic, strong) NSString *qid;
/// 源语言,例如zh-CN, (可不传，自动识别语言)
@property (nonatomic, strong, nullable) NSString *sourceLanguage;
/// 目标语言,例如zh-CN
@property (nonatomic, strong) NSString *targetLanguage;

@end

NS_ASSUME_NONNULL_END
