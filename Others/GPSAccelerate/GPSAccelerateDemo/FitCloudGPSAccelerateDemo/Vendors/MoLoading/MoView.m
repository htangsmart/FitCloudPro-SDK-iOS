//
//  MoView.m
//  StudyLayer
//
//  Created by admin on 15/11/20.
//  Copyright © 2015年 Meone. All rights reserved.
//

#import "MoView.h"
#import "MoCurveLayer.h"

#define DefaultColor RGB(0xff, 0xff, 0xff)
#define ErrorColor [UIColor colorWithRed:255.0/255.0 green:255.0/255.0 blue:255.0/255.0 alpha:1.0]

#define kAnimationDuration 1.3
#define kTickDuratioin 0.6

@interface MoView ()<CAAnimationDelegate>

@property (copy, nonatomic) void(^successBlock)(void);
@property (copy, nonatomic) void(^errorBlock)(void);

// 开始加载
@property (nonatomic, strong) MoCurveLayer *moLayer;

//完成
@property (nonatomic, weak) CAShapeLayer *tickLayer;

@property (nonatomic, assign) NSUInteger isWaitingState;;

@end

@implementation MoView

- (instancetype)initWithFrame:(CGRect)frame
{
    frame.size = CGSizeMake(180, 180);
    self = [super initWithFrame:frame];
    if (self) {
        self.isWaitingState = 0;
        
        self.moLayer = [[MoCurveLayer alloc] init];
        self.moLayer.bounds = self.bounds;
        self.moLayer.anchorPoint = CGPointZero;
        [MoCurveLayer setStrokeColor:DefaultColor];
        [self.layer addSublayer:self.moLayer];
        
    }
    return self;
}

-(instancetype)initWithCoder:(NSCoder *)aDecoder
{
    if(self = [super initWithCoder:aDecoder])
    {
        self.isWaitingState = 0;
        
        self.moLayer = [[MoCurveLayer alloc] init];
        self.moLayer.bounds = self.bounds;
        self.moLayer.anchorPoint = CGPointZero;
        [MoCurveLayer setStrokeColor:DefaultColor];
        [self.layer addSublayer:self.moLayer];
    }
    return self;
}

#pragma mark - successLayer
- (CGPathRef)succesTickLine
{
    CGMutablePathRef tickPath = CGPathCreateMutable();
    CGPathMoveToPoint(tickPath, NULL, 48, 86);
    CGPathAddLineToPoint(tickPath, NULL, 82, 122);
    CGPathAddLineToPoint(tickPath, NULL, 138, 66);
    return tickPath;
}

- (void)addSuccessLayer
{
    CAShapeLayer *tickLayer = [[CAShapeLayer alloc] init];
    tickLayer.fillColor = nil;
    tickLayer.strokeColor = DefaultColor.CGColor;
    tickLayer.lineWidth = 3;
    tickLayer.miterLimit = 3;//斜接，大于线宽，线条衔接处会出现斜接角
    tickLayer.lineCap = kCALineCapRound;
    tickLayer.bounds = self.bounds;
    tickLayer.anchorPoint = CGPointZero;
    [self.layer addSublayer:tickLayer];
    self.tickLayer = tickLayer;
    
    CGPathRef path = [self succesTickLine];
    tickLayer.path = path;
    CGPathRelease(path);

    CABasicAnimation *startAnimation = [CABasicAnimation animationWithKeyPath:@"strokeStart"];
    startAnimation.fromValue = @(0.0);
    startAnimation.toValue = @(0.0);
    
    CABasicAnimation *endAnimation = [CABasicAnimation animationWithKeyPath:@"strokeEnd"];
    endAnimation.fromValue = @(0.0);
    endAnimation.toValue = @(1.0);
    
    CAAnimationGroup *successAnimation = [CAAnimationGroup animation];
    successAnimation.animations = @[startAnimation, endAnimation];
    successAnimation.duration = kTickDuratioin;
    
    successAnimation.delegate = self;
    [successAnimation setValue:@"end" forKey:@"moAnimation"];
    successAnimation.timingFunction = [CAMediaTimingFunction functionWithName:kCAMediaTimingFunctionEaseOut];
    [tickLayer addAnimation:successAnimation forKey:nil];
}

#pragma mark - errorLayer
- (CGPathRef)errorTickLine
{
    CGMutablePathRef tickPath = CGPathCreateMutable();
    CGPathMoveToPoint(tickPath, NULL, 52, 52);
    CGPathAddLineToPoint(tickPath, NULL, 132, 132);
    CGPathMoveToPoint(tickPath, NULL, 132, 52);
    CGPathAddLineToPoint(tickPath, NULL, 52, 132);
    return tickPath;
}

