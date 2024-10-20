//
//  FitCloudIslamicDateModel.h
//  FitCloudKit
//
//  Created by pcjbird on 10/19/24.
//  Copyright © 2024 Zero Status. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// The islamic date model
@interface FitCloudIslamicDateModel : NSObject

/// The islamic year
@property(nonatomic, assign) NSUInteger islamicYear;

/// The islamic month
@property(nonatomic, assign) NSUInteger islamicMonth;

/// The islamic day
@property(nonatomic, assign) NSUInteger islamicDay;

@end

NS_ASSUME_NONNULL_END
