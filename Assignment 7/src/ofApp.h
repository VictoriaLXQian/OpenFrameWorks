#pragma once

#include "ofMain.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    void playPressed();
    void stopPressed();
    
    ofxPanel gui;
    ofxIntSlider eyeballX;
    ofxIntSlider eyeballY;
    ofxIntSlider eyeSizeX;
    ofxIntSlider eyeSizeY;
    ofxVec2Slider center;
    ofxColorSlider faceColor;
    ofxButton rotateFace;
    ofxButton scaleFace;
    ofxButton play;
    ofxButton stop;
    ofxFloatSlider volume;
    ofSoundPlayer sound;
    
    
};




