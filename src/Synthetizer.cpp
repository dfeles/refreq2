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
        for(int n = 0; n < PIXELS_READING; n += 3){
            
            
            if (pixelPickup->readPixels[n][0]>0.000001) {
                
                int freq = pixelPickup->readPixels[n][1];
                phases[n] += INITIAL_BUFFER_SIZE/( (float)SAMPLE_RATE/freq);
                if ( phases[n] > 514 ) phases[n] -= 514;
                
                wave += sinesBuffer[(int) phases[n]] * pixelPickup->readPixels[n][0];
                
            }
        }
        
        wave /= 10.0 / volume;
		
        
        output[i*2    ] = wave;
        output[i*2 + 1] = wave;
        soundWave[i] = wave;
    }
    
}

void Synthetizer::setVolume(float _volume)
{
    volume = _volume;
};

void Synthetizer::reset() {
    for (int i=0;i < INITIAL_BUFFER_SIZE; i++){
        soundWave[i] = 0;
    }
    
    for(int n = 0;n<PIXELS_READING;n++){
        phases[n] = 0;
    }

}