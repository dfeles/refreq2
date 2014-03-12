#include "refreq2.h"
#include <stdlib.h>

@implementation Refreq2

Gui* gui = new Gui;
Vinyl* vinyl = new Vinyl;
Loader* loader = new Loader;
Player* player = new Player;
PixelPickup* pixelPickup = new PixelPickup;
Synthetizer* synthetizer = new Synthetizer;
ofxFft* fft;


- (void)setup
{
    
    NSRect backingBounds = [self convertRectToBacking:[self bounds]];
    
    GLsizei backingPixelWidth  = (GLsizei)(backingBounds.size.width),
    backingPixelHeight = (GLsizei)(backingBounds.size.height);
    
    // Set viewport
    glViewport(0, 0, backingPixelWidth, backingPixelHeight);
    
    //    [[self layer] setContentsScale:[[self window] backingScaleFactor]];
    
    
    appDelegate = [[NSApplication sharedApplication] delegate];
    
    ofSetVerticalSync(true);
	ofDisableDataPath();
    [self setFrameRate:30];
    
    NSBundle *myBundle = [NSBundle mainBundle];
    mainDataPath = std::string([[myBundle resourcePath] UTF8String]);
    
    loader->loadFile(ofToDataPath(mainDataPath + MAIN_IMAGE));
    
    loadPathNextFrame = "";
    
    ofRunApp(new RefreqSynth());
    
    
    [appDelegate setTopPickupButton:0:0];
    [appDelegate setBottomPickupButton:0:0];
}

- (void)update
{
}

- (void)draw
{
    if(loadPathNextFrame != ""){
        loader->loadFile(loadPathNextFrame);
        loadPathNextFrame = "";
    }
    
    player->update();
    if(player->getStatus() == PLAYER_PLAYING){
        float time = player->getCurrentTime()*TIME_SLIDER_MAX_VALUE;
        [appDelegate setUpTimeline:time];
    }
    gui->drawGui();
    
    
}

- (void)exit
{
	ofSoundStreamStop();
    cout << "Iexit";
}

-(void)changeTime:(id)sender
{
    player->setCurrentTime([sender floatValue]/TIME_SLIDER_MAX_VALUE);
}

-(void)setPickupTop:(NSPoint)point
{
    float scale = (float)ofGetHeight() / (float)(ofGetHeight()+60);
    pixelPickup->setTopPickupPoints(point.x, ofGetHeight() - (point.y - 60));
}

-(void)setPickupBottom:(NSPoint)point
{
    float scale = (float)ofGetHeight() / (float)(ofGetHeight()+60);
    pixelPickup->setBottomPickupPoints(point.x, ofGetHeight() - (point.y - 60));
}


- (void)playPlayer
{
    if(player->getStatus() == PLAYER_PAUSED){
        player->setStatus(PLAYER_PLAYING);
        [appDelegate setUpPlayButton:true];
        
    } else {
        player->setStatus(PLAYER_PAUSED);
        [appDelegate setUpPlayButton:false];
    }
}

- (void)keyPressed:(int)key
{
	if(key == 111){
        loadPathNextFrame = gui->getFilePath();
    } else if (key == SPACE_KEY){
        [self playPlayer];
    }
}

- (void)keyReleased:(int)key
{
	
}

- (void)mouseMoved:(NSPoint)p
{
	
}

- (void)mouseDragged:(NSPoint)p button:(int)button
{
	
}

- (void)mousePressed:(NSPoint)p button:(int)button
{
	
}

- (void)mouseReleased:(NSPoint)p button:(int)button
{
	
}

- (void)windowResized:(NSSize)size
{
    vinyl->resizeWindow();
}

@end
