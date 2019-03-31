#include "ofApp.h"
ofVec2f mid;
//--------------------------------------------------------------
ofImage photo;
ofTrueTypeFont amaticr;
void ofApp::setup(){
//    ofSetFrameRate(60);
    mid = ofVec2f (ofGetWidth()/2,ofGetHeight()/2);
    photo.load("faceUse.png");
    amaticr.load("amaticr.ttf", 15);

}
// setup only run once; it runs at the beginning.
//--------------------------------------------------------------
void ofApp::update(){
    int sec = (ofGetFrameNum() / 60) % 60;
//    if (sec > 4) {
        mid.x-=0.003;
//    }
    

}
// everytime update runs before the draw.
//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(251,233,238);
    ofSetColor(0, 0, 0);
    amaticr.drawString("My new home is an empty room,", ofGetWidth()/2-300, ofGetHeight()/2-270);
    amaticr.drawString("with walls in my favorite color,", ofGetWidth()/2-300, ofGetHeight()/2-240);
    amaticr.drawString("a suitcase I bring,", ofGetWidth()/2-300, ofGetHeight()/2-210);
    amaticr.drawString("and a photo of you.", ofGetWidth()/2-300, ofGetHeight()/2-180);
    ofSetColor (255, 255, 255);
    ofDrawRectangle(660,190,160,200); // Portrait Photo Frame
    ofSetColor(248, 252, 253);
    ofDrawRectangle(mid.x-280, mid.y+200, 10, 60);
    ofDrawRectangle(mid.x-230, mid.y+200, 10, 60);
    ofSetColor (13, 57, 73);//outside
    ofDrawRectRounded(mid.x-350, mid.y+260, 200, 150, 15);
    ofSetColor (34, 91, 111);
    ofDrawRectRounded(mid.x-330, mid.y+280, 160, 120, 10);
    ofDrawRectRounded(mid.x-285, mid.y+190, 70, 15, 5);
    ofSetColor (255,255,255);
    photo.draw(670,200);
    photo.resize(140,180); // Load and Resize the premade face with primitive shapes in Illustrator
    
    
    

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
