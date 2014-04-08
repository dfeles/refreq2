//
//  ControlDelegate.m
//  refreq2
//
//  Created by Daniel Feles on 04/03/14.
//
//

#import "ControlDelegate.h"

@implementation ControlDelegate

@synthesize TopPickerY;
@synthesize TopPickerX;
@synthesize BottomPickerX;
@synthesize BottomPickerY;
@synthesize playButton;

- (IBAction) changeTime: (id) sender {
    
    [ofApp changeTime:sender];
    
}

- (IBAction) play: (id) sender {
    [ofApp playPlayer];
    
}
- (IBAction)pixelPickupTopAction:(id)sender {
    screenSize = [[ofApp superview] frame];
    NSPoint mouseLoc = [[ofApp window] mouseLocationOutsideOfEventStream];
    mouseLoc.y = MIN(MAX(mouseLoc.y, 5), screenSize.size.height-5);
    [self setTopPickupButton:mouseLoc.x :mouseLoc.y];
    [ofApp setPickupTop:mouseLoc];
    
}

- (IBAction)pixelPickupBottomAction:(id)sender {
    screenSize = [[ofApp superview] frame];
    NSPoint mouseLoc = [[ofApp window] mouseLocationOutsideOfEventStream];
    mouseLoc.y = MIN(MAX(mouseLoc.y, 5), screenSize.size.height-5);
    [self setBottomPickupButton:mouseLoc.x :mouseLoc.y];
    [ofApp setPickupBottom:mouseLoc];
}

- (void)setTopPickupButton:(int)x :(int)y {
    [TopPickerY setConstant: screenSize.size.height-y-25];
    [TopPickerX setConstant: x-25];
}

- (void)setBottomPickupButton:(int)x :(int)y {
    [BottomPickerY setConstant: y-25];
    [BottomPickerX setConstant: x-25];
}

- (IBAction)importFile:(id)sender {
    [ofApp importFile];
}

- (IBAction)changeVolume:(id)sender {

    [ofApp setVolume2:sender];
}
@end
