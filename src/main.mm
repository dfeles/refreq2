#include "ofMain.h"
#include "refreq2.h"
#include <Cocoa/Cocoa.h>

//========================================================================
int main( ){
	ofSetupOpenGL(1280,800,OF_WINDOW);			// <-------- setup the GL context
    ofSetFrameRate(FRAME_PER_SECOND);

    NSWindow * appWindow = (NSWindow *)ofGetCocoaWindow();

    if(appWindow) {
        
        NSView *themeView = [appWindow.self.contentView superview];
        NSUInteger adj = 6;
        
        int x = 100; //possition x
        int y = 100; //possition y
        
        int width = 130;
        int height = 40;
        
        IBOutlet NSToolbar *toolbar;
        
        [toolbar setAllowsUserCustomization:YES];
        
        
        NSButton *miniaturizeButton = [[[NSButton alloc] initWithFrame:NSMakeRect(x, y, width, height)] autorelease];
        [[appWindow contentView] addSubview: miniaturizeButton];
        [miniaturizeButton setTitle: @"ha"];
        [miniaturizeButton setTransparent:false];
        
        [miniaturizeButton setTarget:appWindow.self];
        [miniaturizeButton setAction:@selector(buttonPressed)];
        
        //NSButton *miniaturizeButton = [appWindow.self standardWindowButton:NSWindowMiniaturizeButton];
        
        [miniaturizeButton removeFromSuperview];
        miniaturizeButton.frame = NSMakeRect( miniaturizeButton.frame.origin.x,
                                            appWindow.frame.size.height - miniaturizeButton.frame.size.height - adj,
                                            miniaturizeButton.frame.size.width, miniaturizeButton.frame.size.height);
        [themeView addSubview:miniaturizeButton];
        
       // [titleBarView setHidden:YES];
        // make your obj-c calls here
    }
	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp(new Refreq2());

}
