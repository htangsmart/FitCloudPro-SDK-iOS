//
//  RTKLPBConnectionUponGATT.h
//  LocalPlayback
//
//  Created by jerome_gu on 2022/3/1.
//  Copyright © 2022 jerome_gu. All rights reserved.
//

#ifdef RTK_SDK_IS_STATIC_LIBRARY
#import "libRTKLEFoundation.h"
#import "RTKLPBFile.h"
#import "RTKLPBPlayList.h"
#else
#import <RTKLEFoundation/RTKLEFoundation.h>
#import <RTKLocalPlaybackSDK/RTKLPBFile.h>
#import <RTKLocalPlaybackSDK/RTKLPBPlayList.h>
#endif

NS_ASSUME_NONNULL_BEGIN

/// Information about the LPB(LocalPlayback) feature on a peripheral.
///
/// An `RTKLPBDeviceInfo` object encapsulates information about configurations and state of a peripheral.
/// You call `-getDeviceInfoWithCompletionHandler:` on an `RTKLPBConnectionUponGATT` to get this information.
@interface RTKLPBDeviceInfo : NSObject

/// The length of the exchanged packets.
@property (nonatomic, readonly) NSUInteger packetSize;

/// The size of a memory section which is used to perform Buffer Check.
@property (nonatomic, readonly) NSUInteger bufferCheckSize;

/// The version of the protocol for communicating with an app.
@property (nonatomic, readonly) NSUInteger protocolVersion;

/// Whether the peripheral is coupled.
///
/// - Returns `YES` if the peripheral is a member of a rws pair.
@property (nonatomic, readonly) BOOL isCoupled;

/// Whether the peripheral acts as the primary role.
@property (nonatomic, readonly) BOOL isPrimaryBud;

/// Returns an integer value identifing the ic information.
@property (nonatomic, readonly) NSUInteger ic;

/// A textual representation of the IC info of a peripheral.
@property (nonatomic, readonly) NSString *ICText;

@end


/// Represents a LPB profile GATT connection with a remote peripheral with  LPB feature supported.
///
/// An ``RTKLPBConnectionUponGATT`` object provides several methods you can use to interact with a connected peripheral, access information of the peripheral, add new files to the peripheral.
/// Before calling any methods, you should ensure that the `RTKLPBConnectionUponGATT` is active, you can activate a connection by calling `-activateWithCompletionHandler:`.
@interface RTKLPBConnectionUponGATT : RTKConnectionUponGATT

/// The retrieved information about LPB feature of the peripheral which this connection manages.
///
/// - Returns `nil` if this information is not settled.
///
/// A successful `-getDeviceInfoWithCompletionHandler:`  settles this property.
@property (nullable, readonly) RTKLPBDeviceInfo *deviceInfo;

/// All songs stored in the peripheral this connection manages.
///
/// - Returns `nil`if this property is not settled.
///
/// General, the songs this property indicates are a subset of all files indicated by `files` property.
/// A successfully `-getShippedFilesWithCompletionHandler:` or `-getSongsWithCompletionHandler:` will updates this property.
@property (nullable, readonly) NSArray <RTKLPBSong*> *songs;

/// A list of files shipped in the connected device.
///
/// - Returns `nil` if this info is not settled.
///
/// A successfully `-getShippedFilesWithCompletionHandler:` will update this property.
@property (nullable, readonly) NSArray <RTKLPBFile*> *files;

/// All playlists shipped with the peripheral which this connection manages.
///
/// - Returns `nil`if this property is not settled.
///
/// A successful activation of this connection settles this property.
@property (nullable, readonly) NSArray <RTKLPBPlayList*> *playlists;

/// Get the information about the connected device.
///
/// - Parameter handler: A block to be called once this task complete.
/// - Parameter success: Indicating if the task is successful or unsuccessful.
/// - Parameter error: A error object if the task fails, or `nil` if it succeeds.
/// - Parameter info: The retrieved information if task succeeds.
- (void)getDeviceInfoWithCompletionHandler:(void(^)(BOOL success, NSError *error, RTKLPBDeviceInfo *info))handler;

/// Get the space information of the SD card installed in the peripheral.
///
/// - Parameter handler: A block to be called once the task completes.
/// - Parameter success: Whether the task completes successfully or unsuccessfully.
/// - Parameter error: A error object if the task fails, or `nil` if it succeeds.
/// - Parameter totalSpace: The capacity of the SD card memory.
/// - Parameter freeSpace: The size of memory that is not used of the SD card.
- (void)getSDSpaceWithCompletionHandler:(void (^)(BOOL success, NSError *_Nullable error, NSUInteger totalSpace, NSUInteger freeSpace))handler;

