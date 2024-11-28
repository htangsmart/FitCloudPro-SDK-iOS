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
//      pcjbird    2024-11-28  Version:1.1.8-beta.2 Build:20241128001

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

/// Log level enumeration for FitCloudWFKit
/// - Note: Used to control logging verbosity and filtering
typedef NS_ENUM(NSInteger, FCWKLOGLEVEL) {
    /// Debug level logging for detailed troubleshooting
    FCWKLOGLEVEL_DEBUG = 0,
    /// Verbose level for detailed flow information
    FCWKLOGLEVEL_VERBOSE,
    /// Info level for general operational messages
    FCWKLOGLEVEL_INFO,
    /// Warning level for potentially harmful situations
    FCWKLOGLEVEL_WARNING,
    /// Error level for serious problems
    FCWKLOGLEVEL_ERROR,
    /// Exception level for caught exceptions
    FCWKLOGLEVEL_EXCEPTION,
    /// Abort level for fatal errors
    FCWKLOGLEVEL_ABORT,
    /// Minimum log level (same as DEBUG)
    FCWKLOGLEVEL_MIN = FCWKLOGLEVEL_DEBUG,
    /// Maximum log level (same as ABORT)
    FCWKLOGLEVEL_MAX = FCWKLOGLEVEL_ABORT,
    /// Mute all logging (same as MAX)
    FCWKLOGLEVEL_MUTE = FCWKLOGLEVEL_MAX
};

/// Position of date and time on the watch face
/// - Note: Defines the location where date and time information is displayed
typedef NS_ENUM(NSInteger, FITCLOUDWATCHFACEDTPOSITION) {
    /// Positioned at the top of the watch face
    FITCLOUDWATCHFACEDTPOSITION_TOP = 0,
    /// Positioned at the bottom of the watch face
    FITCLOUDWATCHFACEDTPOSITION_BOTTOM = 1,
    /// Positioned on the left side of the watch face
    FITCLOUDWATCHFACEDTPOSITION_LEFT = 2,
    /// Positioned on the right side of the watch face
    FITCLOUDWATCHFACEDTPOSITION_RIGHT = 3
};

/// A block type for reporting watch face creation progress
/// - Parameters:
///   - progress: The progress percentage, from 0.0 to 1.0
///   - message: A descriptive message about the current progress state
typedef void (^FitCloudWatchfaceCreatingProgress)(CGFloat progress, NSString *_Nullable message);

/// A block type for logging watch face related messages
/// - Parameters:
///   - level: The severity level of the log message
///   - message: The content of the log message
typedef void (^FitCloudWatchfaceLoggingMessage)(FCWKLOGLEVEL level, NSString *_Nullable message);

/// A block type for logging game skin related messages
/// - Parameters:
///   - level: The severity level of the log message
///   - message: The content of the log message
typedef void (^FitCloudGameSkinLoggingMessage)(FCWKLOGLEVEL level, NSString *_Nullable message);

/// A block type for logging watch sports related messages
/// - Parameters:
///   - level: The severity level of the log message
///   - message: The content of the log message
typedef void (^FitCloudWatchSportsLoggingMessage)(FCWKLOGLEVEL level, NSString *_Nullable message);

/// A block type for logging watch photo related messages
/// - Parameters:
///   - level: The severity level of the log message
///   - message: The content of the log message
typedef void (^FitCloudWatchPhotoLoggingMessage)(FCWKLOGLEVEL level, NSString *_Nullable message);

/// A block type for handling watch face creation results
/// - Parameters:
///   - success: Whether the creation was successful
///   - resultBinPath: The file path of the generated watch face binary file
///   - resultBkImage: The processed background image
///   - resultPreview: The processed preview image
///   - error: Any error that occurred during creation
typedef void (^FitCloudWatchfaceCreateResultBlock)(BOOL success, NSString *_Nullable resultBinPath, UIImage *_Nullable resultBkImage, UIImage *_Nullable resultPreview, NSError *_Nullable error);

/// A block type for handling watch face push index modification results
/// - Parameters:
///   - success: Whether the modification was successful
///   - resultBinPath: The file path of the generated watch face binary file
///   - error: Any error that occurred during modification
typedef void (^FitCloudWatchfacePushIndexModifyResultBlock)(BOOL success, NSString *_Nullable resultBinPath, NSError *_Nullable error);

/// A block type for handling game skin push index modification results
/// - Parameters:
///   - success: Whether the modification was successful
///   - resultBinPath: The file path of the generated game skin binary file
///   - error: Any error that occurred during modification
typedef void (^FitCloudGameSkinPushIndexModifyResultBlock)(BOOL success, NSString *_Nullable resultBinPath, NSError *_Nullable error);

