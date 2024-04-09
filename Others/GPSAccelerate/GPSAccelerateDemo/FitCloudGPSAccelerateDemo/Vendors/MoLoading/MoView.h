//
//  MoView.h
//  StudyLayer
//
//  Created by admin on 15/11/20.
//  Copyright © 2015年 Meone. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface MoView : UIView

- (void)startLoading;

- (void)success:(void (^)(void))successBlock;

- (void)error:(void (^)(void))errorBlock;

@end
