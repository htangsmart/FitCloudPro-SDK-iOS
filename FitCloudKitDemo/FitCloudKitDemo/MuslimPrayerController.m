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
    //XLOG_INFO(@"朝拜闹钟:%@", alarmClock);
    /*[FitCloudKit setMuslimPrayerAlarmClock:alarmClock completion:^(BOOL succeed, NSError * _Nonnull error) {
        
    }];*/
    
    XLOG_INFO(@"朝拜闹钟:%@", [MuslimPrayerParams instance].alarmClock);
    
    [FitCloudKit setMuslimPrayerAlarmClock:[MuslimPrayerParams instance].alarmClock completion:^(BOOL succeed, NSError * _Nonnull error) {
        
    }];
    
}

- (NSArray<FitCloudIslamicEventModel *> *)getIslamicEvents {
    // 这里可以实现你的节日逻辑，返回包含信息的 IslamicHoliday 对象的数组
    // 下面的代码仅作示例
    FitCloudIslamicEventModel *holiday1 = [[FitCloudIslamicEventModel alloc] init];
    {
        NSCalendar *islamicCalendar = [[NSCalendar alloc] initWithCalendarIdentifier:NSCalendarIdentifierIslamicCivil];
        NSDateComponents *islamicComponents = [islamicCalendar components:NSCalendarUnitDay | NSCalendarUnitMonth | NSCalendarUnitYear fromDate:[NSDate date]];
        NSInteger islamicYear = islamicComponents.year;
        NSInteger islamicMonth = islamicComponents.month;
        NSInteger islamicDay = islamicComponents.day;
        FitCloudIslamicDateModel* islamicDate = [FitCloudIslamicDateModel new];
        islamicDate.islamicYear = islamicYear;
        islamicDate.islamicMonth = islamicMonth;
        islamicDate.islamicDay = islamicDay;
        holiday1.islamicDate = islamicDate;
        holiday1.durationOfEventInDays = 3;
        holiday1.correspondingGregorianDate = [NSDate date];
    }

    FitCloudIslamicEventModel *holiday2 = [[FitCloudIslamicEventModel alloc] init];
    {
        FitCloudIslamicDateModel* islamicDate = [FitCloudIslamicDateModel new];
        islamicDate.islamicYear = 1446;
        islamicDate.islamicMonth = 2;
        islamicDate.islamicDay = 10;
        holiday2.islamicDate = islamicDate;
        holiday2.durationOfEventInDays = 5;
        holiday2.correspondingGregorianDate = [[NSDate date] dateByAddingTimeInterval:30*24*60*60];
    }
    
    FitCloudIslamicEventModel *holiday3 = [[FitCloudIslamicEventModel alloc] init];
    {
        FitCloudIslamicDateModel* islamicDate = [FitCloudIslamicDateModel new];
        islamicDate.islamicYear = 1446;
        islamicDate.islamicMonth = 4;
        islamicDate.islamicDay = 12;
        holiday3.islamicDate = islamicDate;
        holiday3.durationOfEventInDays = 8;
        holiday3.correspondingGregorianDate = [[NSDate date] dateByAddingTimeInterval:3*30*24*60*60];
    }
    
    
    FitCloudIslamicEventModel *holiday4 = [[FitCloudIslamicEventModel alloc] init];
    {
        FitCloudIslamicDateModel* islamicDate = [FitCloudIslamicDateModel new];
        islamicDate.islamicYear = 1446;
        islamicDate.islamicMonth = 5;
        islamicDate.islamicDay = 15;
        holiday4.islamicDate = islamicDate;
        holiday4.durationOfEventInDays = 2;
        holiday4.correspondingGregorianDate = [[NSDate date] dateByAddingTimeInterval:4*30*24*60*60];
    }
    
    FitCloudIslamicEventModel *holiday5 = [[FitCloudIslamicEventModel alloc] init];
    {
        FitCloudIslamicDateModel* islamicDate = [FitCloudIslamicDateModel new];
        islamicDate.islamicYear = 1446;
        islamicDate.islamicMonth = 7;
        islamicDate.islamicDay = 18;
        holiday5.islamicDate = islamicDate;
        holiday5.durationOfEventInDays = 6;
        holiday5.correspondingGregorianDate = [[NSDate date] dateByAddingTimeInterval:5*30*24*60*60];
    }
    
    FitCloudIslamicEventModel *holiday6 = [[FitCloudIslamicEventModel alloc] init];
    {
        FitCloudIslamicDateModel* islamicDate = [FitCloudIslamicDateModel new];
        islamicDate.islamicYear = 1446;
        islamicDate.islamicMonth = 9;
        islamicDate.islamicDay = 18;
        holiday6.islamicDate = islamicDate;
        holiday6.durationOfEventInDays = 9;
        holiday6.correspondingGregorianDate = [[NSDate date] dateByAddingTimeInterval:8*30*24*60*60];
    }

    return @[holiday1, holiday2, holiday3, holiday4, holiday5, holiday6];
}

- (IBAction)onSetIslamicEvents:(id)sender {
    XLOG_INFO(@"设置回历节日信息:%@", [[self getIslamicEvents] debugDescription]);
    [FitCloudKit setCurrentIslamicEvents:[self getIslamicEvents] completion:^(BOOL succeed, NSError * _Nonnull error) {
        
    }];
}
- (IBAction)onSetKaaba:(id)sender {
    XLOG_INFO(@"设置克尔白信息:%@", [[MuslimPrayerParams instance].kaaba debugDescription]);
    [FitCloudKit setKaabaData:[MuslimPrayerParams instance].kaaba completion:^(BOOL succeed, NSError * _Nonnull error) {
        
    }];
}

- (IBAction)onGoback:(id)sender {
    [self.navigationController popViewControllerAnimated:YES];
}

@end
