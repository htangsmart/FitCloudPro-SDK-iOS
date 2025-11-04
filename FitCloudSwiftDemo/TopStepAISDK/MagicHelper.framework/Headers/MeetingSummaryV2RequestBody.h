//
//  MeetingSummaryV2RequestBody.h
//  MagicHelper
//
//  Created by ymz on 2025/6/3.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface MeetingSummaryV2RequestBody : NSObject

/// 请求id，有默认值，调用方也可自定,该值也会在结果回调中返回
@property (nonatomic, strong) NSString *qid;
/// 文本
@property (nonatomic, strong) NSString *content;
/// 模版id
@property (nonatomic, assign) NSString *templateId;
/// 语言，例如"zh-CN"
@property (nonatomic, strong) NSString *language;
@end

NS_ASSUME_NONNULL_END
