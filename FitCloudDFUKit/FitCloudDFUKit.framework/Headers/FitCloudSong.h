//
//  FitCloudSong.h
//  FitCloudDFUKit
//
//  Created by pcjbird on 6/12/23.
//  Copyright © 2023 Zero Status. All rights reserved.
//

#import <Foundation/Foundation.h>

/// 播放清单
typedef NS_OPTIONS(NSInteger, FITCLOUDPLAYLISTINDEX) {
    /// 不在播放清单
    FITCLOUDPLAYLISTINDEX_NONE = 0,
    /// 播放清单1
    FITCLOUDPLAYLISTINDEX_1 = 0x01 << 0,
    /// 播放清单2
    FITCLOUDPLAYLISTINDEX_2 = 0x01 << 1,
    /// 播放清单3
    FITCLOUDPLAYLISTINDEX_3 = 0x01 << 2,
    /// 播放清单4
    FITCLOUDPLAYLISTINDEX_4 = 0x01 << 3,
    /// 播放清单5
    FITCLOUDPLAYLISTINDEX_5 = 0x01 << 4,
    /// 播放清单6
    FITCLOUDPLAYLISTINDEX_6 = 0x01 << 5,
    /// 播放清单7
    FITCLOUDPLAYLISTINDEX_7 = 0x01 << 6,
    /// 播放清单8
    FITCLOUDPLAYLISTINDEX_8 = 0x01 << 7,
    /// 播放清单9
    FITCLOUDPLAYLISTINDEX_9 = 0x01 << 8,
    /// 播放清单10
    FITCLOUDPLAYLISTINDEX_10 = 0x01 << 9,
    /// 播放清单11
    FITCLOUDPLAYLISTINDEX_11 = 0x01 << 10,
    /// 播放清单12
    FITCLOUDPLAYLISTINDEX_12 = 0x01 << 11,
    /// 播放清单13
    FITCLOUDPLAYLISTINDEX_13 = 0x01 << 12,
    /// 播放清单14
    FITCLOUDPLAYLISTINDEX_14 = 0x01 << 13,
    /// 播放清单15
    FITCLOUDPLAYLISTINDEX_15 = 0x01 << 14,
    /// 播放清单16
    FITCLOUDPLAYLISTINDEX_16 = 0x01 << 15,
};

/// 歌曲
@interface FitCloudSong : NSObject

+ (instancetype _Nullable)new NS_UNAVAILABLE;
- (instancetype _Nullable)init NS_UNAVAILABLE;


/// 编号
@property (nonatomic, readonly) NSUInteger index;

/// 播放清单
@property (nonatomic, readonly) FITCLOUDPLAYLISTINDEX playlist;

/// 名称
@property (nonatomic, strong, readonly) NSString * _Nonnull name;

/// 初始化歌曲
/// - Parameters:
///   - index: 编号
///   - name: 名称
/// - Returns: 歌曲
- (instancetype _Nonnull )initWithIndex:(NSUInteger)index name:(NSString*_Nonnull)name;

/// 初始化歌曲
/// - Parameters:
///   - index: 编号
///   - name: 名称
///   - playlist: 所属播放清单
/// - Returns: 歌曲
- (instancetype _Nonnull )initWithIndex:(NSUInteger)index name:(NSString*_Nonnull)name playlist:(FITCLOUDPLAYLISTINDEX)playlist;


/// 将歌曲添加到播放清单
/// - Parameters:
///   - playlist 播放清单
- (void)addToPlaylist:(FITCLOUDPLAYLISTINDEX)playlist;

/// 将歌曲从播放清单中移除
/// - Parameters:
///   - playlist 播放清单
- (void)removeFromPlaylist:(FITCLOUDPLAYLISTINDEX)playlist;

/// 判断歌曲是否在指定的播放清单中
/// - Parameters:
///   - playlist: 播放清单
/// - Returns: 是否在指定的播放清单中
- (BOOL) isInPlaylist:(FITCLOUDPLAYLISTINDEX)playlist;

@end

