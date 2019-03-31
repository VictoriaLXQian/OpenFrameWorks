#include "ofApp.h"
ofVec2f aus,chin,dank,fra,gre,hgr,ita,neth,pol;
Boolean pressA,pressC,pressD,pressF,pressG,pressH,pressI,pressN,pressP;
Boolean mouseclick;
int a, b, c, d; //For drawing
int direction;
ofImage photo;
ofImage stampAus,stampChin,stampDnmk,stampFra,stampGre,stampHgr,stampIta,stampNeth,stampPol;
ofVec2f step,cur,pic;
ofTrueTypeFont gillsans, amaticr;
float midX,midY;



//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
//    mid = ofVec2f (ofGetWidth()/2,ofGetHeight()/2);
//    cur = mid;
    midX = ofGetWidth()/2;
    midY = ofGetHeight()/2;
    photo.load("faceUse.png");
    stampAus.load("austria.jpg");
    stampChin.load("china.jpg");
    stampDnmk.load("danmark.jpg");
    stampFra.load("france.jpg");
    stampGre.load("greece.jpg");
    stampHgr.load("hungry.jpg");
    stampIta.load("italia.jpg");
    stampNeth.load("netherland.jpg");
    stampPol.load("poland.jpg");
    pic = ofVec2f (670,200);
    aus = ofVec2f (200,-50);
    chin = ofVec2f (500,50);
    dank = ofVec2f (0,0);
    fra = ofVec2f (200,50);
    gre = ofVec2f (700,50);
    hgr = ofVec2f (0,0);
    ita = ofVec2f (200,-50);
    neth = ofVec2f (700,50);
    pol = ofVec2f (0,0);
    gillsans.load("gillsans.ttf", 10);
    amaticr.load("amaticr.ttf", 15);

    
    
}

//--------------------------------------------------------------
float sec;
void ofApp::update(){
    sec = (ofGetFrameNum()/60)%60;
    
    if (sec == 4){
        pic.x = ofMap(10, 0, 10, 670, 1200);
        pic.y =-50;
        
    }
    switch (direction) {
            
        case 1:
            aus.x--; //LEFT
            chin.x--;
            dank.x--;
            fra.x--;
            gre.x--;
            hgr.x--;
            ita.x--;
            neth.x--;
            pol.x--;
            break;
        case 2:
            aus.y--; // UP
            chin.y--;
            dank.y--;
            fra.y--;
            gre.y--;
            hgr.y--;
            ita.y--;
            neth.y--;
            pol.y--;
            break;
        case 3:
            aus.x++; //RIGHT
            chin.x++;
            dank.x++;
            fra.x++;
            gre.x++;
            hgr.x++;
            ita.x++;
            neth.x++;
            pol.x++;
            break;
        case 4:
            aus.y++; //DOWN
            chin.y++;
            dank.y++;
            fra.y++;
            gre.y++;
            hgr.y++;
            ita.y++;
            neth.y++;
            pol.y++;
            break;
        default:
            break;
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(251,233,238);
    ofSetColor (255, 255, 255);
    ofDrawRectangle(pic.x-10,pic.y-10,160,200); // Portrait Photo Frame
    photo.draw(pic);
    photo.resize(140,180);
    if (sec > 0 && sec < 5) {
        ofSetColor (0,0,0);
        amaticr.drawString("I started to forget,",midX-350, midY-270);
        amaticr.drawString("the face you,",midX-350, midY-230);
        amaticr.drawString("the image of the home,",midX-350, midY-190);
        amaticr.drawString("and the life in that city.",midX-350, midY-150);
    }
    if (sec > 5 && sec < 9) {
        ofSetColor (0,0,0);
        gillsans.drawString("Use 'u' to move up", midX-400, midY-270);
        gillsans.drawString("Use 'j' to move left", midX-400, midY-250);
        gillsans.drawString("Use 'k' to move right", midX-400, midY-230);
        gillsans.drawString("Use 'm' to move down", midX-400, midY-210);
        gillsans.drawString("Press the Initial Letter of the Origin (Country) of the Stamp", midX-400, midY-190);
    }
    
    if (5 < sec){
        ofSetColor (255,255,255,100);
        ofDrawRectangle(600,200,170,170);
        ofSetColor (255,255,255);
        
    }
    if (8 < sec) {
        stampAus.draw(aus.x,aus.y);
        stampAus.resize(150, 150);
    }
    if (pressA){
        aus = ofVec2f(610,210);
    }
    if (aus == ofVec2f(610,210)){
        ofDrawRectangle(300, 500, 120, 170);
        stampChin.resize(100,150);
        stampChin.draw(chin.x,chin.y);
    }
    if (pressC){
        chin = ofVec2f (310,510);
    }
    if (chin == ofVec2f (310,510)) {
        ofDrawRectangle(200, 100, 170, 230);
        stampDnmk.resize(150, 210);
        stampDnmk.draw(dank.x, dank.y);
    }
    if (pressD){
        dank = ofVec2f(210,110);
    }
    if (dank == ofVec2f(210,110)) {
        ofDrawRectangle(50, 400, 150, 110);
        stampFra.resize(140, 100);
        stampFra.draw(fra.x, fra.y);
    }
    if (pressF) {
        fra = ofVec2f (55,405);
    }
    if (fra == ofVec2f (55,405)) {
        ofDrawRectangle(395, 280, 185, 130);
        stampGre.resize(175, 120);
        stampGre.draw(gre.x,gre.y);
    }
    if (pressG) {
        gre = ofVec2f (400,285);
    }
    if (gre == ofVec2f (400,285)) {
        ofDrawRectangle(700, 460, 160, 120);
        stampHgr.resize(140, 100);
        stampHgr.draw(hgr.x, hgr.y);
    }
    if (pressH) {
        hgr = ofVec2f(710,470);
    }
    if (hgr == ofVec2f(710,470)) {
        ofDrawRectangle(500, 450, 155, 260);
        stampIta.resize(135, 240);
        stampIta.draw(ita.x, ita.y);
    }
    if (pressI) {
        ita = ofVec2f (510,460);
    }
    if (ita == ofVec2f (510,460)) {
        ofDrawRectangle(218, 350, 160, 130);
        stampNeth.resize(150, 120);
        stampNeth.draw(neth.x, neth.y);
    }
    if (pressN) {
        neth = ofVec2f (223,355);
    }
    if (neth == ofVec2f (223,355)) {
        ofDrawRectangle(390, 35, 195, 160);
        stampPol.resize(175, 140);
        stampPol.draw(pol.x, pol.y);
    }
    if (pressP){
        pol = ofVec2f (400,45);
    }

    
    
    
    

    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == 'j') direction = 1; //move left
    if(key == 'u') direction = 2; //move up
    if(key == 'k') direction = 3; //move right
    if(key == 'm') direction = 4; //move down
    if(key == 'a') pressA = true;
    if(key == 'c') pressC = true;
    if(key == 'd') pressD = true;
    if(key == 'f') pressF = true;
    if(key == 'g') pressG = true;
    if(key == 'h') pressH = true;
    if(key == 'i') pressI = true;
    if(key == 'n') pressN = true;
    if(key == 'p') pressP = true;
    
    
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
//    mouseclick = true;
    
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
