#import "AppDelegate.h"
#import "refreqConstans.h"

@implementation AppDelegate

@synthesize window;
@synthesize toolBar;
@synthesize playButton;
@synthesize timeSlider;
@synthesize pixelPickupTop;
@synthesize pixelPickupBottom;

- (void)applicationDidFinishLaunching:(NSNotification *)aNotification
{
    [window setToolbar: toolBar];
    [toolBar release];
    
    
    [pixelPickupTop setWantsLayer:YES];
    [pixelPickupTop sendActionOn:(NSLeftMouseDraggedMask | NSMouseExited | NSCursorUpdateMask)];
    
    [pixelPickupBottom setWantsLayer:YES];
    [pixelPickupBottom sendActionOn:(NSLeftMouseDraggedMask | NSMouseExited | NSCursorUpdateMask)];
    
    [timeSlider setMaxValue:TIME_SLIDER_MAX_VALUE];
    [timeSlider sendActionOn:(NSLeftMouseDraggedMask | NSLeftMouseDownMask)];
   
}

-(void) drawRect:(id) sender {
    NSLog(@"asfd");
}



-(void)setTopPickupButton:(int)x :(int)y {
    [pixelPickupTop setFrame:NSMakeRect(x-50, y-50, 100, 100)];
}

-(void)setBottomPickupButton:(int)x :(int)y {
    [pixelPickupBottom setFrame:NSMakeRect(x-50, y-50, 100, 100)];
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
