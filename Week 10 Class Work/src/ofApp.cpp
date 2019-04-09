#include "ofApp.h"

//--------------------------------------------------------------
string whatever;
void recursion(int first,int second, int index){
    //    first = 1;
    index --;
    int sum = first + second;
    cout << sum << endl;
    first = second;
    //    index = 10;

    if (!index) exit(0);
    recursion(second, sum, index);
//    whatever += sum + " ";
    
    
    
}
void ofApp::setup(){
    recursion(0, 1, 10);
    whatever = "Results:";
    
}
// setup only run once; it runs at the beginning.
//--------------------------------------------------------------
void ofApp::update(){
    
    

}
// everytime update runs before the draw.
//--------------------------------------------------------------



void ofApp::draw(){
    
    ofDrawBitmapString(whatever, 100, 100);


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
