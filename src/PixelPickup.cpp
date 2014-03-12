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
    setTopPickupPoints(200,0);
    setBottomPickupPoints(200,660);
    
    for(int i=0; i<PIXELS_READING; i++){
         readPixels[i][0] = 0;
    }
}

void PixelPickup::getPixels() {
    float _s = (float)(ofGetHeight()-HEADER_HEIGHT-FOOTER_HEIGHT)/(float)PIXELS_READING;
    ofLine(pickupPointTop.x * _s, pickupPointTop.y * _s + HEADER_HEIGHT, pickupPointBottom.x * _s, pickupPointBottom.y * _s + HEADER_HEIGHT);
    for(int i=0; i<PIXELS_READING; i++){
        float _x = pickupPointTop.x + (pickupPointBottom.x - pickupPointTop.x) / PIXELS_READING * (float) i;
        
        float _y = pickupPointTop.y + (pickupPointBottom.y - pickupPointTop.y) / PIXELS_READING * (float) i;
        
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
}

void PixelPickup::setTopPickupPoints(float x1, float y1) {
    y1 = limitY(y1);
    x1 = limitX(x1);

    pickupPointTop.x = x1;
    pickupPointTop.y = y1;
}


void PixelPickup::setBottomPickupPoints(float x2, float y2) {
    y2 = limitY(y2);
    x2 = limitX(x2);

    pickupPointBottom.x = x2;
    pickupPointBottom.y = y2;
}

float PixelPickup::limitY (float y) {
    y *= PIXELS_READING / vinyl->getVinylHeight();
    
    y = MIN(y, PIXELS_READING-1);
    y = MAX(y, 0);
    return y;
}

float PixelPickup::limitX (float x) {
    x *= PIXELS_READING / vinyl->getVinylHeight();
    return x;
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