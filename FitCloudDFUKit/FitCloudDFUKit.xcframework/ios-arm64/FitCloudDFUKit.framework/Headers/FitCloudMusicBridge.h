//
//  FitCloudMusicBridge.h
//  FitCloudDFUKit
//
//  Created by pcjbird on 6/12/23.
//  Copyright © 2023 Zero Status. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <FitCloudDFUKit/FitCloudSong.h>
#import <FitCloudDFUKit/FitCloudPlaylist.h>
#import <CoreBluetooth/CoreBluetooth.h>
#import <FitCloudDFUKit/FitCloudDFUKit.h>

typedef void(^FitCloudMusicCompletionBlock)(BOOL success, NSError *_Nullable error);

@class FitCloudMusicBridge;

@protocol FitCloudMusicBridgeDelegate <NSObject>

@optional

/// 激活结果回调
/// - Parameters:
///   - bridge: 音乐管理Bridge
///   - success: 是否成功
///   - error: 错误信息
-(void) bridge:(FitCloudMusicBridge*_Nonnull)bridge didActivate:(BOOL)success error:(NSError* _Nullable)error;


@end

/// 音乐管理Bridge
@interface FitCloudMusicBridge : NSObject

/// 代理
@property (nonatomic, weak, nullable) id<FitCloudMusicBridgeDelegate> delegate;

/// 芯片厂商
@property(nonatomic, readonly) FITCLOUDDFUCHIPVENDOR chipVendor;

/// 是否已经激活
@property(nonatomic, readonly) BOOL activated;

/// 歌曲列表
@property (nonatomic, strong, nullable, readonly) NSArray <FitCloudSong*> *songs;

/// 播放清单列表
@property (nonatomic, strong, nullable, readonly) NSArray <FitCloudPlaylist*> *playlists;

/// SD卡总空间
@property (nonatomic, readonly) NSUInteger totalSpace;

/// SD卡剩余空间
@property (nonatomic, readonly) NSUInteger freeSpace;


///获取歌曲列表
- (void)getSongsWithCompletionHandler:(void(^_Nullable)(BOOL success, NSError * _Nullable error, NSArray <FitCloudSong*> * _Nullable songs))handler;

/// 添加歌曲
- (NSProgress *_Nullable)addNewSongWithFile:(NSString *_Nonnull)filePath completionHandler:(void(^_Nullable)(BOOL success, NSError * _Nullable error, FitCloudSong * _Nonnull newSong))handler;

/// 添加歌曲列表
- (NSProgress *_Nullable)addNewSongsWithFiles:(NSMutableArray <NSString *> *_Nonnull)filePaths completionHandler:(void(^_Nullable)(BOOL success, NSError * _Nullable error))handler;


/// 取消发送歌曲
- (void)cancelSongSendingWithCompletionHandler:(FitCloudMusicCompletionBlock _Nullable )handler;

/// 删除歌曲
- (void)deleteSong:(FitCloudSong *_Nonnull)song withCompletionHandler:(FitCloudMusicCompletionBlock _Nullable )handler;

/// 删除歌曲列表
- (void)deleteSongs:(NSMutableArray <FitCloudSong *> *_Nonnull)songs withCompletionHandler:(FitCloudMusicCompletionBlock _Nullable )handler;

///删除所有歌曲
- (void)deleteAllSongsWithCompletionHandler:(FitCloudMusicCompletionBlock _Nullable )handler DEPRECATED_MSG_ATTRIBUTE("Delete all only song files not support now.");

/// 添加歌曲到播放清单
- (void)addSong:(FitCloudSong *_Nonnull)song toPlayList:(FitCloudPlaylist *_Nonnull)playlist withCompletionHandler:(FitCloudMusicCompletionBlock _Nullable )handler;

/// 从播放清单中移除歌曲
- (void)removeSong:(FitCloudSong *_Nonnull)song fromPlayList:(FitCloudPlaylist *_Nonnull)playlist withCompletionHandler:(FitCloudMusicCompletionBlock _Nullable)handler;

/// 获取SD空间信息
- (void)getSDSpaceWithCompletionHandler:(nullable void (^)(BOOL success, NSError *_Nullable error, NSUInteger totalSpace, NSUInteger freeSpace))handler;


+ (instancetype _Nullable)new NS_UNAVAILABLE;
- (instancetype _Nullable)init NS_UNAVAILABLE;

/// 初始化MusicBridge
/// - Parameters:
///   - peripheral: 外设
///   - chipVendor: 芯片厂商
///   - delegate: 代理
/// - Returns: MusicBridge
- (instancetype _Nullable)initWithPeripheral:(CBPeripheral *_Nonnull) peripheral chipVendor:(FITCLOUDDFUCHIPVENDOR)chipVendor delegate:(id<FitCloudMusicBridgeDelegate>_Nullable)delegate;

/// 激活
- (void) activateWithCompletionHandler:(FitCloudMusicCompletionBlock _Nullable)handler;
@end


