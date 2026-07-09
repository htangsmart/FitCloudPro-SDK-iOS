//
//  FitCloudActivityDataModel.h
//  FitCloudKit
//
//  Created by pcjbird on 2026-07-09.
//  Copyright © 2026 Zero Status. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// Represents daily activity data model
@interface FitCloudActivityDataModel : NSObject

/// Number of steps taken
@property(nonatomic, assign, readonly) NSInteger steps;

/// Exercise duration in minutes
@property(nonatomic, assign, readonly) NSInteger exerciseDurationMinutes;

/// Calories burned in kilocalories (kcal)
@property(nonatomic, assign, readonly) NSInteger caloriesKcal;

/// Initialize activity data model with activity metrics
/// - Parameters:
///   - steps: Number of steps taken
///   - exerciseDurationMinutes: Exercise duration in minutes
///   - caloriesKcal: Calories burned in kilocalories
/// - Returns: A new instance of FitCloudActivityDataModel
- (instancetype)initWithSteps:(NSInteger)steps
        exerciseDurationMinutes:(NSInteger)exerciseDurationMinutes
                   caloriesKcal:(NSInteger)caloriesKcal;

/// Unavailable. Use designated initializer instead.
- (instancetype)init NS_UNAVAILABLE;

/// Unavailable. Use designated initializer instead.
+ (instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END