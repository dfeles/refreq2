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
    ofSetVerticalSync(true);
	ofDisableDataPath();
    [self setFrameRate:30];
    
    loader->loadFile(MAIN_IMAGE);
    loadPathNextFrame = "";
    
    ofRunApp(new RefreqSynth());
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
    gui->drawGui();
    
    
    
}

- (void)exit
{
	ofSoundStreamStop();
    cout << "Iexit";
}

-(void)changeColor:(id)sender
{
    
}

- (void)keyPressed:(int)key
{
	if(key == 111){
        loadPathNextFrame = gui->getFilePath();
    } else if (key == SPACE_KEY){
        if(player->getStatus() == PLAYER_PAUSED){
            player->setStatus(PLAYER_PLAYING);
        } else {
            player->setStatus(PLAYER_PAUSED);
        }
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
