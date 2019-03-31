#include "ofApp.h"

ofSoundPlayer boop;
float midX, midY;
float a, b, c, d;
float l1;
float dist,distant;
int dir;
float counter;
float x, y, yTwo;
float xOne, yOne;
ofTrueTypeFont amaticr;

//ofPolyline straightSegmentPolyline;
//ofPolyline curvedSegmentPolyline;


//--------------------------------------------------------------
void ofApp::setup(){
    // load every sound you will need here
    ofSetFrameRate(60);
    midX = ofGetWidth()/2;
    midY = ofGetHeight()/2;
    a = 50;
    b = 25;
    c = 100;
    d = 125;
    dir = 1;
    dist = 0;
    l1 = 50;
    x = midX;
    y = midY;
    yTwo = y-a;
    xOne = midX;
    amaticr.load("amaticr.ttf", 15);
   
}



//--------------------------------------------------------------
float sec;
void ofApp::update(){
    sec = (ofGetFrameNum()/60)%60;
    yTwo += 0.3;
    distant = yTwo - y;
    if (distant >= c) {
        yTwo = y+c;
        x += 0.2;
        xOne -= 0.2;
    }
//    x ++;
//    x = x*counter;
//    xOne --;
//    xOne = xOne*counter;
    
    
}


//ofPolyline line;
//--------------------------------------------------------------

void ofApp::draw(){
    ofBackground(214,117,117);
    ofSetLineWidth(3.0);  // Line widths apply to polylines
    ofSetColor(255,230,230);
    ofPolyline closedHeart1, closedHeart2, heartBreak;
    closedHeart1.addVertex(x,y-a);
    closedHeart1.addVertex(x+c-b, y-c+b/2);
    closedHeart1.addVertex(x+d, y-a);
    closedHeart1.addVertex(x+c, y);
    closedHeart1.addVertex(x, y+c);
    closedHeart1.draw();
    closedHeart2.addVertex(xOne, y+c);
    closedHeart2.addVertex(xOne-c, y);
    closedHeart2.addVertex(xOne-d,y-a);
    closedHeart2.addVertex(xOne-c+b,y-c+b/2);
    closedHeart2.addVertex(xOne,y-a);
    closedHeart2.draw();
    ofDrawEllipse(x+a, y-a/2, a/2, a);
    ofDrawEllipse(xOne-a, y-a/2, a/2, a);
    ofSetColor(0, 0, 0);
    ofDrawEllipse(x+a, y-a/2, a/4, a/2);
    ofDrawEllipse(xOne-a, y-a/2, a/4, a/2);
    ofSetColor(255, 255, 255);
    ofDrawLine(xOne,y-a,xOne, yTwo);
    ofDrawLine(x, y-a, x, yTwo);
    if (sec > 12) {
        amaticr.drawString("再见", ofGetWidth()/2-5, ofGetHeight()/2);
    }
    if (sec > 19) {
        amaticr.drawString("People say it means goodbye and see you again in Chinese", ofGetWidth()/2-200, ofGetHeight()/2);
    }
    if (sec > 23) {
        amaticr.drawString("They also say people always say goodbye in a rainy day.", ofGetWidth()/2-200, ofGetHeight()/2);
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
