//
//  FitCloudWFKit.h
//  FitCloudWFKit
//
//  Created by pcjbird on 7/10/20.
//  Copyright © 2020 Zero Status. All rights reserved.
//
//  框架名称:FitCloudWFKit.xcframework
//  框架功能:The iOS framework for the FitCloudPro smartwatch, which is designed to assist you in easily customizing your own watchface files.
//         FitCloudPro 智能手表表盘辅助框架， 旨在帮助您轻松自定义属于您自己的表盘文件。
//
//  构建版本:
//      pcjbird    2024-09-30  Version:1.1.7 Build:20240930001

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import <FitCloudWFKit/FCWKErrorCode.h>
#import <FitCloudWFKit/DevicePhotoCreateParams.h>

//! Project version number for FitCloudWFKit.
FOUNDATION_EXPORT double FitCloudWFKitVersionNumber;

//! Project version string for FitCloudWFKit.
FOUNDATION_EXPORT const unsigned char FitCloudWFKitVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <FitCloudWFKit/PublicHeader.h>

/// 日志等级
typedef NS_ENUM(NSInteger, FCWKLOGLEVEL) {
    FCWKLOGLEVEL_DEBUG = 0,
    FCWKLOGLEVEL_VERBOSE,
    FCWKLOGLEVEL_INFO,
    FCWKLOGLEVEL_WARNING,
    FCWKLOGLEVEL_ERROR,
    FCWKLOGLEVEL_EXCEPTION,
    FCWKLOGLEVEL_ABORT,
    FCWKLOGLEVEL_MIN = FCWKLOGLEVEL_DEBUG,
    FCWKLOGLEVEL_MAX = FCWKLOGLEVEL_ABORT,
    FCWKLOGLEVEL_MUTE = FCWKLOGLEVEL_MAX
};

/// 日期时间在表盘上的位置
typedef NS_ENUM(NSInteger, FITCLOUDWATCHFACEDTPOSITION)
{
    FITCLOUDWATCHFACEDTPOSITION_TOP = 0,         //上方
    FITCLOUDWATCHFACEDTPOSITION_BOTTOM = 1,      //下方
    FITCLOUDWATCHFACEDTPOSITION_LEFT = 2,        //左方
    FITCLOUDWATCHFACEDTPOSITION_RIGHT = 3,       //右方
};


/**
 *@brief 表盘生成进度
 *@param progress 进度百分比，0.0～1.0
 *@param message 进度提示
 */
typedef void (^FitCloudWatchfaceCreatingProgress)(CGFloat progress, NSString* _Nullable message);

/**
 *@brief 日志
 *@param level 日志等级
 *@param message 日志内容
*/
typedef void (^FitCloudWatchfaceLoggingMessage)(FCWKLOGLEVEL level, NSString* _Nullable message);

/**
 *@brief 日志
 *@param level 日志等级
 *@param message 日志内容
*/
typedef void (^FitCloudGameSkinLoggingMessage)(FCWKLOGLEVEL level, NSString* _Nullable message);

/**
 *@brief 日志
 *@param level 日志等级
 *@param message 日志内容
*/
typedef void (^FitCloudWatchSportsLoggingMessage)(FCWKLOGLEVEL level, NSString* _Nullable message);


/**
 *@brief 日志
 *@param level 日志等级
 *@param message 日志内容
*/
typedef void (^FitCloudWatchPhotoLoggingMessage)(FCWKLOGLEVEL level, NSString* _Nullable message);

/**
 *@brief 表盘生成结果
 *@param success 是否生成成功
 *@param resultBinPath 生成的表盘Bin文件路径
 *@param resultBkImage 处理后的背景图
 *@param resultPreview 处理后的预览图
 *@param error 错误
*/
typedef void(^FitCloudWatchfaceCreateResultBlock)(BOOL success, NSString* _Nullable resultBinPath, UIImage* _Nullable resultBkImage, UIImage* _Nullable resultPreview, NSError* _Nullable error);

/**
 *@brief 表盘推送位置修改结果
 *@param success 是否生成成功
 *@param resultBinPath 生成的表盘Bin文件路径
 *@param error 错误
*/
typedef void(^FitCloudWatchfacePushIndexModifyResultBlock)(BOOL success, NSString* _Nullable resultBinPath, NSError* _Nullable error);

/**
 *@brief 游戏皮肤推送位置修改结果
 *@param success 是否生成成功
 *@param resultBinPath 生成的游戏皮肤Bin文件路径
 *@param error 错误
*/
typedef void(^FitCloudGameSkinPushIndexModifyResultBlock)(BOOL success, NSString* _Nullable resultBinPath, NSError* _Nullable error);

/**
 *@brief 手表运动Bin推送位置修改结果
 *@param success 是否生成成功
 *@param resultBinPath 生成的手表运动Bin文件路径
 *@param error 错误
*/
typedef void(^FitCloudWatchSportsBinPushIndexModifyResultBlock)(BOOL success, NSString* _Nullable resultBinPath, NSError* _Nullable error);


