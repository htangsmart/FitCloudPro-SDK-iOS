//
//  MeetingSummaryRequestBody.h
//  MagicHelper
//
//  Created by ymz on 2025/4/16.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface MeetingSummaryRequestBody : NSObject

/// 请求id，有默认值，调用方也可自定,该值也会在结果回调中返回
@property (nonatomic, strong) NSString *qid;
/// 语言
@property (nonatomic, strong) NSString *language;
/// 音频路径(注意要是wav格式的)
@property (nonatomic, strong) NSString *audioPath;

@end

NS_ASSUME_NONNULL_END
