//
//  FitCloudKit+Titan.h
//  FitCloudKit
//
//  Created by pcjbird on 11/7/25.
//  Copyright © 2025 Zero Status. All rights reserved.
//

#ifndef FitCloudKit_Titan_h
#define FitCloudKit_Titan_h
#import <Foundation/Foundation.h>
#import <FitCloudKit/FitCloudKit.h>

/// Menstruation cycle phases for Titan devices.
typedef NS_ENUM(NSInteger, TitanMenstruationType) {
    /// Menstruation period
    TitanMenstruationTypeMenstruation = 1,  
    /// Fertile window
    TitanMenstruationTypeFertileWindow = 2,     
    /// Ovulation day
    TitanMenstruationTypeOvulationDay = 3,      
    /// Safe period
    TitanMenstruationTypeSafePeriod = 4,
    
    TitanMenstruationTypeMin = TitanMenstruationTypeMenstruation,

    TitanMenstruationTypeMax = TitanMenstruationTypeSafePeriod,
};

@interface FitCloudKit (Titan)


/// Sends the last two months’ menstrual-cycle data to a Titan watch.
///
/// Each element in the arrays must be a value from `TitanMenstruationType`.
/// The count of elements must not exceed the number of days in the corresponding month.
/// For the current month, do **not** include any day later than today.
///
/// - Parameters:
///   - lastMonthData: Menstrual data for the previous month.
///   - thisMonthData: Menstrual data for the current month.
///   - completion: Called on the main queue when the operation finishes. 
///     - success: `YES` if the operation was successful, otherwise `NO`.
///     - error: An error object if the operation failed, otherwise `nil`.
+ (void)sendTitanWatchLastTwoMonthsMenstrualDataWithLastMonthData:(nonnull NSArray<NSNumber*> *)lastMonthData
                                                    thisMonthData:(nonnull NSArray<NSNumber*> *)thisMonthData
                                                       completion:(nullable void(^)(BOOL success, NSError * _Nullable error))completion;

@end

#endif /* FitCloudKit_Titan_h */
