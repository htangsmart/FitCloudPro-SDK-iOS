//
//  FutureHourlyWeatherController.m
//  FitCloudSwiftDemo
//
//  Created by pcjbird on 2026/9/17.
//  Copyright © 2026 Zero Status. All rights reserved.
//

#import "FutureHourlyWeatherController.h"

#define OpResultToastTip(v, success) [v makeToast:success ? NSLocalizedString(@"Op success.", nil) : NSLocalizedString(@"Op failure.", nil) duration:3.0f position:CSToastPositionTop]

/// 生成的小时条数，与原 Demo 保持一致。
static const NSInteger kHourlyWeatherCount = 100;

@interface FutureHourlyWeatherController ()

- (IBAction)OnGoBack:(id)sender;
- (IBAction)OnRandomize:(id)sender;
- (IBAction)OnSend:(id)sender;

@property(nonatomic, copy) NSArray<FitCloudHourlyWeatherModel *> *hourlyWeathers;

@property(weak, nonatomic) IBOutlet UILabel *countLabel;
@property(weak, nonatomic) IBOutlet UIButton *sendButton;

@end

@implementation FutureHourlyWeatherController

#pragma mark - Lifecycle

- (void)viewDidLoad {
    [super viewDidLoad];
    self.tableView.rowHeight = 54;
    [self regenerateHourlyWeathers];
}

#pragma mark - Data

/// 随机生成 kHourlyWeatherCount 条未来逐小时天气数据。
/// 修正了原 Demo 中 weatherType 可能为 0（非法）的问题，
/// 仅在有效枚举范围 0x01~0x10 内取值。
- (void)regenerateHourlyWeathers {
    NSMutableArray<FitCloudHourlyWeatherModel *> *array = [NSMutableArray arrayWithCapacity:kHourlyWeatherCount];
    NSDate *now = [NSDate date];
    for (NSInteger index = 0; index < kHourlyWeatherCount; index++) {
        FitCloudHourlyWeatherModel *model = [FitCloudHourlyWeatherModel new];
        model.timestamp = [now dateByAddingTimeInterval:index * 3600];
        // 0x01~0x10 共 16 种有效天气类型
        model.weatherType = (Byte)(1 + arc4random_uniform(16));
        // -20~40 °C
        model.temperature = (SInt8)(-20 + (SInt8)arc4random_uniform(61));
        // 0~12 级风力
        model.windScale = (UInt8)arc4random_uniform(13);
        // 0~11 UV 指数
        model.uvIndex = (UInt8)arc4random_uniform(12);
        // 100~30000 米，避开 0；上限受 SDK 约束为 30000
        model.visibility = (UInt16)(100 + arc4random_uniform(30000 - 100));
        // 0~400 空气质量指数
        model.airQualityIndex = (UInt16)arc4random_uniform(401);
        [array addObject:model];
    }
    self.hourlyWeathers = [array copy];
    [self.countLabel setText:[NSString stringWithFormat:NSLocalizedString(@"%@ hours", nil), @(kHourlyWeatherCount)]];
    self.sendButton.enabled = YES;
    [self.tableView reloadData];
}

/// 将天气类型枚举值映射为可读名称，对齐 SDK 头文件注释。
- (NSString *)displayNameForWeatherType:(FITCLOUDWEATHERTYPE)type {
    static NSDictionary<NSNumber *, NSString *> *names = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        names = @{
            @(FITCLOUDWEATHERTYPE_SUNNY): @"Sunny",
            @(FITCLOUDWEATHERTYPE_CLOUDY): @"Cloudy",
            @(FITCLOUDWEATHERTYPE_OVERCAST): @"Overcast",
            @(FITCLOUDWEATHERTYPE_SHOWERS): @"Showers",
            @(FITCLOUDWEATHERTYPE_THUNDERSHOWERSWITHHAIL): @"Thunder/Hail",
            @(FITCLOUDWEATHERTYPE_LIGHTRAIN): @"Light Rain",
            @(FITCLOUDWEATHERTYPE_MHSRAIN): @"Heavy Rain",
            @(FITCLOUDWEATHERTYPE_SLEET): @"Sleet",
            @(FITCLOUDWEATHERTYPE_LIGHTSNOW): @"Light Snow",
            @(FITCLOUDWEATHERTYPE_HEAVYSNOW): @"Heavy Snow",
            @(FITCLOUDWEATHERTYPE_SANDSTORM): @"Sandstorm",
            @(FITCLOUDWEATHERTYPE_FOGORHAZE): @"Fog/Haze",
            @(FITCLOUDWEATHERTYPE_WINDY): @"Windy",
            @(FITCLOUDWEATHERTYPE_CLOUDYINEVENING): @"Cloudy Eve",
            @(FITCLOUDWEATHERTYPE_CLEARINEVENING): @"Clear Eve",
            @(FITCLOUDWEATHERTYPE_EVENINGSHOWERS): @"Eve Showers",
            @(FITCLOUDWEATHERTYPE_UNKNOWN): @"Unknown",
        };
    });
    return names[@(type)] ?: @"Unknown";
}

