#include "Refreq2.h"

Vinyl* vinyl = new Vinyl;
Loader* loader = new Loader;
Player* player = new Player;
PixelPickup* pixelPickup = new PixelPickup;
Synthetizer* synthetizer = new Synthetizer;

//--------------------------------------------------------------
void Refreq2::setup(){
    
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
    drawGui();
}


void Refreq2::audioRequested 	(float * output, int bufferSize, int nChannels){
    synthetizer -> calculateWave(output);
}

void Refreq2::audioReceived 	(float * output, int bufferSize, int nChannels){
}


//--------------------------------------------------------------
void Refreq2::keyPressed(int key){
    handleKeyPressed(key);
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
    handleDraggedFile(dragInfo);
}
