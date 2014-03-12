//
//  refreqSynth.cpp
//  refreq2
//
//  Created by Daniel Feles on 04/03/14.
//
//

#include "refreqSynth.h"

void RefreqSynth::setup() {
    ofSoundStreamSetup(2, 2, SAMPLE_RATE, INITIAL_BUFFER_SIZE, 4);
    ofSoundStreamStop();
}

void RefreqSynth::audioRequested 	(float * output, int bufferSize, int nChannels){
    synthetizer -> calculateWave(output);
}

void RefreqSynth::audioReceived 	(float * output, int bufferSize, int nChannels){
}
void RefreqSynth::dragEvent(ofDragInfo info) {
    cout << info.files[0];
}
void RefreqSynth::exit()    {
    ofSoundStreamStop();
}