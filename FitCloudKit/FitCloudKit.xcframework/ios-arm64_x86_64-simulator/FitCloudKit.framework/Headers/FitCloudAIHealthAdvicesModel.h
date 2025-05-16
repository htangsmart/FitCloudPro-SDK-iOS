//
//  FitCloudAIHealthAdvicesModel.h
//  FitCloudKit
//
//  Created by pcjbird on 5/16/25.
//  Copyright © 2025 Zero Status. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// A model class that encapsulates AI-generated health advice and recommendations
@interface FitCloudAIHealthAdvicesModel : NSObject

/// Sleep-related recommendations and advice
/// - Note: Contains personalized suggestions for improving sleep quality and patterns
@property (nonatomic, copy, nullable) NSString *sleepAdvice;

/// Heart rate monitoring recommendations
/// - Note: Provides insights and advice based on heart rate data analysis
@property (nonatomic, copy, nullable) NSString *heartRateAdvice;

/// Blood oxygen level recommendations
/// - Note: Contains advice related to blood oxygen saturation measurements
@property (nonatomic, copy, nullable) NSString *bloodOxygenAdvice;

/// Step count and activity recommendations
/// - Note: Provides suggestions for daily physical activity and step goals
@property (nonatomic, copy, nullable) NSString *stepCountAdvice;

/// Comprehensive health summary and recommendations
/// - Note: Overall health assessment combining insights from all monitored metrics
@property (nonatomic, copy, nullable) NSString *overallSummary;

@end

NS_ASSUME_NONNULL_END
