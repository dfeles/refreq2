//
//  PixelPickup.cpp
//  refreq2
//
//  Created by Daniel Feles on 2/5/14.
//
//  This is responsible for reading the pixels from loaded image, and combining the values with frequency values
//

#include "PixelPickup.h"

PixelPickup::PixelPickup(){
    //remember: x can only be between 0 - vinylWidth
    //remember: y can only be between 0 - PIXELS_READING-1
    
    setupHertz(DEFAULT_MIN_HZ, DEFAULT_MAX_HZ, false);
    
    pickupPoint1.x = 200;
    pickupPoint1.y = 0;
    
    pickupPoint2.x = 200;
    pickupPoint2.y = PIXELS_READING-1;
    
    for(int i=0; i<PIXELS_READING; i++){
         readPixels[i][0] = 0;
    }
}

void PixelPickup::getPixels() {
    float _s = (float)(ofGetHeight()-HEADER_HEIGHT-FOOTER_HEIGHT)/(float)PIXELS_READING;
    ofLine(pickupPoint1.x * _s, pickupPoint1.y * _s + HEADER_HEIGHT, pickupPoint2.x * _s, pickupPoint2.y * _s + HEADER_HEIGHT);
    for(int i=0; i<PIXELS_READING; i++){
        float _x = pickupPoint1.x + (pickupPoint2.x - pickupPoint1.x) / PIXELS_READING * (float) i;
        
        float _y = pickupPoint1.y + (pickupPoint2.y - pickupPoint1.y) / PIXELS_READING * (float) i;
        
        ofPoint pointToGet = *new ofVec2f((int)_x,(int)_y);
        
        readPixels[i][0] = vinyl->getPixel(pointToGet).getBrightness()/255.0;
        readPixels[i][1] = getFreq(pointToGet.y);
        
        
        if(i%2 == 0){
            ofEnableBlendMode(OF_BLENDMODE_MULTIPLY);
            ofSetColor(readPixels[i-1][0]*255.0, readPixels[i-1][0]*255.0, readPixels[i-1][0]*255.0,readPixels[i-1][0]*10.0);
            ofCircle(_x*_s, _y*_s+HEADER_HEIGHT, readPixels[i-1][0]*20.0);
            ofDisableBlendMode();
        }
    }
    //cout << "NEXTFRAME #########" << endl;
}

void PixelPickup::setupHertz (float min, float max, bool logarithmic) {
    if (logarithmic){
        for(int n = 1;n<PIXELS_READING+1;n++){
            hertzScale[n] = log((max-min) / PIXELS_READING) * n;
        }
    }else{
        for(int n = 1;n<PIXELS_READING+1;n++){
            hertzScale[n] = (max-min) / PIXELS_READING * n;
        }
    }
}

int PixelPickup::getFreq(int y) {
    return hertzScale[(int)PIXELS_READING-y];
}