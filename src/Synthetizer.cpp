//
//  Synthetizer.cpp
//  refreq2
//
//  Created by Daniel Feles on 2/5/14.
//
//  This is responsible for loading images or music into refreq
//

#include "Synthetizer.h"

Synthetizer::Synthetizer () {
    for (int i=0;i < INITIAL_BUFFER_SIZE; i++){
        soundWave[i] = 0;
    }
}

void Synthetizer::calculateWave (float * output) {
    for (int i = 0; i < INITIAL_BUFFER_SIZE; i++){
        
        wave = 0.0;
        
        for(int n = 0;n<PIXELS_READING;n++){
            
            if (pixelPickup->readPixels[n][0]>0.00001) {
                phases[n] += 512./(44100.0/(pixelPickup->readPixels[n][1]));
                
                if ( phases[n] >= 511 ) phases[n] -=512;
                
                //remainder = phases[n] - floor(phases[n]);
                //wave+=(float) ((1-remainder) * sineBuffer[1+ (long) phases[n]] + remainder * sineBuffer[2+(long) phases[n]])*amp[n];
                
                wave+=(sinesBuffer[1+ (long) phases[n]]) * pixelPickup->readPixels[n][0];
            }
        }
        
        wave/=10.0;
        //if(wave>1.0) wave=1.0;
        //if(wave<-1.0) wave=-1.0;
		
        
        output[i*2    ] = wave;
        output[i*2 + 1] = wave;
        soundWave[i] = wave;
    }
    
}