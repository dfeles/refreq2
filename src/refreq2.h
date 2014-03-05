#pragma once

#include "ofMain.h"
#include "AppDelegate.h"
#include "ofxCocoaGLView.h"
#include "Gui.h"
#include "Vinyl.h"
#include "Loader.h"
#include "Player.h"
#include "PixelPickup.h"
#include "Synthetizer.h"
#include "ofxFft.h"
#include "refreqSynth.h"


@interface Refreq2 : ofxCocoaGLView {
    
    string loadPathNextFrame;
    AppDelegate *appDelegate;
    
}



- (void)setup;
- (void)update;
- (void)draw;
- (void)exit;

- (void)keyPressed:(int)key;
- (void)keyReleased:(int)key;
- (void)mouseMoved:(NSPoint)p;
- (void)mouseDragged:(NSPoint)p button:(int)button;
- (void)mousePressed:(NSPoint)p button:(int)button;
- (void)mouseReleased:(NSPoint)p button:(int)button;
- (void)windowResized:(NSSize)size;

- (void)changeTime:(id)sender;
- (void)playPlayer;



@end
