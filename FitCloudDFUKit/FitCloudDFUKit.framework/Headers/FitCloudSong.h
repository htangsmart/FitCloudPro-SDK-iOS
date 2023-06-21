//
//  FitCloudSong.h
//  FitCloudDFUKit
//
//  Created by pcjbird on 6/12/23.
//  Copyright © 2023 Zero Status. All rights reserved.
//

#import <Foundation/Foundation.h>


/// 歌曲
@interface FitCloudSong : NSObject

+ (instancetype _Nullable)new NS_UNAVAILABLE;
- (instancetype _Nullable)init NS_UNAVAILABLE;

/// 名称
@property (nonatomic, strong, readonly) NSString * _Nonnull name;


@end

