#include "ofApp.h"

ofImage moonlight;
float midX, midY;
float z,w;

//--------------------------------------------------------------
void ofApp::setup(){
    midX = ofGetWidth()/2;
    midY = ofGetHeight()/2;
    z = 255;
    w = z;
    
//    gui.setup();
//    gui.add(sky.setup("skyColor", ofColor(9, 15, 41), ofColor(0, 0), ofColor(255,255)));

//    gui.add(faceColor.setup("faceColor", ofColor(253, 234, 182), ofColor(0, 0), ofColor(255, 255)));
    moonlight.load("moon.png");
}


//--------------------------------------------------------------
void ofApp::update(){
    w -= 0.03;
    z -= 0.015;
 
   
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(194, 213, 234);
    ofSetColor(9,15,41,w);
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    ofSetColor(255,255,255,z);
    ofPushMatrix();
    ofScale(0.06, 0.06);
    moonlight.draw(1000, 700);
    ofPopMatrix();
    ofSetColor (86,51,13);
    ofDrawRectangle(midX-100, midY - 5, 200, 130);
    // window
    ofSetColor(188,166,173);
    ofDrawRectangle(midX-90, midY, 180, 120);
    // window frame
    ofSetColor (86,51,13);
    ofDrawRectangle(midX-90, midY +58, 180, 4); //horizontal
    ofDrawRectangle(midX -35, midY, 4, 120);
    ofDrawRectangle(midX +35, midY, 4, 120);
    
    
    
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
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
