//
//  ControlDelegate.h
//  refreq2
//
//  Created by Daniel Feles on 04/03/14.
//
//

#import <Cocoa/Cocoa.h>
#import "ofxCocoaGLView.h"

@interface ControlDelegate : NSObject <NSApplicationDelegate> {
    
    IBOutlet NSSlider *timeSlider;
    IBOutlet ofxCocoaGLView* ofApp;
	NSButton *playButton;
    
    NSRect screenSize;
    
    NSLayoutConstraint *TopPickerY;
    NSLayoutConstraint *TopPickerX;
    NSLayoutConstraint *BottomPickerX;
    NSLayoutConstraint *BottomPickerY;
}

- (IBAction) changeTime: (id) sender;
- (IBAction) play: (id) sender;
- (IBAction) pixelPickupTopAction: (id) sender;
- (IBAction)importFile:(id)sender;
- (IBAction)changeVolume:(id)sender;

@property (assign) IBOutlet NSLayoutConstraint *TopPickerY;
@property (assign) IBOutlet NSLayoutConstraint *TopPickerX;
@property (assign) IBOutlet NSLayoutConstraint *BottomPickerX;
@property (assign) IBOutlet NSLayoutConstraint *BottomPickerY;
@property (assign) IBOutlet NSButton *playButton;

@end