/// Get the space information of Flash in the peripheral.
///
/// - Parameter handler: A block to be called once the task completes.
/// - Parameter success: Whether the task completes successfully or unsuccessfully.
/// - Parameter error: A error object if the task fails, or `nil` if it succeeds.
/// - Parameter totalSpace: The capacity of the total memory.
/// - Parameter freeSpace: The size of memory that is not used.
- (void)getFlashSpaceInfoWithCompletionHandler:(void (^)(BOOL success, NSError *_Nullable error, NSUInteger totalSpace, NSUInteger freeSpace))handler;

// MARK: -

/// Get the shipped files on the device.
///
/// - Parameter handler: A block to be called once the task completes.
/// - Parameter success: Indicating if the task is successful or unsuccessful.
/// - Parameter error: A error object if the task fails, or `nil` if it succeeds.
/// - Parameter files: A list of files.
- (void)getShippedFilesWithCompletionHandler:(void(^)(BOOL success, NSError *error, NSArray <RTKLPBFile*> *files))handler;

/// Add a new file to the device.
///
/// - Parameter handler: A block to be called once the task completes.
/// - Parameter success: Indicating if the task is successful or unsuccessful.
/// - Parameter error: A error object if the task fails, or `nil` if it succeeds.
/// - Parameter newFile: An object that represents the new added file.
///
/// - Returns a progress object which you can access progress information about this underlying transimission.
- (NSProgress *)addNewFile:(NSString *)filePath withCompletionHandler:(nullable void(^)(BOOL success, NSError *error, RTKLPBFile *newFile))handler;

/// Add a number of new files to the device.
///
/// - Parameters:
///     - filePaths: A list of file paths.
///     - handler: A block to be called once the task completes.
///     - success: Indicating if the task is successful or unsuccessful.
///     - error: A error object if the task fails, or `nil` if it succeeds.
///     - newFiles: A list of `RTKLPBFile` objects each represents a new added file.
///
/// - Returns a progress object which you can access progress information about this underlying transimission.
- (NSProgress *)addNewFiles:(NSArray <NSString *> *)filePaths withCompletionHandler:(nullable void(^)(BOOL success, NSError *error, NSArray<RTKLPBFile*> *newFiles))handler;

/// Cancel adding new file to the device.
///
/// - Parameter handler: A block to be called once the task completes.
/// - Parameter success: Indicating if the task is successful or unsuccessful.
/// - Parameter error: A error object if the task fails, or `nil` if it succeeds.
///
/// This method cancel the task started by ``addNewFile:withCompletionHandler:`` or ``addNewFiles:withCompletionHandler:``.
- (void)cancelAddingFileWithCompletionHandler:(nullable RTKLECompletionBlock)handler;


/// Delete a file in the device.
///
/// - Parameter file: The file to be deleted.
/// - Parameter handler: A block to be called once the task completes.
/// - Parameter success: Indicating if the task is successful or unsuccessful.
/// - Parameter error: A error object if the task fails, or `nil` if it succeeds.
- (void)deleteFile:(RTKLPBFile *)file withCompletionHandler:(nullable RTKLECompletionBlock)handler;

/// Delete all files which have the specified format type.
///
/// - Parameters:
///     - type: The type of which the file to be delete.
///     - handler: The block to be called when task completes.
- (void)deleteFilesByType:(RTKLPBFileFormat)type withCompletionHandler:(nullable RTKLECompletionBlock)handler;

/// Delete multiple files in the device.
///
/// - Parameter files: The files to be deleted.
/// - Parameter handler: A block to be called once the task completes.
/// - Parameter success: Indicating if the task is successful or unsuccessful.
/// - Parameter error: A error object if the task fails, or `nil` if it succeeds.
- (void)deleteFiles:(NSArray <RTKLPBFile*> *)files withCompletionHandler:(nullable RTKLECompletionBlock)handler;

/// Delete all files in the device.
///
/// - Parameter handler: A block to be called once the task completes.
/// - Parameter success: Indicating if the task is successful or unsuccessful.
/// - Parameter error: A error object if the task fails, or `nil` if it succeeds.
- (void)deleteAllFilesWithCompletionHandler:(nullable RTKLECompletionBlock)handler;


