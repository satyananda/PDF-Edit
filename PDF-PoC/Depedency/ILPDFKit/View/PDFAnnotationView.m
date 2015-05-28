//
//  AnnotationView.m
//  PDF-PoC
//
//  Created by Rajeshkumar on 12/05/15.
//  Copyright (c) 2015 T-Mobile. All rights reserved.
//

#import "PDFAnnotationView.h"

#define DEFAULT_ZOOM_SCALE 1.0f;

@interface PDFAnnotationView()
{
    CGRect baseFrame;
    CGFloat zoomScale;
}
@end

@implementation PDFAnnotationView

/*
// Only override drawRect: if you perform custom drawing.
// An empty implementation adversely affects performance during animation.
- (void)drawRect:(CGRect)rect {
    // Drawing code
}
*/

- (instancetype)initWithFrame:(CGRect)frame
{
    self = [super initWithFrame:frame];
    if(self){
        [self doInitialSetup];
    }
    return self;
}

- (void)updateWithZoom:(CGFloat)scale
{
    zoomScale = scale;
    self.frame = CGRectMake(baseFrame.origin.x*zoomScale, baseFrame.origin.y*zoomScale, baseFrame.size.width*zoomScale, baseFrame.size.height*zoomScale);
}

#pragma mark - Private

- (void)doInitialSetup
{
    baseFrame = [self frame];
    zoomScale = DEFAULT_ZOOM_SCALE;
}

@end
