//
//  FitCloudPhotoAlbumParams.h
//  FitCloudKit
//
//  Created by pcjbird on 12/14/23.
//  Copyright © 2023 Zero Status. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>

/// The photo album parameters
@interface FitCloudPhotoAlbumParams : NSObject

/// whether current watch is round screen
@property(nonatomic, assign, readonly) BOOL   isRound;

/// the screen width
@property(nonatomic, assign, readonly) CGFloat width;

/// the screen height
@property(nonatomic, assign, readonly) CGFloat height;

/// the screen corner radius
@property(nonatomic, assign, readonly) CGFloat cornerRadius;

/// the watchface preview width
@property(nonatomic, assign, readonly) CGFloat previewWidth;

/// the watchface preview height
@property(nonatomic, assign, readonly) CGFloat previewHeight;

/// the watchface preview corne radius
@property(nonatomic, assign, readonly) CGFloat previewCornerRadius;

/// the photo album preview width
@property(nonatomic, assign, readonly) CGFloat photoAlbumPreviewWidth;

/// the photo album  preview height
@property(nonatomic, assign, readonly) CGFloat photoAlbumPreviewHeight;

/// the photo album preview corne radius
@property(nonatomic, assign, readonly) CGFloat photoAlbumPreviewCornerRadius;

@end

