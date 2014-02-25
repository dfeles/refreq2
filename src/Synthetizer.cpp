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
        
        for(int n = 0;n<PIXELS_READING;n+=1){
            
            
            if (pixelPickup->readPixels[n][0]>0.000001) {
                
                //if ( phases[n] >= INITIAL_BUFFER_SIZE ) phases[n] -= INITIAL_BUFFER_SIZE;
                //wave+=(sinesBuffer[1+ (long) phases[n]]) * pixelPickup->readPixels[n][0];
                
                
                int freq = pixelPickup->readPixels[n][1];
                phases[n] += INITIAL_BUFFER_SIZE/(44100.0/freq);
                if ( phases[n] >= INITIAL_BUFFER_SIZE ) phases[n] -= INITIAL_BUFFER_SIZE;
                
                wave+=sinesBuffer[(int)(1+ (long) phases[n]) % 514] * pixelPickup->readPixels[n][0];
                
                //remainder = phases[n] - floor(phases[n]);
                //wave+=(float) ((1-remainder) * sineBuffer[1+ (long) phases[n]] + remainder * sineBuffer[2+(long) phases[n]])*amp[n];
                
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
void Synthetizer::reset() {
    for (int i=0;i < INITIAL_BUFFER_SIZE; i++){
        soundWave[i] = 0;
    }
    
    for(int n = 0;n<PIXELS_READING;n++){
        phases[n] = 0;
    }

}