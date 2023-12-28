//
//  RTKLPBPlayList.h
//  LocalPlayback
//
//  Created by jerome_gu on 2020/7/29.
//  Copyright © 2020 jerome_gu. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <RTKLocalPlaybackSDK/RTKLPBFile.h>

NS_ASSUME_NONNULL_BEGIN

/// Represents a playlist item in a LPB peripheral.
///
/// You don't create an `RTKLPBPlayList` instance yourself. Instead, you can retrieve all playlists of a peripheral by the`RTKLPBConnectionUponGATT`object that manages the connection of it.
@interface RTKLPBPlayList : NSObject

/// The name of this playlist.
@property (nonatomic, copy, readonly) NSString *name;

/// All songs contained in this playlist.
@property (nonatomic, readonly) NSArray <RTKLPBSong*> *songs;

@end

NS_ASSUME_NONNULL_END
