#include "ofApp.h"

//--------------------------------------------------------------
float midX, midY;
int x, y;
float girlX, girlY;
ofVec2f girl;
void ofApp::setup(){
    ofSetFrameRate(60);
    midX = ofGetWidth()/2;
    midY = ofGetHeight()/2;
    girl = ofVec2f(midX, midY);
    x = ofGetWidth();
    y = ofGetHeight();
//    girlX = midX;
//    girlY = midY;

}
// setup only run once; it runs at the beginning.
int direction = -1;
float distance;
float step;
int sec;
//--------------------------------------------------------------
void ofApp::update(){
    sec = (ofGetFrameNum()/60)%60;
//    float distance = abs(mid.x - midX);
    if (sec == 3){
    girl.x = ofMap(midX, 0, 60, midX, midX-2.75);
    }
 
    
   
    
//    mid.y = ofMap(1, 1, 20, midY, midY-20);
//    mid.x -= 0.03;
//
//    if (abs(mid.x - midX) > 1.75) {
//        mid.x -= 0.03 * direction;
//    }
    

}
// everytime update runs before the draw.
//--------------------------------------------------------------
void ofApp::draw(){
    // background pink as the photo wall scene
    ofBackground(251,233,238);
    // window
    ofSetColor(31,50,137);
    ofDrawRectangle(midX-300, midY - 240, 600, 400);
    // window frame
    ofSetColor (197,150,97);
    ofDrawRectangle(midX-300, midY -40, 600, 4); //horizontal
    ofDrawRectangle(midX -100, midY -240, 4, 400);
    ofDrawRectangle(midX +100, midY -240, 4, 400);
    ofDrawRectangle(midX-320, midY+160, 640, 15);
    // moon
    ofSetColor(236,234,190);
    ofSetCircleResolution(60);
    ofDrawCircle(midX + 200, midY-150, 35);
    // girl shadow
    ofSetColor(231, 214, 188);
    ofDrawRectRounded(midX- 195, midY + 100, 10, 120, 70, 20, 20, 10, 10);
    ofSetColor(242, 249, 255); // dress
    ofDrawTriangle(midX-185, midY + 155, midX-90, midY + 155, girl.x -140, midY +340);
    ofDrawTriangle(midX -140, midY + 105, girl.x-220, midY + 390, girl.x - 60, midY + 390); // MOVEMENT
    ofSetColor(69, 43, 3); //hair_MOVEMENT
    ofDrawRectRounded(midX- 180, midY + 20, 10, 90, 170, 40, 40, 25, 25);
    
 
    
    
    
    

}
// draw is pure graphic, no heavy math, etc.
//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
