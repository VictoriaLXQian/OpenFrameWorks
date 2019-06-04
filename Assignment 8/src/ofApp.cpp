#include "ofApp.h"
using namespace std;
float humidity;
int currentYear, currentMonth, currentDate;
float currentM,currentD;
int year, month, day;
int epochtime;
float a, b;
int sunR, sunS, current;
//bool Sunrise, Sunset;
float tempHigh,tempLow,tempRatio;


//--------------------------------------------------------------
void ofApp::setup(){
    std::string url = "https://api.darksky.net/forecast/your API Key/45.4642,9.1900";
    bool parsingSuccessful = json.open(url);
    
    if (parsingSuccessful)
    {
        ofLogNotice("ofApp::setup") << json.getRawString(true);
    } else {
        ofLogNotice("ofApp::setup") << "Failed to parse JSON.";
    }
    
    epochtime = json["daily"]["data"][0]["time"].asInt();
    sunR=json["daily"]["data"][0]["sunriseTime"].asFloat();
    sunS=json["daily"]["data"][0]["sunsetTime"].asFloat();
    current=json["daily"]["data"][0]["time"].asFloat();
    
    
    ofBackground(240, 240, 240);
    gui.setup();
    gui.add(uvindex.setup("UV Index", json["daily"]["data"][0]["uvIndex"].asFloat(), 0, 10));
    gui.add(temperature.setup("Temperature of Today", json["currently"]["temperature"].asFloat(), json["daily"]["data"][0]["temperatureLow"].asFloat(), json["daily"]["data"][0]["temperatureHigh"].asFloat()));
    gui.add(Sunrise.setup("sunrise"));
    gui.add(Sunset.setup("sunset"));
}

//--------------------------------------------------------------
void ofApp::update(){
    year = 60*60*24*365.24;
    currentYear = 1970 + epochtime/year;
    cout<<"currentYear"<<endl;
    month = 60*60*24*30.44;
    currentMonth = (epochtime % year)/month;
    currentM =(epochtime % year) % month;
    cout<<"currentMonth"<<endl;
    if (currentM > 0){
        currentMonth ++;
    } // When there is reminder, it is already next month.
    day = 60*60*24;
    currentDate = ((epochtime % year) % month)/ day;
    currentD = ((epochtime % year) % month) % day;
    cout<<"currentDate"<<endl;
    if (currentD > 0){
        currentDate ++;
    } // The json["daily"]["data"][0]["time"].asInt() starts at 12am, no reminder, but it is the next day, plus 1.
    

    tempHigh=json["daily"]["data"][0]["temperatureHigh"].asFloat();
    tempLow=json["daily"]["data"][0]["temperatureLow"].asFloat();
    tempRatio= (temperature-tempLow)/(tempHigh-tempLow);
    
    a = sunR - current;
    b = sunS - current;
    

}

//--------------------------------------------------------------
void ofApp::draw(){
//    humidity = json["daily"]["data"][i]["humidity"].asFloat();
    //    time = json["daily"]["data"][i]["humidity"].asFloat();
    //    humidity = ofMap(i, 0, 100, 0, 1);
    //    humidity = 0.5;
    //    a = humidity;
    
//    ofColor black = ofColor(0,0,0);
//    ofColor yellow = ofColor(255,250,70);
    
//    ofColor result= black.lerp (yellow, humidity);
    
//    ofBackground (result);
    
    ofSetColor(255, 0, 0, 255*(uvindex/10));
    ofDrawRectangle(0, 0, tempRatio*ofGetWidth(), ofGetHeight());
    
    ofSetColor(0, 0, 0);
    std::string time  = json["daily"]["data"][0]["time"].asString();
    std::string sunrise  = json["daily"]["data"][0]["sunriseTime"].asString();
    std::string sunset  = json["daily"]["data"][0]["sunsetTime"].asString();
    std::string high  = json["daily"]["data"][0]["temperatureHigh"].asString();
    std::string low  = json["daily"]["data"][0]["temperatureLow"].asString();
    std::string uvIndex  = json["daily"]["data"][0]["uvIndex"].asString();
    std::string summary = json["daily"]["data"][0]["summary"].asString();
    if (currentMonth==1) {
        ofDrawBitmapString("Jan.", 120, 90);
    }
    if (currentMonth==2) {
        ofDrawBitmapString("Feb.", 120, 90);
    }
    if (currentMonth==3) {
        ofDrawBitmapString("Mar.", 120, 90);
    }
    if (currentMonth==4) {
        ofDrawBitmapString("Apr.", 120, 90);
    }
    if (currentMonth==5) {
        ofDrawBitmapString("May.", 120, 90);
    }
    if (currentMonth==6) {
        ofDrawBitmapString("Jun.", 120, 90);
    }
    if (currentMonth==7) {
        ofDrawBitmapString("Jul.", 120, 90);
    }
    if (currentMonth==8) {
        ofDrawBitmapString("Aug.", 120, 90);
    }
    if (currentMonth==9) {
        ofDrawBitmapString("Sept.", 120, 90);
    }
    if (currentMonth==10) {
        ofDrawBitmapString("Oct.", 120, 90);
    }
    if (currentMonth==11) {
        ofDrawBitmapString("Nov.", 120, 90);
    }
    if (currentMonth==12) {
        ofDrawBitmapString("Dec.", 120, 90);
    }
    ofDrawBitmapString(currentDate, 155, 90);
    ofDrawBitmapString(currentYear, 180, 90);
    ofDrawBitmapString("Milan, Italy", 120, 120);
    ofDrawBitmapString("current epoch time", 120, 160);
    ofDrawBitmapString(time, 120, 180);
    ofDrawBitmapString("sunrise epoch time", 120, 210);
    ofDrawBitmapString(sunrise, 120, 230);
    ofDrawBitmapString("sunset epoch time", 120, 260);
    ofDrawBitmapString(sunset, 120, 280);
    ofDrawBitmapString("high of today", 120, 310);
    ofDrawBitmapString(high, 120, 330);
    ofDrawBitmapString("low of today", 120, 360);
    ofDrawBitmapString(low, 120, 380);
    ofDrawBitmapString("uvIndex", 120, 410);
    ofDrawBitmapString(uvIndex, 120, 430);
    ofDrawBitmapString(summary, 120, 460);
    ofDrawBitmapString(currentM, 150, 500);
    
    ofSetColor(246, 218, 102);
    ofSetCircleResolution(40);
    if (Sunrise){
        ofDrawCircle((a/day)*ofGetWidth(), 600, 50);
    }
    if (Sunset){
        ofDrawCircle((b/day)*ofGetWidth(), 600, 50);
    }
    gui.draw();
    

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
