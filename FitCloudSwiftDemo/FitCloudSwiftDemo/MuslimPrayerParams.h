//
//  MuslimPrayerParams.h
//  FitCloudKitDemo
//
//  Created by pcjbird on 10/23/24.
//  Copyright © 2024 HetangSmart. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <FitCloudKit/FitCloudKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface MuslimPrayerParams : NSObject

@property(nonatomic, strong) FitCloudMuslimPrayerAlarmClockModel* alarmClock;

@property(nonatomic, strong) FitCloudKaabaModel* kaaba;

+(instancetype) instance;

@end

NS_ASSUME_NONNULL_END
