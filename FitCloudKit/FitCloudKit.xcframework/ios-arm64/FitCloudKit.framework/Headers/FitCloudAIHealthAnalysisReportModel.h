//
//  FitCloudAIHealthAnalysisReportModel.h
//  FitCloudKit
//
//  Created by pcjbird on 5/16/25.
//  Copyright © 2025 Zero Status. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// A model class that represents AI-powered health analysis reports
@interface FitCloudAIHealthAnalysisReportModel : NSObject

/// A detailed analysis of sleep patterns and quality
@property (nonatomic, strong, nullable) NSString *sleepAnalysis;

/// Analysis of heart rate data including trends and anomalies
@property (nonatomic, strong, nullable) NSString *heartRateAnalysis;

/// Blood oxygen level analysis and saturation trends
@property (nonatomic, strong, nullable) NSString *bloodOxygenAnalysis;

/// Analysis of daily step count and activity patterns
@property (nonatomic, strong, nullable) NSString *stepCountAnalysis;

/// Comprehensive summary of overall health status and recommendations
@property (nonatomic, strong, nullable) NSString *healthSummary;

@end

NS_ASSUME_NONNULL_END
