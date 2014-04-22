//
//  Loader.cpp
//  refreq2
//
//  Created by Daniel Feles on 2/5/14.
//
//  This is responsible for loading images or music into refreq
//

#include "Loader.h"

void Loader( ){
    
}

void Loader::loadFile(string path){
    ofFile fileToLoad(path);
    cout << fileToLoad.getFileName() << endl;
    string extension = ofToLower(fileToLoad.getExtension());
    if (extension == "mp3" or extension == "wav" or extension == "m4a"){
        player->setStatus(PLAYER_PAUSED);
        loadMusic(path);
    }else if (extension == "png" or extension == "jpg" or extension == "jpeg"){
        player->setStatus(PLAYER_PAUSED);
        loadPicture(fileToLoad);
    }
    gui->drawMessage("Loading");
}

void Loader::loadMusic(string path){
    audio.load(path);
    
    const vector<float>& rawSamples = audio.getRawSamples();
    int channels = audio.getChannels();
    int n = rawSamples.size();
    
    float seconds = (float) audio.getNumSamples() /  (float) audio.getSampleRate() / channels;
    int frames = seconds * FRAME_PER_SECOND;
    
    
    int samplesPerFrame = audio.getNumSamples() / frames;
    
    fft = ofxFft::create(2500, OF_FFT_WINDOW_SINE, OF_FFT_FFTW);
    
    createdSpectrum.clear();
    createdSpectrum.allocate(frames, PIXELS_READING, OF_IMAGE_COLOR);
    
    for(int x = 0; x < frames; x++) {
        float frameSamples[samplesPerFrame];
        for(int n = 0; n < samplesPerFrame; n++){
            frameSamples[n] = rawSamples[(x*samplesPerFrame+n)];
        }
        fft->setSignal(frameSamples);
        
        ofColor actualColor;
        for(int y=0; y<PIXELS_READING; y++){
            float amplitude = fft->getAmplitudeAtFrequency(pixelPickup->getFreq(y), (float) audio.getSampleRate());
            
            amplitude = log2(amplitude+1);
            amplitude *= 5;
            int bright = MAX(MIN(amplitude * 254.0, 254), 0);
            
         //   bright = 254;
            
            //actualColor.set(bright, bright, bright);
            
//            int i = y * frames * 3 + x * 3;
            int index = (x + y*frames)*3;
            
            createdSpectrum.getPixelsRef()[index]   = 255-bright;
            createdSpectrum.getPixelsRef()[index+1] = 255-bright;
            createdSpectrum.getPixelsRef()[index+2] = 255-bright;
            
        }
    }
    
    vinyl->setImageFromSpectrum(createdSpectrum);
    cout << "im done" << endl;
    
}

void Loader::loadPicture(ofFile file){
    
    vinyl->setImageFromPath(file.getAbsolutePath());
}