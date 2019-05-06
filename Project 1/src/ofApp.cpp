#include "ofApp.h"

float midX, midY; // midpoint
float barOne, barTwo; // train window-movement
float yTrain;
ofVec2f rP,posFm; //running person, the station name MOVEMENT
ofTrueTypeFont gillsans,amaticr;
float startX, startY; //RAINDROP MOVEMENT
float picsizeX,picsizeY;
float picX,picY;
ofImage raindrop;
float sec;
float x,y;
float a, b, c, d; // HEARTBREAK
float l1;
float distant;
int dir,dist;
float counter;
float xMid, yMid, yTwo;
float xOne, yOne;
ofImage image;
// cry face
float xFace, yFace, xPos, xPosone, yPos;
// wall with photo, still, arrival scene
ofVec2f mid;
ofImage photo;
// night girl looking at the window
ofVec2f girl,hair;
float girlX, girlY;
// from night to morning
ofImage moonlight;
float z,w;
// stamp moving on the wall
int direction;
ofVec2f aus,chin,dank,fra,gre,hgr,ita,neth,pol;
ofVec2f pic;
Boolean pressA,pressC,pressD,pressF,pressG,pressH,pressI,pressN,pressP;
ofImage stampAus,stampChin,stampDnmk,stampFra,stampGre,stampHgr,stampIta,stampNeth,stampPol;

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofSetCircleResolution(60);
    midX = ofGetWidth() / 2;
    midY = ofGetHeight() / 2;
    barOne = midX - 300;
    barTwo = midX + 500;
    rP = ofVec2f(650, 450);
    posFm = ofVec2f(200,350);
    yTrain = midY;
    gillsans.load("gillsans.ttf", 14);
    amaticr.load("amaticr.ttf", 20);
    
    // raindrop
    image.load("leavingNight.jpg");
    raindrop.load("Raindrop.png");
    picX = 0;
    picY = 0;
    picsizeX = ofGetWidth();
    picsizeY = ofGetHeight();
    
    // wall with photo
    mid = ofVec2f (ofGetWidth()/2,ofGetHeight()/2);
    photo.load("faceUse.png");
    
    // HEARTBREAK
    a = 50;
    b = 25;
    c = 100;
    d = 125;
    dir = 1;
    dist = 0;
    l1 = 50;
    x = midX;
    y = midY;
    yTwo = midY-a;
    xOne = midX;
    
    // GIRL ALONE
    girlX = ofGetWidth()/2;
    girlY = ofGetHeight()/2;
    girl = ofVec2f(girlX,girlY);
    hair = ofVec2f(girlX-180,girlY+20);
    
    // from night to morning
    z = 255;
    w = z;
    moonlight.load("moon.png");
    
    // cry face
    xFace = midX;
    yFace = midY;
    xPos = ofGetWidth()/2;
    xPosone = xPos;
    yPos = ofGetHeight()/2;

    
    //stamp moving on the wall
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
    



}

