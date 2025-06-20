//
//  FitCloudGamePlayCountModel.h
//  FitCloudKit
//
//  Created by pcjbird on 6/20/25.
//  Copyright © 2025 Zero Status. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <FitCloudKit/FitCloudKitDefines.h>

NS_ASSUME_NONNULL_BEGIN

/// A model class that represents the play count statistics for a FitCloud game.
///
/// Use this class to track how many times a specific game has been played on the device.
@interface FitCloudGamePlayCountModel : NSObject

/// The unique identifier of the game.
///
/// This property stores the game's ID which is used to distinguish different games
/// in the FitCloud ecosystem.
@property(nonatomic, readonly) FITCLOUDGAME gameId;

/// The number of times the game has been played.
///
/// This property keeps track of how many times the user has played this specific game.
@property(nonatomic, readonly) NSInteger playCount;

/// Disable default initialization method
+ (instancetype)new NS_UNAVAILABLE;
/// Disable default initialization method
- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
