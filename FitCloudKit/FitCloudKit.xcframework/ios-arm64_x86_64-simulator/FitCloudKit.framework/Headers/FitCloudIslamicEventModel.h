//
//  FitCloudIslamicEventModel.h
//  FitCloudKit
//
//  Created by pcjbird on 10/19/24.
//  Copyright © 2024 Zero Status. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <FitCloudKit/FitCloudIslamicDateModel.h>

NS_ASSUME_NONNULL_BEGIN

/// the islamic event model
@interface FitCloudIslamicEventModel : NSObject

/// the islamic date
@property(nonatomic, strong) FitCloudIslamicDateModel* islamicDate;

/// the duration of the event in days
@property(nonatomic, assign) NSUInteger durationOfEventInDays;

/// the corresponding gregorian date
@property(nonatomic, strong) NSDate* correspondingGregorianDate;

/// Return whether is valid
-(BOOL) isValid;

@end

NS_ASSUME_NONNULL_END
