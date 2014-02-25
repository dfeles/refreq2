//
//  PixelPickup.h
//  refreq2
//
//  Created by Daniel Feles on 2/5/14.
//
//

#ifndef __refreq2__PixelPickup__
#define __refreq2__PixelPickup__

#include <iostream>
#include "ofMain.h"
#include "refreqConstans.h"
#include "Vinyl.h"

extern Vinyl* vinyl;

class PixelPickup {
    public:
        PixelPickup();
        ofPoint pickupPoint1;
        ofPoint pickupPoint2;
        void getPixels();
        float readPixels [(int)PIXELS_READING][2];
        void setupHertz (float min, float max, bool logarithmic);
        int getHertzMin ();
        int getHertzMax ();
        int getFreq(int y);
    private:
        float averageB = 0;
        float hertzScale[(int)PIXELS_READING];
    
};
#endif /* defined(__refreq2__PixelPickup__) */
