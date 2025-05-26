//
//  FitCloudWorldClockModel.h
//  FitCloudKit
//
//  Created by pcjbird on 5/20/25.
//  Copyright © 2025 Zero Status. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// A model representing a world clock with timezone and city information.
@interface FitCloudWorldClockModel : NSObject

/// The unique identifier for the world clock.
@property (nonatomic, assign) NSInteger clockId;

/// The timezone offset in minutes from UTC. For example, -480 for UTC-8.
@property (nonatomic, assign) NSInteger timeZone;

/// The name of the city associated with this world clock.
@property (nonatomic, copy) NSString *cityName;

@end

NS_ASSUME_NONNULL_END
