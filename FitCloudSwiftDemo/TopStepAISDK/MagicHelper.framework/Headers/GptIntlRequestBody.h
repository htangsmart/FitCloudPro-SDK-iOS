

#import <Foundation/Foundation.h>
#import "ChatRequestBody.h"

NS_ASSUME_NONNULL_BEGIN

@interface GptIntlRequestBody : NSObject

/// 请求id，有默认值，调用方也可自定,该值也会在结果回调中返回
@property (nonatomic, strong) NSString *qid;

/// 任务id,上一流程返回的tid，没有就不传
@property (nonatomic, strong, nullable) NSString *tid;

/// 输入文本
@property (nonatomic, strong) NSString *prompt;

/// 语种
@property (nonatomic, strong) NSString *language;

/// 用户id
@property (nonatomic, strong) NSString *userId;

/// 是否返回流
@property (nonatomic, assign) BOOL stream;

/// 最大token数， 默认200，最大2000
@property (nonatomic, assign) NSInteger max_tokens;

/// 是否关联上下文，默认关闭，开启后需传入messages
@property (nonatomic, assign) BOOL enableContext;

/// 是否开启搜索， 默认不开启
@property (nonatomic, assign) BOOL enableSearch;

/// 上下文信息
/// 支持MagicRoleTypeUser 和 MagicRoleTypeAssistant 必须是奇数个,必须以user开头，user结尾
/// 如 messages = @[ChatRequestBodyDataMessage.role = MagicRoleTypeUser,
///                 ChatRequestBodyDataMessage.role = MagicRoleTypeAssistant,
///                 ChatRequestBodyDataMessage.role = MagicRoleTypeUser,
/// ]
@property (nonatomic, strong, nullable) NSArray<ChatRequestBodyDataMessage *> *messages;

@end

NS_ASSUME_NONNULL_END
