//
//  ChatRequestBodyV2.h
//  MagicHelper
//
//  Created by ymz on 2025/2/19.
//

#import <Foundation/Foundation.h>
#import "ChatRequestBody.h"

NS_ASSUME_NONNULL_BEGIN

@interface ChatRequestBodyV2 : NSObject

/// 请求id，有默认值，调用方也可自定,该值也会在结果回调中返回
@property (nonatomic, strong) NSString *qid;

/// 大模型类型，比如doubao 或者 deepseek
/// 该字段chatWithBodyV2可用
/// 见BDMagicHelper.getSupportedModelTypes
@property (nonatomic, strong, nullable) NSString *type;
/// 是否开启思考（目前只有type == deepseek时有效）
@property (nonatomic, assign) BOOL enableThought;

/// 输入文本
@property (nonatomic, strong) NSString *prompt;

/// 用户id
@property (nonatomic, strong) NSString *userId;

/// 是否返回流
@property (nonatomic, assign) BOOL stream;

/// 最大token数， 默认200，最大2000
@property (nonatomic, assign) NSInteger max_tokens;

/// 上下文信息
/// 支持MagicRoleTypeUser 和 MagicRoleTypeAssistant 必须是奇数个,必须以user开头，user结尾
/// 如 messages = @[ChatRequestBodyDataMessage.role = MagicRoleTypeUser,
///                 ChatRequestBodyDataMessage.role = MagicRoleTypeAssistant,
///                 ChatRequestBodyDataMessage.role = MagicRoleTypeUser,
/// ]
@property (nonatomic, strong, nullable) NSArray<ChatRequestBodyDataMessage *> *messages;

/// 目前不可用
@property (nonatomic, assign) BOOL isOpenIncercept;

@end

NS_ASSUME_NONNULL_END