/// A block type for handling watch sports binary push index modification results
/// - Parameters:
///   - success: Whether the modification was successful
///   - resultBinPath: The file path of the generated watch sports binary file
///   - error: Any error that occurred during modification
typedef void (^FitCloudWatchSportsBinPushIndexModifyResultBlock)(BOOL success, NSString *_Nullable resultBinPath, NSError *_Nullable error);

/// A block type for handling watch photo creation results
/// - Parameters:
///   - success: Whether the creation was successful
///   - resultBinPath: The file path of the generated watch photo binary file
///   - error: Any error that occurred during creation
typedef void (^FitCloudWatchPhotoCreateResultBlock)(BOOL success, NSString *_Nullable resultBinPath, NSError *_Nullable error);

/// A framework for assisting with watch face generation and management
@interface FitCloudWFKit : NSObject

#pragma mark Version Information

/// Get the SDK version number
/// - Returns: The current SDK version string
+ (NSString *_Nonnull)sdkVersion;

/// Get the SDK build number
/// - Returns: The current SDK build number string
+ (NSString *_Nonnull)sdkBuild;

#pragma mark Create Custom Watch Face Binary File From Template

/// Creates a new custom watch face binary file from a template
/// - Parameters:
///   - templateBin: The file path of the template binary file
///   - isNextGUI: Whether this is a next generation GUI template
///   - nextGUIWatchfaceNo: The watch face number for NextGUI, only valid when isNextGUI is true. Pass nil to keep original number
///   - bkImage: The background image
///   - bkCornerRadius: The corner radius for the background image
///   - preview: The preview image (should be pre-processed, e.g. circular for round watch faces)
///   - dtPosition: The position of date and time on the watch face
///   - progress: A block for reporting creation progress
///   - logging: A block for logging messages
///   - completion: A block for handling the creation result
+ (void)createWithTemplateBin:(NSString *_Nonnull)templateBin isNextGUI:(BOOL)isNextGUI rewriteNextGUIWatchfaceNo:(NSNumber *_Nullable)nextGUIWatchfaceNo bkImage:(UIImage *_Nonnull)bkImage bkCornerRadius:(CGFloat)bkCornerRadius preview:(UIImage *_Nonnull)preview dtPosition:(FITCLOUDWATCHFACEDTPOSITION)dtPosition progress:(FitCloudWatchfaceCreatingProgress _Nullable)progress logging:(FitCloudWatchfaceLoggingMessage _Nullable)logging completion:(FitCloudWatchfaceCreateResultBlock _Nullable)completion;

#pragma mark Modify Watch Face Push Index

/// Modifies the push index of a watch face binary file
/// - Parameters:
///   - pushIndex: The new push index (range: 1-8)
///   - templateBin: The file path of the template binary file
///   - logging: A block for logging messages
///   - completion: A block for handling the modification result
+ (void)modifyWatchfaceBinPushIndexTo:(NSInteger)pushIndex fromTemplateBin:(NSString *_Nonnull)templateBin logging:(FitCloudWatchfaceLoggingMessage _Nullable)logging completion:(FitCloudWatchfacePushIndexModifyResultBlock _Nullable)completion;

#pragma mark Modify Game Skin Push Index

/// Modifies the push index of a game skin binary file
/// - Parameters:
///   - pushIndex: The new push index (range: 1-10)
///   - templateBin: The file path of the template binary file
///   - logging: A block for logging messages
///   - completion: A block for handling the modification result
+ (void)modifyGameSkinBinPushIndexTo:(NSInteger)pushIndex fromTemplateBin:(NSString *_Nonnull)templateBin logging:(FitCloudGameSkinLoggingMessage _Nullable)logging completion:(FitCloudGameSkinPushIndexModifyResultBlock _Nullable)completion;

#pragma mark Modify Watch Sports Push Index

/// Modifies the push index of a watch sports binary file
/// - Parameters:
///   - pushIndex: The new push index (range: 1-N)
///   - templateBin: The file path of the template binary file
///   - logging: A block for logging messages
///   - completion: A block for handling the modification result
+ (void)modifyWatchSportsBinPushIndexTo:(NSInteger)pushIndex fromTemplateBin:(NSString *_Nonnull)templateBin logging:(FitCloudWatchSportsLoggingMessage _Nullable)logging completion:(FitCloudWatchSportsBinPushIndexModifyResultBlock _Nullable)completion;

#pragma mark Create Watch Photo Binary File

/// Creates a watch photo binary file
/// - Parameters:
///   - photo: The photo to convert
///   - params: Device-specific creation parameters
///   - logging: A block for logging messages
///   - completion: A block for handling the creation result
+ (void)createPhotoBinWith:(UIImage *_Nonnull)photo
                parameters:(DevicePhotoCreateParams *_Nonnull)params
                   logging:(FitCloudWatchPhotoLoggingMessage _Nullable)logging
                completion:(FitCloudWatchPhotoCreateResultBlock _Nullable)completion;

@end
