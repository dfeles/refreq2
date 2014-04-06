#import <Cocoa/Cocoa.h>

@interface AppDelegate : NSObject <NSApplicationDelegate>
{
	NSWindow *window;
	NSToolbar *toolBar;
	NSButton *playButton;
	NSButton *pixelPickupTop;
	NSButton *pixelPickupBottom;
    NSSplitView *splitView;
    NSView *settingsSidebar;
    NSView *frequencySideBar;
    NSTextField *MaxHz;
    NSSlider *timeSlider;
}


@property (assign) IBOutlet NSWindow *window;
@property (assign) IBOutlet NSToolbar *toolBar;
@property (assign) IBOutlet NSButton *playButton;
@property (assign) IBOutlet NSButton *pixelPickupTop;
@property (assign) IBOutlet NSButton *pixelPickupBottom;
@property (assign) IBOutlet NSSplitView *splitView;
@property (assign) IBOutlet NSView *settingsSidebar;
@property (assign) IBOutlet NSView *frequencySideBar;
@property (assign) IBOutlet NSTextField *MaxHz;

@property (assign) IBOutlet NSSlider *timeSlider;

-(IBAction)changeColor:(id)sender;
-(void)setUpPlayButton:(BOOL)playing;
-(void)setUpTimeline:(int)time;
- (IBAction)openSettingsSidebar:(id)sender;

@end
