#include "ofApp.h"

snow ml0,ml1,ml2,ml3,ml4,ml5,ml6,ml7,ml8,ml9; // when using the instructor methods, drawing a new one just add the code wherever ml0 is called.
ofTrueTypeFont amaticr;

snow::snow(){
    offsetX=ofRandom(-400, 500);
    offsetY=ofRandom(-500, 500);
}
int sec;
void snow::setup(){  // why can't we load the image in the constructor?
    snowflake.load("snow.png");
}

void snow::update(){
//    sec = (ofGetFrameNum()/60)%60;
//    rX+=0.05;
//    if (ofGetFrameNum() % 3 == 0)
//        rY+=0.03;
//    if (ofGetFrameNum() % 7 == 0)
//        rZ+=0.07;
    
    float time = ofGetElapsedTimef();
    rX = ofSignedNoise(time * 0.05, time * 0.05, time * 0.05) * 400.0;  // rotate +- 400deg
    // https://www.reddit.com/r/gamedev/comments/4y23pn/how_do_i_generate_deterministic_noise_that/
    rY = ofSignedNoise(time * 0.03) * 400.0;
    rZ = ofSignedNoise(time * 0.09) * 400.0;
    offsetY += 0.02;
    if (offsetY > ofGetHeight()){
        offsetY = ofRandom(-500, -100);
    }
}

void snow::draw(){

        ofPushMatrix();
        ofTranslate(ofGetWidth()/2 + offsetX, ofGetHeight()/2 + offsetY);
        ofScale(0.025, 0.025, 0.025);  // can be 3 dimensional
        ofRotateX(rX);
        ofRotateY(rY);
        ofRotateZ(rZ);
        snowflake.draw(0 - snowflake.getWidth()/2, 0 - snowflake.getHeight()/2);  // draw at new 0,0
        ofPopMatrix();
    
    
    
    
//    ofBackground(255);
    
//    ofPushMatrix();
    // seems like best practice to indent the code between ofPushMatrix and ofPopMatrix
    
    // Original rectangle in blue
//    ofSetColor(0, 0, 255);
//    ofDrawRectangle(500, 200, 200, 200);
    
    // Scaled down rectangle in red
//    ofTranslate(500, 200);
//    ofScale(0.5, 0.5);  // We are only working in x and y, so let's leave the z scale at its default (1.0)
//    ofSetColor(255, 0, 0);
//    ofDrawRectangle(0, 0, 200, 200);
//    ofPopMatrix();
}

//--------------------------------------------------------------
float midX, midY;


void ofApp::setup(){
    amaticr.load("amaticr.ttf", 15);
    ofSeedRandom();
    ml0.setup();
    ml1.setup();
    ml2.setup();
    ml3.setup();
    ml4.setup();
    ml5.setup();
    ml6.setup();
    ml7.setup();
    ml8.setup();
    ml9.setup();
    midX = ofGetWidth()/2;
    midY = ofGetHeight()/2;
}

//--------------------------------------------------------------
void ofApp::update(){
    
    ml0.update();
    ml1.update();
    ml2.update();
    ml3.update();
    ml4.update();
    ml5.update();
    ml6.update();
    ml7.update();
    ml8.update();
    ml9.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(179,196,193); //change a color as the building color
    ofSetColor (86,51,13);
    ofDrawRectangle(midX-220, midY - 250, 440, 286);
    // window
    ofSetColor(188,166,173);
    ofDrawRectangle(midX-200, midY - 240, 400, 266);
    
    // window frame
    ofSetColor (86,51,13);
    ofDrawRectangle(midX-200, midY -107, 400, 4); //horizontal
    ofDrawRectangle(midX -75, midY -240, 4, 266);
    ofDrawRectangle(midX +75, midY -240, 4, 266);
    ofSetColor(255, 255, 255);
    ml0.draw();
    ml1.draw();
    ml2.draw();
    ml3.draw();
    ml4.draw();
    ml5.draw();
    ml6.draw();
    ml7.draw();
    ml8.draw();
    ml9.draw();
    ofSetColor(0, 0, 0);
    amaticr.drawString("Some years later, in a gloomy afternoon", ofGetWidth()/2 - 350, ofGetHeight()/2+ 200);
    amaticr.drawString("I had a dream.", ofGetWidth()/2 - 200, ofGetHeight()/2+ 230);
    amaticr.drawString("I saw you there,", ofGetWidth()/2 - 200, ofGetHeight()/2+ 260);
    amaticr.drawString("waiting.", ofGetWidth()/2 - 200, ofGetHeight()/2+ 290);
    amaticr.drawString("Nothing changed.", ofGetWidth()/2 - 200, ofGetHeight()/2+ 320);
    amaticr.drawString("Home is always HOME.", ofGetWidth()/2 - 200, ofGetHeight()/2+ 350);
}

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
