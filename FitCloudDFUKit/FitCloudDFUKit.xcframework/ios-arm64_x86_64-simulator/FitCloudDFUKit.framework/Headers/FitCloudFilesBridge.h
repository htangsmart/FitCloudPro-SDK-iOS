//
//  FitCloudFilesBridge.h
//  FitCloudDFUKit
//
//  Created by pcjbird on 12/5/23.
//  Copyright © 2023 Zero Status. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <FitCloudDFUKit/FitCloudFile.h>
#import <CoreBluetooth/CoreBluetooth.h>
#import <FitCloudDFUKit/FitCloudDFUKit.h>

typedef void(^FitCloudFilesCompletionBlock)(BOOL success, NSError *_Nullable error);

@class FitCloudFilesBridge;

@protocol FitCloudFilesBridgeDelegate <NSObject>

@optional

/// 激活结果回调
/// - Parameters:
///   - bridge: 文件管理Bridge
///   - success: 是否成功
///   - error: 错误信息
-(void) bridge:(FitCloudFilesBridge*_Nonnull)bridge didActivate:(BOOL)success error:(NSError* _Nullable)error;


@end

/// 文件管理Bridge
@interface FitCloudFilesBridge : NSObject

/// 代理
@property (nonatomic, weak, nullable) id<FitCloudFilesBridgeDelegate> delegate;

/// 芯片厂商
@property(nonatomic, readonly) FITCLOUDDFUCHIPVENDOR chipVendor;

/// 是否已经激活
@property(nonatomic, readonly) BOOL activated;

/// 文件列表
@property (nonatomic, strong, nullable, readonly) NSArray <FitCloudFile*> *files;

/// SD卡总空间
@property (nonatomic, readonly) NSUInteger totalSpace;

/// SD卡剩余空间
@property (nonatomic, readonly) NSUInteger freeSpace;

/// Flash总空间
@property (nonatomic, readonly) NSUInteger totalFlashSpace;

/// Flash剩余空间
@property (nonatomic, readonly) NSUInteger freeFlashSpace;


///获取文件列表
- (void)getFilesWithCompletionHandler:(void(^_Nullable)(BOOL success, NSError * _Nullable error, NSArray <FitCloudFile*> * _Nullable files))handler;

/// 添加文件
- (NSProgress *_Nullable)addNewFile:(NSString *_Nonnull)filePath completionHandler:(void(^_Nullable)(BOOL success, NSError * _Nullable error, FitCloudFile * _Nonnull newFile))handler;

/// 添加文件列表
- (NSProgress *_Nullable)addNewFiles:(NSArray <NSString *> *_Nonnull)filePaths completionHandler:(void(^_Nullable)(BOOL success, NSError * _Nullable error, NSArray<FitCloudFile*> * _Nullable newFiles))handler;


/// 取消发送文件
- (void)cancelFileSendingWithCompletionHandler:(FitCloudFilesCompletionBlock _Nullable )handler;

/// 删除文件
- (void)deleteFile:(FitCloudFile *_Nonnull)file withCompletionHandler:(FitCloudFilesCompletionBlock _Nullable )handler;

/// 删除文件列表
- (void)deleteFiles:(NSMutableArray <FitCloudFile *> *_Nonnull)files withCompletionHandler:(FitCloudFilesCompletionBlock _Nullable )handler;

///删除所有文件
- (void)deleteAllFilesWithCompletionHandler:(FitCloudFilesCompletionBlock _Nullable )handler;


/// 获取SD空间信息
- (void)getSDSpaceWithCompletionHandler:(nullable void (^)(BOOL success, NSError *_Nullable error, NSUInteger totalSpace, NSUInteger freeSpace))handler;

/// 获取Flash空间信息
- (void)getFlashSpaceWithCompletionHandler:(nullable void (^)(BOOL success, NSError *_Nullable error, NSUInteger totalSpace, NSUInteger freeSpace))handler;


+ (instancetype _Nullable)new NS_UNAVAILABLE;
- (instancetype _Nullable)init NS_UNAVAILABLE;

/// 初始化MusicBridge
/// - Parameters:
///   - peripheral: 外设
///   - chipVendor: 芯片厂商
///   - delegate: 代理
/// - Returns: MusicBridge
- (instancetype _Nullable)initWithPeripheral:(CBPeripheral *_Nonnull) peripheral chipVendor:(FITCLOUDDFUCHIPVENDOR)chipVendor delegate:(id<FitCloudFilesBridgeDelegate>_Nullable)delegate;

/// 激活
- (void) activateWithCompletionHandler:(FitCloudFilesCompletionBlock _Nullable)handler;

@end

