#include "ofApp.h"
using namespace std;
ofColor color, cold, hot;
float milanHigh,milanLow,milanCurrent,milanUv;
float minnHigh,minnLow,minnCurrent,minnUv;
float nycHigh, nycLow, nycCurrent,nycUv, nycForlow, nycForhigh;
float ncHigh, ncLow, ncCurrent,ncUv;
float hkgHigh, hkgLow, hkgCurrent, hkgUv;
float x; // x is a constant to transfer to the scale of the screen
bool milan, minneapolis, hkg, nyc, nc;
bool nycX, nycY;
bool nycSign;
float nycAver;
int y;

//--------------------------------------------------------------
void ofApp::setup(){
    std::string urlMilan = "https://api.darksky.net/forecast/352dc2df4f80b08a0b3d0b71250b3b7b/45.4642,9.1900";
    std::string urlMinneapolis = "https://api.darksky.net/forecast/352dc2df4f80b08a0b3d0b71250b3b7b/44.9778,-93.2650";
    std::string urlNyc = "https://api.darksky.net/forecast/352dc2df4f80b08a0b3d0b71250b3b7b/40.7128,-74.0060";
    std::string urlNc = "https://api.darksky.net/forecast/352dc2df4f80b08a0b3d0b71250b3b7b/35.7796,-78.6382";
    std::string urlHkg = "https://api.darksky.net/forecast/352dc2df4f80b08a0b3d0b71250b3b7b/22.3193,114.1694";
    bool milan = jsonMilan.open(urlMilan);
    bool minneapolis = jsonMinn.open(urlMinneapolis);
    bool nyc = jsonNyc.open(urlNyc);
    bool nc = jsonNc.open(urlNc);
    bool hkg = jsonHkg.open(urlHkg);
    nycLow = (((jsonNyc["daily"]["data"][0]["temperatureLow"].asFloat())-32)*5)/9;
    nycHigh = (((jsonNyc["daily"]["data"][0]["temperatureHigh"].asFloat())-32)*5)/9;
    nycCurrent = (((jsonNyc["currently"]["temperature"].asFloat())-32)*5)/9;
    nycUv = jsonNyc["daily"]["data"][0]["uvIndex"].asFloat();
    gui.setup();
    gui.add(tempLow.setup("tempLow",nycLow,-50,50));
    gui.add(tempHigh.setup("tempHigh",nycHigh,-50,50));
    gui.add(tempCurrent.setup("tempCurrent",nycCurrent,-50,50));
    gui.add(uvIndex.setup("uvIndex",nycUv,0,10));

}
//--------------------------------------------------------------

