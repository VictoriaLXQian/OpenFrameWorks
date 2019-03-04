#include "ofApp.h"
const int framerate = 60;
ofVec2f org, cur, mouse;
ofFbo fbo, hedgehog9;  // framebuffer object
ofColor heart(0,0,0);
ofColor white(255,255,255);
Boolean pressF;
Boolean finalPosition;
float a, b, c, d;
int direction;

ofTrueTypeFont gillsans;


//--------------------------------------------------------------
void ofApp::setup(){
    gillsans.load("gillsans.ttf", 24);
    ofSetFrameRate(framerate);
    ofBackground(255, 255, 255);
    org = ofVec2f(ofGetWidth()/3,ofGetHeight()/2);
    a = 50;
    b = 25;
    c = 100;
    d = 125;
    cur = org;
    
    fbo.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA32F); // higher precision alpha (no artifacts)
    fbo.begin();
    ofClear(255,255,255, 0);
    fbo.end();
    ofSetBackgroundColor(255, 255, 255);
    
    pressF = false;
    finalPosition = false;
}

//--------------------------------------------------------------
void ofApp::update(){
    
    switch (direction) {
        case 1:
            cur.x--; //LEFT
            break;
        case 2:
            cur.y--; // UP
            break;
        case 3:
            cur.x++; //RIGHT
            break;
        case 4:
            cur.y++; //DOWN
            break;
        default:
            break;
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255, 255, 0);
    gillsans.drawString ("PLAY WITH MY HEART", 150, 200);
    gillsans.drawString ("Press the letters 'W' 'A' 'S' 'D'\in the same way as you use arrow key to navigate.", 400, 300);
    if (pressF == true)
        cur = mouse;
    fbo.begin();
    ofSetColor(white, 10); // background color with alpha
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    ofSetColor(heart);
    ofNoFill();
    ofNoFill();
    ofPolyline closedHeart1;
    closedHeart1.addVertex(cur.x, cur.y-a);
    closedHeart1.addVertex(cur.x+c-b, cur.y-c+b/2);
    closedHeart1.addVertex(cur.x+d, cur.y-a);
    closedHeart1.addVertex(cur.x+c, cur.y);
    closedHeart1.addVertex(cur.x, cur.y+c);
    closedHeart1.addVertex(cur.x-c, cur.y);
    closedHeart1.addVertex(cur.x-d,cur.y-a);
    closedHeart1.addVertex(cur.x-c+b,cur.y-c+b/2);
    closedHeart1.close();
    closedHeart1.draw();
    ofDrawEllipse(cur.x+a, cur.y-a/2, a/2, a);
    ofDrawEllipse(cur.x-a, cur.y-a/2, a/2, a);
    ofFill();
    ofSetColor(0, 0, 0);
    ofDrawEllipse(cur.x+a, cur.y-a/2, a/4, a/2);
    ofDrawEllipse(cur.x-a, cur.y-a/2, a/4, a/2);
    ofFill();
   
    
    
    fbo.end();
    
    ofSetColor(255,255,255);  // always set the color before drawing the fbo
    if (finalPosition == false)
        fbo.draw(0,0);
    else
        fbo.draw(100,375);
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key=='f') pressF = true;
    if(key == 'w') direction = 2;
    if(key == 's') direction = 3;
    if(key == 'a') direction = 1;
    if(key == 'd') direction = 3;
    //    if (key == 'w' || key == 's' || key == 'a' || key == 'd') move = true;
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    mouse = ofVec2f(x,y);
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    finalPosition = true;
    
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
