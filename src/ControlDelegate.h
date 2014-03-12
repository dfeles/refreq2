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
	NSButton *pixelPickupTop;
	NSButton *pixelPickupBottom;
    
	NSView *onTopOfOpenGLView;
}

- (IBAction) changeTime: (id) sender;
- (IBAction) play: (id) sender;
- (IBAction) pixelPickupTopAction: (id) sender;
- (IBAction) drawRect: (id) sender;

@property (assign) IBOutlet NSButton *playButton;
@property (assign) IBOutlet NSButton *pixelPickupTop;
@property (assign) IBOutlet NSButton *pixelPickupBottom;

@property (assign) IBOutlet NSView *onTopOfOpenGLView;

@end
