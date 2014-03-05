#import "AppDelegate.h"
#import "refreqConstans.h"

@implementation AppDelegate

@synthesize window;
@synthesize toolBar;
@synthesize playButton;
@synthesize timeSlider;

- (void)applicationDidFinishLaunching:(NSNotification *)aNotification
{
    [window setToolbar: toolBar];
    [toolBar release];
    
    [timeSlider setMaxValue:TIME_SLIDER_MAX_VALUE];
   
}

- (void)dealloc
{
    [super dealloc];
}

- (void)setUpPlayButton:(BOOL)playing
{
    if(playing){
        [playButton setImage:[NSImage imageNamed:@"pauseIcon"]];
    }else{
        [playButton setImage:[NSImage imageNamed:@"playIcon"]];
    }
}

- (void)setUpTimeline:(int)time
{
    [timeSlider setFloatValue:time];
}

@end
