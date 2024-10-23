//
//  MuslimPrayerController.m
//  FitCloudKitDemo
//
//  Created by pcjbird on 10/23/24.
//  Copyright © 2024 HetangSmart. All rights reserved.
//

#import "MuslimPrayerController.h"
#import "MuslimPrayerParams.h"
#import "FitCloudKitDemo-Swift.h"

@interface MuslimPrayerController ()

@property (weak, nonatomic) IBOutlet UIDatePicker *time1;
@property (weak, nonatomic) IBOutlet UIDatePicker *time2;
@property (weak, nonatomic) IBOutlet UIDatePicker *time3;
@property (weak, nonatomic) IBOutlet UIDatePicker *time4;
@property (weak, nonatomic) IBOutlet UIDatePicker *time5;
@property (weak, nonatomic) IBOutlet UITextField *location;
@property (weak, nonatomic) IBOutlet UITextField *angle;
@property (weak, nonatomic) IBOutlet UITextField *distance;
@end

@implementation MuslimPrayerController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    self.time1.date = [MuslimPrayerParams instance].alarmClock.timeForFajr;
    self.time2.date = [MuslimPrayerParams instance].alarmClock.timeForDhuhr;
    self.time3.date = [MuslimPrayerParams instance].alarmClock.timeForAsr;
    self.time4.date = [MuslimPrayerParams instance].alarmClock.timeForMaghrib;
    self.time5.date = [MuslimPrayerParams instance].alarmClock.timeForIsha;
    
    self.location.text = [NSString stringWithFormat:@"%@", @([MuslimPrayerParams instance].kaaba.locationServiceState)];
    self.angle.text = [NSString stringWithFormat:@"%@", @([MuslimPrayerParams instance].kaaba.azimuthAngle)];
    self.distance.text = [NSString stringWithFormat:@"%@", @([MuslimPrayerParams instance].kaaba.distanceInKM)];
}

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/
- (IBAction)onSave:(id)sender {
    [MuslimPrayerParams instance].alarmClock.timeForFajr = self.time1.date;
    [MuslimPrayerParams instance].alarmClock.timeForDhuhr = self.time2.date;
    [MuslimPrayerParams instance].alarmClock.timeForAsr = self.time3.date;
    [MuslimPrayerParams instance].alarmClock.timeForMaghrib = self.time4.date;
    [MuslimPrayerParams instance].alarmClock.timeForIsha = self.time5.date;
    
    [MuslimPrayerParams instance].kaaba.locationServiceState = [self.location.text integerValue];
    [MuslimPrayerParams instance].kaaba.azimuthAngle = [self.angle.text integerValue];
    [MuslimPrayerParams instance].kaaba.distanceInKM = [self.distance.text integerValue];
}

- (IBAction)onSetAlarmClock:(id)sender {
    
    XLOG_INFO(@"开始设置朝拜闹钟到手表...");
    NSCalendar *cal = [[NSCalendar alloc] initWithCalendarIdentifier:NSCalendarIdentifierGregorian];
    NSDateComponents *date = [cal components:NSCalendarUnitDay|NSCalendarUnitMonth|NSCalendarUnitYear fromDate:[NSDate date]];
    
    BACalculationParameters *params = [[BACalculationParameters alloc] initWithMethod:BACalculationMethodMuslimWorldLeague];
    params.madhab = BAMadhabHanafi;
    BACoordinates *coordinates = [[BACoordinates alloc] initWithLatitude:35.78056 longitude:-78.6389];
    
    BAPrayerTimes *prayerTimes = [[BAPrayerTimes alloc] initWithCoordinates:coordinates date:date calculationParameters:params];
    
    FitCloudMuslimPrayerAlarmClockModel* alarmClock = [FitCloudMuslimPrayerAlarmClockModel new];
    alarmClock.timeForFajr = prayerTimes.fajr;
    alarmClock.timeForDhuhr = prayerTimes.dhuhr;
    alarmClock.timeForAsr = prayerTimes.asr;
    alarmClock.timeForMaghrib = prayerTimes.maghrib;
    alarmClock.timeForIsha = prayerTimes.isha;
    
    [FitCloudKit setMuslimPrayerAlarmClock:alarmClock completion:^(BOOL succeed, NSError * _Nonnull error) {
        
    }];
    
    /*[FitCloudKit setMuslimPrayerAlarmClock:[MuslimPrayerParams instance].alarmClock completion:^(BOOL succeed, NSError * _Nonnull error) {
        
    }];*/
    
}


- (IBAction)onGoback:(id)sender {
    [self.navigationController popViewControllerAnimated:YES];
}

@end
