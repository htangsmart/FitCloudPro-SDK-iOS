//
//  RTKLPBSong.h
//  LocalPlayback
//
//  Created by jerome_gu on 2020/7/29.
//  Copyright © 2020 jerome_gu. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// Constants each indicates a file format.
typedef NS_ENUM(NSUInteger, RTKLPBFileFormat) {
    RTKLPBFileFormat_unknown,       ///< The format is unknown currently
    RTKLPBFileFormat_mp3,           ///< A MP3 file.
    RTKLPBFileFormat_mp4,           ///< A MP4 file.
    RTKLPBFileFormat_rtk,           ///< A audio file that Realtek defined.
    RTKLPBFileFormat_aac,           ///< An AAC audio file.
    RTKLPBFileFormat_flac,          ///< A FLAC audio file.
    RTKLPBFileFormat_txt,           ///< A plain text file.
    RTKLPBFileFormat_dat,           ///< A data file.
    RTKLPBFileFormat_bin,           ///< A binary file
};

/// Represents a song item contained in a LPB peripheral.
///
/// Don't create an `RTKLPBSong` object yourself. Instead, call `-getSongsWithCompletionHandler:` on an `RTKLPBConnectionUponGATT` to retrieve all the song items shipped in the peripheral.
@interface RTKLPBFile : NSObject

/// The name of this song.
@property (nonatomic, copy, readonly) NSString *name;

/// The format of this file.
@property (readonly) RTKLPBFileFormat format;

@end

/// The legacy `RTKLPBSong` class is not defined as an alias name for `RTKLPBFile`.
///
/// The `RTKLPBSong` is defined for compatiblity and convenience. In semantic, a song is a subtype of a file. Generally you should not use RTKLPBSong class.
typedef RTKLPBFile RTKLPBSong;

NS_ASSUME_NONNULL_END
