//
//  AIGCV3RequestBody.h
//  MagicHelper
//
//  Created by ymz on 2024/5/9.
//

#import <Foundation/Foundation.h>
#import "ChatPictureRequestBody.h"

NS_ASSUME_NONNULL_BEGIN

@interface AIGCV3RequestBody : NSObject

/// 请求id，有默认值，调用方也可自定,该值也会在结果回调中返回
@property (nonatomic, strong) NSString *qid;

/********************文生图专用**********************/
/// 输入的文本
@property (nonatomic, strong) NSString *prompt;
/// prompt对应语种，支持的语种见文档
@property (nonatomic, strong) NSString *language;

/********************图生图专用**********************/
/// 参考图，需 base64 编码，大小不超过 10M，最短边至少 15px，最长边最大 8192px，支持jpg/jpeg/png/bmp 格式
@property (nonatomic, strong) NSString *image;
/// 参考图影响因子，支持 1-10 内；数值越大参考图影响越大
@property (nonatomic, assign) NSInteger change_degree;

/**===============================================**/

/// 图片大小（只支持下列size,不支持自定义）
/// 512x512、640x360、360x640、1024x1024、1280x720、720x1280、2048x2048、2560x1440、1440x2560
@property (nonatomic, assign) NSInteger width;
@property (nonatomic, assign) NSInteger height;

/// 图片生成的数量最多2张
/// 返回的实际张数可能会小于该值
@property (nonatomic, assign) NSInteger batchSize;

/// 风格类型，见BDMagicHelper.aigcV3Styles
/// 如果不传则默认现实风格
@property (nonatomic, strong, nullable) NSString *style;

/// 指定结果回调中的数据类型，默认image
/// 指定AIImageReturnWithUrl，url只有一个小时的有效期，同时如果返回结果中包含Authorization字段，则访问该url时，需设置header为{@"Authorization": @"返回结果中Authorization对应的值"}
@property (nonatomic, assign) AIImageReturnType imageReturnType;


/// defaultBody中包含固定参数和可变参数，如要修改请基于defaultBody修改其中属性
+ (AIGCV3RequestBody *)defaultBody;

@end

NS_ASSUME_NONNULL_END
