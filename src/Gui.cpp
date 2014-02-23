//
//  Gui.cpp
//  refreq2
//
//  Created by Daniel Feles on 2/5/14.
//
//

#include "Gui.h"
#include "refreqConstans.h"

void Gui(){
}

void Gui::drawGui( ){
    
    ofSetColor(255,255,255);
    //ofRect(0, 0, ofGetWindowWidth(), ofGetWindowHeight());
    ofSetColor(233,233,233);
    
    ofRect(0, 0, ofGetScreenWidth(), HEADER_HEIGHT);
    ofRect(0, ofGetWindowHeight()-FOOTER_HEIGHT, ofGetWindowWidth(), FOOTER_HEIGHT);
    
   // ofSetColor(0,233,233);
    
    for(int i=0; i<INITIAL_BUFFER_SIZE; i++){
        ofCircle(i, synthetizer->soundWave[i]*100+150, 1);
    }

}

void Gui::handleKeyPressed(int key){
    if(key == 111){
        string path = getFilePath();
        loader->loadFile(path);
    } else if (key == SPACE_KEY){
        if(player->getStatus() == PLAYER_PAUSED){
            player->setStatus(PLAYER_PLAYING);
        } else {
            player->setStatus(PLAYER_PAUSED);
        }
    };
}

void Gui::handleDraggedFile(ofDragInfo info){
    if( info.files.size() > 0 ){
        loader->loadFile(info.files[0]);
    }
}

string Gui::getFilePath(){
    string URL;
	
    ofFileDialogResult result = ofSystemLoadDialog("Import File", true, "");
    if(result.bSuccess){
        URL = result.filePath;
		return URL;
	}
}