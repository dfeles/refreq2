//
//  Vinyl.cpp
//  refreq2
//
//  Created by Daniel Feles on 2/5/14.
//
//  This is responsible for storing, displaying, modifying the loaded Image (Vinyl)
//

#include "Vinyl.h"
#include "refreqConstans.h"

Vinyl::Vinyl () {
    vinylHeight = 660;
}
void Vinyl::setImageFromPath(string path) {
    vinylImage.clear();
    vinylImage.loadImage(path);
    if(vinylImage.bAllocated()){
        setImage();
    }
}
void Vinyl::setImageFromSpectrum(ofImage image) {
    vinylImage.clear();
    vinylImage = image;
    setImage();
}


void Vinyl::setImage () {
    quad.clear();

    ofDisableArbTex();
	quad.getVertices().resize(4);
	quad.getTexCoords().resize(4);
	quad.setMode(OF_PRIMITIVE_TRIANGLE_FAN);
    
    
    vinylHeight = (ofGetHeight()-HEADER_HEIGHT-FOOTER_HEIGHT);
    s = PIXELS_READING/vinylImage.getHeight();
    w = vinylImage.getWidth()*s;
    h = vinylImage.getHeight()*s;
    
    vinylImage.resize(w, h);
    
    if(vinylImage.bAllocated()){
        updateTexture();
    }
}

void Vinyl::exportVinyl(string currentLoadedFileName) {
    
    ofFileDialogResult result = ofSystemSaveDialog(currentLoadedFileName, "Export image");
    ofFile exportingFile(result.filePath);
    string path = result.filePath;
    if (exportingFile.getExtension()!=".png"){
        path += ".png";
    }
    saveVinylImage(path);
}

void Vinyl::saveVinylImage(string path) {
    vinylImage.saveImage(path);
}

ofColor Vinyl::getPixel(ofPoint point) {
    return vinylImage.getColor((int)(point.x + (int)(offsetX*vinylImage.getWidth())) % (int)vinylImage.getWidth(), point.y);
    
}

void Vinyl::setOffsetX(float _offsetX) {
    offsetX = _offsetX;
}

void Vinyl::drawVinyl() {
    
    if(vinylImage.getHeight()>0){
        offXRatio = 0 + offsetX;
		offYRatio = 0;
        updateTexture();
        
        //glActiveTexture(GL_TEXTURE0); donno if its needed
        
        vinylImage.bind();
        quad.draw();
        vinylImage.unbind();
    }
    
}

void Vinyl::resizeWindow() {
    vinylHeight = (ofGetHeight()-HEADER_HEIGHT-FOOTER_HEIGHT);
    s = PIXELS_READING/vinylImage.getHeight();
    w = vinylImage.getWidth()*s;
    h = vinylImage.getHeight()*s;
    
    if(vinylImage.bAllocated()){
        updateTexture();
    }
    
}


void Vinyl::updateTexture() {
    
    float scale = vinylHeight / h;
    float ratio = ofGetWidth()/(w*scale);
    
    vinylImage.getTextureReference().setTextureWrap(GL_REPEAT, GL_REPEAT);
    vinylImage.getTextureReference().setTextureMinMagFilter(GL_LINEAR,GL_LINEAR);
    
    px0 = 0;
    py0 = HEADER_HEIGHT;
    px1 = ofGetWidth();
    py1 = HEADER_HEIGHT+vinylHeight;
    tx0 = 0 + offXRatio;
    ty0 = 0 + offYRatio;
    tx1 = ratio + offXRatio;
    ty1 = 1.0 + offYRatio;
    
    quad.getVertices()[0].set(px0,py0,0);
    quad.getVertices()[1].set(px1,py0,0);
    quad.getVertices()[2].set(px1,py1,0);
    quad.getVertices()[3].set(px0,py1,0);
    
    quad.getTexCoords()[0].set(tx0,ty0);
    quad.getTexCoords()[1].set(tx1,ty0);
    quad.getTexCoords()[2].set(tx1,ty1);
    quad.getTexCoords()[3].set(tx0,ty1);
}



float Vinyl::getVinylHeight(){
    return vinylHeight;
}