#include "refreq2.h"
#include <stdlib.h>

@implementation Refreq2

Gui* gui = new Gui;
Vinyl* vinyl = new Vinyl;
Loader* loader = new Loader;
Player* player = new Player;
PixelPickup* pixelPickup = new PixelPickup;
Synthetizer* synthetizer = new Synthetizer;
RefreqSynth* refreqSynth = new RefreqSynth;
ofxFft* fft;

- (void)setup
{
    ofSetVerticalSync(true);
	ofDisableDataPath();
    loader->loadFile(MAIN_IMAGE);
    ofSoundStreamSetup(2, 2, SAMPLE_RATE, INITIAL_BUFFER_SIZE, 4);
    ofSoundStreamStop();
    loadPathNextFrame = "";
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

- (void)audioRequested:(float *)output :(int)bufferSize :(int)nChannels{
    synthetizer -> calculateWave(output);
}

- (void)audioReceived:(float *)input :(int)bufferSize :(int)nChannels{
}

@end
