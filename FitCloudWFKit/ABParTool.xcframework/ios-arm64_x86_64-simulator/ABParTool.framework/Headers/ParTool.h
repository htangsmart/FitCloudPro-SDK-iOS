//
//  ParTool.h
//  ABParTool
//
//  Created by Bluetrum on 2024/3/27.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface ParTool : NSObject

/// 转换原始图像数据到PAR格式图像
/// - Parameters:
///   - rawImageData: 原始图像数据
///   - width: 图像宽度
///   - height: 图像高度
///   - runAlpha: 是否处理Alpha通道
///   - useFilter: 是否使用滤镜
///   - supportRotate: PAR图像是否支持旋转
/// - Returns: PAR格式图像数据
+ (nullable NSData *)parFromRaw:(NSData *)rawImageData width:(int)width height:(int)height runAlpha:(BOOL)runAlpha useFilter:(BOOL)useFilter supportRotate:(BOOL)supportRotate;

/// 转换原始图像数据到RLE格式图像
/// - Parameters:
///   - rawImageData: 原始图像数据
///   - width: 图像宽度
///   - height: 图像高度
///   - transparentColor: 透明色
/// - Returns: RLE格式图像数据
+ (nullable NSData *)rleFromRaw:(NSData *)rawImageData width:(int)width height:(int)height transparentColor:(int)transparentColor;

/// 转换原始图像数据到PAR V3格式图像
/// - Parameters:
///   - rawImageData: 原始图像数据
///   - width: 图像宽度
///   - height: 图像高度
///   - runAlpha: 是否处理Alpha通道
///   - useFilter: 是否使用滤镜
/// - Returns: PAR V3格式图像数据
+ (nullable NSData *)parv3FromRaw:(NSData *)rawImageData width:(int)width height:(int)height runAlpha:(BOOL)runAlpha useFilter:(BOOL)useFilter;

/// 转换UIImage到PAR格式图像
/// - Parameters:
///   - image: UIImage
///   - runAlpha: 是否处理Alpha通道
///   - useFilter: 是否使用滤镜
///   - supportRotate: PAR图像是否支持旋转
/// - Returns: PAR格式图像数据
+ (nullable NSData *)parFromImage:(UIImage *)image runAlpha:(BOOL)runAlpha useFilter:(BOOL)useFilter supportRotate:(BOOL)supportRotate;

/// 转换压缩图像数据到PAR格式图像
/// - Parameters:
///   - imageData: 压缩图像数据，格式为[UIImage imageWithData:data]支持格式
///   - runAlpha: 是否处理Alpha通道
///   - useFilter: 是否使用滤镜
///   - supportRotate: PAR图像是否支持旋转
/// - Returns: PAR格式图像数据
+ (nullable NSData *)parFromImageData:(NSData *)imageData runAlpha:(BOOL)runAlpha useFilter:(BOOL)useFilter supportRotate:(BOOL)supportRotate;

/// 转换UIImage到PAR V3格式图像
/// - Parameters:
///   - image: UIImage
///   - runAlpha: 是否处理Alpha通道
///   - useFilter: 是否使用滤镜
/// - Returns: PAR V3格式图像数据
+ (nullable NSData *)parv3FromImage:(UIImage *)image runAlpha:(BOOL)runAlpha useFilter:(BOOL)useFilter;

/// 转换压缩图像数据到PAR V3格式图像
/// - Parameters:
///   - imageData: 压缩图像数据，格式为[UIImage imageWithData:data]支持格式
///   - runAlpha: 是否处理Alpha通道
///   - useFilter: 是否使用滤镜
/// - Returns: PAR V3格式图像数据
+ (nullable NSData *)parv3FromImageData:(NSData *)imageData runAlpha:(BOOL)runAlpha useFilter:(BOOL)useFilter;

/// 转换UIImage到RLE格式图像
/// - Parameters:
///   - image: UIImage
///   - transparentColor: 透明色
/// - Returns: RLE格式图像数据
+ (nullable NSData *)rleFromImage:(UIImage *)image transparentColor:(int)transparentColor;

/// 转换压缩图像数据到RLE格式图像
/// - Parameters:
///   - imageData: 压缩图像数据，格式为[UIImage imageWithData:data]支持格式
///   - transparentColor: 透明色
/// - Returns: RLE格式图像数据
+ (nullable NSData *)rleFromImageData:(NSData *)imageData transparentColor:(int)transparentColor;

@end

NS_ASSUME_NONNULL_END
