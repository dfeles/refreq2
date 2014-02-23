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
    string extension = ofToLower(fileToLoad.getExtension());
    if (extension == "mp3" or extension == "wav"){
        loadMusic(path);
    }else if (extension == "png" or extension == "jpg" or extension == "jpeg"){
        loadPicture(fileToLoad);
    }
}

void Loader::loadMusic(string path){
    
}

void Loader::loadPicture(ofFile file){
    
    ofImage loadedImage;
    loadedImage.loadImage(file.getAbsolutePath());
    vinyl->setImage(loadedImage);
}