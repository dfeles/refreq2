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
    //gui->drawMessage("Loading");
    ofFile fileToLoad(path);
    string extension = ofToLower(fileToLoad.getExtension());
    if (extension == "mp3" or extension == "wav" or extension == "m4a"){
        player->setStatus(PLAYER_PAUSED);
        loadMusic(path);
    }else if (extension == "png" or extension == "jpg" or extension == "jpeg"){
        player->setStatus(PLAYER_PAUSED);
        loadPicture(fileToLoad);
    }
}

void Loader::loadMusic(string path){
//    musicLoader->loadMusic(path);
    cout << path;
    
    
    
    audio.load(path);
    
    const vector<float>& rawSamples = audio.getRawSamples();
    int channels = audio.getChannels();
    int n = rawSamples.size();
    
    float seconds = (float) audio.getNumSamples() /  (float) audio.getSampleRate() / channels;
    int frames = seconds * FRAME_PER_SECOND;
    
    
    int samplesPerFrame = audio.getNumSamples() / frames;
    
    fft = ofxFft::create(2500, OF_FFT_WINDOW_SINE, OF_FFT_BASIC);
    
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
            float amplitude = fft->getAmplitudeAtFrequency(pixelPickup->getFreq(y)/2.0, (float) audio.getSampleRate());
            
            amplitude = log2(amplitude+1);
            int bright = MIN(amplitude * 255.0, 255);
            bright = MAX(bright, 0);
            
            actualColor.set(bright, bright, bright);
            
//            int i = y * frames * 3 + x * 3;
            int index = (x + y*frames)*3;
            
            createdSpectrum.getPixelsRef()[index]   = amplitude * 255.0;
            createdSpectrum.getPixelsRef()[index+1] = amplitude * 255.0;
            createdSpectrum.getPixelsRef()[index+2] = amplitude * 255.0;
            
        }
    }
    
    vinyl->setImageFromSpectrum(createdSpectrum);
    cout << "im done" << endl;
    
}

void Loader::loadPicture(ofFile file){
    
//    ofImage loadedImage;
//    loadedImage.loadImage(file.getAbsolutePath());
    vinyl->setImageFromPath(file.getAbsolutePath());
}