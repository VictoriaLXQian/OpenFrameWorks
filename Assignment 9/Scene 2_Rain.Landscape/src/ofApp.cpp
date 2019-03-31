#include "ofApp.h"

//--------------------------------------------------------------
float midX, midY;
float startX, startY;
float endX;
float sec;
float x,y;
ofTrueTypeFont amaticr;


void ofApp::setup(){
    ofSetFrameRate(60);
    image.load("leavingNight.jpg");
    midX = ofGetWidth()/2;
    midY = ofGetHeight()/2;
    startX = 0;
    startY = 0;
    endX = ofGetWidth();
    x = ofGetWidth();
    y = ofGetHeight();
    amaticr.load("amaticr.ttf", 15);

    

}
// setup only run once; it runs at the beginning.
//--------------------------------------------------------------
void ofApp::update(){
    sec = (ofGetFrameNum() / 60) % 60;
    startY += 0.5;
    midY += 0.3;
    x *= 0.9999;
    y *= 0.9999;
//    if (startY > ofGetHeight()){
//        startY = 0;
//    }
//    if (midY > ofGetHeight()){
//        midY - ofGetHeight()/2;
//    }
    

}
// everytime update runs before the draw.
//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0,0,0);
    image.draw(0,0);
    image.resize(x, y);
    ofSetColor (255,255,255);
    amaticr.drawString("and you,", midX-20, midY+170);
    if (sec > 0 ) {
        amaticr.drawString("just like this familiar city, disappeared, in a rainy night.", midX-150, midY+200);
        ofSetColor (255,255,255,100); // Change color
        ofDrawEllipse(midX, startY + 10, 5, 8);
        ofDrawEllipse(midX-120, startY + 100, 10, 15);
        ofDrawEllipse(startX + 80, midY - 200, 15, 18);
        ofDrawEllipse(midX + 400, midY, 8, 12);
    }
    if (4 < sec){
        ofDrawEllipse(startX + 20, startY, 5, 9);
        ofDrawEllipse(endX - 70, startY + 60, 8, 14);
        ofDrawEllipse(midX + 400, midY, 7, 14);
    }
    if (7 < sec){
        ofDrawEllipse(startX + 100, midY + 100, 20, 25);
        ofDrawEllipse(midX - 250, startY + 20, 10, 15);
        ofDrawEllipse(midX + 300, startY + 10, 5, 8);
       
    }
    if (10 < sec){
        ofDrawEllipse(midX - 350, midY - 200, 8, 16);
        ofDrawEllipse(midX + 300, startY + 160, 10, 17);
        ofDrawEllipse(startX + 20, startY, 5, 9);
        ofDrawEllipse(endX - 70, startY + 60, 8, 14);
        ofDrawEllipse(midX + 400, midY, 7, 14);
    }
    
    
//    STILL RAINDROPS
    

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
