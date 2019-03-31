#include "ofApp.h"


int midX, midY;
float barOne, barTwo;
float counter;
ofVec2f rP,posFm; //running person
ofTrueTypeFont gillsans,amaticr;

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    midX = ofGetWidth() / 2;
    midY = ofGetHeight() / 2;
    barOne = midX - 300;
    barTwo = midX + 500;
    rP = ofVec2f(650, 450);
    posFm = ofVec2f(200,350);
    gillsans.load("gillsans.ttf", 20);
    amaticr.load("amaticr.ttf", 15);
    
    
    
}


//--------------------------------------------------------------

float inc = 0.5;
ofVec2f rpFinal;
float dirt;
float sec;

void ofApp::update(){
    sec = (ofGetFrameNum() / 60) % 60;
    inc += 0.007;
    barOne -= inc;
    barTwo -= inc;
   if (barOne+50 < 0){
       barOne = midX + 1000;
   }
    if (barTwo+50 < 0){
        barTwo =midX+1000;
    }

    
    dirt = 0.15;
    rP.x = ofMap(dirt, 0, 320, rP.x, 1700);
    posFm.x = ofMap(dirt, 0, 500, posFm.x, 1700);
   

}


void ofApp::draw(){
    ofBackground(0, 0, 0);
    ofSetColor(255, 255, 255);
    if (sec > 0.5) {
        amaticr.drawString("I always remember that day,", midX, midY);
    }
    if (sec > 1.5){
        amaticr.drawString("the day you were waving goodbye.", midX, midY+30);
    }
    if (sec > 2.5){
        amaticr.drawString("And I always remember you said", midX, midY+60);
    }
    if (sec > 3.5) {
        amaticr.drawString("'You always have a home here. We are all waiting for you'.", midX, midY+90);
    }
    if (sec > 6){
        ofBackground(255,255,255);
        ofSetColor(0,0,0);
        ofDrawRectangle(0, 0, 1100, 100);
        ofDrawRectangle(barOne, 100, 50, 800); // bar one
        ofDrawRectangle(barTwo, 100, 50, 800); // bar two
        ofDrawRectangle(0, 700, 1100, 100);
        ofDrawRectangle(0, 250, 1800, 20);
        ofSetLineWidth(4);
        ofDrawLine(0, 550, 1700, 550); // Drawing the frame of the window
        ofSetColor(0, 0, 0);
        ofDrawRectangle(posFm, 230, 60);//Station Name
        ofDrawEllipse(rP, 30, 36);
        ofDrawRectangle(rP.x-10, rP.y+18, 20, 40);
        ofSetLineWidth(7);
        ofDrawLine(posFm.x+60, posFm.y+60, posFm.x+60, 535);
        ofDrawLine(posFm.x+170, posFm.y+60, posFm.x+170, 535);
        ofDrawLine(rP.x-5, rP.y+58, rP.x-12, rP.y+100);
        ofDrawLine(rP.x+4, rP.y+58, rP.x+4, rP.y+98);
        ofSetLineWidth(5);
        ofDrawLine(rP.x-10, rP.y+25, rP.x-16, rP.y+68);
        ofDrawLine(rP.x+10, rP.y+22, rP.x+18, rP.y+45);
        ofDrawLine(rP.x+18, rP.y+45, rP.x+22, rP.y+15);
        ofSetColor(255, 255, 255);
        gillsans.drawString("M. P.ta GARIBALDI", posFm.x+8, posFm.y+40);
    }
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
