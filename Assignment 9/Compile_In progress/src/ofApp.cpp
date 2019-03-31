#include "ofApp.h"


float midX, midY; // midpoint
float barOne, barTwo; // train window-movement
float yTrain;
ofVec2f rP,posFm; //running person, the station name MOVEMENT
ofTrueTypeFont gillsans,amaticr;
float startX, startY; //RAINDROP MOVEMENT
float endX;
float sec;
float x,y;
float a, b, c, d; // HEARTBREAK
float l1;
float distant;
int dir;
float counter;
float xMid, yMid, yTwo;
float xOne, yOne;
ofImage image;
// cry face
int xFace, yFace, xPos, xPosone, yPos;
// wall with photo, still, arrival scene
ofVec2f mid;
ofImage photo;
// night girl looking at the window
ofVec2f girl;
// from night to morning
ofImage moonlight;
float z,w;
// stamp moving on the wall
int direction;
ofVec2f aus,chin,dank,fra,gre,hgr,ita,neth,pol;
ofVec2f pic;
Boolean pressA,pressC,pressD,pressF,pressG,pressH,pressI,pressN,pressP;
ofImage stampAus,stampChin,stampDnmk,stampFra,stampGre,stampHgr,stampIta,stampNeth,stampPol;

// snow
snow ml0,ml1,ml2,ml3,ml4,ml5,ml6,ml7,ml8,ml9; // when using the instructor methods, drawing a new one just add the code wherever ml0 is called.

