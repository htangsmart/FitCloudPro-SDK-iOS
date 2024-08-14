//
//  FitCloudKit+TranssionInfinix.h
//  FitCloudKit
//
//  Created by pcjbird on 8/9/24.
//  Copyright © 2024 Zero Status. All rights reserved.
//

#ifndef FitCloudKit_TranssionInfinix_h
#define FitCloudKit_TranssionInfinix_h

#import <Foundation/Foundation.h>

@interface FitCloudKit (TranssionInfinix)

#pragma mark - Query whether Transsion Infinix watch is support menstrual feature

/// Query whether Transsion Infinix watch is support menstrual feature
/// - Parameters:
///   - completion: the completion callback
+(void) queryTranssionInfinixWatchWhetherSupportMenstrualWithCompletion:(void(^_Nullable)(BOOL success, BOOL isSupport, NSError* _Nullable error))completion;

/// Send Transsion Infinix watch menstrual 3 elements
/// - Parameters:
///   - recentMenstruationBeginTimestamp: the menstruation begin timestamp since 1970-1-1
///   - menstrualDuration: the menstrual duration in days
///   - menstrualCycle: the menstrual cycle in days
///   - completion: the completion callback
+(void) sendTranssionInfinixWatchMenstrual3Elements:(NSInteger)recentMenstruationBeginTimestamp menstrualDuration:(NSInteger)menstrualDuration menstrualCycle:(NSInteger)menstrualCycle completion:(void(^_Nullable)(BOOL success, NSError* _Nullable error))completion;

/// Query Transsion Infinix watch menstrual 3 elements
/// - Parameters:
///   - completion: the completion callback
+(void) queryTranssionInfinixWatchMenstrual3ElementsWithCompletion:(void(^_Nullable)(BOOL success, NSInteger recentMenstruationBeginTimestamp, NSInteger menstrualDuration, NSInteger menstrualCycle, NSError* _Nullable error))completion;

/// Send Transsion Infinix watch menstrual corrected start day
/// - Parameters:
///   - correctedMenstrualStartDay: the corrected menstrual start day, the sample format: `20240203`
///   - completion: the completion callback
+(void) sendTranssionInfinixWatchMenstrualCorrectedStartDay:(NSString*_Nonnull)correctedMenstrualStartDay completion:(void(^_Nullable)(BOOL success, NSError* _Nullable error))completion;


/// Send Transsion Infinix watch menstrual corrected end day
/// - Parameters:
///   - correctedMenstrualEndDay: the corrected menstrual end day, the sample format: `20240203`
///   - completion: the completion callback
+(void) sendTranssionInfinixWatchMenstrualCorrectedEndDay:(NSString*_Nonnull)correctedMenstrualEndDay completion:(void(^_Nullable)(BOOL success, NSError* _Nullable error))completion;

/// Query Transsion Infinix watch menstrual data for the month
/// - Parameters:
///   - month: the month of the menstrual data, the sample format: `202402`
///   - completion: the completion callback
+(void) queryTranssionInfinixWatchMenstrualDataForMonth:(NSString*_Nonnull)month completion:(void(^_Nullable)(BOOL success, NSArray<NSNumber*>*_Nullable menstrualDataArray, NSError* _Nullable error))completion;


@end

#endif /* FitCloudKit_TranssionInfinix_h */
