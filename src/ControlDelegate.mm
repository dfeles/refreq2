//
//  ControlDelegate.m
//  refreq2
//
//  Created by Daniel Feles on 04/03/14.
//
//

#import "ControlDelegate.h"

@implementation ControlDelegate

@synthesize playButton;
@synthesize pixelPickupTop;
@synthesize pixelPickupBottom;
@synthesize onTopOfOpenGLView;

- (IBAction) changeTime: (id) sender {
    
    [ofApp changeTime:sender];
    
    NSString *digit = [sender stringValue];
    
}

- (IBAction) play: (id) sender {
    [ofApp playPlayer];
    
}
- (IBAction)pixelPickupTopAction:(id)sender {
//    [onTopOfOpenGLView setWantsLayer:YES];
    /*
    NSBezierPath* thePath = [[[NSBezierPath alloc] init] autorelease];
    [thePath moveToPoint:NSMakePoint(0.0, 0.0)];
    [thePath lineToPoint:NSMakePoint(1000.0, 1200.0)];
    [thePath setLineWidth:3.0];
    [thePath stroke];
    */
    
    NSPoint mouseLoc = [[ofApp window] mouseLocationOutsideOfEventStream];
    [self setTopPickupButton:mouseLoc.x :mouseLoc.y];
    [ofApp setPickupTop:mouseLoc];
    
}

- (IBAction)pixelPickupBottomAction:(id)sender {
    NSPoint mouseLoc = [[ofApp window] mouseLocationOutsideOfEventStream];
    [self setBottomPickupButton:mouseLoc.x :mouseLoc.y];
    [ofApp setPickupBottom:mouseLoc];
}

- (void)setTopPickupButton:(int)x :(int)y {
    [pixelPickupTop setFrame:NSMakeRect(x-50, y-50, 100, 100)];
}

- (void)setBottomPickupButton:(int)x :(int)y {
    [pixelPickupBottom setFrame:NSMakeRect(x-50, y-50, 100, 100)];
}

@end
