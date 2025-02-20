//
//  RealtimeMeasureController.m
//  FitCloudKitDemo
//
//  Created by pcjbird on 2019/9/2.
//  Copyright © 2019 HetangSmart. All rights reserved.
//

#import "RealtimeMeasureController.h"

#define ConsoleResultToastTip(v) [v makeToast:NSLocalizedString(@"View the results in the console.", nil) duration:3.0f position:CSToastPositionTop]
#define OpResultToastTip(v, success) [v makeToast:success ? NSLocalizedString(@"Op success.", nil) : NSLocalizedString(@"Op failure.", nil) duration:3.0f position:CSToastPositionTop]

/**
 *@brief 健康实时测量事件类型定义
 */
typedef NS_ENUM(NSInteger, REALTIMEHEALTHMEASUREEVENTTYPE)
{
    REALTIMEHEALTHMEASUREEVENTTYPE_HEARTRATE,
    REALTIMEHEALTHMEASUREEVENTTYPE_ECG,
    REALTIMEHEALTHMEASUREEVENTTYPE_BLOODPRESSURE,
    REALTIMEHEALTHMEASUREEVENTTYPE_BLOODOXYGEN,
    REALTIMEHEALTHMEASUREEVENTTYPE_BREATHERATE,
    REALTIMEHEALTHMEASUREEVENTTYPE_ALL,
};

@interface RealtimeMeasureController ()
- (IBAction)OnGoBack:(id)sender;
@end

@implementation RealtimeMeasureController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    // Uncomment the following line to preserve selection between presentations.
    // self.clearsSelectionOnViewWillAppear = NO;
    
    // Uncomment the following line to display an Edit button in the navigation bar for this view controller.
    // self.navigationItem.rightBarButtonItem = self.editButtonItem;
}

/**
 * @brief 创建实时测量参数
 * @param etype 测量类型
 */
+(FitCloudRealTimeHealthMeasuringParam *) measureParamWith:(REALTIMEHEALTHMEASUREEVENTTYPE) etype
{
    FITCLOUDREALTIMEMHEALTHEASUREITEM item = FITCLOUDREALTIMEMHEALTHEASUREITEM_NONE;
    switch(etype)
    {
        case REALTIMEHEALTHMEASUREEVENTTYPE_HEARTRATE:
        {
            item = FITCLOUDREALTIMEMHEALTHEASUREITEM_HEARTRATE;
            break;
        }
        case REALTIMEHEALTHMEASUREEVENTTYPE_ECG:
        {
            item = FITCLOUDREALTIMEMHEALTHEASUREITEM_ECG;
            break;
        }
        case REALTIMEHEALTHMEASUREEVENTTYPE_BLOODPRESSURE:
        {
            item = FITCLOUDREALTIMEMHEALTHEASUREITEM_BLOODPRESSURE;
            break;
        }
        case REALTIMEHEALTHMEASUREEVENTTYPE_BLOODOXYGEN:
        {
            item = FITCLOUDREALTIMEMHEALTHEASUREITEM_BLOODOXYGEN;
            break;
        }
        case REALTIMEHEALTHMEASUREEVENTTYPE_BREATHERATE:
        {
            item = FITCLOUDREALTIMEMHEALTHEASUREITEM_BREATHERATE;
            break;
        }
        case REALTIMEHEALTHMEASUREEVENTTYPE_ALL: {
            FitCloudAllConfigObject* allConfig = [FitCloudKit allConfig];
            BOOL isHeartRateSupported = (allConfig && allConfig.firmware && (allConfig.firmware.hardwareSupported & FITCLOUDHARDWARE_HEARTRATE));
            BOOL isBloodPressureSupported = (allConfig && allConfig.firmware && (allConfig.firmware.hardwareSupported & FITCLOUDHARDWARE_BLOODPRESSURE));
            BOOL isBloodOxygenSupported = (allConfig && allConfig.firmware && (allConfig.firmware.hardwareSupported & FITCLOUDHARDWARE_BLOODOXYGEN));
            BOOL isBreatheRateSupported = (allConfig && allConfig.firmware && (allConfig.firmware.hardwareSupported & FITCLOUDHARDWARE_BREATHERATE));
            if(isHeartRateSupported)
            {
                item = item | FITCLOUDREALTIMEMHEALTHEASUREITEM_HEARTRATE;
            }
            if(isBloodPressureSupported)
            {
                item = item | FITCLOUDREALTIMEMHEALTHEASUREITEM_BLOODPRESSURE;
            }
            if(isBloodOxygenSupported)
            {
                item = item | FITCLOUDREALTIMEMHEALTHEASUREITEM_BLOODOXYGEN;
            }
            if(isBreatheRateSupported)
            {
                item = item | FITCLOUDREALTIMEMHEALTHEASUREITEM_BREATHERATE;
            }
            break;
        }
        default:
        {
            break;
        }
    }
    if(FITCLOUDREALTIMEMHEALTHEASUREITEM_NONE == item)
    {
        XLOG_ERROR(@"试图创建未知类型的健康实时测量(测量类型：%@)", @(etype));
        return nil;
    }
    FitCloudRealTimeHealthMeasuringParam *param = [FitCloudRealTimeHealthMeasuringParam new];
    param.item = item;
    param.interval = 5;
    param.maxMeasuringMinutes = 1;
    return param;
}

