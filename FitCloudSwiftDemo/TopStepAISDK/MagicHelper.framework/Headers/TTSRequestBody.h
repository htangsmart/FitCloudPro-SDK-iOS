

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TTSRequestBody : NSObject

/// 文本
@property (nonatomic, strong) NSString *text;

/// 请求id，有默认值，调用方也可自定,该值也会在结果回调中返回
@property (nonatomic, strong) NSString *qid;

/// 发声人物 0：女一 1：男一 3：男二 4：女二 , 默认4
@property (nonatomic, assign) NSInteger person;

/// 语速，取值0-15，默认为5
@property (nonatomic, assign) NSInteger speed;

/// 音量，0-9，默认5， 取值为0时为音量最小值，并非为无声
@property (nonatomic, assign) NSInteger volume;

/// 音调，取值0-15，默认为5中语调
@property (nonatomic, assign) NSInteger tone;

@end

NS_ASSUME_NONNULL_END
