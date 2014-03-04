//
//  refreqSynth.h
//  refreq2
//
//  Created by Daniel Feles on 04/03/14.
//
//

#ifndef __refreq2__refreqSynth__
#define __refreq2__refreqSynth__

#include "ofMain.h"
#include <iostream>
#include "Synthetizer.h"

extern Synthetizer* synthetizer;

class RefreqSynth : public ofBaseApp{
public:
	void setup();
    void exit();
    
private:
	void audioRequested 	(float * input, int bufferSize, int nChannels); /* output method */
	void audioReceived 	(float * input, int bufferSize, int nChannels); /* input method */
    
};

#endif /* defined(__refreq2__refreqSynth__) */
