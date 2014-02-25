//
//  Loader.h
//  refreq2
//
//  Created by Daniel Feles on 2/5/14.
//
//

#ifndef __refreq2__Loader__
#define __refreq2__Loader__

#include <iostream>
#include <algorithm>
#include "ofMain.h"
#include "Vinyl.h"
#include "refreqConstans.h"
#include "ofxAudioDecoder.h"
#include "ofxFft.h"
#include "Player.h"
#include "Gui.h"

extern Vinyl* vinyl;
extern Player* player;
extern Gui* gui;

class Loader {
    public:
        void loadFile(string path);
        ofImage createdSpectrum;
    
    private:
        ofxAudioDecoder audio;    
        ofxFft* fft;

        void loadMusic(string path);
        void loadPicture(ofFile file);
    
};
#endif /* defined(__refreq2__Loader__) */
