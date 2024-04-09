//
//  LocalizedButton.m
//
//
//  Created by Raphaël Pinto on 18/01/12.
//
// The MIT License (MIT)
// Copyright (c) 2013 Raphael Pinto.
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#import "LocalizedButton.h"

@interface LocalizedButton()

- (void)setup;

@end

@implementation LocalizedButton



#pragma mark -
#pragma mark Object Life Cycle Methods



- (id)initWithFrame:(CGRect)_Frame
{
	self = [super initWithFrame:_Frame];
	if(self)
	{
        [self setup];
    }
	return self;
}


- (id)initWithCoder:(NSCoder *)aDecoder
{
	self = [super initWithCoder:aDecoder];
	if(self)
	{
        [self setup];
    }
	return self;
}



#pragma mark -
#pragma mark View Update Methods



- (void)setup
{
    [self setTitle:NSLocalizedString(self.titleLabel.text, self.text) forState:UIControlStateNormal];
    [self setTitle:NSLocalizedString(self.titleLabel.text, self.text) forState:UIControlStateSelected];
    [self setTitle:NSLocalizedString(self.titleLabel.text, self.text) forState:UIControlStateDisabled];
    [self setTitle:NSLocalizedString(self.titleLabel.text, self.text) forState:UIControlStateHighlighted];
    
    
    // BG Image
    UIImage *bgImage = [self backgroundImageForState:UIControlStateNormal];
    if (bgImage != nil) {
        bgImage = [bgImage stretchableImageWithLeftCapWidth:(int)bgImage.size.width / 2.0 topCapHeight:(int)bgImage.size.height / 2.0];
        [self setBackgroundImage:bgImage forState:UIControlStateNormal];		}
    
    UIImage *bgHlImage = [self backgroundImageForState:UIControlStateHighlighted];
    if (bgHlImage != nil) {
        bgHlImage = [bgHlImage stretchableImageWithLeftCapWidth:(int)bgHlImage.size.width / 2.0 topCapHeight:(int)bgHlImage.size.height / 2.0];
        [self setBackgroundImage:bgHlImage forState:UIControlStateHighlighted];
    }
    
    UIImage *bgSelectedImage = [self backgroundImageForState:UIControlStateSelected];
    if (bgSelectedImage != nil) {
        bgSelectedImage = [bgSelectedImage stretchableImageWithLeftCapWidth:(int)bgSelectedImage.size.width / 2.0 topCapHeight:(int)bgSelectedImage.size.height / 2.0];
        [self setBackgroundImage:bgSelectedImage forState:UIControlStateSelected];
    }
    
    
    // Image
    UIImage *image = [self imageForState:UIControlStateNormal];
    if (image != nil) {
        image = [image stretchableImageWithLeftCapWidth:(int)image.size.width / 2.0 topCapHeight:(int)image.size.height / 2.0];
        [self setImage:image forState:UIControlStateNormal];
    }
    
    UIImage *hlImage = [self imageForState:UIControlStateHighlighted];
    if (hlImage != nil) {
        hlImage = [hlImage stretchableImageWithLeftCapWidth:(int)hlImage.size.width / 2.0 topCapHeight:(int)hlImage.size.height / 2.0];
        [self setImage:hlImage forState:UIControlStateHighlighted];
    }
    
    UIImage *selectedImage = [self imageForState:UIControlStateSelected];
    if (selectedImage != nil) {
        selectedImage = [selectedImage stretchableImageWithLeftCapWidth:(int)selectedImage.size.width / 2.0 topCapHeight:(int)selectedImage.size.height / 2.0];
        [self setImage:selectedImage forState:UIControlStateSelected];
    }
}


- (void) touchesBegan:(NSSet *)touches withEvent:(UIEvent *)event
{
    [super touchesBegan:touches withEvent:event];
        
    [NSOperationQueue.mainQueue addOperationWithBlock:^{ self.highlighted = YES; }];
}


- (void) touchesCancelled:(NSSet *)touches withEvent:(UIEvent *)event
{
    [super touchesCancelled:touches withEvent:event];
    
    [self performSelector:@selector(setDefault) withObject:nil afterDelay:0.1];
}

- (void)touchesEnded:(NSSet *)touches withEvent:(UIEvent *)event
{
    [super touchesEnded:touches withEvent:event];
    
    [self performSelector:@selector(setDefault) withObject:nil afterDelay:0.1];
}


- (void)setDefault
{
    [NSOperationQueue.mainQueue addOperationWithBlock:^{ self.highlighted = NO; }];
}
@end
