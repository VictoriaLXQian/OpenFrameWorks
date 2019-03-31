#include "ofApp.h"



int midX, midY;
int x, y, xPos, xPosone, yPos;


//--------------------------------------------------------------

void ofApp::setup(){
    ofSetFrameRate(60);
    midX = ofGetWidth()/2;
    midY = ofGetHeight()/2;
    x = midX;
    y = midY;
    xPos = ofGetWidth()/2;
    xPosone = xPos;
    yPos = ofGetHeight()/2;
}



//--------------------------------------------------------------


void ofApp::update(){
    
    
    bool tear= false;
    
    xPos--;
    if (xPos < 0){
        xPos = midX;
    }
    xPosone++;
    if (xPosone > ofGetWidth()){
        xPosone = midX;
    }
    yPos++;
    if (yPos > ofGetHeight()){
        yPos = midY;
    }
    
    
 

    
}



//--------------------------------------------------------------

void ofApp::draw(){
    ofSetCircleResolution(40);
    ofBackground(214, 225, 240);
    ofSetColor(253,234,182);
    ofDrawCircle(midX, midY, 150);// Round Face + COLOR
    ofSetColor(255, 255, 255);
    ofDrawCircle(midX-45, midY-25, 40); //Left Eye Ball
    ofDrawCircle(midX+45, midY-25, 40); //Right Eye Ball
    ofSetColor(0, 0, 0);
    ofDrawCircle(midX-45, midY-25, 20); //Left Eye
    ofDrawCircle(midX+45, midY-25, 20); //Right Eye
    ofDrawLine(midX, midY, midX, midY+45); //Nose
    ofDrawLine(midX-25, midY+70, midX+25, midY+70); // Mouth (The Neutral Face)
    ofSetColor(68, 178, 201);
    ofDrawEllipse(x-40, yPos-20, 7, 10);
    ofDrawEllipse(x-65, yPos-20, 7, 10);
    ofDrawEllipse(x+40, yPos-20, 7, 12);
    ofDrawEllipse(x+65, yPos-20, 7, 12);
    ofDrawCircle(xPos-40, midY-20, 7);
    ofDrawCircle(xPosone+40, midY-20, 7);
    
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
