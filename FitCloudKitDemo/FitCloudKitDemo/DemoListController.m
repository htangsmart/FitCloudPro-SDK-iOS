//
//  DemoListController.m
//  FitCloudKitDemo
//
//  Created by pcjbird on 2019/8/20.
//  Copyright © 2019 HetangSmart. All rights reserved.
//

#import "DemoListController.h"

@interface DemoListController ()

- (IBAction)OnGoBack:(id)sender;
@end

@implementation DemoListController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    // Uncomment the following line to preserve selection between presentations.
    // self.clearsSelectionOnViewWillAppear = NO;
    
    // Uncomment the following line to display an Edit button in the navigation bar for this view controller.
    // self.navigationItem.rightBarButtonItem = self.editButtonItem;
}



- (IBAction)OnGoBack:(id)sender {
    [self.navigationController popViewControllerAnimated:YES];
}
@end
