#import "AppDelegate.h"
#import "refreqConstans.h"

@implementation AppDelegate

@synthesize window;
@synthesize toolBar;
@synthesize playButton;
@synthesize timeSlider;
@synthesize pixelPickupTop;
@synthesize pixelPickupBottom;
@synthesize splitView;
@synthesize settingsSidebar;
@synthesize frequencySideBar;
@synthesize MaxHz;

- (void)applicationDidFinishLaunching:(NSNotification *)aNotification
{
    [self setupToolBar];
    [self setupPixelPickerUIs];
    [self setupSplitView];
    [self setupFrequencySidebar];
    [self setupSettingsSidebar];
    
    [timeSlider setMaxValue:TIME_SLIDER_MAX_VALUE];
    [timeSlider sendActionOn:(NSLeftMouseDraggedMask | NSLeftMouseDownMask)];
   
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

- (void)setupToolBar
{
    [window setToolbar: toolBar];
    [toolBar release];
}

- (void)setupPixelPickerUIs
{
    [pixelPickupTop setWantsLayer:YES];
    [pixelPickupTop sendActionOn:(NSLeftMouseDraggedMask | NSMouseExited | NSCursorUpdateMask)];
    
    [pixelPickupBottom setWantsLayer:YES];
    [pixelPickupBottom sendActionOn:(NSLeftMouseDraggedMask | NSMouseExited | NSCursorUpdateMask)];
}

- (void)setUpTimeline:(int)time
{
    [timeSlider setFloatValue:time];
}

- (void)setupFrequencySidebar
{
    [frequencySideBar setWantsLayer:YES];
    frequencySideBar.layer.backgroundColor = CGColorCreateGenericRGB(.2, .2, .2, 0.6);
}

- (void)setupSettingsSidebar
{
    [settingsSidebar setWantsLayer:YES];
    settingsSidebar.layer.backgroundColor = CGColorCreateGenericRGB(.7, .7, .7, 0);
    
}

- (void)setupSplitView
{
    
    NSView *left  = [[[self splitView] subviews] objectAtIndex:0];
    NSRect leftFrame = [left frame];
    NSRect overallFrame = [window frame];
    [left setFrameSize:NSMakeSize(overallFrame.size.width,leftFrame.size.height)];
    [self collapseRightView];
}

- (IBAction)openSettingsSidebar:(id)sender {
    BOOL rightViewCollapsed = [[self splitView] isSubviewCollapsed:[[[self splitView] subviews] objectAtIndex: 1]];
	if (rightViewCollapsed) {
		[self uncollapseRightView];
	} else {
		[self collapseRightView];
	}
}

-(void)collapseRightView
{
    NSView *right = [[[self splitView] subviews] objectAtIndex:1];
    NSView *left  = [[[self splitView] subviews] objectAtIndex:0];
    NSRect leftFrame = [left frame];
    NSRect overallFrame = [window frame];
    [right setHidden:YES];
    [left setFrameSize:NSMakeSize(overallFrame.size.width,leftFrame.size.height)];
    [[self splitView] display];
}

-(void)uncollapseRightView
{
	NSView *left  = [[[self splitView] subviews] objectAtIndex:0];
	NSView *right = [[[self splitView] subviews] objectAtIndex:1];
    [right setHidden:NO];
    
	CGFloat dividerThickness = [[self splitView] dividerThickness];
	
	NSRect leftFrame = [left frame];
	NSRect rightFrame = [right frame];
    
	leftFrame.size.width = (leftFrame.size.width-rightFrame.size.width-dividerThickness);
	rightFrame.origin.x = leftFrame.size.width + dividerThickness;
	[left setFrameSize:leftFrame.size];
	[right setFrame:rightFrame];
	[[self splitView] display];
}

- (BOOL)splitView:(NSSplitView *)splitView canCollapseSubview:(NSView *)subview;
{
    NSView* rightView = [[splitView subviews] objectAtIndex:1];
    return ([subview isEqual:rightView]);
}

- (BOOL)splitView:(NSSplitView *)splitView shouldCollapseSubview:(NSView *)subview forDoubleClickOnDividerAtIndex:(NSInteger)dividerIndex;
{
    NSView* rightView = [[splitView subviews] objectAtIndex:1];
    return ([subview isEqual:rightView]);
}

- (BOOL)splitView:(NSSplitView *)splitView shouldHideDividerAtIndex:(NSInteger)dividerIndex;
{
    return YES;
}

- (CGFloat)splitView:(NSSplitView *)splitView constrainMinCoordinate:(CGFloat)proposedMinimumPosition ofSubviewAt:(NSInteger)dividerIndex;
{
    return proposedMinimumPosition + 1000;
}

- (CGFloat)splitView:(NSSplitView *)splitView constrainMaxCoordinate:(CGFloat)proposedMaximumPosition ofSubviewAt:(NSInteger)dividerIndex;
{
    return proposedMaximumPosition - 180;
}

@end
