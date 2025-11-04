

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class ChatPictureParams;
@class ChatPictureIntlParams;

/// 指定图片返回类型
typedef NS_ENUM(NSInteger, AIImageReturnType) {
    AIImageReturnWithImage = 0,/**< 以image返回*/
    AIImageReturnWithUrl = 1,/**< 以url返回*/
};

@interface ChatPictureRequestBody : NSObject

/// 请求id，有默认值，调用方也可自定,该值也会在结果回调中返回
@property (nonatomic, strong) NSString *qid;

/// 任务id,上一流程返回的tid，没有就不传
@property (nonatomic, strong, nullable) NSString *tid;

/// 国内版参数列表，根据将要调用的接口选择设置国内版参数还是海外版参数
@property (nonatomic, strong) ChatPictureParams *params;

/// 海外版参数列表
@property (nonatomic, strong) ChatPictureIntlParams *intlParams;


/// 用户ID，defaultBody中有设置默认值
@property (nonatomic, strong) NSString *userId;

/// 业务令牌 推荐随机16位字符串，defaultBody中有设置默认值
@property (nonatomic, strong) NSString *token;

/// 指定结果回调中的数据类型，默认image
/// 指定AIImageReturnWithUrl，url只有一个小时的有效期，同时如果返回结果中包含Authorization字段，则访问该url时，需设置header为{@"Authorization": @"返回结果中Authorization对应的值"}
@property (nonatomic, assign) AIImageReturnType imageReturnType;

/// defaultBody中包含固定参数和可变参数，如要修改请基于defaultBody修改其中属性
+ (ChatPictureRequestBody *)defaultBody;

@end


@interface ChatPictureParams : NSObject

/// 输入的文本 （语音识别的时候传nil，或者空字符串）
@property (nonatomic, strong, nullable) NSString *query;

/// 提示词，比如 动物：一只可爱的小猫咪，其中动物就是提示词，一只可爱的小猫咪就是query的内容
@property (nonatomic, strong, nullable) NSString *tag;

/// 风格类型
@property (nonatomic, strong) NSString *style;

/// 图片生成的数量最多4张
/// 返回的实际张数可能会小于该值
@property (nonatomic, assign) NSInteger batchSize;

/// 图片宽度 512 ~ 1024
@property (nonatomic, assign) NSInteger width;

/// 图片高度 512 ~ 1024
@property (nonatomic, assign) NSInteger height;


+ (ChatPictureParams *)defaultParams;

@end


@interface ChatPictureIntlParams : NSObject

/// 输入的文本
/// 方法一：调用BDMagicHelper.intlAigc，则该字段是必填项
/// 方法二：调用BDMagicHelper.startWithAigcIntl，如果该字段有值则会跳过ASR，直接AIGC;
/// 反之则从ASR开始，SDK内部会自动将ASR的结果填充该字段发起AIGC
@property (nonatomic, strong, nullable) NSString *query;

/// 提示词，比如 动物：一只可爱的小猫咪，其中动物就是提示词，一只可爱的小猫咪就是query的内容
@property (nonatomic, strong, nullable) NSString *tag;

/// 语种，支持的语种见文档
/// 如果主动填写了query，则language也需要填写，不然会影响AIGC的准确性
@property (nonatomic, strong, nullable) NSString *language;

/// 风格类型，见BDMagicHelper.aiStyle
@property (nonatomic, strong) NSString *style;

/// 图片生成的数量最多2张
/// 返回的实际张数可能会小于该值
@property (nonatomic, assign) NSInteger batchSize;

/// 图片宽度 512x512、640x360、360x640、1024x1024、1280x720、720x1280、2048x2048、2560x1440、1440x2560
@property (nonatomic, assign) NSInteger width;

/// 图片高度 512x512、640x360、360x640、1024x1024、1280x720、720x1280、2048x2048、2560x1440、1440x2560
@property (nonatomic, assign) NSInteger height;

+ (ChatPictureIntlParams *)defaultParams;

@end

NS_ASSUME_NONNULL_END
