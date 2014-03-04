#import "AppDelegate.h"

@implementation AppDelegate

@synthesize window;

- (void)dealloc
{
    [super dealloc];
}


-(void)changeColor:(id)sender
{
    [ofApp changeColor:self];
}


@end
