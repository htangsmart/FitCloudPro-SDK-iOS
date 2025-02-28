//
//  FitCloudAppSidePermissionStatusModel.h
//  FitCloudKit
//
//  Created by pcjbird on 2/28/25.
//  Copyright © 2025 Zero Status. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <FitCloudKit/FitCloudKitDefines.h>

NS_ASSUME_NONNULL_BEGIN

@interface FitCloudAppSidePermissionStatusModel : NSObject

@property(nonatomic, readonly) FITCLOUDAPPSIDEPERMISSIONTYPE permission;

@property(nonatomic, readonly) BOOL enabled;

- (instancetype)initWithPermission:(FITCLOUDAPPSIDEPERMISSIONTYPE)permission enabled:(BOOL)enabled;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
