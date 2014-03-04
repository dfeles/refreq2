//
//  refreqSynth.cpp
//  refreq2
//
//  Created by Daniel Feles on 04/03/14.
//
//

#include "refreqSynth.h"

void RefreqSynth::setup() {
    cout << "helo";
    ofSoundStreamSetup(2, 2, SAMPLE_RATE, INITIAL_BUFFER_SIZE, 4);
    ofSoundStreamStop();
}

void RefreqSynth::audioRequested 	(float * output, int bufferSize, int nChannels){
    synthetizer -> calculateWave(output);
}

void RefreqSynth::audioReceived 	(float * output, int bufferSize, int nChannels){
}
void RefreqSynth::exit()    {
    ofSoundStreamStop();
}