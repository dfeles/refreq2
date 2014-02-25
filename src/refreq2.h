#pragma once

#include "ofMain.h"
#include "Gui.h"
#include "Vinyl.h"
#include "Loader.h"
#include "Player.h"
#include "PixelPickup.h"
#include "Synthetizer.h"
#include "ofxFft.h"


class Refreq2 : public ofBaseApp{

public:
	void setup();
	void update();
	void draw();
   
	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);
    threadedMusicLoader musicLoader;
    void exit();
    
private:
	void audioRequested 	(float * input, int bufferSize, int nChannels); /* output method */
	void audioReceived 	(float * input, int bufferSize, int nChannels); /* input method */
		
};
