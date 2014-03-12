//
//  Player.h
//  refreq2
//
//  Created by Daniel Feles on 2/5/14.
//
//

#ifndef __refreq2__Player__
#define __refreq2__Player__

#include <iostream>
#include "refreqConstans.h"
#include "Vinyl.h"
#include "PixelPickup.h"
#include "Synthetizer.h"

extern Vinyl* vinyl;
extern PixelPickup* pixelPickup;
extern Synthetizer* synthetizer;

class Player {
public:
    void update ();
    int getStatus ();
    int getSpeed ();
    float getCurrentTime ();
    void setStatus (int status);
    void setSpeed (float _speed);
    void setCurrentTime (float _time);
    void setLength (float _width);
    float stepLength();
    bool settingUpTime = false;
private:
    int status = PLAYER_PAUSED;
    float speed = 1;
    float currentTime = 0;
    float length;
};

#endif /* defined(__refreq2__Player__) */
