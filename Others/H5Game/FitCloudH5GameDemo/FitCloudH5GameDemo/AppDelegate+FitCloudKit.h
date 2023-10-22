//
//  AppDelegate+FitCloudKit.h
//  FitCloudH5GameDemo
//
//  Created by pcjbird on 2023-10-22.
//

#import "AppDelegate.h"
#import <FitCloudKit/FitCloudKit.h>
#import <FitCloudH5Game/FitCloudH5Game.h>

NS_ASSUME_NONNULL_BEGIN

@interface AppDelegate (FitCloudKit)<FitCloudCallback>

-(void) fitCloudKitConfig;

@end

NS_ASSUME_NONNULL_END
