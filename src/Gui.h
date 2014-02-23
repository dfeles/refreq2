//
//  Gui.h
//  refreq2
//
//  Created by Daniel Feles on 2/5/14.
//
//

#ifndef __refreq2__Gui__
#define __refreq2__Gui__

#include <iostream>
#include "ofMain.h"
#include "ofGraphics.h"
#include "Loader.h"
#include "Player.h"
#include "Synthetizer.h"

extern Loader* loader;
extern Player* player;
extern Synthetizer* synthetizer;

class Gui {
    public:
        void drawGui();
        void handleKeyPressed(int key);
        void handleDraggedFile(ofDragInfo info);
    
    private:
        string getFilePath();
    
};

#endif /* defined(__refreq2__Gui__) */
