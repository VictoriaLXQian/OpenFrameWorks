#include "ofApp.h"


int midX, midY;
int a, b, x, y, z, w, u;
//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    image.load("faceUse.png"); //load a picture in the bin/data
    midX = ofGetWidth() / 2;
    midY = ofGetHeight() / 2;
    a = midX - 150;
    b = midX + 150;
    x = midX - 95;
    u = midX + 95;
    y = midX + 55;
    z = midX - 20;
    w = midX - 30;
    
    
    
}

bool drawFirst = true;
bool drawSecond = true&true;
//--------------------------------------------------------------
void ofApp::update(){
    int sec = (ofGetFrameNum() / 60) % 60;
    drawFirst = sec < 2;
    drawSecond = ( 2 <= sec && sec <= 4);

}


void ofApp::draw(){
    if (drawFirst) {
        ofBackground(255,255,255);
        ofSetColor(0,0,0);
        ofDrawRectangle(0, 0, 1100, 100);
        ofDrawRectangle(100, 100, 65, 800);
        ofDrawRectangle(1000, 100, 40, 800);
        ofDrawRectangle(0, 700, 1100, 100);
        ofDrawRectangle(150, 250, 1000, 15);
        ofDrawLine(0, 650, 1100, 410); // Drawing the frame of the window
        ofDrawCircle(650, 476, 4); // Figure Head
        ofDrawRectangle(648, 480, 4, 13);
        ofDrawLine(650, 493, 643, 508);
        ofDrawLine(650, 493, 653, 501);
        ofDrawLine(652, 501, 660, 498);
        ofDrawLine(648, 485, 643, 495);
        ofDrawLine(652, 485, 656, 482);
        ofDrawLine(656, 482, 657, 473); //the Running Figure
    
    } else if (drawSecond) {
        ofBackground(219,225,236);
        ofSetColor(246,237,242);
        ofDrawTriangle(midX, 220, a, 290, b, 290);
        ofSetColor(244, 192, 210);
        ofDrawTriangle(midX, 220, x, 286, u, 286); //   ROOF
        ofSetColor(244, 192, 210);
        ofDrawRectangle(a, 290, 300, 300); // HOUSE
        ofSetColor(246,237,242);
        ofDrawRectangle(x, 325, 40, 70);
        ofDrawRectangle(z, 325, 40, 70);
        ofDrawRectangle(y, 325, 40,70);
        ofSetColor(210,124,140);
        ofDrawRectangle(x, 430, 40, 70);
        ofDrawRectangle(z, 440, 40, 20);
        ofDrawRectangle(y, 430, 40, 70); // WINDOWS
        ofSetColor(193,46,98);
        ofDrawRectangle(w, 480, 60, 110); // DOOR
        ofSetColor(0, 100, 100); // Color: Green
        ofDrawTriangle(150, 500, 125, 580, 175, 580);
        ofDrawTriangle(300, 400, 275, 480, 325, 480);
        ofDrawTriangle(950, 500, 925, 580, 975, 580);
        ofDrawTriangle(750, 400, 725, 480, 775, 480);
        ofSetColor(129,60,60); // Tree
        ofDrawRectangle(140, 580, 20, 50);
        ofDrawRectangle(290, 480, 20, 50);
        ofDrawRectangle(940, 580, 20, 50);
        ofDrawRectangle(740, 480, 20, 50);
    } else {
        ofBackground(251,233,238);
        ofSetColor (255, 255, 255);
        ofDrawRectangle(660,190,160,200); // Portrait Photo Frame
        ofDrawRectangle(200,230,120,90); // Frame 1
        ofDrawRectangle (400,350,120,120); // Frame 3
        image.draw(670,200);
        image.resize(140,180); // Load and Resize the premade face with primitive shapes in Illustrator
        ofSetColor (246,232,146); // Golden/Yellow
        ofDrawRectangle(545,285,90,140); //Frame 2
        ofDrawRectangle(205,235,110,80); //Photo 1
        ofSetColor(255,247,249); // Light Pink
        ofDrawRectangle(555,295,70,120); //Photo 2
        ofDrawRectangle(410, 360, 100, 100); //Photo 3
        
        
        
    }
    
    
    // cout << t.getAsMilliseconds() << endl;
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
