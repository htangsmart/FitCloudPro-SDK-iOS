//
//  FitCloudPlaylist.h
//  FitCloudDFUKit
//
//  Created by pcjbird on 6/12/23.
//  Copyright © 2023 Zero Status. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <FitCloudDFUKit/FitCloudSong.h>

/// 歌曲播放清单
@interface FitCloudPlaylist : NSObject

+ (instancetype _Nullable)new NS_UNAVAILABLE;
- (instancetype _Nullable)init NS_UNAVAILABLE;

/// 播放清单名称
@property (nonatomic, strong, readonly) NSString * _Nonnull name;

/// 歌曲列表
@property (nonatomic, strong, readonly) NSArray <FitCloudSong*> * _Nullable songs;

/// 初始化播放清单
/// - Parameters:
///   - plName: 名称
///   - songs: 歌曲列表
/// - Returns: 播放清单
- (instancetype _Nonnull )initWithName:(NSString *_Nonnull)plName songs:(nullable NSArray <FitCloudSong*> *)songs;

/// 添加歌曲
/// - Parameters:
///   - song: 歌曲
- (void)addSong:(FitCloudSong *_Nonnull)song;

/// 移除歌曲
/// - Parameters:
///   - song: 歌曲
- (void)removeSong:(FitCloudSong *_Nonnull)song;

/// 移除所有歌曲
- (void)removeAllSongs;

@end


