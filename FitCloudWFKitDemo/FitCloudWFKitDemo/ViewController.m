//
//  ViewController.m
//  FitCloudWFKitDemo
//
//  Created by pcjbird on 5/26/21.
//

#import "ViewController.h"
#import <FitCloudWFKit/FitCloudWFKit.h>

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    __weak typeof(self) weakSelf = self;
    NSString* templateBinPath = [[NSBundle mainBundle] pathForResource:@"test_watchface_template" ofType:@"bin"];
    
    UIImage* resolvedBKImage = [UIImage imageNamed:@"test_360_bg"];
    CGFloat bkCornerRadius = 24;
    UIImage* resolvedPreviewImage = [UIImage imageNamed:@"test_360_preview"];
    [FitCloudWFKit createWithTemplateBin:templateBinPath isNextGUI:YES rewriteNextGUIWatchfaceNo:nil bkImage:resolvedBKImage bkCornerRadius:bkCornerRadius preview:resolvedPreviewImage dtPosition:FITCLOUDWATCHFACEDTPOSITION_TOP progress:^(CGFloat progress, NSString * _Nullable message) {
        NSLog(@"progress:%@, tip:%@", @(progress), message);
        
    } logging:^(FCWKLOGLEVEL level, NSString * _Nullable message) {
        message = [[message stringByReplacingOccurrencesOfString:@"<" withString:@"["] stringByReplacingOccurrencesOfString:@">" withString:@"]"];
        if(level == FCWKLOGLEVEL_INFO)
        {
            NSLog(@"%@", message);
        }
        else if(level == FCWKLOGLEVEL_WARNING)
        {
            NSLog(@"%@", message);
        }
        else if(level == FCWKLOGLEVEL_ERROR)
        {
            NSLog(@"%@", message);
        }
        else if(level == FCWKLOGLEVEL_DEBUG)
        {
            NSLog(@"%@", message);
        }
    } completion:^(BOOL success, NSString * _Nullable resultBinPath, UIImage * _Nullable resultBkImage, UIImage * _Nullable resultPreview, NSError * _Nullable error) {
        
        if(success)
        {
            __strong typeof(self) strongSelf = weakSelf;
            if(!strongSelf) return;
            NSLog(@"create watchface success, bin file: %@", resultBinPath);
            NSString* binPath = resultBinPath;
            
            
        }
        else
        {
            __strong typeof(self) strongSelf = weakSelf;
            if(!strongSelf) return;
            NSLog(@"create watchface failure with error: %@", error.localizedDescription);
        }
    }];
}


@end
