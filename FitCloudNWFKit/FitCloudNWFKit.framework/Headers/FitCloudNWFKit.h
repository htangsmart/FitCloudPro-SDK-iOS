//
//  FitCloudNWFKit.h
//  FitCloudNWFKit
//
//  Created by pcjbird on 2021/8/31.
//

//  框架名称:FitCloudNWFKit.framework
//  框架功能:iOS framework help you creating nordic watchface with fitcloud smart watch easily. FitCloud 智能手表表盘创建辅助框架，旨在帮助您轻松创建属于您自己的Nordic芯片表盘文件。
//  修改记录:
//     pcjbird    2022-05-19  Version:1.0.1 Build:202205190001
//                            1.bitcode支持
//
//     pcjbird    2021-08-31  Version:1.0.0 Build:202108310001
//                            1.首次发布SDK版本
//

#import <Foundation/Foundation.h>
#import <FitCloudNWFKit/FCNWKErrorCode.h>

//! Project version number for FitCloudNWFKit.
FOUNDATION_EXPORT double FitCloudNWFKitVersionNumber;

//! Project version string for FitCloudNWFKit.
FOUNDATION_EXPORT const unsigned char FitCloudNWFKitVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <FitCloudNWFKit/PublicHeader.h>


/**
 * @brief 日志等级
*/
typedef NS_ENUM(NSInteger, FCNWKLOGLEVEL) {
    FCNWKLOGLEVEL_DEBUG = 0,
    FCNWKLOGLEVEL_VERBOSE,
    FCNWKLOGLEVEL_INFO,
    FCNWKLOGLEVEL_WARNING,
    FCNWKLOGLEVEL_ERROR,
    FCNWKLOGLEVEL_EXCEPTION,
    FCNWKLOGLEVEL_ABORT,
    FCNWKLOGLEVEL_MIN = FCNWKLOGLEVEL_DEBUG,
    FCNWKLOGLEVEL_MAX = FCNWKLOGLEVEL_ABORT,
    FCNWKLOGLEVEL_MUTE = FCNWKLOGLEVEL_MAX
};

/**
 *@brief 日志
 *@param level 日志等级
 *@param message 日志内容
*/
typedef void (^FitCloudNWatchfaceLoggingMessage)(FCNWKLOGLEVEL level, NSString* _Nullable message);

/**
 *@brief 表盘推送位置修改结果
 *@param success 是否生成成功
 *@param resultFilePath 生成的表盘文件路径
 *@param error 错误
*/
typedef void(^FitCloudNWatchfacePushIndexModifyResultBlock)(BOOL success, NSString* _Nullable resultFilePath, NSError* _Nullable error);


/**
 * @brief 表盘生成辅助框架
 */
@interface FitCloudNWFKit : NSObject


/**
 * @brief 根据模版文件修改表盘的推送位置，生成新的表盘文件
 * @param pushIndex 推送索引，取值范围 1～8
 * @param templateFile 模版文件路径
 * @param logging 日志
 * @param completion 结果回调
*/
+(void) modifyWatchfacePushIndexTo:(NSInteger)pushIndex fromTemplate:(NSString*_Nonnull)templateFile logging:(FitCloudNWatchfaceLoggingMessage _Nullable)logging completion:(FitCloudNWatchfacePushIndexModifyResultBlock _Nullable)completion;


@end