snow::snow(){
    offsetX=ofRandom(-400, 500);
    offsetY=ofRandom(-500, 500);
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

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    midX = ofGetWidth() / 2;
    midY = ofGetHeight() / 2;
    barOne = midX - 300;
    barTwo = midX + 500;
    rP = ofVec2f(650, 450);
    posFm = ofVec2f(200,350);
    yTrain = midY;
    gillsans.load("gillsans.ttf", 20);
    amaticr.load("amaticr.ttf", 15);
    
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
    
    // raindrop
    image.load("leavingNight.jpg");
    startX = 0;
    startY = 0;
    endX = ofGetWidth();
    x = ofGetWidth();
    y = ofGetHeight();
    
    a = 50; // HEARTBREAK
    b = 25;
    c = 100;
    d = 125;
    dir = 1;
    l1 = 50;
    xMid = midX;
    yMid = midY;
    yTwo = yMid-a;
    xOne = midX;
    
    // cry face
    xFace = midX;
    yFace = midY;
    xPos = ofGetWidth()/2;
    xPosone = xPos;
    yPos = ofGetHeight()/2;
    
    // wall with photo
    mid = ofVec2f (ofGetWidth()/2,ofGetHeight()/2);
    photo.load("faceUse.png");
   
    // night girl looking at the window
    girl = ofVec2f(midX, midY);
    
    // from night to morning
    z = 255;
    w = z;
    moonlight.load("moon.png");
    
    // snow
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

float inc = 0.5;
ofVec2f rpFinal;
float dirt;
int minute;

void ofApp::update(){
    minute = (ofGetFrameNum()/60) / 60;
    sec = (ofGetFrameNum() / 60) % 60;
   
    mid.x-=0.5; // wall suitcase moving
    
    w -= 0.03; // color of the sky changing from night to morning
    z -= 0.015;
    
    // TRAIN MOVEMENT
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
    rP.x = ofMap(dirt, 0, 300, rP.x, 1700);
    posFm.x = ofMap(dirt, 0, 450, posFm.x, 1700);
    
    // RAINTDROP WINDOW
    sec = (ofGetFrameNum() / 60) % 60;
    startY += 0.5;
    yTrain += 0.3;
    x *= 0.9999;
    y *= 0.9999;
    // Heartbreak
    yTwo += 0.3;
    distant = yTwo - yMid;
    if (distant >= c) {
        yTwo = yMid+c;
        xMid += 0.2;
        xOne -= 0.2;
    }
    // cry face
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
    
    //night girl looking at the window
    
    if (minute == 1 && sec > 13){
        girl.x = ofMap(midX, 0, 60, midX, midX-2.75);
    }
    
    if (minute == 1 && sec > 44){
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
            
    // snow
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
void ofApp::draw(){
    ofBackground(0, 0, 0);
    ofSetColor(255, 255, 255);
    amaticr.drawString("I always remember that day,", midX, midY);
    amaticr.drawString("the day you were waving goodbye.", midX, midY+30);
    amaticr.drawString("And I always remember you said", midX, midY+60);
    amaticr.drawString("'You always have a home here. We are all waiting for you'.", midX, midY+90);
    // First Scene, goodbye, train station, blakc and white-memories
    if (minute == 0 && 4 < sec && sec < 40) {
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
    // RAINDROP Change to class method!!!
    if (minute==0 && 42 < sec ) {
        amaticr.drawString("and you,", midX-20, midY+170); // * change accordingly to the time
        amaticr.drawString("just like this familiar city, disappeared, in a rainy night.", midX-150, midY+200);
        image.draw(0,0);
        image.resize(x, y);
    }
    if (minute==0 && 42.5 < sec ) {
        ofSetColor (255,255,255,100); // Change color
        ofDrawEllipse(midX, startY + 10, 5, 8);
        ofDrawEllipse(midX-120, startY + 100, 10, 15);
        ofDrawEllipse(startX + 80, midY - 200, 15, 18);
        ofDrawEllipse(midX + 400, midY, 8, 12);
        }
    if (minute==0 && 46 < sec){
        ofDrawEllipse(startX + 20, startY, 5, 9);
        ofDrawEllipse(endX - 70, startY + 60, 8, 14);
        ofDrawEllipse(midX + 400, midY, 7, 14);
        }
    if (minute==0 && 47 < sec){
        ofDrawEllipse(startX + 100, midY + 100, 20, 25);
        ofDrawEllipse(midX - 250, startY + 20, 10, 15);
        ofDrawEllipse(midX + 300, startY + 10, 5, 8);
        }
    if (minute==0 && 52 < sec){
        ofDrawEllipse(midX - 350, midY - 200, 8, 16);
        ofDrawEllipse(midX + 300, startY + 160, 10, 17);
        ofDrawEllipse(startX + 20, startY, 5, 9);
        ofDrawEllipse(endX - 70, startY + 60, 8, 14);
        ofDrawEllipse(midX + 400, midY, 7, 14);
        }
    // WHY NOTHING DRAW ON THE SCREEN?
    if (minute==0 && 53 < sec) {
        ofPolyline closedHeart1, closedHeart2;
        ofBackground(214,117,117);
        ofSetLineWidth(3.0);  // Line widths apply to polylines
        ofSetColor(255,230,230);
        closedHeart1.addVertex(xMid,yMid-a);
        closedHeart1.addVertex(xMid+c-b, yMid-c+b/2);
        closedHeart1.addVertex(xMid+d, yMid-a);
        closedHeart1.addVertex(xMid+c, yMid);
        closedHeart1.addVertex(xMid, yMid+c);
        closedHeart1.draw();
        closedHeart2.addVertex(xOne, yMid+c);
        closedHeart2.addVertex(xOne-c, yMid);
        closedHeart2.addVertex(xOne-d,yMid-a);
        closedHeart2.addVertex(xOne-c+b,yMid-c+b/2);
        closedHeart2.addVertex(xOne,yMid-a);
        closedHeart2.draw();
        ofDrawEllipse(xMid+a, yMid-a/2, a/2, a);
        ofDrawEllipse(xOne-a, yMid-a/2, a/2, a);
        ofSetColor(0, 0, 0);
        ofDrawEllipse(xMid+a, yMid-a/2, a/4, a/2);
        ofDrawEllipse(xOne-a, yMid-a/2, a/4, a/2);
        ofSetColor(255, 255, 255);
        ofDrawLine(xOne,yMid-a,xOne, yTwo);
        ofDrawLine(xMid,yMid-a,xMid, yTwo);
    }
//    if (minute == 1 && sec > 5) {
//        amaticr.drawString("再见", midX-5, midY);
//    }   * TYPE CHINESE
    if (minute == 1 && sec > 12) {
        amaticr.drawString("People say it means goodbye and see you again in Chinese", midX-200, midY);
    }
    if (minute == 1 && sec > 17) {
        amaticr.drawString("They also say people always say goodbye in a rainy day.", midX-200, midY);
    }
    // empty room only with a photo and suitcase
    // * empty room - suitcase moving - photo, entire scene
    if (minute == 1 && sec > 5){
        ofBackground(251,233,238);
        ofSetColor(0, 0, 0);
        amaticr.drawString("My new home is an empty room,", midX-300, midY-270);
        amaticr.drawString("with walls in my favorite color,", midX-300, midY-240);
        amaticr.drawString("a suitcase I bring,", midX-300, midY-210);
        amaticr.drawString("and a photo of you.", midX-300, midY-180);
        ofSetColor (255, 255, 255);
        ofDrawRectangle(660,190,160,200); // Portrait Photo Frame
        ofSetColor(248, 252, 253);
        ofDrawRectangle(mid.x-280, mid.y+200, 10, 60);
        ofDrawRectangle(mid.x-230, mid.y+200, 10, 60);
        ofSetColor (13, 57, 73);//outside
        ofDrawRectRounded(mid.x-350, mid.y+260, 200, 150, 15);
        ofSetColor (34, 91, 111);
        ofDrawRectRounded(mid.x-330, mid.y+280, 160, 120, 10);
        ofDrawRectRounded(mid.x-285, mid.y+190, 70, 15, 5);
        ofSetColor (255,255,255);
        photo.draw(670,200);
        photo.resize(140,180);
    }
    // girl looking at the window
    //    * load music here + voice over
    if (minute == 1 && sec > 10) {
        // background pink as the photo wall scene
        ofBackground(251,233,238);
        // window
        ofSetColor(31,50,137);
        ofDrawRectangle(midX-300, midY - 240, 600, 400);
        // window frame
        ofSetColor (197,150,97);
        ofDrawRectangle(midX-300, midY -40, 600, 4); //horizontal
        ofDrawRectangle(midX -100, midY -240, 4, 400);
        ofDrawRectangle(midX +100, midY -240, 4, 400);
        ofDrawRectangle(midX-320, midY+160, 640, 15);
        // moon
        ofSetColor(236,234,190);
        ofSetCircleResolution(60);
        ofDrawCircle(midX + 200, midY-150, 35);
        // girl shadow
        ofSetColor(231, 214, 188);
        ofDrawRectRounded(midX- 195, midY + 100, 10, 120, 70, 20, 20, 10, 10);
        ofSetColor(242, 249, 255); // dress
        ofDrawTriangle(midX-185, midY + 155, midX-90, midY + 155, girl.x -140, midY +340);
        ofDrawTriangle(midX -140, midY + 105, girl.x-220, midY + 390, girl.x - 60, midY + 390); // MOVEMENT
        ofSetColor(69, 43, 3); //hair_MOVEMENT
        ofDrawRectRounded(midX- 180, midY + 20, 10, 90, 170, 40, 40, 25, 25);
    }
    // from night to morning
    if (minute == 1 && sec > 16) {
        ofBackground(194, 213, 234);
        ofSetColor(9,15,41,w);
        ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
        ofSetColor(255,255,255,z);
        ofPushMatrix();
        ofScale(0.06, 0.06);
        moonlight.draw(1000, 700);
        ofPopMatrix();
        ofSetColor (86,51,13);
        ofDrawRectangle(midX-100, midY - 5, 200, 130);
        // window
        ofSetColor(188,166,173);
        ofDrawRectangle(midX-90, midY, 180, 120);
        // window frame
        ofSetColor (86,51,13);
        ofDrawRectangle(midX-90, midY +58, 180, 4); //horizontal
        ofDrawRectangle(midX -35, midY, 4, 120);
        ofDrawRectangle(midX +35, midY, 4, 120);
    }
    // cry face
    if (minute == 1 && sec > 26){
        ofSetLineWidth(0.5);
        ofSetCircleResolution(40);
        ofBackground(214, 225, 240);
        ofSetColor(253,234,182);
        ofDrawCircle(midX, midY, 150);// Round Face + COLOR
        ofSetColor(255, 255, 255);
        ofDrawCircle(midX-45, midY-25, 40); //Left Eye Ball
        ofDrawCircle(midX+45, midY-25, 40); //Right Eye Ball
        ofSetColor(0, 0, 0);
        ofDrawCircle(midX-45, midY-25, 20); //Left Eye
        ofDrawCircle(midX+45, midY-25, 20); //Right Eye
        ofDrawLine(midX, midY, midX, midY+45); //Nose
        ofDrawLine(midX-25, midY+70, midX+25, midY+70); // Mouth (The Neutral Face)
        ofSetColor(68, 178, 201);
        ofDrawEllipse(xFace-40, yPos-20, 7, 10);
        ofDrawEllipse(xFace-65, yPos-20, 7, 10);
        ofDrawEllipse(xFace+40, yPos-20, 7, 12);
        ofDrawEllipse(xFace+65, yPos-20, 7, 12);
        ofDrawCircle(xPos-40, midY-20, 7);
        ofDrawCircle(xPosone+40, midY-20, 7);
    }
    if (minute == 1 && sec > 40) {
        ofBackground(0, 0, 0);
        gillsans.drawString("Another Scene Needed", midX, midY);
    }
    // stamps moving

    
    if (minute == 1 && sec > 42) {
        ofBackground(251,233,238);
        ofSetColor (255, 255, 255);
        ofDrawRectangle(pic.x-10,pic.y-10,160,200); // Portrait Photo Frame
        photo.draw(pic);
        photo.resize(140,180);
        amaticr.drawString("I started to forget,",midX-350, midY-270);
        amaticr.drawString("the face you,",midX-350, midY-230);
        amaticr.drawString("the image of the home,",midX-350, midY-190);
        amaticr.drawString("and the life in that city.",midX-350, midY-150);
    }
    if (minute == 1 && sec > 45) {
        ofSetColor (255,255,255,100);
        ofDrawRectangle(600,200,170,170);
        ofSetColor (255,255,255);
        gillsans.drawString("Use 'u' to move up", midX-400, midY-270);
        gillsans.drawString("Use 'j' to move left", midX-400, midY-230);
        gillsans.drawString("Use 'k' to move right", midX-400, midY-190);
        gillsans.drawString("Use 'm' to move down", midX-400, midY-150);
        gillsans.drawString("Press the Initial Letter of the Origin (Country) of the Stamp", midX-400, midY-110);
    }
    if (minute == 1 && sec > 46) {
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
    
    if (minute == 2 && sec> 40){
        ofBackground(179,196,193); //change the color as the building color
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
        amaticr.drawString("Some years later, in a gloomy afternoon", midX - 350, midY+ 200);
        amaticr.drawString("I had a dream.", midX - 200, midY+ 230);
        amaticr.drawString("I saw you there,", midX - 200, midY+ 260);
        amaticr.drawString("waiting.", midX - 200, midY+ 290);
        amaticr.drawString("Nothing changed.", midX - 200, midY+ 320);
        amaticr.drawString("Home is always HOME.", midX - 200, midY+ 350);
    }
    
    // train running back
    

}
//
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
//
}
//
////--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
//
}
//
//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){

}