-(void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
    if(indexPath.row == 0)
    {
        REALTIMEHEALTHMEASUREEVENTTYPE etype = REALTIMEHEALTHMEASUREEVENTTYPE_HEARTRATE;
        FitCloudRealTimeHealthMeasuringParam *param = [[self class] measureParamWith:etype];
        if(!param) return;
        ConsoleResultToastTip(self.view);
        [FitCloudKit requestRealTimeHealthMeasuring:param block:^(BOOL succeed, NSError *error) {
            if(!succeed || [error isKindOfClass:[NSError class]])
            {
                XLOG_ERROR(@"健康实时测量(测量类型：%@)启动失败：%@", @(etype), error);
                return;
            }
            XLOG_INFO(@"健康实时测量(测量类型：%@)启动成功。", @(etype));
        }];
        
    }
    else if(indexPath.row == 1)
    {
        REALTIMEHEALTHMEASUREEVENTTYPE etype = REALTIMEHEALTHMEASUREEVENTTYPE_ALL;
        FitCloudRealTimeHealthMeasuringParam *param = [[self class] measureParamWith:etype];
        if(!param) return;
         ConsoleResultToastTip(self.view);
        [FitCloudKit requestRealTimeHealthMeasuring:param block:^(BOOL succeed, NSError *error) {
            if(!succeed || [error isKindOfClass:[NSError class]])
            {
                XLOG_ERROR(@"健康实时测量(测量类型：%@)启动失败：%@", @(etype), error);
                return;
            }
            XLOG_INFO(@"健康实时测量(测量类型：%@)启动成功。", @(etype));
        }];
    }
    else if(indexPath.row == 2)
    {
        ConsoleResultToastTip(self.view);
        FitCloudRealTimeHealthMeasuringParam *param = [FitCloudRealTimeHealthMeasuringParam new];
        param.item = FITCLOUDREALTIMEMHEALTHEASUREITEM_NONE;
        param.interval = 5;
        param.maxMeasuringMinutes = 1;
        [FitCloudKit requestRealTimeHealthMeasuring:param block:^(BOOL succeed, NSError *error) {
            if(!succeed || [error isKindOfClass:[NSError class]])
            {
                XLOG_ERROR(@"健康实时测量停止失败：%@", error);
                return;
            }
            XLOG_INFO(@"健康实时测量停止成功。");
        }];
    }
}

/*
 #pragma mark - Navigation
 
 // In a storyboard-based application, you will often want to do a little preparation before navigation
 - (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
 // Get the new view controller using [segue destinationViewController].
 // Pass the selected object to the new view controller.
 }
 */
- (IBAction)OnGoBack:(id)sender {
    [self.navigationController popViewControllerAnimated:YES];
}
@end