/**
 *@brief 手表照片推送文件生成结果
 *@param success 是否生成成功
 *@param resultBinPath 生成的手表照片Bin文件路径
 *@param error 错误
*/
typedef void(^FitCloudWatchPhotoCreateResultBlock)(BOOL success, NSString* _Nullable resultBinPath, NSError* _Nullable error);


/**
 * @brief 表盘生成辅助框架
 */
@interface FitCloudWFKit : NSObject

#pragma mark 版本信息

/// SDK版本号
/// - Returns:
/// SDK 版本号
+(NSString*_Nonnull) sdkVersion;

/// SDK Build 版本号
/// - Returns:
/// SDK Build 版本号
+(NSString*_Nonnull) sdkBuild;


#pragma mark 根据模版Bin文件生成新的自定义表盘Bin文件

/**
 * @brief 根据模版Bin文件生成新的自定义表盘Bin文件
 * @param templateBin 模版Bin文件路径
 * @param isNextGUI 是否为下一代表盘GUI模版
 * @param nextGUIWatchfaceNo NextGUI表盘编号，为nil时表示不修改表盘编号，仅当isNextGUI为true时有效
 * @param bkImage 背景图
 * @param bkCornerRadius 背景图圆角大小
 * @param preview 预览图，您需要事先处理好预览图，例如圆形表盘你需要事先将预览图处理成圆形
 * @param dtPosition 表盘日期时间在表盘上的位置
 * @param progress 进度
 * @param logging 日志
 * @param completion 结果回调
*/
+(void) createWithTemplateBin:(NSString*_Nonnull)templateBin isNextGUI:(BOOL)isNextGUI rewriteNextGUIWatchfaceNo:(NSNumber* _Nullable)nextGUIWatchfaceNo bkImage:(UIImage*_Nonnull)bkImage bkCornerRadius:(CGFloat)bkCornerRadius preview:(UIImage*_Nonnull)preview dtPosition:(FITCLOUDWATCHFACEDTPOSITION)dtPosition progress:(FitCloudWatchfaceCreatingProgress  _Nullable)progress logging:(FitCloudWatchfaceLoggingMessage _Nullable)logging completion:(FitCloudWatchfaceCreateResultBlock _Nullable)completion;


#pragma mark 根据模版Bin文件修改表盘的推送位置，生成新的表盘Bin文件

/**
 * @brief 根据模版Bin文件修改表盘的推送位置，生成新的表盘Bin文件
 * @param pushIndex 推送索引，取值范围 1～8
 * @param templateBin 模版Bin文件路径
 * @param logging 日志
 * @param completion 结果回调
*/
+(void) modifyWatchfaceBinPushIndexTo:(NSInteger)pushIndex fromTemplateBin:(NSString*_Nonnull)templateBin logging:(FitCloudWatchfaceLoggingMessage _Nullable)logging completion:(FitCloudWatchfacePushIndexModifyResultBlock _Nullable)completion;

#pragma mark 根据模版Bin文件修改游戏皮肤的推送位置，生成新的游戏皮肤Bin文件

/**
 * @brief 根据模版Bin文件修改游戏皮肤的推送位置，生成新的游戏皮肤Bin文件
 * @param pushIndex 推送索引，取值范围 1～10
 * @param templateBin 模版Bin文件路径
 * @param logging 日志
 * @param completion 结果回调
*/
+(void) modifyGameSkinBinPushIndexTo:(NSInteger)pushIndex fromTemplateBin:(NSString*_Nonnull)templateBin logging:(FitCloudGameSkinLoggingMessage _Nullable)logging completion:(FitCloudGameSkinPushIndexModifyResultBlock _Nullable)completion;

#pragma mark 根据模版Bin文件修改手表运动的推送位置，生成新的手表运动Bin文件

/**
 * @brief 根据模版Bin文件修改手表运动的推送位置，生成新的手表运动Bin文件
 * @param pushIndex 推送索引，取值范围 1～N
 * @param templateBin 模版Bin文件路径
 * @param logging 日志
 * @param completion 结果回调
*/
+(void) modifyWatchSportsBinPushIndexTo:(NSInteger)pushIndex fromTemplateBin:(NSString*_Nonnull)templateBin logging:(FitCloudWatchSportsLoggingMessage _Nullable)logging completion:(FitCloudWatchSportsBinPushIndexModifyResultBlock _Nullable)completion;

#pragma mark 创建手表照片推送文件(bin)

/// 创建手表照片推送文件(bin)
/// - Parameters:
///   - photo: 照片
///   - params: 设备参数
///   - logging: 日志
///   - completion 结果回调
+(void) createPhotoBinWith:(UIImage*_Nonnull)photo
                parameters:(DevicePhotoCreateParams*_Nonnull)params
                   logging:(FitCloudWatchPhotoLoggingMessage _Nullable)logging
                completion:(FitCloudWatchPhotoCreateResultBlock _Nullable)completion;

@end
