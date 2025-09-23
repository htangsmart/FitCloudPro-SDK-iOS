//
//  FitCloudWorkoutSummaryDataModel.h
//  FitCloudKit
//
//  Created by pcjbird on 9/23/25.
//  Copyright © 2025 Zero Status. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <FitCloudKit/FitCloudKitDefines.h>

NS_ASSUME_NONNULL_BEGIN

/// A data model that represents a summary of workout data.
///
/// Use this class to access workout summary information like the data type and value.
@interface FitCloudWorkoutSummaryDataModel : NSObject

/// The type of workout summary data.
///
/// This property indicates what kind of workout data this summary represents.
@property(nonatomic, readonly) FitCloudWorkoutSummaryDataType dataType;

/// The numerical value of the workout summary data.
///
/// This property contains the actual value of the workout metric. The value may be nil if no data is available.
@property(nonatomic, readonly, nullable, copy) NSNumber* value;

@end

NS_ASSUME_NONNULL_END
