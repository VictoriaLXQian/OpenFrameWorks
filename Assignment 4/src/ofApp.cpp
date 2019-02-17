#include "ofApp.h"





ofVec2f mid, cur, step, direction;
ofVec2f eyeLeft, eyeRight, leftUp, rightUp; // Happy, eye movement
ofVec2f curEye, curLeft, curRight, surprise, nose, mouth, mouthLeft, mouthRight;
int midX, midY; // no movement int!
int x, y, z;
int xPos,xPosone, yPos;
int sec; // second, 2 second for the emotion/ 1 second to netural
//--------------------------------------------------------------

void ofApp::setup(){
    ofSetFrameRate(60);
    
    midX = ofGetWidth()/2;
    midY = ofGetHeight()/2;
    
    // vector
    mid = ofVec2f (ofGetWidth()/ 2, ofGetHeight()/ 2);
    step = ofVec2f (0,4);
    direction = ofVec2f (1,1);
    cur = mid;
    eyeLeft = ofVec2f (45,25);
    eyeRight = ofVec2f (50,-25);
    leftUp = ofVec2f (55,25);
    rightUp = ofVec2f (40, -25);
    curLeft = ofVec2f((ofGetWidth()/2)-45,(ofGetHeight()/2)-25);
    curRight = ofVec2f((ofGetWidth()/2)+50,(ofGetHeight()/2)-25);
    surprise = ofVec2f(10,0);
    nose = ofVec2f (0,30);
    mouth = ofVec2f (50,-57);
    
    // integer
    x = midX;
    z = x;
    y = midY;
    xPos = ofGetWidth()/2;
    xPosone = xPos;
    yPos = ofGetHeight()/2;
    
    
    
    
    
}



//--------------------------------------------------------------
const int maxDistance = 500;
bool drawNeutral = true;
bool drawOriginal = true;
bool drawHappy = true;
bool drawSad = true;
bool drawSurprise = true;
bool drawAngry = true;
int stepAngry = 2;
int directionRight = 1;
int directionLeft = -1;
const int maxDistanceangry = 25; // ANGRY Movement


void ofApp::update(){
    
    int sec = (ofGetFrameNum()/60) % 60;
    drawNeutral = sec < 1;
    drawHappy = ( 1 < sec && sec < 4);
    drawSad = (  4 < sec && sec < 7);
    drawSurprise = ( 7 < sec && sec < 10);
    drawAngry = ( 10 < sec && sec < 13);

 
  
    
    bool easingHappy = false;
    int dist;
    
    dist = cur.distance(mid);
    
    int stepY = ofMap(dist, 0, 500, 1, 10);
    step = ofVec2f(5, stepY);
    
    if ((cur + (step * direction)).distance(mid) > maxDistance) {
        
        direction *= -1;
    }
    
    cur += step * direction;
    
    cout << cur.distance(mid) << endl;
    
    // HAPPY Face Jumping around the screen
    
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
    
    // SAD face
    
    bool easingLeft = false;
    int distSurleft;
    
    distSurleft = cur.distance(mid);
    
    int stepV = ofMap(dist, -500, 500, 1, 10);
    step = ofVec2f(5, stepV);
    
    if ((cur + (step * direction)).distance(mid) > maxDistance) {
        
        direction *= -1;
    }
    
    curLeft += step * direction;
    
    cout << cur.distance(mid) << endl;
    
    // Left eyeball, movement
    
    bool easingRight = false;
    int distSurright;
    
    distSurright = distSurleft;
    
    int stepZ = ofMap(dist, 500, 500, 1, 10);
    step = ofVec2f(5, stepZ);
    
    if ((cur + (step * direction)).distance(mid) > maxDistance) {
        
        direction *= -1;
    }
    
    curRight += step * direction;
    
    cout << cur.distance(mid) << endl;
    
    // Right eyeball, movement
    
    xPos--;
    xPosone++;
    yPos++;
    
    bool easingAngryright = false;
    int distRight;
    
    distRight = abs(x-midX);
    if (easingRight) {
        stepAngry = ofMap(distRight, 0, 200, 1, 10);
    }
    
    if (distRight + stepAngry > maxDistanceangry) {
        directionRight *= -1;
    }
    
    x += stepAngry * directionRight;
    
    cout << distRight << endl; // ANGRY RIGHT EYE
    
    bool easingAngryleft = false;
    int distLeft;
    
    distLeft = abs(z-midX);
    if (easingLeft) {
        stepAngry = ofMap(distLeft, 0, 200, 1, 10);
    }
    
    if (distLeft + stepAngry > maxDistanceangry) {
        directionLeft *= -1;
    }
    
    z += stepAngry * directionLeft;
    
    cout << distLeft << endl;
  
}



//--------------------------------------------------------------

