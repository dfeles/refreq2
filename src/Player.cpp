//
//  Player.cpp
//  refreq2
//
//  Created by Daniel Feles on 2/5/14.
//
//  This is responsible for managing everything related to the player
//

#include "Player.h"

void Player( ){
}

void Player::update (){
    setLength(vinyl->w);
    if (status == PLAYER_PLAYING) {
        
        setCurrentTime (currentTime + speed * stepLength());
        vinyl->setOffsetX(currentTime);
        vinyl->drawVinyl();
        pixelPickup->getPixels();
    } else if (status == PLAYER_PAUSED) {
        vinyl->drawVinyl();
    }
}

int Player::getStatus () {
    return status;
}

int Player::getSpeed () {
    return speed;
}

void Player::setStatus (int _status) {
    status = _status;
    
    if(status == PLAYER_PAUSED){
        ofSoundStreamStop();
    } else {
        ofSoundStreamStart();
    }
}

void Player::setSpeed (float _speed) {
    speed = _speed;
}

void Player::setCurrentTime (float _time) {
    if(_time > 1){
        _time = 0;
    }
    currentTime = _time;
}

float Player::stepLength (){
    return PIXELS_PER_FRAME / length;
}

void Player::setLength (float _width){
    length = _width / PIXELS_PER_FRAME;
}
