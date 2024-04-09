//
//  AppDelegate+FitCloudKit.h
//  FitCloudKitDemo
//
//  Created by pcjbird on 2019/6/12.
//  Copyright © 2019 HetangSmart. All rights reserved.
//

#import "AppDelegate.h"

NS_ASSUME_NONNULL_BEGIN

@interface AppDelegate (FitCloudKit)<FitCloudCallback>

-(void) fitCloudKitConfig;

@end

NS_ASSUME_NONNULL_END