//--------------------------------------------------------------
float inc = 0.5;
ofVec2f rpFinal;
float dirt;
void ofApp::update(){
    sec = ofGetElapsedTimef();
//    ----------- TRAIN ----------
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
    
//     ----------  Raindrop on Window ----------
    if (sec > 27.5) {
        midY += 0.6;
        picsizeX *= 0.9995;
        picsizeY *= 0.9995;
        picX = (ofGetWidth()-image.getWidth())/2;
        picY = (ofGetHeight()-image.getHeight())/2;
    }
    
//    -----------  Broken Heart  -----------
    if (sec > 66){
        yTwo += 0.3;
        distant = yTwo - y;
        if (distant >= c) {
            yTwo = y+c;
            x += 0.2;
            xOne -= 0.2;
        }
    }
    
//    -----------  Girl Alone  -------------
    if (sec > 92){
        girl.x = ofMap(girlX, 0, 150, girlX, girlX-3);
        hair.x = ofMap(girlX, 0, 150, girlX-180, girlX-180.75);
    }
    if (sec > 96){
        girl.x = ofMap(girlX, 0, 250, girlX-3, girlX+5);
        hair.x = ofMap(girlX, 0, 150, girlX-180.75, girlX-179.75);
    }
    if (sec > 101){
        girl.x = ofMap(girlX, 0, 150, girlX+5, girlX);
        hair.x = ofMap(girlX, 0, 150, girlX-179.5, girlX-180);
    }
//      ----------  All Night  --------------
    if (sec > 106){
        w -= 0.3;
        z -= 0.19;
    }
    
//    -----------  Cry Face  -----------------
    if (sec > 120){
        xPos-=0.5;
        if (xPos < midX - 105){
            xPos = midX;
        }
        xPosone+=0.5;
        if (xPosone > midX + 105){
            xPosone = midX;
        }
        yPos+=0.65;
        if (yPos > (ofGetHeight()/2+90)){
            yPos = midY;
        }
    }
//    ----------  Stamp  --------------------
    if (sec > 1.5){
//        pic.x = ofMap(10, 0, 10, 670, 1200);
        pic.y --;
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
}
void ofApp::opening(){
    ofBackground(0, 0, 0);
    ofSetColor(255, 255, 255);
    if (sec > 0.2) {
        amaticr.drawString("I always remember that day,", midX, midY);
    }
    if (sec > 2){
        amaticr.drawString("the day you were waving goodbye.", midX, midY+50);
    }
    if (sec > 3.5){
        amaticr.drawString("And I always remember you said", midX, midY+100);
    }
    if (sec > 5) {
        amaticr.drawString("'You always have a home here. We are all waiting for you'.", midX-3, midY+150);
    }
}

void ofApp::train(){
    if (sec > 9){
        ofBackground(255,255,255,180);
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
        ofSetColor(0,0,0);
        ofDrawRectangle(0, 0, 1100, 100);
        ofDrawRectangle(barOne, 100, 50, 800); // bar one
        ofDrawRectangle(barTwo, 100, 50, 800); // bar two
        ofDrawRectangle(0, 700, 1100, 100);
        ofDrawRectangle(0, 250, 1800, 20);
        ofSetLineWidth(4);
        ofDrawLine(0, 550, 1700, 550); // Drawing the frame of the window
        ofSetColor(255, 255, 255);
    }
}

void ofApp::rain(){
    if (sec > 27){
    ofBackground(0,0,0);
    image.draw(picX,picY);
    image.resize(picsizeX, picsizeY);
    raindrop.draw(0, 0);
    ofSetColor (255,255,255);
    amaticr.drawString("and you,", midX-20, midY-250);
    amaticr.drawString("just like this familiar city,", midX-82, midY-200);
    amaticr.drawString("disappeared, ", midX-30, midY-150);
    amaticr.drawString("in a rainy night.", midX-48, midY-100);
    }
    if (sec > 45){
        amaticr.drawString("TITLE", midX-10, ofGetHeight()/3);
    }
}
//--------------------------------------------------------------
void ofApp::emptyroom(){
    if (sec > 49){
        ofBackground(0, 0, 0);
    }
    if (sec > 52){
        ofBackground(251,233,238);
        ofSetColor(0, 0, 0);
        if (sec > 53.5)
            amaticr.drawString("My new place is an empty room,", ofGetWidth()/2-300, ofGetHeight()/2-270);
        if (sec > 55.5)
            amaticr.drawString("with walls in my favorite color,", ofGetWidth()/2-300, ofGetHeight()/2-220);
    }
    if (sec > 57.5){
        amaticr.drawString("a suitcase I traveled with,", ofGetWidth()/2-300, ofGetHeight()/2-170);
        ofSetColor(248, 252, 253);
        ofDrawRectangle(mid.x-280, mid.y+200, 10, 60);
        ofDrawRectangle(mid.x-230, mid.y+200, 10, 60);
        ofSetColor (13, 57, 73);//outside
        ofDrawRectRounded(mid.x-350, mid.y+260, 200, 150, 15);
        ofSetColor (34, 91, 111);
        ofDrawRectRounded(mid.x-330, mid.y+280, 160, 120, 10);
        ofDrawRectRounded(mid.x-285, mid.y+190, 70, 15, 5);
        ofSetColor (255,255,255);
    }
    if (sec > 59.5){
        ofSetColor(0, 0, 0);
        amaticr.drawString("and a photo of you.", ofGetWidth()/2-300, ofGetHeight()/2-120);
        ofSetColor (255, 255, 255);
        ofDrawRectangle(660,190,160,200); // Portrait Photo Frame
        photo.draw(670,200);
        photo.resize(140,180);
    }
}
void ofApp::brokenheart(){
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
}
void ofApp::girlalone(){
    ofBackground(251,233,238); // background pink as the photo wall scene
    // window
    ofSetColor(31,50,137);
    ofDrawRectangle(girlX-300, girlY - 240, 600, 400);
    // window frame
    ofSetColor (197,150,97);
    ofDrawRectangle(girlX-300, girlY -40, 600, 4); //horizontal
    ofDrawRectangle(girlX -100, girlY -240, 4, 400);
    ofDrawRectangle(girlX +100, girlY -240, 4, 400);
    ofDrawRectangle(girlX-320, girlY+160, 640, 15);
    // moon
    ofSetColor(236,234,190);
    ofDrawCircle(girlX + 200, girlY-150, 35);
    // girl shadow
    ofSetColor(231, 214, 188);
    ofDrawRectRounded(girlX- 195, girlY + 100, 10, 120, 70, 20, 20, 10, 10);
    ofSetColor(242, 249, 255); // dress
    ofDrawTriangle(girlX-185, girlY + 155, girlX-90, girlY + 155, girl.x -140, girlY +340);
    ofDrawTriangle(girlX -140, girlY + 105, girl.x-220, girlY + 390, girl.x - 60, girlY + 390); // MOVEMENT
    ofSetColor(69, 43, 3); //hair_MOVEMENT
    ofDrawRectRounded(hair.x, hair.y, 10, 90, 170, 40, 40, 25, 25);
}
void ofApp::allnight(){
    ofBackground(194, 213, 234);
    ofSetColor(9,15,41,w);
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    ofSetColor(255,255,255,z);
    ofPushMatrix();
    ofScale(0.06, 0.06);
    moonlight.draw(1000, 700);
    ofPopMatrix();
    ofSetColor (86,51,13);
    ofDrawRectangle(girlX-100, girlY - 5, 200, 130);
    // window
    ofSetColor(188,166,173);
    ofDrawRectangle(girlX-90, girlY, 180, 120);
    // window frame
    ofSetColor (86,51,13);
    ofDrawRectangle(girlX-90, girlY +58, 180, 4); //horizontal
    ofDrawRectangle(girlX -35, girlY, 4, 120);
    ofDrawRectangle(girlX +35, girlY, 4, 120);
    cout << w << endl;
}
void ofApp::cry(){
    ofBackground(0,0,0);
    ofSetColor(214, 225, 240);
    ofDrawRectangle(midX-160, midY-90, 320, 180);
    ofSetColor(253,234,182);
    ofDrawCircle(midX, midY, 70);// Round Face + COLOR
    ofSetColor(255, 255, 255);
    ofDrawCircle(midX-28, midY-15, 21); //Left Eye Ball
    ofDrawCircle(midX+28, midY-15, 21); //Right Eye Ball
    ofSetColor(0, 0, 0);
    ofDrawCircle(midX-28, midY-15, 10.5); //Left Eye
    ofDrawCircle(midX+28, midY-15, 10.5); //Right Eye
    ofSetLineWidth(1.5);
    ofDrawLine(midX, midY+8, midX, midY+30); //Nose
    ofDrawLine(midX-15, midY+40, midX+15, midY+40); // Mouth (The Neutral Face)
    ofSetColor(68, 178, 201);
    ofDrawEllipse(xFace-25, yPos-20, 6, 9);
    ofDrawEllipse(xFace-45, yPos-20, 6, 9);
    ofDrawEllipse(xFace+25, yPos-20, 6, 11);
    ofDrawEllipse(xFace+45, yPos-20, 6, 11);
    ofDrawCircle(xPos-40, midY-15, 5);
    ofDrawCircle(xPosone+40, midY-15, 5);
}

void ofApp::travel(){
    
}
void ofApp::stampwall(){
    ofBackground(251,233,238);
    ofSetColor (255, 255, 255);
    ofDrawRectangle(pic.x-10,pic.y-10,160,200); // Portrait Photo Frame
    photo.draw(pic);
    photo.resize(140,180);
    ofSetColor (0,0,0);
    if (sec > 0 && sec < 8) {
        amaticr.drawString("I started to forget,",midX-350, midY-270);
    }
    if (sec > 2 && sec < 8) {
        amaticr.drawString("the face you,",midX-350, midY-220);
    }
    if (sec > 4 && sec < 8) {
        amaticr.drawString("the imagery of home,",midX-350, midY-170);
    }
    if (sec > 6 && sec < 8) {
        amaticr.drawString("and the life in that city.",midX-350, midY-120);
    }
    if (sec > 8 && sec < 12) {
        gillsans.drawString("Use ARROW keys to move up, left, right, down.", midX-400, midY-270);
        gillsans.drawString("Press the Initial Letter of the Origin (Country) of the Stamp", midX-400, midY-230);
    }
    
    if (10 < sec){
        ofSetColor (255,255,255,100);
        ofDrawRectangle(600,200,170,170);
        ofSetColor (255,255,255);
        
    }
    if (12 < sec) {
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
void ofApp::draw(){
    opening();
    train();
    rain();
    emptyroom();
    if (sec > 62){
        ofBackground(0, 0, 0);
        amaticr.drawString("I am used to international travels,", ofGetWidth()/2-135, ofGetHeight()/2);
    }
    if (sec > 64) {
        ofBackground(0, 0, 0);
        amaticr.drawString("But, not this empty room.", ofGetWidth()/2-100, ofGetHeight()/2);
    }
    if (sec > 66){
    brokenheart();
        if (sec > 80) {
            amaticr.drawString("I miss", ofGetWidth()/2-10, ofGetHeight()/2);
        }
    }
    if (sec > 90){
        girlalone();
    }
    if (sec > 105){
        allnight();
        if (sec > 108){
            amaticr.drawString("And now, standing ,looking at the moon, thinking of my distant home", ofGetWidth()/2-200, ofGetHeight());
        }
    }
    if (sec > 120){
        cry();
    }
    if (sec > 0){
        stampwall();
    }

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == OF_KEY_LEFT) direction = 1; //move left
    if(key == OF_KEY_UP) direction = 2; //move up
    if(key == OF_KEY_RIGHT) direction = 3; //move right
    if(key == OF_KEY_DOWN) direction = 4; //move down
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
