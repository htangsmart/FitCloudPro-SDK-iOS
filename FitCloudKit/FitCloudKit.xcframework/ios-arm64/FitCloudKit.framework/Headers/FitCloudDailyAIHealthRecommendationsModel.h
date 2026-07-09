//
//  FitCloudDailyAIHealthRecommendationsModel.h
//  FitCloudKit
//
//  Created by pcjbird on 2026-07-09.
//  Copyright © 2026 Zero Status. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// Represents daily AI health recommendations result model
@interface FitCloudDailyAIHealthRecommendationsModel : NSObject

/// Date of the health recommendations
@property(nonatomic, strong, readonly) NSDate *date;

/// Health recommendation content
@property(nonatomic, copy, readonly) NSString *content;

/// List of action recommendations
@property(nonatomic, copy, readonly) NSArray<NSString *> *actionRecommendations;

/// Disclaimer text for health recommendations
@property(nonatomic, copy, readonly) NSString *disclaimer;

/// Initialize daily AI health recommendations model
/// - Parameters:
///   - date: Date of the health recommendations
///   - content: Health recommendation content
///   - actionRecommendations: List of action recommendations
///   - disclaimer: Disclaimer text for health recommendations
/// - Returns: A new instance of FitCloudDailyAIHealthRecommendationsModel
- (instancetype)initWithDate:(NSDate *)date
                  content:(NSString *)content
        actionRecommendations:(NSArray<NSString *> *)actionRecommendations
                   disclaimer:(NSString *)disclaimer;

/// Unavailable. Use designated initializer instead.
- (instancetype)init NS_UNAVAILABLE;

/// Unavailable. Use designated initializer instead.
+ (instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
