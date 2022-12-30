//
//  FitCloudWFKit.h
//  FitCloudWFKit
//
//  Created by pcjbird on 7/10/20.
//  Copyright © 2020 Zero Status. All rights reserved.
//
//  框架名称:FitCloudWFKit.framework
//  框架功能:iOS framework help you creating watchface with fitcloud smart watch easily. FitCloud 智能手表表盘创建辅助框架，旨在帮助您轻松创建属于您自己的表盘文件。
//  修改记录:
//     pcjbird    2022-12-30 Version:1.1.6 Build:202212300001
//                            1.更新错误码翻译
//
//     pcjbird    2022-05-19 Version:1.1.5 Build:202205190001
//                            1.新增印地语
//                            2.bitcode支持
//
//     pcjbird    2022-01-24 Version:1.1.4 Build:202201240001
//                            1.修正修改游戏皮肤推送位置不正确的问题
//
//     pcjbird    2021-11-03 Version:1.1.3 Build:202111030001
//                            1.新增修改手表运动的推送位置
//
//     pcjbird    2021-06-17 Version:1.1.2 Build:202106170001
//                            1.新增修改游戏皮肤的推送位置
//
//     pcjbird    2021-06-16 Version:1.1.1 Build:202106160001
//                            1.Next GUI 表盘图片存储优化
//
//     pcjbird    2021-06-05 Version:1.1.0 Build:202106050001
//                            1.Next GUI 支持修改表盘编号
//
//     pcjbird    2021-06-01  Version:1.0.9 Build:202106010001
//                            1.修正 Next GUI 自定义表盘生成圆角处理的问题
//
//     pcjbird    2021-05-26  Version:1.0.8 Build:202105260001
//                            1.Next GUI 自定义表盘生成支持
//
//     pcjbird    2021-02-02  Version:1.0.7 Build:202102020001
//                            1.自定义表盘增加文件大小信息的日志打印
//
//     pcjbird    2021-01-28  Version:1.0.6 Build:202101280002
//                            1.新增修改表盘的推送位置
//
//     pcjbird    2020-09-28  Version:1.0.5 Build:202009280001
//                            1.新增土耳其语/乌克兰语
//
//     pcjbird    2020-08-21  Version:1.0.4 Build:202008210001
//                            1.支持设置圆角，缩略图的圆角会根据背景圆角大小按比例自动缩放
//
//     pcjbird    2020-08-14  Version:1.0.3 Build:202008140001
//                            1.新增克罗地亚语/阿尔巴尼亚语
//
//     pcjbird    2020-07-18  Version:1.0.2 Build:202007180001
//                            1.rename to FitCloudWFKit
//
//     pcjbird    2020-07-16  Version:1.0.1 Build:202007160001
//                            1.自动裁剪背景图/预览图
//
//     pcjbird    2020-07-10  Version:1.0.0 Build:202007100001
//                            1.首次发布SDK版本
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import <FitCloudWFKit/FCWKErrorCode.h>

//! Project version number for FitCloudWFKit.
FOUNDATION_EXPORT double FitCloudWFKitVersionNumber;

//! Project version string for FitCloudWFKit.
FOUNDATION_EXPORT const unsigned char FitCloudWFKitVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <FitCloudWFKit/PublicHeader.h>

/**
 * @brief 日志等级
*/
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

/**
 * @brief 日期时间在表盘上的位置
 */
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
 * @brief 表盘生成辅助框架
 */
@interface FitCloudWFKit : NSObject

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


/**
 * @brief 根据模版Bin文件修改表盘的推送位置，生成新的表盘Bin文件
 * @param pushIndex 推送索引，取值范围 1～8
 * @param templateBin 模版Bin文件路径
 * @param logging 日志
 * @param completion 结果回调
*/
+(void) modifyWatchfaceBinPushIndexTo:(NSInteger)pushIndex fromTemplateBin:(NSString*_Nonnull)templateBin logging:(FitCloudWatchfaceLoggingMessage _Nullable)logging completion:(FitCloudWatchfacePushIndexModifyResultBlock _Nullable)completion;

/**
 * @brief 根据模版Bin文件修改游戏皮肤的推送位置，生成新的游戏皮肤Bin文件
 * @param pushIndex 推送索引，取值范围 1～10
 * @param templateBin 模版Bin文件路径
 * @param logging 日志
 * @param completion 结果回调
*/
+(void) modifyGameSkinBinPushIndexTo:(NSInteger)pushIndex fromTemplateBin:(NSString*_Nonnull)templateBin logging:(FitCloudGameSkinLoggingMessage _Nullable)logging completion:(FitCloudGameSkinPushIndexModifyResultBlock _Nullable)completion;

/**
 * @brief 根据模版Bin文件修改手表运动的推送位置，生成新的手表运动Bin文件
 * @param pushIndex 推送索引，取值范围 1～N
 * @param templateBin 模版Bin文件路径
 * @param logging 日志
 * @param completion 结果回调
*/
+(void) modifyWatchSportsBinPushIndexTo:(NSInteger)pushIndex fromTemplateBin:(NSString*_Nonnull)templateBin logging:(FitCloudWatchSportsLoggingMessage _Nullable)logging completion:(FitCloudWatchSportsBinPushIndexModifyResultBlock _Nullable)completion;

@end
