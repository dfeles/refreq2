#include "ofMain.h"
#include "refreq2.h"
#include <Cocoa/Cocoa.h>

//========================================================================
int main( ){
	ofSetupOpenGL(1280,800,OF_WINDOW);			// <-------- setup the GL context
    ofSetFrameRate(FRAME_PER_SECOND);

    NSWindow * appWindow = (NSWindow *)ofGetCocoaWindow();

    if(appWindow) {
        
        
        [appWindow setTitle:@"refreq2"];
        
        NSToolbar *toolbar = [[NSToolbar alloc] initWithIdentifier:@"toolbar"];
        
        [toolbar setAllowsUserCustomization:YES];
        [toolbar setAutosavesConfiguration:YES];
        [toolbar setDisplayMode:NSToolbarDisplayModeDefault];
        
//        [toolbar setDelegate:appWindow.self];
        
        
        [appWindow setToolbar:toolbar];
        [toolbar release];
        
        
        NSView *themeView = [appWindow.self.contentView superview];
        
        
        
        NSToolbarItem *item = [[NSToolbarItem alloc] initWithItemIdentifier:@"toolbarItem"];
        [item setLabel:@"haliho"];
        
        
        
        NSButton *button = [[NSButton alloc]init];
        [button setImage:[NSImage imageNamed:@"StarEmpty"]];
        [button setAlternateImage:[NSImage imageNamed:@"StarFull"]];
        [button setImagePosition:NSImageOnly];
        [button setBordered:NO];
        

        
        
        
        
//        [toolbar setView:miniaturizeButton];
        
       // [titleBarView setHidden:YES];
        // make your obj-c calls here
    }
	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp(new Refreq2());

}
