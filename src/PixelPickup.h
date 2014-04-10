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
    
        ofPoint pickupPointTop;
        ofPoint pickupPointBottom;
        void getPixels();
        float readPixels [(int)PIXELS_READING][2];
        void setTopPickupPoints(float x1, float y1);
        void setBottomPickupPoints(float x2, float y2);
        void setupHertz (float min, float max, bool logarithmic);
        int getHertzMin ();
        int getHertzMax ();
        int getFreq(int y);
        float echo = .5;
private:
    float limitY (float y);
    float limitX (float x);
        float averageB = 0;
        float hertzScale[(int)PIXELS_READING];
    
};
#endif /* defined(__refreq2__PixelPickup__) */
