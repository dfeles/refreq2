#include "ofMain.h"
#include "refreq2.h"

//========================================================================
int main( ){
	ofSetupOpenGL(1280,800,OF_WINDOW);			// <-------- setup the GL context
    ofSetFrameRate(FRAME_PER_SECOND);

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp(new Refreq2());

}
