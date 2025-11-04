

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// 模型类型
typedef NSString * MagicChatMode NS_STRING_ENUM;

/// 海外版(支持多语言)
FOUNDATION_EXPORT MagicChatMode const MagicChatModeV2;

/// 国内版
FOUNDATION_EXPORT MagicChatMode const MagicChatModeV4;

/// 海外版
FOUNDATION_EXPORT MagicChatMode const MagicChatModeV6;

/// 上下文角色
typedef NSString * MagicRoleType NS_STRING_ENUM;
FOUNDATION_EXPORT MagicRoleType const MagicRoleTypeUser;
FOUNDATION_EXPORT MagicRoleType const MagicRoleTypeAssistant;


@class ChatRequestBodyData;
@class ChatRequestBodyDcsData;
@class ChatRequestBodyDataMessage;


/// chat参数模型
@interface ChatRequestBody : NSObject

/// 请求id,请求方自定
@property (nonatomic, strong) NSString *qid;

/// 用户id
@property (nonatomic, strong) NSString *userId;

/// 模型类型，默认MagicChatModeV4
@property (nonatomic, strong) MagicChatMode pid;

/// 模式 0:默认，融合模式； 1:仅助手模式；2:仅大模型模式
/// 注意：如果走混合模式，，会优先返回音频资源的
@property (nonatomic, assign) NSInteger mode;

/// 输入信息
@property (nonatomic, strong) ChatRequestBodyData *data;

/// 辅助信息
@property (nonatomic, strong) ChatRequestBodyDcsData *dcs_data;

/// 默认请求参数
+ (ChatRequestBody *)defaultBody;

@end


@interface ChatRequestBodyData : NSObject

/// 输入文本
@property (nonatomic, strong) NSString *prompt;

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

+ (ChatRequestBodyData *)defaultData;

@end

@interface ChatRequestBodyDataMessage : NSObject

/// 上下文角色
@property (nonatomic, strong) MagicRoleType role;

/// 上下文内容
@property (nonatomic, strong) NSString *content;

@end


@interface ChatRequestBodyDcsData : NSObject

/// 文本内容，该内容必须与ChatRequestBodyData.prompt相同
@property (nonatomic, strong) NSString *text;

/// 设备mac地址，该mac地址需要提前入库
@property (nonatomic, strong) NSString *cuid;

/// 配置版本
@property (nonatomic, strong) NSString *didp;

/// sessionid 客户端生成
@property (nonatomic, strong) NSString *sn;

/// dcs 上报时间 端状态信息
@property (nonatomic, strong) NSString *events;

+ (ChatRequestBodyDcsData *)defaultDcsData;

@end



NS_ASSUME_NONNULL_END
