#include "Refreq2.h"

Gui* gui = new Gui;
Vinyl* vinyl = new Vinyl;
Loader* loader = new Loader;
Player* player = new Player;
PixelPickup* pixelPickup = new PixelPickup;
Synthetizer* synthetizer = new Synthetizer;
ofxFft* fft;



//--------------------------------------------------------------
void Refreq2::setup(){
	ofSetVerticalSync(true);
	ofDisableDataPath();
    loader->loadFile(MAIN_IMAGE);
    ofSoundStreamSetup(2, 2, SAMPLE_RATE, INITIAL_BUFFER_SIZE, 4);
    ofSoundStreamStop();
}

//--------------------------------------------------------------
void Refreq2::update(){

}

//--------------------------------------------------------------
void Refreq2::draw(){
    player->update();
    gui->drawGui();
//    musicLoader.createdSpectrum.draw(0,0);
}


void Refreq2::audioRequested 	(float * output, int bufferSize, int nChannels){
    synthetizer -> calculateWave(output);
}

void Refreq2::audioReceived 	(float * output, int bufferSize, int nChannels){
}


//--------------------------------------------------------------
void Refreq2::keyPressed(int key){
    if(key == 111){
        string path = gui->getFilePath();
        loader->loadFile(path);
    } else if (key == SPACE_KEY){
        if(player->getStatus() == PLAYER_PAUSED){
            player->setStatus(PLAYER_PLAYING);
        } else {
            player->setStatus(PLAYER_PAUSED);
        }
    }
}

//--------------------------------------------------------------
void Refreq2::keyReleased(int key){

}

//--------------------------------------------------------------
void Refreq2::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void Refreq2::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void Refreq2::mousePressed(int x, int y, int button){
    
    //musicLoader.start();
}

//--------------------------------------------------------------
void Refreq2::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void Refreq2::windowResized(int w, int h){
    vinyl->resizeWindow();
}

//--------------------------------------------------------------
void Refreq2::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void Refreq2::dragEvent(ofDragInfo dragInfo){
    if( dragInfo.files.size() > 0 ){
        loader->loadFile(dragInfo.files[0]);
    }
}

//--------------------------------------------------------------
void Refreq2::exit() {
    ofSoundStreamStop();
    cout << "Iexit";
    // stop the thread
}
