#import <Cocoa/Cocoa.h>

@interface AppDelegate : NSObject <NSApplicationDelegate>
{
	NSWindow *window;
	NSToolbar *toolBar;
	NSButton *playButton;
	NSButton *pixelPickupTop;
	NSButton *pixelPickupBottom;
    NSSlider *timeSlider;
}


@property (assign) IBOutlet NSWindow *window;
@property (assign) IBOutlet NSToolbar *toolBar;
@property (assign) IBOutlet NSButton *playButton;
@property (assign) IBOutlet NSButton *pixelPickupTop;
@property (assign) IBOutlet NSButton *pixelPickupBottom;

@property (assign) IBOutlet NSSlider *timeSlider;

-(IBAction)changeColor:(id)sender;
-(void)setUpPlayButton:(BOOL)playing;
-(void)setUpTimeline:(int)time;

-(void)setTopPickupButton:(int)x :(int)y;
-(void)setBottomPickupButton:(int)x :(int)y;

@end
