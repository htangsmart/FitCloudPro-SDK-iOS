//
//  FitCloudHRVMonitorConfigModel.h
//  FitCloudKit
//
//  Created by pcjbird on 2026-05-21.
//  Copyright © 2026 Zero Status. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// HRV measurement configuration model
@interface FitCloudHRVMonitorConfigModel : NSObject

// Indicate whether to enable HRV measurement
@property(nonatomic, assign) BOOL enabled;

// Indicate whether to enable HRV status prompts on the device based on HRV status analysis over a period of time
@property(nonatomic, assign) BOOL enablePrompt;

// Measurement interval, default 30 minutes, unit: minutes
@property(nonatomic, assign) NSInteger interval;

// Start time, minutes, offset relative to 0:00
@property(nonatomic, assign) NSInteger begin;

// End time, minutes, offset relative to 0:00
@property(nonatomic, assign) NSInteger end;

@end

NS_ASSUME_NONNULL_END