/// Get the songs saved in the device.
///
/// - Parameter handler: A block to be called once this task complete successfullly or unsuccessfully.
/// - Parameter success: Indicating if the task is successful or unsuccessful.
/// - Parameter error: A error object if the task fails, or `nil` if it succeeds.
/// - Parameter songs: A list of songs that are shipped with the connected peripheral if task succeeds. `nil` if the task fails.
- (void)getSongsWithCompletionHandler:(void(^)(BOOL success, NSError *error, NSArray <RTKLPBSong*> *songs))handler;

/// Add a new song to the connected device.
///
/// - Parameter filePath: The path of a song file to be added.
/// - Parameter handler: A block to be called once this task complete successfullly or unsuccessfully.
/// - Parameter success: Indicating if the task is successful or unsuccessful.
/// - Parameter error: A error object if the task fails, or `nil` if it succeeds.
/// - Parameter newSong: An `RTKLPBSong` object representing the just added song if task succeeds. `nil` if the task fails.
///
/// - Returns a progress object which convey song data transmission progress.
- (NSProgress *)addNewSongWithFile:(NSString *)filePath completionHandler:(void(^)(BOOL success, NSError *error, RTKLPBSong *newSong))handler  DEPRECATED_MSG_ATTRIBUTE("Use -addNewFile:withCompletionHandler: instead");

/// Add multiple songs to the connected device.
///
/// - Parameter filePaths: A list of file paths each containing data of a song.
/// - Parameter handler: A block to be called once this task complete successfullly or unsuccessfully.
/// - Parameter success: Indicating if the task is successful or unsuccessful.
/// - Parameter error: A error object if the task fails, or `nil` if it succeeds.
///
/// - Returns a progress object which convey song data transmission progress.
- (NSProgress *)addNewSongsWithFiles:(NSArray <NSString *> *)filePaths completionHandler:(void(^)(BOOL success, NSError *error))handler  DEPRECATED_MSG_ATTRIBUTE("Use -addNewFiles:withCompletionHandler: instead");


/// Cancel the transmission of song data.
///
/// - Parameter handler: A block to be called once this task complete successfullly or unsuccessfully.
- (void)cancelSongSendingWithCompletionHandler:(RTKLECompletionBlock)handler  DEPRECATED_MSG_ATTRIBUTE("Use -cancelAddingFileWithCompletionHandler: instead");

/// Delete a song from the peripheral.
///
/// - Parameter song: An object identifying a song item in the peripheral to be deleted.
/// - Parameter handler: A block to be called when this task complete successfullly or unsuccessfully.
- (void)deleteSong:(RTKLPBSong *)song withCompletionHandler:(RTKLECompletionBlock)handler  DEPRECATED_MSG_ATTRIBUTE("Use -deleteFile:withCompletionHandler: instead");


/// Delete multiple songs from the peripheral.
///
/// - Parameter songs: A list of song objects to be deleted.
/// - Parameter handler: A block to be called once this task complete successfullly or unsuccessfully.
- (void)deleteSongs:(NSArray <RTKLPBSong *> *)songs withCompletionHandler:(RTKLECompletionBlock)handler  DEPRECATED_MSG_ATTRIBUTE("Use -deleteFiles:withCompletionHandler: instead");


/// Delete all song items from the peripheral.
///
/// - Parameter handler: A block to be called when this task complete successfullly or unsuccessfully.
- (void)deleteAllSongsWithCompletionHandler:(RTKLECompletionBlock)handler  DEPRECATED_MSG_ATTRIBUTE("Use -deleteAllFilesWithCompletionHandler: instead");


/// Add a song into the specific playlist.
///
/// - Parameter song: The song instance to be added.
/// - Parameter playlist: The playlist to be added into.
/// - Parameter handler: A block to be called when this task complete successfullly or unsuccessfully.
- (void)addSong:(RTKLPBSong *)song toPlayList:(RTKLPBPlayList *)playlist withCompletionHandler:(nullable RTKLECompletionBlock)handler;


/// Remove a song from the playlist.
///
/// - Parameter song: The song instance to be removed from a playlist.
/// - Parameter playlist: The playlist to be removed from.
/// - Parameter handler: A block to be called when this task complete successfullly or unsuccessfully.
- (void)removeSong:(RTKLPBSong *)song fromPlayList:(RTKLPBPlayList *)pl withCompletionHandler:(nullable RTKLECompletionBlock)handler;


@end

NS_ASSUME_NONNULL_END