void ofApp::update(){
    x = ofGetScreenWidth()/50;
//    cout << x << endl;
    milanCurrent = (((jsonMilan["currently"]["temperature"].asFloat())-32)*5)/9;
    milanLow = (((jsonMilan["daily"]["data"][y]["temperatureLow"].asFloat())-32)*5)/9;
    milanHigh = (((jsonMilan["daily"]["data"][y]["temperatureHigh"].asFloat())-32)*5)/9;
    milanUv = jsonMilan["daily"]["data"][0]["uvIndex"].asFloat();
    // milan
    minnLow = (((jsonMinn["daily"]["data"][0]["temperatureLow"].asFloat())-32)*5)/9;
    cout << minnLow << endl;
    cout << abs(minnLow)<< endl;
    minnHigh = (((jsonMinn["daily"]["data"][0]["temperatureHigh"].asFloat())-32)*5)/9;
    cout << minnHigh << endl;
    minnCurrent = (((jsonMinn["currently"]["temperature"].asFloat())-32)*5)/9;
    minnUv = jsonMinn["daily"]["data"][0]["uvIndex"].asFloat();
    // minneapolis
    
    nycUv = jsonNyc["daily"]["data"][0]["uvIndex"].asFloat();
    nycAver = abs((tempLow+tempHigh)/100);
    // new york city
    ncLow = (((jsonNc["daily"]["data"][y]["temperatureLow"].asFloat())-32)*5)/9;
    ncHigh = (((jsonNc["daily"]["data"][y]["temperatureHigh"].asFloat())-32)*5)/9;
    ncCurrent = (((jsonNc["currently"]["temperature"].asFloat())-32)*5)/9;
    ncUv = jsonNc["daily"]["data"][0]["uvIndex"].asFloat();
    // north carolina
    hkgLow = (((jsonHkg["daily"]["data"][y]["temperatureLow"].asFloat())-32)*5)/9;
    hkgHigh = (((jsonHkg["daily"]["data"][y]["temperatureHigh"].asFloat())-32)*5)/9;
    hkgCurrent = (((jsonHkg["currently"]["temperature"].asFloat())-32)*5)/9;
    hkgUv = jsonHkg["daily"]["data"][0]["uvIndex"].asFloat();
    // hong kong
    cold = ofColor(0, 0, 255);
    hot = ofColor(234, 37, 77);
}
//-------------------------------------------------------------
void ofApp::draw(){
    ofBackground(255,255,255);
    ofSetColor(122, 122, 122);
    for (float g = 0.2; g < 1.2; g += 0.2) {
        ofDrawRectangle(0, g*ofGetScreenHeight(), ofGetScreenWidth(), 0.5);
        ofDrawRectangle(g*ofGetScreenWidth(), 0, 0.5, ofGetScreenHeight());
        ofDrawRectangle((g-0.1)*ofGetScreenWidth(), 0, 0.2, ofGetScreenHeight());
    }
//    ofSetColor(0, 0, 0);
//    ofDrawRectangle(ofGetScreenWidth()/2-35, 0.02*ofGetScreenHeight()-5, 70, 30);
    ofSetColor(255, 0, 0, 255*(uvIndex/10));
    ofDrawBitmapString("New York", ofGetScreenWidth()/2-30,  0.02*ofGetScreenHeight()); //NYC
    if (tempLow > 0 && tempHigh > 0) {
        color = hot;
        ofSetColor(color,255*nycAver);
        ofDrawRectangle(tempLow*x, 0.06*ofGetScreenHeight(), (tempHigh-tempLow)*x, 4);
        ofSetColor(color,255*(tempCurrent/50));
        ofDrawCircle(tempCurrent*x, 0.06*ofGetScreenHeight(), 3);
    }
    if (tempHigh < 0 && tempLow < 0) {
        color = cold;
        ofSetColor(color,255*nycAver);
        ofTranslate(ofGetScreenWidth(), 0);
        ofDrawRectangle(tempLow*x, 0.06*ofGetScreenHeight(), (abs(tempHigh-tempLow))*x, 4);
        ofSetColor(color,255*abs(tempCurrent/50));
        ofDrawCircle(tempCurrent*x, 0.06*ofGetScreenHeight(), 3);
    }
    if (tempHigh >= 0 && tempLow <= 0) {
        ofSetColor(hot,(tempHigh/50)*255);
        ofDrawRectangle(0, 0.06*ofGetScreenHeight(), tempHigh*x, 4);
        ofSetColor(cold, ((abs(tempLow))/50)*255);
        ofDrawRectangle(ofGetScreenWidth()-(abs(tempLow))*x, 0.06*ofGetScreenHeight(), (abs(tempLow))*x, 4);
        if (tempCurrent == 0) {
            ofSetColor(127, 127, 127);
            ofDrawCircle(0, 0.06*ofGetScreenHeight(), 3);
            ofDrawCircle(ofGetScreenWidth(), 0.06*ofGetScreenHeight(), 3);
        }else if (tempCurrent > 0) {
            ofSetColor(hot,255*(tempCurrent/50));
            ofDrawCircle(tempCurrent*x, 0.06*ofGetScreenHeight(), 3);
        }else if (tempCurrent < 0) {
            ofSetColor(cold,255*(tempCurrent/50));
            ofTranslate(ofGetScreenWidth(), 0);
            ofDrawCircle(tempCurrent*x, 0.06*ofGetScreenHeight(), 3);
        }
    }
    float nycForecast [5] [2] = {
        {(((jsonNyc["daily"]["data"][1]["temperatureLow"].asFloat())-32)*5)/9,(((jsonNyc["daily"]["data"][1]["temperatureHigh"].asFloat())-32)*5)/9},
        {(((jsonNyc["daily"]["data"][2]["temperatureLow"].asFloat())-32)*5)/9,(((jsonNyc["daily"]["data"][2]["temperatureHigh"].asFloat())-32)*5)/9},
        {(((jsonNyc["daily"]["data"][3]["temperatureLow"].asFloat())-32)*5)/9,(((jsonNyc["daily"]["data"][3]["temperatureHigh"].asFloat())-32)*5)/9},
        {(((jsonNyc["daily"]["data"][4]["temperatureLow"].asFloat())-32)*5)/9,(((jsonNyc["daily"]["data"][4]["temperatureHigh"].asFloat())-32)*5)/9},
        {(((jsonNyc["daily"]["data"][5]["temperatureLow"].asFloat())-32)*5)/9,(((jsonNyc["daily"]["data"][5]["temperatureHigh"].asFloat())-32)*5)/9}
    };
    
    for (int u = 0; u < 5; u++) {
        float nycFor = abs((nycForecast[u][0]+nycForecast[u][1])/100);
        float z=0.1;
        if (u == 0) {
            z = 0.1;
        } else if (u == 1){
            z = 0.12;
        } else if (u == 2){
            z = 0.14;
        } else if (u == 3){
            z = 0.16;
        } else if (u == 4){
            z = 0.18;
        }
        if (nycForecast[u][0] > 0 && nycForecast[u][1]>0) {
            color = hot;
            ofSetColor(color,255*nycFor);
            ofDrawRectangle(nycForecast[u][0]*x, z*ofGetScreenHeight(), (nycForecast[u][1]-nycForecast[u][0])*x, 2);
        }else if (nycForecast[u][0] < 0 && nycForecast[u][1]<0){
            color = cold;
            ofSetColor(color,255*nycFor);
            ofTranslate(ofGetScreenWidth(), 0);
            ofDrawRectangle(nycForecast[u][0]*x, z*ofGetScreenHeight(), (abs(nycForecast[u][0]-nycForecast[u][1]))*x, 2);
        }else if (nycForecast[u][1]>= 0 && nycForecast[u][0] <= 0){
            ofSetColor(hot,(nycForecast[u][1]/50)*255);
            ofDrawRectangle(0, z*ofGetScreenHeight(), nycForecast[u][1]*x, 2);
            ofSetColor(cold, ((abs(nycForecast[u][0]))/50)*255);
            ofDrawRectangle(ofGetScreenWidth()-(abs(nycForecast[u][0]))*x, z*ofGetScreenHeight(), (abs(nycForecast[u][0]))*x, 2);
        }
    }
    if (nycX && nycY) {
        ofSetColor(0, 255, 255);
//        ofDrawRectangle(<#float x1#>, <#float y1#>, <#float w#>, <#float h#>
        std::string summary = jsonNyc["daily"]["data"][0]["summary"].asString();
        ofDrawBitmapString(summary, 250, 250); // change the position
    }
    float ncAver =abs((ncHigh+ncLow)/100);
    ofSetColor(hot, 255*(ncUv/10));
    ofDrawBitmapString("Raleigh", ofGetScreenWidth()/2-28,  0.22*ofGetScreenHeight()); //NC
    if (ncLow > 0 && ncHigh > 0) {
        color = hot;
        ofSetColor(color,255*ncAver);
        ofDrawRectangle(ncLow*x, 0.26*ofGetScreenHeight(), (ncHigh-ncLow)*x, 4);
        ofSetColor(color,255*(ncCurrent/50));
        ofDrawCircle(ncCurrent*x, 0.26*ofGetScreenHeight(), 3);
    }
    if (ncHigh < 0 && ncLow < 0) {
        color = cold;
        ofSetColor(color,255*ncAver);
        ofTranslate(ofGetScreenWidth(), 0);
        ofDrawRectangle(ncLow*x, 0.26*ofGetScreenHeight(), (abs(ncHigh-ncLow))*x, 4);
        ofSetColor(color,255*(abs(ncCurrent)/50));
        ofDrawCircle(ncCurrent*x, 0.26*ofGetScreenHeight(), 3);
    }
    if (ncHigh >= 0 && ncLow <= 0) {
        ofSetColor(hot,(ncHigh/50)*255);
        ofDrawRectangle(0, 0.26*ofGetScreenHeight(), ncHigh*x, 4);
        ofSetColor(cold, ((abs(ncLow))/50)*255);
        ofDrawRectangle(ofGetScreenWidth()-(abs(ncLow))*x, 0.26*ofGetScreenHeight(), (abs(ncLow))*x, 4);
        if (ncCurrent == 0) {
            ofSetColor(127, 127, 127);
            ofDrawCircle(0, 0.26*ofGetScreenHeight(), 3);
            ofDrawCircle(ofGetScreenWidth(), 0.26*ofGetScreenHeight(), 3);
        }else if (ncCurrent > 0) {
            ofSetColor(hot,255*(ncCurrent/50));
            ofDrawCircle(ncCurrent*x, 0.26*ofGetScreenHeight(), 3);
        }else if (ncCurrent < 0) {
            ofSetColor(cold,255*(ncCurrent/50));
            ofTranslate(ofGetScreenWidth(), 0);
            ofDrawCircle(ncCurrent*x, 0.26*ofGetScreenHeight(), 3);
        }
    }
    float ncForecast [5] [2] = {
        {(((jsonNc["daily"]["data"][1]["temperatureLow"].asFloat())-32)*5)/9,(((jsonNc["daily"]["data"][1]["temperatureHigh"].asFloat())-32)*5)/9},
        {(((jsonNc["daily"]["data"][2]["temperatureLow"].asFloat())-32)*5)/9,(((jsonNc["daily"]["data"][2]["temperatureHigh"].asFloat())-32)*5)/9},
        {(((jsonNc["daily"]["data"][3]["temperatureLow"].asFloat())-32)*5)/9,(((jsonNc["daily"]["data"][3]["temperatureHigh"].asFloat())-32)*5)/9},
        {(((jsonNc["daily"]["data"][4]["temperatureLow"].asFloat())-32)*5)/9,(((jsonNc["daily"]["data"][4]["temperatureHigh"].asFloat())-32)*5)/9},
        {(((jsonNc["daily"]["data"][5]["temperatureLow"].asFloat())-32)*5)/9,(((jsonNc["daily"]["data"][5]["temperatureHigh"].asFloat())-32)*5)/9}
    };
    
    for (int w = 0; w < 5; w++) {
        float ncFor = abs((ncForecast[w][0]+ncForecast[w][1])/100);
        float u=0.3;
        if (w == 0) {
            u = 0.3;
        } else if (w == 1){
            u = 0.32;
        } else if (w == 2){
            u = 0.34;
        } else if (w == 3){
            u = 0.36;
        } else if (w == 4){
            u = 0.38;
        }
        if (ncForecast[w][0] > 0 && ncForecast[w][1]>0) {
            color = hot;
            ofSetColor(color,255*ncFor);
            ofDrawRectangle(ncForecast[w][0]*x, u*ofGetScreenHeight(), (ncForecast[w][1]-ncForecast[w][0])*x, 2);
        }else if (ncForecast[w][0] < 0 && ncForecast[w][1]<0){
            color = cold;
            ofSetColor(color,255*ncFor);
            ofTranslate(ofGetScreenWidth(), 0);
            ofDrawRectangle(ncForecast[w][0]*x, u*ofGetScreenHeight(), (abs(ncForecast[w][0]-ncForecast[w][1]))*x, 2);
        }else if (ncForecast[w][1]>= 0 && ncForecast[w][0] <= 0){
            ofSetColor(hot,(ncForecast[w][1]/50)*255);
            ofDrawRectangle(0, u*ofGetScreenHeight(), ncForecast[w][1]*x, 2);
            ofSetColor(cold, ((abs(ncForecast[w][0]))/50)*255);
            ofDrawRectangle(ofGetScreenWidth()-(abs(ncForecast[w][0]))*x, u*ofGetScreenHeight(), (abs(ncForecast[w][0]))*x, 2);
        }
    }

    float hkgAver =abs((hkgHigh+hkgLow)/100);
        color = hot;
        ofSetColor(color,255*hkgAver);
        ofDrawRectangle(hkgLow*x, 0.46*ofGetScreenHeight(), (hkgHigh-hkgLow)*x, 4);
        ofSetColor(color,255*(hkgCurrent/50));
        ofDrawCircle(hkgCurrent*x, 0.46*ofGetScreenHeight(), 3);
        ofSetColor(hot, 255*(hkgUv/10));
        ofDrawBitmapString("Hong Kong", ofGetScreenWidth()/2-36,  0.42*ofGetScreenHeight()); //Twin cities

    // It is IMPOSSIBLE that Hong Kong is below 0 degree.

    float hkgForecast [5] [2] = {
        {(((jsonHkg["daily"]["data"][1]["temperatureLow"].asFloat())-32)*5)/9,(((jsonHkg["daily"]["data"][1]["temperatureHigh"].asFloat())-32)*5)/9},
        {(((jsonHkg["daily"]["data"][2]["temperatureLow"].asFloat())-32)*5)/9,(((jsonHkg["daily"]["data"][2]["temperatureHigh"].asFloat())-32)*5)/9},
        {(((jsonHkg["daily"]["data"][3]["temperatureLow"].asFloat())-32)*5)/9,(((jsonHkg["daily"]["data"][3]["temperatureHigh"].asFloat())-32)*5)/9},
        {(((jsonHkg["daily"]["data"][4]["temperatureLow"].asFloat())-32)*5)/9,(((jsonHkg["daily"]["data"][4]["temperatureHigh"].asFloat())-32)*5)/9},
        {(((jsonHkg["daily"]["data"][5]["temperatureLow"].asFloat())-32)*5)/9,(((jsonHkg["daily"]["data"][5]["temperatureHigh"].asFloat())-32)*5)/9}
    };
    
    for (int e = 0; e < 5; e++) {
        float hkgFor = abs((hkgForecast[e][0]+hkgForecast[e][1])/100);
        float f=0.5;
        if (e == 0) {
            f = 0.5;
        } else if (e == 1){
            f = 0.52;
        } else if (e == 2){
            f = 0.54;
        } else if (e == 3){
            f = 0.56;
        } else if (e == 4){
            f = 0.58;
        }
        if (hkgForecast[e][0] > 0 && hkgForecast[e][1]>0) {
            color = hot;
            ofSetColor(color,255*hkgFor);
            ofDrawRectangle(hkgForecast[e][0]*x, f*ofGetScreenHeight(), (hkgForecast[e][1]-hkgForecast[e][0])*x, 2);
        }
    }
    
    float milanAver =abs((milanHigh+milanLow)/100);
    ofSetColor(hot, 255*(milanUv/10));
    ofDrawBitmapString("Milan", ofGetScreenWidth()/2-18,  0.62*ofGetScreenHeight()); //MILANO
    if (milanLow > 0 && milanHigh > 0) {
        color = hot;
        ofSetColor(color,255*milanAver);
        ofDrawRectangle(milanLow*x, 0.66*ofGetScreenHeight(), (milanHigh-minnLow)*x, 4);
        ofSetColor(color,255*(milanCurrent/50));
        ofDrawCircle(milanCurrent*x, 0.66*ofGetScreenHeight(), 3);
    }
    if (milanHigh < 0 && milanLow < 0) {
        color = cold;
        ofSetColor(color,255*milanAver);
        ofTranslate(ofGetScreenWidth(), 0);
        ofDrawRectangle(milanLow*x, 0.66*ofGetScreenHeight(), (abs(milanHigh-milanLow))*x, 4);
        ofSetColor(color,255*(abs(milanCurrent)/50));
        ofDrawCircle(milanCurrent*x, 0.66*ofGetScreenHeight(), 3);
    }
    if (milanHigh >= 0 && milanLow <= 0) {
        ofSetColor(hot,(milanHigh/50)*255);
        ofDrawRectangle(0, 0.66*ofGetScreenHeight(), milanHigh*x, 4);
        ofSetColor(cold, ((abs(milanLow))/50)*255);
        ofDrawRectangle(ofGetScreenWidth()-(abs(milanLow))*x, 0.66*ofGetScreenHeight(), (abs(milanLow))*x, 4);
        if (milanCurrent == 0) {
            ofSetColor(127, 127, 127);
            ofDrawCircle(0, 0.66*ofGetScreenHeight(), 3);
            ofDrawCircle(ofGetScreenWidth(), 0.66*ofGetScreenHeight(), 3);
        }else if (milanCurrent > 0) {
            ofSetColor(hot,255*(ncCurrent/50));
            ofDrawCircle(ncCurrent*x, 0.66*ofGetScreenHeight(), 3);
        }else if (milanCurrent < 0) {
            ofSetColor(cold,255*(ncCurrent/50));
            ofTranslate(ofGetScreenWidth(), 0);
            ofDrawCircle(milanCurrent*x, 0.66*ofGetScreenHeight(), 3);
        }
    }
    float milanForecast [5] [2] = {
        {(((jsonMilan["daily"]["data"][1]["temperatureLow"].asFloat())-32)*5)/9,(((jsonMilan["daily"]["data"][1]["temperatureHigh"].asFloat())-32)*5)/9},
        {(((jsonMilan["daily"]["data"][2]["temperatureLow"].asFloat())-32)*5)/9,(((jsonMilan["daily"]["data"][2]["temperatureHigh"].asFloat())-32)*5)/9},
        {(((jsonMilan["daily"]["data"][3]["temperatureLow"].asFloat())-32)*5)/9,(((jsonMilan["daily"]["data"][3]["temperatureHigh"].asFloat())-32)*5)/9},
        {(((jsonMilan["daily"]["data"][4]["temperatureLow"].asFloat())-32)*5)/9,(((jsonMilan["daily"]["data"][4]["temperatureHigh"].asFloat())-32)*5)/9},
        {(((jsonMilan["daily"]["data"][5]["temperatureLow"].asFloat())-32)*5)/9,(((jsonMilan["daily"]["data"][5]["temperatureHigh"].asFloat())-32)*5)/9}
    };
    
    for (int c = 0; c < 5; c++) {
        float milanFor = abs((milanForecast[c][0]+milanForecast[c][1])/100);
        float d=0.7;
        if (c == 0) {
            d = 0.7;
        } else if (c == 1){
            d = 0.72;
        } else if (c == 2){
            d = 0.74;
        } else if (c == 3){
            d = 0.76;
        } else if (c == 4){
            d = 0.78;
        }
        if (milanForecast[c][0] > 0 && milanForecast[c][1]>0) {
            color = hot;
            ofSetColor(color,255*milanFor);
            ofDrawRectangle(milanForecast[c][0]*x, d*ofGetScreenHeight(), (milanForecast[c][1]-milanForecast[c][0])*x, 2);
        }else if (milanForecast[c][0] < 0 && milanForecast[c][1]<0){
            color = cold;
            ofSetColor(color,255*milanFor);
            ofTranslate(ofGetScreenWidth(), 0);
            ofDrawRectangle(milanForecast[c][0]*x, d*ofGetScreenHeight(), (abs(milanForecast[c][0]-milanForecast[c][1]))*x, 2);
        }else if (milanForecast[c][1]>= 0 && milanForecast[c][0] <= 0){
            ofSetColor(hot,(milanForecast[c][1]/50)*255);
            ofDrawRectangle(0, d*ofGetScreenHeight(), milanForecast[c][1]*x, 2);
            ofSetColor(cold, ((abs(milanForecast[c][0]))/50)*255);
            ofDrawRectangle(ofGetScreenWidth()-(abs(milanForecast[c][0]))*x, d*ofGetScreenHeight(), (abs(milanForecast[c][0]))*x, 2);
        }
    }
    float minnAver =abs((minnHigh+minnLow)/100);
    ofSetColor(hot, 255*(minnUv/10));
    ofDrawBitmapString("Minneapolis", ofGetScreenWidth()/2-44,  0.82*ofGetScreenHeight()); //Twin cities
    if (minnLow > 0 && minnHigh > 0) {
        color = hot;
        ofSetColor(color,255*minnAver);
        ofDrawRectangle(minnLow*x, 0.86*ofGetScreenHeight(), (minnHigh-minnLow)*x, 4);
        ofSetColor(color,255*(minnCurrent/50));
        ofDrawCircle(minnCurrent*x, 0.86*ofGetScreenHeight(), 3);
    }
    if (minnHigh < 0 && minnLow < 0) {
        color = cold;
        ofSetColor(color,255*minnAver);
        ofTranslate(ofGetScreenWidth(), 0);
        ofDrawRectangle(minnLow*x, 0.86*ofGetScreenHeight(), (abs(minnHigh-minnLow))*x, 4);
        ofSetColor(color,255*(abs(minnCurrent)/50));
        ofDrawCircle(minnCurrent*x, 0.86*ofGetScreenHeight(), 3);
    }
    if (minnHigh >= 0 && minnLow <= 0) {
        ofSetColor(hot,(minnHigh/50)*255);
        ofDrawRectangle(0, 0.86*ofGetScreenHeight(), minnHigh*x, 4);
        ofSetColor(cold, ((abs(minnLow))/50)*255);
        ofDrawRectangle(ofGetScreenWidth()-(abs(minnLow))*x, 0.86*ofGetScreenHeight(), (abs(minnLow))*x, 4);
        if (minnCurrent == 0) {
            ofSetColor(127, 127, 127);
            ofDrawCircle(0, 0.86*ofGetScreenHeight(), 3);
            ofDrawCircle(ofGetScreenWidth(), 0.86*ofGetScreenHeight(), 3);
        }else if (minnCurrent > 0) {
            ofSetColor(hot,255*(minnCurrent/50));
            ofDrawCircle(minnCurrent*x, 0.86*ofGetScreenHeight(), 3);
        }else if (ncCurrent < 0) {
            ofSetColor(cold,255*(minnCurrent/50));
            ofTranslate(ofGetScreenWidth(), 0);
            ofDrawCircle(minnCurrent*x, 0.86*ofGetScreenHeight(), 3);
        }
    }
    float minnForecast [5] [2] = {
        {(((jsonMinn["daily"]["data"][1]["temperatureLow"].asFloat())-32)*5)/9,(((jsonMinn["daily"]["data"][1]["temperatureHigh"].asFloat())-32)*5)/9},
        {(((jsonMinn["daily"]["data"][2]["temperatureLow"].asFloat())-32)*5)/9,(((jsonMinn["daily"]["data"][2]["temperatureHigh"].asFloat())-32)*5)/9},
        {(((jsonMinn["daily"]["data"][3]["temperatureLow"].asFloat())-32)*5)/9,(((jsonMinn["daily"]["data"][3]["temperatureHigh"].asFloat())-32)*5)/9},
        {(((jsonMinn["daily"]["data"][4]["temperatureLow"].asFloat())-32)*5)/9,(((jsonMinn["daily"]["data"][4]["temperatureHigh"].asFloat())-32)*5)/9},
        {(((jsonMinn["daily"]["data"][5]["temperatureLow"].asFloat())-32)*5)/9,(((jsonMinn["daily"]["data"][5]["temperatureHigh"].asFloat())-32)*5)/9}
    };
    
    for (int a = 0; a < 5; a++) {
        float minnFor = abs((minnForecast[a][0]+minnForecast[a][1])/100);
        float b=0.9;
        if (a == 0) {
            b = 0.9;
        } else if (a == 1){
            b = 0.92;
        } else if (a == 2){
            b = 0.94;
        } else if (a == 3){
            b = 0.96;
        } else if (a == 4){
            b = 0.98;
        }
        if (minnForecast[a][0] > 0 && minnForecast[a][1]>0) {
            color = hot;
            ofSetColor(color,255*minnFor);
            ofDrawRectangle(minnForecast[a][0]*x, b*ofGetScreenHeight(), (minnForecast[a][1]-minnForecast[a][0])*x, 2);
        }else if (minnForecast[a][0] < 0 && minnForecast[a][1]<0){
            color = cold;
            ofSetColor(color,255*minnFor);
            ofTranslate(ofGetScreenWidth(), 0);
            ofDrawRectangle(minnForecast[a][0]*x, b*ofGetScreenHeight(), (abs(minnForecast[a][0]-minnForecast[a][1]))*x, 2);
        }else if (minnForecast[a][1]>= 0 && minnForecast[a][0] <= 0){
            ofSetColor(hot,(minnForecast[a][1]/50)*255);
            ofDrawRectangle(0, b*ofGetScreenHeight(), minnForecast[a][1]*x, 2);
            ofSetColor(cold, ((abs(minnForecast[a][0]))/50)*255);
            ofDrawRectangle(ofGetScreenWidth()-(abs(minnForecast[a][0]))*x, b*ofGetScreenHeight(), (abs(minnForecast[a][0]))*x, 2);
        }
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
    if ( button >= ofGetScreenWidth()/2-35 && button <= ofGetScreenWidth()/2+35) nycX = true;
    
    if ( y >= ofGetScreenWidth()/2-35 && y <= ofGetScreenWidth()/2+35) nycY = true;
    
//            ofDrawRectangle(ofGetScreenWidth()/2-35, 0.02*ofGetScreenHeight()-5, 70, 30);
    
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
