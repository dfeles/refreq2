//
//  CustomDrawingView.m
//  refreq2
//
//  Created by Daniel Feles on 14/03/14.
//
//

#import "CustomDrawingView.h"

@implementation CustomDrawingView

- (id)initWithFrame:(NSRect)frame
{
    self = [super initWithFrame:frame];
    if (self) {
        [self setWantsLayer:YES];
        // Initialization code here.
    }
    return self;
}

- (void)drawRect:(NSRect)dirtyRect
{
    [super drawRect:dirtyRect];
    
    [[NSColor blueColor] set];
    NSRectFill(dirtyRect);
}

@end
