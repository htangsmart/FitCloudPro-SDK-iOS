//
//  FitCloudFestivalWishTimeModel.h
//  FitCloudKit
//
//  Created by pcjbird on 8/5/25.
//  Copyright © 2025 Zero Status. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <FitCloudKit/FitCloudKitDefines.h>

NS_ASSUME_NONNULL_BEGIN

/// A model class representing festival wishes for FitCloud devices.
///
/// Use this class to manage festival-related information and wishes that can be synchronized with FitCloud devices.
@interface FitCloudFestivalWishTimeModel : NSObject

/// The type of festival for the wish.
///
/// This property specifies which festival the wish is associated with.
@property(nonatomic, assign) FitCloudFestival festival;

/// The date of the festival.
///
/// This property stores the specific date when the festival occurs.
@property(nonatomic, copy) NSDate *date;

-(BOOL) isValid;

@end

NS_ASSUME_NONNULL_END
