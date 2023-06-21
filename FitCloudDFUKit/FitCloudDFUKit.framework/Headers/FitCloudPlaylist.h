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


@end


