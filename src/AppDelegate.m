#import "AppDelegate.h"
#import "refreqConstans.h"
#import <objc/runtime.h>


@interface AppDelegate(ShutUpXcode)
- (float)roundedCornerRadius;
- (void)drawRectOriginal:(NSRect)rect;
@end

@implementation AppDelegate

@synthesize window;
@synthesize toolBar;
@synthesize playButton;
@synthesize timeSlider;
@synthesize changeVolume;
@synthesize changeEcho;
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
    
    [changeVolume sendActionOn:(NSLeftMouseDraggedMask | NSLeftMouseDownMask)];
    [changeEcho sendActionOn:(NSLeftMouseDraggedMask | NSLeftMouseDownMask)];
    
   
	
	// Get window's frame view class
	id class = [[[window contentView] superview] class];
    
	
	// Exchange draw rect
	Method m0 = class_getInstanceMethod([self class], @selector(drawRect:));
	class_addMethod(class, @selector(drawRectOriginal:), method_getImplementation(m0), method_getTypeEncoding(m0));
	
	Method m1 = class_getInstanceMethod(class, @selector(drawRect:));
	Method m2 = class_getInstanceMethod(class, @selector(drawRectOriginal:));
	
	method_exchangeImplementations(m1, m2);
   
}


- (void)drawRect:(NSRect)rect
{
	// Call original drawing method
	[self drawRectOriginal:rect];
    
	//
	// Build clipping path : intersection of frame clip (bezier path with rounded corners) and rect argument
	//
    if (![[[self window] title]  isEqual: @"refreq2"]){
        return;
    };
	NSRect windowRect = [[self window] frame];
	windowRect.origin = NSMakePoint(0, 0);
    
	float cornerRadius = 3;
	[[NSBezierPath bezierPathWithRoundedRect:windowRect xRadius:cornerRadius yRadius:cornerRadius] addClip];
	[[NSBezierPath bezierPathWithRect:rect] addClip];
    
	//
	// Draw a background color on top of everything
	//
	CGContextRef context = [[NSGraphicsContext currentContext]graphicsPort];
	CGContextSetBlendMode(context, kCGBlendModeNormal);
//	[[NSColor colorWithCalibratedRed:0.18 green:0.18 blue:0.18 alpha:1] set];
	[[NSColor colorWithCalibratedRed:1 green:1 blue:1 alpha:1] set];
	[[NSBezierPath bezierPathWithRect:rect] fill];
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
    frequencySideBar.layer.backgroundColor = CGColorCreateGenericRGB(.8, .8, .8, 0.6);
}

- (void)setupSettingsSidebar
{
    [settingsSidebar setWantsLayer:YES];
    settingsSidebar.layer.backgroundColor = CGColorCreateGenericRGB(.9, .9, .9, 1);
    
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