- (void)addErrorLayer
{
    CAShapeLayer *tickLayer = [[CAShapeLayer alloc] init];
    tickLayer.fillColor = nil;
    tickLayer.strokeColor = ErrorColor.CGColor;
    tickLayer.lineWidth = 3;
    tickLayer.miterLimit = 3;//斜接，大于线宽，线条衔接处会出现斜接角
    tickLayer.lineCap = kCALineCapRound;
    tickLayer.bounds = self.bounds;
    tickLayer.anchorPoint = CGPointZero;
    [self.layer addSublayer:tickLayer];
    self.tickLayer = tickLayer;
    
    CGPathRef path = [self errorTickLine];
    tickLayer.path = path;
    CGPathRelease(path);
    
    CABasicAnimation *startAnimation = [CABasicAnimation animationWithKeyPath:@"strokeStart"];
    startAnimation.fromValue = @(0.0);
    startAnimation.toValue = @(0.0);
    
    CABasicAnimation *endAnimation = [CABasicAnimation animationWithKeyPath:@"strokeEnd"];
    endAnimation.fromValue = @(0.0);
    endAnimation.toValue = @(1.0);
    
    CAAnimationGroup *successAnimation = [CAAnimationGroup animation];
    successAnimation.animations = @[startAnimation, endAnimation];
    successAnimation.duration = kTickDuratioin;
    
    successAnimation.delegate = self;
    [successAnimation setValue:@"end" forKey:@"moAnimation"];
    successAnimation.timingFunction = [CAMediaTimingFunction functionWithName:kCAMediaTimingFunctionEaseOut];
    [tickLayer addAnimation:successAnimation forKey:nil];
}

#pragma mark - 三步动画
- (void)reset
{
    if (self.tickLayer) {
        [self.tickLayer removeFromSuperlayer];
    }
}

- (void)startLoading
{
    if (self.isWaitingState == 0) {
        [self reset];
        [self.moLayer reset];
        CABasicAnimation *firstAnimation = [self startCAAnimation];
        [self.moLayer applyAnimation:firstAnimation];
        self.isWaitingState = 1;
    }
}

- (CABasicAnimation *)startCAAnimation
{
    CABasicAnimation *animation = [CABasicAnimation animationWithKeyPath:@"progress"];
    animation.fromValue = [NSNumber numberWithDouble:0.0];
    animation.toValue = [NSNumber numberWithDouble:kSuccessState];
    animation.duration = kAnimationDuration * kSuccessState;
    [animation setValue:@"start" forKey:@"moAnimation"];
    animation.delegate = self;
    return animation;
}

- (CABasicAnimation *)loadingProcessCAAnimation
{
    CABasicAnimation *animation = [CABasicAnimation animationWithKeyPath:@"progress"];
    animation.fromValue = [NSNumber numberWithDouble:kSuccessState];
    animation.toValue = [NSNumber numberWithDouble:2.0 - (1 - kSuccessState)];
    animation.duration = kAnimationDuration;
    animation.repeatCount = HUGE_VAL;
    animation.removedOnCompletion = NO;
    [animation setValue:@"loading" forKey:@"moAnimation"];
    animation.delegate = self;
    return animation;
}

- (CABasicAnimation *)finishProcessCAAnimation:(CGFloat)startProgress
{
    CABasicAnimation *animation = [CABasicAnimation animationWithKeyPath:@"progress"];
    animation.fromValue = [NSNumber numberWithDouble:startProgress];
    CGFloat end = 0;
    if (startProgress >= kSuccessState) {
        //start完成
        end = 1 - fabs(1.0-startProgress);
    } else {
        //start未完成
        end = fabs(1.0-startProgress);
    }
    CGFloat finishProcessing = (startProgress + end);
    [MoCurveLayer recordFinishProcessing:finishProcessing];
    animation.toValue = [NSNumber numberWithDouble:finishProcessing];
    animation.duration = end * kAnimationDuration;
    animation.delegate = self;
    [animation setValue:@"finish" forKey:@"moAnimation"];
    return animation;
}

//第一阶段动画完成,执行第二段无限重复动画
- (void)animationDidStop:(CAAnimation *)anim finished:(BOOL)flag
{
    if (flag) {
        NSString *moAnimation = [anim valueForKey:@"moAnimation"];
        if (moAnimation && [moAnimation isEqualToString:@"start"]) {

            [self.moLayer applyAnimation:[self loadingProcessCAAnimation]];
        } else if([moAnimation isEqualToString:@"finish"]){

            if (self.isWaitingState == 2) {

                [self addSuccessLayer];
            } else {

                [self addErrorLayer];
            }
        } else if([moAnimation isEqualToString:@"end"]) {
            if (self.isWaitingState == 2) {
                if (self.successBlock) {
                    dispatch_async(dispatch_get_main_queue(), ^{
                        self.successBlock();
                    });
                }
            } else {
                if (self.errorBlock) {
                    dispatch_async(dispatch_get_main_queue(), ^{
                        self.errorBlock();
                    });
                }
            }
            self.isWaitingState = 0;
        }
    }
}


- (void)success:(void (^)(void))successBlock
{
    if(self.isWaitingState == 1) {
        self.moLayer.progress = [MoCurveLayer processing];
        [self.moLayer removeAllAnimations];
        [MoCurveLayer setStrokeColor:DefaultColor];
        [self.moLayer applyAnimation:[self finishProcessCAAnimation:self.moLayer.progress]];
        self.isWaitingState = 2;
        self.successBlock = successBlock;
    }
}

- (void)error:(void (^)(void))errorBlock
{
    if (self.isWaitingState == 1) {
        self.moLayer.progress = [MoCurveLayer processing];
        [self.moLayer removeAllAnimations];
        [MoCurveLayer setStrokeColor:ErrorColor];
        [self.moLayer applyAnimation:[self finishProcessCAAnimation:self.moLayer.progress]];
        self.isWaitingState = 3;
        self.errorBlock = errorBlock;
    }
}

@end
