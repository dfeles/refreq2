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
}

- (IBAction) changeTime: (id) sender;
- (IBAction) play: (id) sender;

@property (assign) IBOutlet NSButton *playButton;

@end
