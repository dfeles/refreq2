#import <Cocoa/Cocoa.h>
#import "ofxCocoaGLView.h"

@interface AppDelegate : NSObject <NSApplicationDelegate>
{
	NSWindow *window;
    IBOutlet ofxCocoaGLView* ofApp;
}


@property (assign) IBOutlet NSWindow *window;

-(IBAction)changeColor:(id)sender;


@end
