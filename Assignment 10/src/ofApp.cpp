#include "ofApp.h"
ofPoint orgin;
//--------------------------------------------------------------
void drawTriangle(int numTriangles){
    
    ofPushMatrix();
    ofPushStyle();
//    orgin = ofPoint (10,10);
    ofSetColor(102, 30+(25*numTriangles), 144);
    ofDrawTriangle(0-5*numTriangles, 0+8*numTriangles,0,0, 0+5*numTriangles, 0+8*numTriangles);
    ofTranslate(0+5*numTriangles, 0+8*numTriangles);
    ofRotateZDeg(4);
    if (--numTriangles>1)
        drawTriangle(numTriangles);
    ofPopStyle();
    ofPopMatrix();
}
void ofApp::setup(){

    ofBackground(190,210,204);
    gui.setup();
    gui.add(numberChange.setup("numTriangles", 5, 1, 20));
//    orgin = ofPoint (ofGetScreenWidth()/2,ofGetScreenHeight()/2);

    
}
// setup only run once; it runs at the beginning.
//--------------------------------------------------------------


void ofApp::update(){

    
}
// everytime update runs before the draw.


//--------------------------------------------------------------

void ofApp::draw(){
    ofPushMatrix();
    orgin = ofPoint (ofGetScreenWidth()/2,ofGetScreenHeight()/2);
    ofTranslate(orgin);
    for (int numTriangles=0; numTriangles <=360; numTriangles+=numberChange){
        ofPushMatrix();
        ofPushStyle();
        ofRotateZDeg(numTriangles);
        drawTriangle(4);
        ofPopStyle();
        ofPopMatrix();
    }
    
    ofPopMatrix();
    gui.draw();
    
    
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
