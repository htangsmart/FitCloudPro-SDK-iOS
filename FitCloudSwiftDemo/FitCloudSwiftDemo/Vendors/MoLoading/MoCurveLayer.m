//
//  MoCurveLayer.m
//  StudyLayer
//
//  Created by admin on 15/11/20.
//  Copyright © 2015年 Meone. All rights reserved.
//

#import "MoCurveLayer.h"
#define kLineWidth 3


static CGFloat recordProgcessing = 0.f;
static CGFloat finishProgcessing = 0.f;
static UIColor * strokeColor = nil;
@implementation MoCurveLayer

- (instancetype)init
{
    self = [super init];
    if (self) {
        self.progress = 0.f;
        self.contentsScale = [UIScreen mainScreen].scale;
        strokeColor = RGB(0x75, 0xBD, 0x21);
    }
    return self;
}

+ (BOOL)needsDisplayForKey:(NSString *)key
{
    if ([key isEqualToString:@"progress"]) {
        return YES;
    }
    
    return [super needsDisplayForKey:key];
}

- (void)reset
{
    self.progress = 0.f;
    strokeColor = RGB(0xff, 0xff, 0xff);
    recordProgcessing = 0.f;
    finishProgcessing = 0.f;
}

//为了保存动画运行的状态
+ (CGFloat)processing
{
    return recordProgcessing;
}

//保存动画结束的值
+ (void)recordFinishProcessing:(CGFloat)processing
{
    finishProgcessing = processing;
}

+ (void)setStrokeColor:(UIColor*)color
{
    strokeColor = color;
}

- (void)applyAnimation:(CABasicAnimation*)animation
{
    CABasicAnimation *copy = [animation copy];
    if (copy.fromValue == nil) {
        copy.fromValue = [[self presentationLayer] valueForKey:[copy keyPath]];
    }
    [self addAnimation:copy forKey:[copy keyPath]];
    [self setValue:copy.toValue forKeyPath:copy.keyPath];
}

// layer的property属性在drawInContext时,只有ca中指定的属性值会保存
// 其余数据均被置为默认,ca执行完属性值重新赋值了

- (void)drawInContext:(CGContextRef)ctx
{
    CGMutablePathRef path = CGPathCreateMutable();
    CGFloat radius = MIN(CGRectGetWidth(self.bounds), CGRectGetHeight(self.bounds)) / 2 - kLineWidth / 2;
    CGFloat x = CGRectGetWidth(self.bounds)/2;
    CGFloat y = CGRectGetHeight(self.bounds)/2;
    CGFloat startAngle = M_PI * (4/3 - 2 * self.progress);
    CGFloat endAngle = 0;
    
    if(finishProgcessing > 0) {
        
        if ((finishProgcessing - self.progress) <= (1.f - kSuccessState)) {
            endAngle = startAngle - 2 * M_PI * self.progress;
        } else if(self.progress > kSuccessState){
            //start完成
            endAngle = startAngle - 2 * M_PI * kSuccessState;
        } else {
            //start未完成
            endAngle = startAngle - 2 * M_PI * self.progress;
        }
        
    
    } else {
        if (self.progress <= kSuccessState) {
            endAngle = startAngle - 2 * M_PI * self.progress;
        } else if(self.progress <= (1.f + kSuccessState)){
            endAngle = startAngle - 2 * M_PI * kSuccessState;
        }
    }
    
    
    
    recordProgcessing = self.progress;
    // clockwise NO => 逆时针填充  YES => 顺时针填充
    CGPathAddArc(path, NULL, x, y, radius, endAngle, startAngle, NO);

    CGContextSetLineWidth(ctx, kLineWidth);
    CGContextSetLineCap(ctx, kCGLineCapRound);
    
    //设置RGB,取0.0~1.0之间,x/255.0
    CGContextSetRGBStrokeColor(ctx, strokeColor.red, strokeColor.green, strokeColor.blue, 1.0);
    
//    CGContextSetStrokeColorWithColor(ctx, [UIColor colorWithRed:60.0/255.0 green:151.0/255.0 blue:227.0/255.0 alpha:1.0].CGColor);
    
    CGContextAddPath(ctx, path);
    
    CGPathRelease(path);
    
//    CGMutablePathRef tickPath = CGPathCreateMutable();
//    CGPathMoveToPoint(tickPath, NULL, 15, 29);
//    CGPathAddLineToPoint(tickPath, NULL, 22, 36);
//    CGPathAddLineToPoint(tickPath, NULL, 39, 20);
//    CGContextAddPath(ctx, tickPath);
//    CGPathRelease(tickPath);

    
    CGContextStrokePath(ctx);
}

- (void)dealloc
{
//    // 监听该对象的progress不能用该对象自身,因为layer在使用ca动画时,会不停调用dealloc方法
//   NSLog(@"layer dealloc");
}
@end
