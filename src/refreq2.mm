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
    appDelegate = [[NSApplication sharedApplication] delegate];
    ofEnableSmoothing;
    ofSetVerticalSync(true);
	ofDisableDataPath();
    [self setFrameRate:FRAME_PER_SECOND];
    
    [self loadMainImage];
    loadPathNextFrame = "";
    
    ofRunApp(new RefreqSynth());
}

- (void)update
{
}

- (void)draw
{
    [self loadFileIfNeeded];
    
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
}

- (void)loadMainImage
{
    NSBundle *myBundle = [NSBundle mainBundle];
    mainDataPath = std::string([[myBundle resourcePath] UTF8String]);
    
    loader->loadFile(ofToDataPath(mainDataPath + MAIN_IMAGE));
}

- (void)loadFileIfNeeded
{
    if(loadPathNextFrame != ""){
        loader->loadFile(loadPathNextFrame);
        loadPathNextFrame = "";
        
        vinyl->saveVinylImage("../../../a.png");
    }
}

-(void)changeTime:(id)sender
{
    player->setCurrentTime([sender floatValue]/TIME_SLIDER_MAX_VALUE);
}

-(void)setVolume2:(id)sender
{
    synthetizer->setVolume([sender floatValue]);
}

-(void)setPickupTop:(NSPoint)point
{
    float scale = (float)ofGetHeight() / (float)(ofGetHeight());
    pixelPickup->setTopPickupPoints(point.x, ofGetHeight() - (point.y));
}

-(void)setPickupBottom:(NSPoint)point
{
    float scale = (float)ofGetHeight() / (float)(ofGetHeight());
    pixelPickup->setBottomPickupPoints(point.x, ofGetHeight() - (point.y));
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


- (void)importFile
{
    loadPathNextFrame = gui->getFilePath();
}

- (void)keyPressed:(int)key
{
	if(key == 105){
        loadPathNextFrame = gui->getFilePath();
    }
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
