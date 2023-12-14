//
//  DevicePhotoCreateParams.h
//  FitCloudWFKit
//
//  Created by pcjbird on 12/14/23.
//  Copyright © 2023 Zero Status. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// The device photo create params
@interface DevicePhotoCreateParams : NSObject

/// whether current watch is round screen
@property(nonatomic, assign) BOOL   isRound;

/// the screen width
@property(nonatomic, assign) CGFloat width;

/// the screen height
@property(nonatomic, assign) CGFloat height;

/// the screen corner radius
@property(nonatomic, assign) CGFloat cornerRadius;

/// the watchface preview width
@property(nonatomic, assign) CGFloat previewWidth;

/// the watchface preview height
@property(nonatomic, assign) CGFloat previewHeight;

/// the watchface preview corne radius
@property(nonatomic, assign) CGFloat previewCornerRadius;

/// the photo album preview width
@property(nonatomic, assign) CGFloat photoAlbumPreviewWidth;

/// the photo album  preview height
@property(nonatomic, assign) CGFloat photoAlbumPreviewHeight;

/// the photo album preview corne radius
@property(nonatomic, assign) CGFloat photoAlbumPreviewCornerRadius;

@end

NS_ASSUME_NONNULL_END
