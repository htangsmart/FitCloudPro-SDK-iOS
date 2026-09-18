//
//  FitCloudDanmakuModel.h
//  FitCloudKit
//
//  Created by pcjbird on 9/18/26.
//  Copyright © 2026 Zero Status. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <FitCloudKit/FitCloudKitDefines.h>

NS_ASSUME_NONNULL_BEGIN

/// A model representing a danmaku (barrage) item sent to the device.
@interface FitCloudDanmakuModel : NSObject

/// The danmaku type (mine or friend).
@property(nonatomic, assign) FitCloudDanmakuType type;

/// The text content of the danmaku. UTF-8 encoded, max 128 bytes (excluding null terminator).
@property(nonatomic, copy) NSString *text;

/// The text color. Stored as RGBA internally.
@property(nonatomic, strong) UIColor *color;

/// The font size in pixels (e.g., 32 means 32px).
@property(nonatomic, assign) UInt8 fontSize;

/// The animation type.
@property(nonatomic, assign) FitCloudDanmakuAnimation animation;

/// The scroll speed in pixels per second.
@property(nonatomic, assign) UInt8 speed;

/// The Y coordinate. Use `FitCloudDanmakuRandomYCoordinate` (-32768) for a random position.
@property(nonatomic, assign) NSInteger yCoordinate;

/// Validates the model. Returns YES if all required fields are set correctly.
- (BOOL)isValid;

@end

NS_ASSUME_NONNULL_END
