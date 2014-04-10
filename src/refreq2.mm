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
    if(filesToLoad.size() > 0){
        loader->loadFile(filesToLoad[0]);
        ofFile fileToLoad(filesToLoad[0]);
        filesToLoad.erase(filesToLoad.begin());
        
        string fileName = fileToLoad.getFileName().substr(0, fileToLoad.getFileName().size()-4);
        //vinyl->saveVinylImage("../../../newF/" + fileName + ".png"); // this is only for my diploma
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

-(void)setEcho:(id)sender
{
    pixelPickup->echo = [sender floatValue];
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

- (void)exportImage
{
    vinyl->exportVinyl(currentLoadedFileName);
}


- (void)importFile
{
    string path = gui->getFilePath();
    ofFile fileToLoad(path);
    
    cout << filesToLoad.size() << endl;
    if(fileToLoad.getExtension() == ""){
        ofDirectory dir(path);
        dir.allowExt("mp3");
        dir.listDir();
        for(int i = 0; i < dir.numFiles(); i++){
            filesToLoad.push_back(dir.getPath(i));
        }
    }else{
        filesToLoad.push_back(path);
    };
}

- (void)keyPressed:(int)key
{
    if(key == 105){
        [self exportImage];
    }
	if(key == 111){
        [self importFile];
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