void ofApp::draw(){
    if (drawNeutral) {
        ofBackground (214,214,214);
        ofSetColor(253,234,182);
        ofDrawCircle(mid, 150); //the face; remain still
        ofSetColor(255,255,255);
        ofDrawEllipse(midX-50, midY-25, 45, 70); // Left eye, outside
        ofDrawEllipse(midX+50, midY-25, 45, 70); // right eye, outside
        ofSetColor(16,47,90);
        ofDrawEllipse(midX-48, midY-25, 20, 40); // left eyeball
        ofDrawEllipse(midX+48, midY-25, 20, 40); // right eyeball
        ofDrawLine(mid, mid+nose*1.5);
        ofDrawLine(midX, midY+70,midX-50, midY+70);
        ofDrawLine(midX,midY+70,midX+50, midY+70);
    } else if (drawHappy) {
        ofBackground(242, 207, 205);
        ofSetColor(253,234,182);
        ofDrawCircle(cur, 150); // Face
        ofSetColor(255,255,255);
        ofDrawEllipse(cur-eyeLeft, 45, 70); // left eye, Black
        ofDrawEllipse(cur+eyeRight, 45, 70); // right eye, Black
        ofSetColor(16,47,90);
        ofDrawEllipse(cur-leftUp, 20, 40); // left eye, outside
        ofDrawEllipse(cur+rightUp, 20, 40); // right eye, outside
        ofDrawLine(cur, cur+nose*1.5);
        ofDrawLine(cur+nose*2.5, cur-mouth);
        ofDrawLine(cur+nose*2.5, cur+60);
        ofDrawBitmapStringHighlight("I'm content(a)!", midX-50, 70);
    } else if (drawSad) {
        ofBackground(214, 225, 240);
        ofSetColor(253,234,182);
        ofDrawCircle(midX, midY, 150);// Round Face + COLOR
        ofSetColor(255, 255, 255);
        ofDrawCircle(midX-45, midY-25, 40); //Left Eye Ball
        ofDrawCircle(midX+45, midY-25, 40); //Right Eye Ball
        ofSetColor(16,47,90);
        ofDrawCircle(midX-45, midY-25, 22); //Left Eye
        ofDrawCircle(midX+45, midY-25, 22); //Right Eye
        ofDrawLine(midX, midY, midX, midY+45); //Nose
        ofDrawLine(midX-25, midY+70, midX+25, midY+70); // Mouth (The Neutral Face)
        ofSetColor(68, 178, 201);
        ofDrawEllipse(midX-40, yPos-20, 7, 10);
        ofDrawEllipse(midX-65, yPos-20, 7, 10);
        ofDrawEllipse(midX+40, yPos-20, 7, 12);
        ofDrawEllipse(midX+65, yPos-20, 7, 12);
        ofDrawCircle(xPos-40, midY-20, 7);
        ofDrawCircle(xPosone+40, midY-20, 7);
        ofDrawBitmapStringHighlight("CRY. CRY.", midX-30, 700);
    } else if (drawSurprise){
        ofBackground(234, 170, 127);
        ofSetColor(253,234,182);
        ofDrawCircle(mid, 150); //the face; remain still
        ofSetColor(255,255,255);
        ofDrawEllipse(curLeft, 45, 70); // left eye
        ofDrawEllipse(curRight, 45, 70); // right eye
        ofSetColor(16,47,90);
        ofDrawEllipse(curLeft-surprise, 20, 40); // left eyeball
        ofDrawEllipse(curRight-surprise, 20, 40); // right eyeball
        ofDrawLine(mid, mid+nose*1.5);
        ofDrawLine(xPos, yPos+57,xPos-50, yPos+50);
        ofDrawLine(xPosone,yPos+57,xPosone+50, yPos+50);
        ofDrawBitmapStringHighlight("Where are my eyeballs?!!", midX-90, 700);
    } else if (drawAngry) {
        ofBackground(199, 53, 53);
        ofSetColor(253,234,182);
        ofDrawCircle(mid, 150); //the face; remain still
        ofSetColor(255,255,255);
        ofDrawEllipse(midX-45,midY-25, 45, 70); // left eye, Outside
        ofDrawEllipse(midX+50,midY-25, 45, 70); // right eye, Outside
        ofSetColor(16,47,90);
        ofDrawEllipse(z-55,midY-25, 20, 40); // left eye, eyeball
        ofDrawEllipse(x+40,midY-25, 20, 40); // right eye, eyeball
        ofDrawLine(midX, midY, midX, midY +45);
        ofDrawLine(midX, midY+70,midX-45, midY+77);
        ofDrawLine(midX,midY+70,midX+45, midY+77); // Nose and mouth stay STILL.
        ofDrawBitmapStringHighlight("Ugh!!!!!!", midX-30, 700);
    } else {
        ofBackground (214,214,214);
        ofSetColor(253,234,182);
        ofDrawCircle(mid, 150); //the face; remain still
        ofSetColor(255,255,255);
        ofDrawEllipse(midX-50, midY-25, 45, 70); // Left eye, outside
        ofDrawEllipse(midX+50, midY-25, 45, 70); // right eye, outside
        ofSetColor(16,47,90);
        ofDrawEllipse(midX-48, midY-25, 20, 40); // left eyeball
        ofDrawEllipse(midX+48, midY-25, 20, 40); // right eyeball
        ofDrawLine(mid, mid+nose*1.5);
        ofDrawLine(midX, midY+70,midX-50, midY+70);
        ofDrawLine(midX,midY+70,midX+50, midY+70);
    }
        
    
    
    
    
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
