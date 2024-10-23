//
//  FitCloudKaabaModel.h
//  FitCloudKit
//
//  Created by pcjbird on 10/19/24.
//  Copyright © 2024 Zero Status. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <FitCloudKit/FitCloudKitDefines.h>

NS_ASSUME_NONNULL_BEGIN

/// The kaaba data model
@interface FitCloudKaabaModel : NSObject

/// The location service state
@property(nonatomic, assign) APPLOCATIONSERVICESTATE locationServiceState;

/// the azimuth angle from -180 to 180
///
/// > The azimuth angle of the Kaaba relative to the current location.
@property(nonatomic, assign) NSInteger azimuthAngle;

/// the distance in km
///
/// > The distance of the Kaaba relative to the current location.
@property(nonatomic, assign) NSInteger distanceInKM;

@end

NS_ASSUME_NONNULL_END
