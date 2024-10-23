//
//  MuslimPrayerParams.m
//  FitCloudKitDemo
//
//  Created by pcjbird on 10/23/24.
//  Copyright © 2024 HetangSmart. All rights reserved.
//

#import "MuslimPrayerParams.h"

@implementation MuslimPrayerParams

static MuslimPrayerParams* _sharedInstance = nil;

+ (instancetype)instance
{
    static dispatch_once_t onceToken;
    
    dispatch_once(&onceToken, ^{
        _sharedInstance = [[[self class] alloc] init];
    });

    return _sharedInstance;
}

-(id)init
{
    if(self = [super init])
    {
        self.alarmClock = [FitCloudMuslimPrayerAlarmClockModel new];
        self.alarmClock.timeForFajr = [NSDate date];
        self.alarmClock.timeForDhuhr = [NSDate date];
        self.alarmClock.timeForAsr = [NSDate date];
        self.alarmClock.timeForMaghrib = [NSDate date];
        self.alarmClock.timeForIsha = [NSDate date];
        self.kaaba = [FitCloudKaabaModel new];
        self.kaaba.locationServiceState = 0;
        self.kaaba.azimuthAngle = -20;
        self.kaaba.distanceInKM = 1800;
    }
    return self;
}

@end
