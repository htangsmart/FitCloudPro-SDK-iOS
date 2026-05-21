//
//  FitCloudDailyHRVDataModel.h
//  FitCloudKit
//
//  Created by pcjbird on 2026-05-21.
//  Copyright © 2026 Zero Status. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <FitCloudKit/FitCloudKitDefines.h>

NS_ASSUME_NONNULL_BEGIN

/// Daily HRV data model
@interface FitCloudDailyHRVDataModel : NSObject

/// Date of the measurement
@property(nonatomic, strong) NSDate *date;

/// Lower limit of the baseline value
@property(nonatomic, assign) NSInteger lowerLimit;

/// Upper limit of the baseline value
@property(nonatomic, assign) NSInteger upperLimit;

/// Center point of the baseline value
@property(nonatomic, assign) NSInteger centerValue;

/// Average HRV for the day
@property(nonatomic, assign) NSInteger avgHRV;

/// HRV level
@property(nonatomic, assign) FitCloudHRVLevel level;

@end

NS_ASSUME_NONNULL_END
