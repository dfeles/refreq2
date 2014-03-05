#import <Cocoa/Cocoa.h>

@interface AppDelegate : NSObject <NSApplicationDelegate>
{
	NSWindow *window;
	NSToolbar *toolBar;
	NSButton *playButton;
    NSSlider *timeSlider;
}


@property (assign) IBOutlet NSWindow *window;
@property (assign) IBOutlet NSToolbar *toolBar;
@property (assign) IBOutlet NSButton *playButton;
@property (assign) IBOutlet NSSlider *timeSlider;

-(IBAction)changeColor:(id)sender;
-(void)setUpPlayButton:(BOOL)playing;
-(void)setUpTimeline:(int)time;


@end
