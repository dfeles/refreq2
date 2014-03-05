//
//  ControlDelegate.m
//  refreq2
//
//  Created by Daniel Feles on 04/03/14.
//
//

#import "ControlDelegate.h"

@implementation ControlDelegate

@synthesize playButton;

- (IBAction) changeTime: (id) sender {
    [ofApp changeTime:sender];
    
    NSString *digit = [sender stringValue];
    
}

- (IBAction) play: (id) sender {
    
    
}

@end
