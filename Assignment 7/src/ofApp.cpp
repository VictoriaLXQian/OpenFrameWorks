#include "ofApp.h"

int midX, midY;
float rX, rY;
ofTrueTypeFont amaticBold;

//--------------------------------------------------------------
void ofApp::setup(){
    midX = ofGetWidth()/2;
    midY = ofGetHeight()/2;
    rX = 0;
    rY = 0;
    amaticBold.load("amaticBold.ttf", 32);
    ofSetVerticalSync(true);
    play.addListener(this,&ofApp::playPressed);
    stop.addListener(this,&ofApp::stopPressed);
    
    gui.setup();
    gui.add(eyeballX.setup("eyeballX",20,20,100));
    gui.add(eyeballY.setup("eyeballY",30,20,110));
    gui.add(eyeSizeX.setup("eyeSizeX",45,20,90));
    gui.add(eyeSizeY.setup("eyeSizeY",70,20,100));
    gui.add(faceColor.setup("faceColor", ofColor(253, 234, 182), ofColor(0, 0), ofColor(255, 255)));
    gui.add(center.setup("center", ofVec2f(ofGetWidth()/2, ofGetHeight()/2), ofVec2f(0, 0), ofVec2f(ofGetWidth(), ofGetHeight())));
    gui.add(rotateFace.setup("rotateFaceOne"));
    gui.add(scaleFace.setup("scaleFace"));
    gui.add(play.setup("soundPlay"));
    gui.add(stop.setup("soundStop"));
    gui.add(volume.setup("volume", 0.5, 0.0, 1.0));
    sound.load("music.wav");
    
    
}

void ofApp::playPressed(){
    sound.play();
}

//--------------------------------------------------------------
void ofApp::update(){
    rY += 0.05;
    if (ofGetFrameNum() % 3 == 0)
        rX+=0.1;
}

void ofApp::stopPressed(){
    sound.stop();
}

//--------------------------------------------------------------
void ofApp::draw(){
    //    ofDrawCircle(ofGetWidth()/2, ofGetHeight()/2, radius);
    ofSetCircleResolution(45);
//    ofSetLineWidth(4);
    ofSetColor(240, 226, 226);
    amaticBold.drawString ("A NOT-SO-HAPPY FACE", 100, 150);
//    gillsans.drawString ("", 650, 530);
    
    if (scaleFace){
        ofPushMatrix();
        ofSetColor(faceColor);
        ofDrawCircle(center->x,center->y, 150);
        ofTranslate(center->x, center->y);
        ofScale(1.5, 1.5);
        ofDrawCircle(0, 0, 150);
        ofPopMatrix();
    } else if (rotateFace){
        ofPushMatrix();
        ofTranslate(center->x,center->y);
        ofRotateX(rX);
        ofRotateY(rY);
        ofSetColor(faceColor);
        ofDrawCircle(center->x,center->y, 150); //the face; remain still
        ofSetColor(255,255,255);
        ofDrawEllipse(center->x-45,center->y-25, eyeSizeX, eyeSizeY); // left eye, Outside
        ofDrawEllipse(center->x+40,center->y-25,eyeSizeX, eyeSizeY); // right eye, Outside
        ofSetColor(0,0,0);
        ofDrawEllipse(center->x-45,center->y-25, eyeballX, eyeballY); // left eye, eyeball, moving with slider
        ofDrawEllipse(center->x+45,center->y-25, eyeballX, eyeballY); // right eye, eyeball, moving with slider
        ofDrawLine(center->x, center->y, center->x, center->y +45);
        ofDrawLine(center->x, center->y+70,center->x-50, center->y+77);
        ofDrawLine(center->x,center->y+70,center->x+50, center->y+77); // Nose and mouth stay STILL.
        ofPopMatrix();
    } else
        ofSetColor(faceColor);
    ofDrawCircle(center->x,center->y, 150); //the face; remain still
    ofSetColor(255,255,255);
    ofDrawEllipse(center->x-45,center->y-25, eyeSizeX, eyeSizeY); // left eye, Outside
    ofDrawEllipse(center->x+45,center->y-25, eyeSizeX, eyeSizeY); // right eye, Outside
    ofSetColor(0,0,0);
    ofDrawEllipse(center->x-45,center->y-25, eyeballX, eyeballY); // left eye, eyeball, moving with slider
    ofDrawEllipse(center->x+45,center->y-25, eyeballX, eyeballY); // right eye, eyeball, moving with slider
    ofDrawLine(center->x, center->y, center->x, center->y +45);
    ofDrawLine(center->x, center->y+70,center->x-50, center->y+77);
    ofDrawLine(center->x,center->y+70,center->x+50, center->y+77); // Nose and mouth stay STILL.
    gui.draw();
    sound.setVolume(volume);
    
    
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