/// 将可见度（米）格式化为更友好的展示，超过 1000 米用 km。
- (NSString *)visibilityText:(UInt16)meters {
    if (meters >= 1000) {
        return [NSString stringWithFormat:@"%.1fkm", meters / 1000.0];
    }
    return [NSString stringWithFormat:@"%dm", meters];
}

#pragma mark - Actions

- (IBAction)OnGoBack:(id)sender {
    [self.navigationController popViewControllerAnimated:YES];
}

- (IBAction)OnRandomize:(id)sender {
    [self regenerateHourlyWeathers];
    [self.view makeToast:NSLocalizedString(@"Randomized.", nil) duration:1.5f position:CSToastPositionTop];
}

- (IBAction)OnSend:(id)sender {
    NSArray<FitCloudHourlyWeatherModel *> *payload = self.hourlyWeathers;
    if (!payload.count) {
        return;
    }
    // 发送期间禁用按钮，避免重复点击。
    self.sendButton.enabled = NO;
    __weak typeof(self) weakSelf = self;
    [FitCloudKit sendFutureHourlyWeathers:payload completion:^(BOOL success, NSError * _Nullable error) {
        if ([error isKindOfClass:[NSError class]]) {
            XLOG_ERROR(@"Failed to send future hourly weathers: %@.", error);
            dispatch_async(dispatch_get_main_queue(), ^{
                [weakSelf.view makeToast:error.localizedDescription duration:3.0f position:CSToastPositionTop];
                weakSelf.sendButton.enabled = YES;
            });
            return;
        }
        if (success) {
            XLOG_INFO(@"Sent %lu future hourly weathers.", (unsigned long)payload.count);
        } else {
            XLOG_ERROR(@"Failed to send future hourly weathers.");
        }
        dispatch_async(dispatch_get_main_queue(), ^{
            OpResultToastTip(weakSelf.view, success);
            weakSelf.sendButton.enabled = YES;
        });
    }];
}

#pragma mark - Table view data source

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    return (NSInteger)self.hourlyWeathers.count;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:@"HourlyCell" forIndexPath:indexPath];
    FitCloudHourlyWeatherModel *model = self.hourlyWeathers[indexPath.row];

    static NSDateFormatter *formatter = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        formatter = [[NSDateFormatter alloc] init];
        formatter.dateFormat = @"MM-dd HH:mm";
    });

    NSString *timeText = [formatter stringFromDate:model.timestamp];
    NSString *weatherName = [self displayNameForWeatherType:(FITCLOUDWEATHERTYPE)model.weatherType];
    NSString *tempText = [NSString stringWithFormat:@"%d°C", model.temperature];

    cell.textLabel.text = [NSString stringWithFormat:@"%@  %@  %@", timeText, weatherName, tempText];
    cell.textLabel.font = [UIFont fontWithName:@"Menlo-Bold" size:13];
    cell.textLabel.numberOfLines = 0;

    cell.detailTextLabel.text = [NSString stringWithFormat:NSLocalizedString(@"Wind %d  UV %d  Vis %@  AQI %d", nil),
                                 model.windScale, model.uvIndex, [self visibilityText:model.visibility], model.airQualityIndex];
    cell.detailTextLabel.font = [UIFont fontWithName:@"Menlo-Regular" size:11];
    cell.detailTextLabel.textColor = [UIColor darkGrayColor];
    cell.detailTextLabel.numberOfLines = 0;

    cell.selectionStyle = UITableViewCellSelectionStyleNone;
    return cell;
}

@end
