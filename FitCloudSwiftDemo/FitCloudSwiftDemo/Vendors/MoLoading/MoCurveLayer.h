//
//  MoCurveLayer.h
//  StudyLayer
//
//  Created by admin on 15/11/20.
//  Copyright © 2015年 Meone. All rights reserved.
//

#import <QuartzCore/QuartzCore.h>
#import <UIKit/UIKit.h>

#define kSuccessState 0.91f



@interface MoCurveLayer : CALayer

// 控制动画加载
@property (nonatomic, assign) CGFloat progress;

- (void)applyAnimation:(CABasicAnimation*)animation;

- (void)reset;

+ (CGFloat)processing;

+ (void)recordFinishProcessing:(CGFloat)processing;

+ (void)setStrokeColor:(UIColor*)color;

@end
