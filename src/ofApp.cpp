#include "ofApp.h"

//#pragma mark - Setups
//--------------------------------------------------------------
void ofApp::setupColors()
{
    colorsArray.push_back(RED_1);
    colorsArray.push_back(RED_2);
    colorsArray.push_back(RED_3);
    colorsArray.push_back(RED_4);
    
    colorsArray.push_back(GREEN_1);
    colorsArray.push_back(GREEN_2);
    colorsArray.push_back(GREEN_3);
    colorsArray.push_back(GREEN_4);
    
    colorsArray.push_back(BLUE_1);
    colorsArray.push_back(BLUE_2);
    colorsArray.push_back(BLUE_3);
    colorsArray.push_back(BLUE_4);
    
    colorsArray.push_back(WHITE);
    colorsArray.push_back(OFF);
}
//--------------------------------------------------------------
void ofApp::openConfig(string configFile)
{
    bool isOpen = config.open(configFile);
    
    if (!isOpen) {
        cout << "File Not Opened" << endl;
        return;
    }
    
    RED_1 = ofColor(config["colors"][0]["red1"]["r"].asInt(),config["colors"][0]["red1"]["g"].asInt(),config["colors"][0]["red1"]["b"].asInt());
    
    RED_2 = ofColor(config["colors"][1]["red2"]["r"].asInt(),config["colors"][1]["red2"]["g"].asInt(),config["colors"][1]["red2"]["b"].asInt());
    
    RED_3 = ofColor(config["colors"][2]["red3"]["r"].asInt(),config["colors"][2]["red3"]["g"].asInt(),config["colors"][2]["red3"]["b"].asInt());
    
    RED_4 = ofColor(config["colors"][3]["red4"]["r"].asInt(),config["colors"][3]["red4"]["g"].asInt(),config["colors"][3]["red4"]["b"].asInt());
    
    GREEN_1 = ofColor(config["colors"][4]["green1"]["r"].asInt(),config["colors"][4]["green1"]["g"].asInt(),config["colors"][4]["green1"]["b"].asInt());
    
    GREEN_2 = ofColor(config["colors"][5]["green2"]["r"].asInt(),config["colors"][5]["green2"]["g"].asInt(),config["colors"][5]["green2"]["b"].asInt());
    
    GREEN_3 = ofColor(config["colors"][6]["green3"]["r"].asInt(),config["colors"][6]["green3"]["g"].asInt(),config["colors"][6]["green3"]["b"].asInt());
    
    GREEN_4 = ofColor(config["colors"][7]["green4"]["r"].asInt(),config["colors"][7]["green4"]["g"].asInt(),config["colors"][7]["green4"]["b"].asInt());
    
    BLUE_1 = ofColor(config["colors"][8]["blue1"]["r"].asInt(),config["colors"][8]["blue1"]["g"].asInt(),config["colors"][8]["blue1"]["b"].asInt());
    
    BLUE_2 = ofColor(config["colors"][9]["blue2"]["r"].asInt(),config["colors"][9]["blue2"]["g"].asInt(),config["colors"][9]["blue2"]["b"].asInt());
    
    BLUE_3 = ofColor(config["colors"][10]["blue3"]["r"].asInt(),config["colors"][10]["blue3"]["g"].asInt(),config["colors"][10]["blue3"]["b"].asInt());
    
    BLUE_4 = ofColor(config["colors"][11]["blue4"]["r"].asInt(),config["colors"][11]["blue4"]["g"].asInt(),config["colors"][11]["blue4"]["b"].asInt());
    
    
    
    WHITE = ofColor(255,255,255);
    OFF = ofColor(0,0,0);
    
}
//--------------------------------------------------------------
void ofApp::setupDMX(string device)
{
    enttecBox.connect(device);
    if (!enttecBox.isConnected()) {
        cout << "DMX not connected" << endl;
        dmxConnected = false;
    }
    else {
        dmxConnected = true;
        cout << "DMX connected: " << device << endl;
    }
}
//--------------------------------------------------------------
void ofApp::setupTestSequence()
{
    testSequence.push_back("#"+ofToString(ALL_OFF));
    testSequence.push_back("#"+ofToString(T1_ON_R1));
    testSequence.push_back("#"+ofToString(T1_ON_R1)+","+ofToString(T2_ON_R1));
    testSequence.push_back("#"+ofToString(T1_ON_R1)+","+ofToString(T2_ON_R1)+","+ofToString(T3_ON_R1));
    testSequence.push_back("#"+ofToString(T1_ON_R1)+","+ofToString(T2_ON_R1)+","+ofToString(T3_ON_R1)+","+ofToString(T4_ON_R1));
    testSequence.push_back("#"+ofToString(T1_ON_R1)+","+ofToString(T2_ON_R1)+","+ofToString(T3_ON_R1)+","+ofToString(T4_ON_R1)+","+ofToString(T5_ON_R1));
    testSequence.push_back("#"+ofToString(T1_ON_R1)+","+ofToString(T2_ON_R1)+","+ofToString(T3_ON_R1)+","+ofToString(T4_ON_R1)+","+ofToString(T5_ON_R1)+","+ofToString(T6_ON_R1));
    testSequence.push_back("#"+ofToString(T1_ON_R1)+","+ofToString(T2_ON_R1)+","+ofToString(T3_ON_R1)+","+ofToString(T4_ON_R1)+","+ofToString(T5_ON_R1)+","+ofToString(T6_ON_R1)+","+ofToString(T7_ON_R1));
    testSequence.push_back("#"+ofToString(T1_ON_R1)+","+ofToString(T2_ON_R1)+","+ofToString(T3_ON_R1)+","+ofToString(T4_ON_R1)+","+ofToString(T5_ON_R1)+","+ofToString(T6_ON_R1)+","+ofToString(T7_ON_R1)+","+ofToString(T8_ON_R1));
    
    testSequence.push_back("#"+ofToString(T1_ON_G1));
    testSequence.push_back("#"+ofToString(T1_ON_G1)+","+ofToString(T2_ON_G1));
    testSequence.push_back("#"+ofToString(T1_ON_G1)+","+ofToString(T2_ON_G1)+","+ofToString(T3_ON_G1));
    testSequence.push_back("#"+ofToString(T1_ON_G1)+","+ofToString(T2_ON_G1)+","+ofToString(T3_ON_G1)+","+ofToString(T4_ON_G1));
    testSequence.push_back("#"+ofToString(T1_ON_G1)+","+ofToString(T2_ON_G1)+","+ofToString(T3_ON_G1)+","+ofToString(T4_ON_G1)+","+ofToString(T5_ON_G1));
    testSequence.push_back("#"+ofToString(T1_ON_G1)+","+ofToString(T2_ON_G1)+","+ofToString(T3_ON_G1)+","+ofToString(T4_ON_G1)+","+ofToString(T5_ON_G1)+","+ofToString(T6_ON_G1));
    testSequence.push_back("#"+ofToString(T1_ON_G1)+","+ofToString(T2_ON_G1)+","+ofToString(T3_ON_G1)+","+ofToString(T4_ON_G1)+","+ofToString(T5_ON_G1)+","+ofToString(T6_ON_G1)+","+ofToString(T7_ON_G1));
    testSequence.push_back("#"+ofToString(T1_ON_G1)+","+ofToString(T2_ON_G1)+","+ofToString(T3_ON_G1)+","+ofToString(T4_ON_G1)+","+ofToString(T5_ON_G1)+","+ofToString(T6_ON_G1)+","+ofToString(T7_ON_G1)+","+ofToString(T8_ON_G1));
    
    testSequence.push_back("#"+ofToString(T1_ON_B1));
    testSequence.push_back("#"+ofToString(T1_ON_B1)+","+ofToString(T2_ON_B1));
    testSequence.push_back("#"+ofToString(T1_ON_B1)+","+ofToString(T2_ON_B1)+","+ofToString(T3_ON_B1));
    testSequence.push_back("#"+ofToString(T1_ON_B1)+","+ofToString(T2_ON_B1)+","+ofToString(T3_ON_B1)+","+ofToString(T4_ON_B1));
    testSequence.push_back("#"+ofToString(T1_ON_B1)+","+ofToString(T2_ON_B1)+","+ofToString(T3_ON_B1)+","+ofToString(T4_ON_B1)+","+ofToString(T5_ON_B1));
    testSequence.push_back("#"+ofToString(T1_ON_B1)+","+ofToString(T2_ON_B1)+","+ofToString(T3_ON_B1)+","+ofToString(T4_ON_B1)+","+ofToString(T5_ON_B1)+","+ofToString(T6_ON_B1));
    testSequence.push_back("#"+ofToString(T1_ON_B1)+","+ofToString(T2_ON_B1)+","+ofToString(T3_ON_B1)+","+ofToString(T4_ON_B1)+","+ofToString(T5_ON_B1)+","+ofToString(T6_ON_B1)+","+ofToString(T7_ON_B1));
    testSequence.push_back("#"+ofToString(T1_ON_B1)+","+ofToString(T2_ON_B1)+","+ofToString(T3_ON_B1)+","+ofToString(T4_ON_B1)+","+ofToString(T5_ON_B1)+","+ofToString(T6_ON_B1)+","+ofToString(T7_ON_B1)+","+ofToString(T8_ON_B1));
    
    testSequence.push_back("#"+ofToString(T1_ON_R2));
    testSequence.push_back("#"+ofToString(T1_ON_R2)+","+ofToString(T2_ON_R2));
    testSequence.push_back("#"+ofToString(T1_ON_R2)+","+ofToString(T2_ON_R2)+","+ofToString(T3_ON_R2));
    testSequence.push_back("#"+ofToString(T1_ON_R2)+","+ofToString(T2_ON_R2)+","+ofToString(T3_ON_R2)+","+ofToString(T4_ON_R2));
    testSequence.push_back("#"+ofToString(T1_ON_R2)+","+ofToString(T2_ON_R2)+","+ofToString(T3_ON_R2)+","+ofToString(T4_ON_R2)+","+ofToString(T5_ON_R2));
    testSequence.push_back("#"+ofToString(T1_ON_R2)+","+ofToString(T2_ON_R2)+","+ofToString(T3_ON_R2)+","+ofToString(T4_ON_R2)+","+ofToString(T5_ON_R2)+","+ofToString(T6_ON_R2));
    testSequence.push_back("#"+ofToString(T1_ON_R2)+","+ofToString(T2_ON_R2)+","+ofToString(T3_ON_R2)+","+ofToString(T4_ON_R2)+","+ofToString(T5_ON_R2)+","+ofToString(T6_ON_R2)+","+ofToString(T7_ON_R2));
    testSequence.push_back("#"+ofToString(T1_ON_R2)+","+ofToString(T2_ON_R2)+","+ofToString(T3_ON_R2)+","+ofToString(T4_ON_R2)+","+ofToString(T5_ON_R2)+","+ofToString(T6_ON_R2)+","+ofToString(T7_ON_R2)+","+ofToString(T8_ON_R2));
    
    testSequence.push_back("#"+ofToString(T1_ON_G2));
    testSequence.push_back("#"+ofToString(T1_ON_G2)+","+ofToString(T2_ON_G2));
    testSequence.push_back("#"+ofToString(T1_ON_G2)+","+ofToString(T2_ON_G2)+","+ofToString(T3_ON_G2));
    testSequence.push_back("#"+ofToString(T1_ON_G2)+","+ofToString(T2_ON_G2)+","+ofToString(T3_ON_G2)+","+ofToString(T4_ON_G2));
    testSequence.push_back("#"+ofToString(T1_ON_G2)+","+ofToString(T2_ON_G2)+","+ofToString(T3_ON_G2)+","+ofToString(T4_ON_G2)+","+ofToString(T5_ON_G2));
    testSequence.push_back("#"+ofToString(T1_ON_G2)+","+ofToString(T2_ON_G2)+","+ofToString(T3_ON_G2)+","+ofToString(T4_ON_G2)+","+ofToString(T5_ON_G2)+","+ofToString(T6_ON_G2));
    testSequence.push_back("#"+ofToString(T1_ON_G2)+","+ofToString(T2_ON_G2)+","+ofToString(T3_ON_G2)+","+ofToString(T4_ON_G2)+","+ofToString(T5_ON_G2)+","+ofToString(T6_ON_G2)+","+ofToString(T7_ON_G2));
    testSequence.push_back("#"+ofToString(T1_ON_G2)+","+ofToString(T2_ON_G2)+","+ofToString(T3_ON_G2)+","+ofToString(T4_ON_G2)+","+ofToString(T5_ON_G2)+","+ofToString(T6_ON_G2)+","+ofToString(T7_ON_G2)+","+ofToString(T8_ON_G2));
    
    testSequence.push_back("#"+ofToString(T1_ON_B2));
    testSequence.push_back("#"+ofToString(T1_ON_B2)+","+ofToString(T2_ON_B2));
    testSequence.push_back("#"+ofToString(T1_ON_B2)+","+ofToString(T2_ON_B2)+","+ofToString(T3_ON_B2));
    testSequence.push_back("#"+ofToString(T1_ON_B2)+","+ofToString(T2_ON_B2)+","+ofToString(T3_ON_B2)+","+ofToString(T4_ON_B2));
    testSequence.push_back("#"+ofToString(T1_ON_B2)+","+ofToString(T2_ON_B2)+","+ofToString(T3_ON_B2)+","+ofToString(T4_ON_B2)+","+ofToString(T5_ON_B2));
    testSequence.push_back("#"+ofToString(T1_ON_B2)+","+ofToString(T2_ON_B2)+","+ofToString(T3_ON_B2)+","+ofToString(T4_ON_B2)+","+ofToString(T5_ON_B2)+","+ofToString(T6_ON_B2));
    testSequence.push_back("#"+ofToString(T1_ON_B2)+","+ofToString(T2_ON_B2)+","+ofToString(T3_ON_B2)+","+ofToString(T4_ON_B2)+","+ofToString(T5_ON_B2)+","+ofToString(T6_ON_B2)+","+ofToString(T7_ON_B2));
    testSequence.push_back("#"+ofToString(T1_ON_B2)+","+ofToString(T2_ON_B2)+","+ofToString(T3_ON_B2)+","+ofToString(T4_ON_B2)+","+ofToString(T5_ON_B2)+","+ofToString(T6_ON_B2)+","+ofToString(T7_ON_B2)+","+ofToString(T8_ON_B2));
    
    testSequence.push_back("#"+ofToString(T1_ON_R3));
    testSequence.push_back("#"+ofToString(T1_ON_R3)+","+ofToString(T2_ON_R3));
    testSequence.push_back("#"+ofToString(T1_ON_R3)+","+ofToString(T2_ON_R3)+","+ofToString(T3_ON_R3));
    testSequence.push_back("#"+ofToString(T1_ON_R3)+","+ofToString(T2_ON_R3)+","+ofToString(T3_ON_R3)+","+ofToString(T4_ON_R3));
    testSequence.push_back("#"+ofToString(T1_ON_R3)+","+ofToString(T2_ON_R3)+","+ofToString(T3_ON_R3)+","+ofToString(T4_ON_R3)+","+ofToString(T5_ON_R3));
    testSequence.push_back("#"+ofToString(T1_ON_R3)+","+ofToString(T2_ON_R3)+","+ofToString(T3_ON_R3)+","+ofToString(T4_ON_R3)+","+ofToString(T5_ON_R3)+","+ofToString(T6_ON_R3));
    testSequence.push_back("#"+ofToString(T1_ON_R3)+","+ofToString(T2_ON_R3)+","+ofToString(T3_ON_R3)+","+ofToString(T4_ON_R3)+","+ofToString(T5_ON_R3)+","+ofToString(T6_ON_R3)+","+ofToString(T7_ON_R3));
    testSequence.push_back("#"+ofToString(T1_ON_R3)+","+ofToString(T2_ON_R3)+","+ofToString(T3_ON_R3)+","+ofToString(T4_ON_R3)+","+ofToString(T5_ON_R3)+","+ofToString(T6_ON_R3)+","+ofToString(T7_ON_R3)+","+ofToString(T8_ON_R3));
    
    testSequence.push_back("#"+ofToString(T1_ON_G3));
    testSequence.push_back("#"+ofToString(T1_ON_G3)+","+ofToString(T2_ON_G3));
    testSequence.push_back("#"+ofToString(T1_ON_G3)+","+ofToString(T2_ON_G3)+","+ofToString(T3_ON_G3));
    testSequence.push_back("#"+ofToString(T1_ON_G3)+","+ofToString(T2_ON_G3)+","+ofToString(T3_ON_G3)+","+ofToString(T4_ON_G3));
    testSequence.push_back("#"+ofToString(T1_ON_G3)+","+ofToString(T2_ON_G3)+","+ofToString(T3_ON_G3)+","+ofToString(T4_ON_G3)+","+ofToString(T5_ON_G3));
    testSequence.push_back("#"+ofToString(T1_ON_G3)+","+ofToString(T2_ON_G3)+","+ofToString(T3_ON_G3)+","+ofToString(T4_ON_G3)+","+ofToString(T5_ON_G3)+","+ofToString(T6_ON_G3));
    testSequence.push_back("#"+ofToString(T1_ON_G3)+","+ofToString(T2_ON_G3)+","+ofToString(T3_ON_G3)+","+ofToString(T4_ON_G3)+","+ofToString(T5_ON_G3)+","+ofToString(T6_ON_G3)+","+ofToString(T7_ON_G3));
    testSequence.push_back("#"+ofToString(T1_ON_G3)+","+ofToString(T2_ON_G3)+","+ofToString(T3_ON_G3)+","+ofToString(T4_ON_G3)+","+ofToString(T5_ON_G3)+","+ofToString(T6_ON_G3)+","+ofToString(T7_ON_G3)+","+ofToString(T8_ON_G3));
    
    testSequence.push_back("#"+ofToString(T1_ON_B3));
    testSequence.push_back("#"+ofToString(T1_ON_B3)+","+ofToString(T2_ON_B3));
    testSequence.push_back("#"+ofToString(T1_ON_B3)+","+ofToString(T2_ON_B3)+","+ofToString(T3_ON_B3));
    testSequence.push_back("#"+ofToString(T1_ON_B3)+","+ofToString(T2_ON_B3)+","+ofToString(T3_ON_B3)+","+ofToString(T4_ON_B3));
    testSequence.push_back("#"+ofToString(T1_ON_B3)+","+ofToString(T2_ON_B3)+","+ofToString(T3_ON_B3)+","+ofToString(T4_ON_B3)+","+ofToString(T5_ON_B3));
    testSequence.push_back("#"+ofToString(T1_ON_B3)+","+ofToString(T2_ON_B3)+","+ofToString(T3_ON_B3)+","+ofToString(T4_ON_B3)+","+ofToString(T5_ON_B3)+","+ofToString(T6_ON_B3));
    testSequence.push_back("#"+ofToString(T1_ON_B3)+","+ofToString(T2_ON_B3)+","+ofToString(T3_ON_B3)+","+ofToString(T4_ON_B3)+","+ofToString(T5_ON_B3)+","+ofToString(T6_ON_B3)+","+ofToString(T7_ON_B3));
    testSequence.push_back("#"+ofToString(T1_ON_B3)+","+ofToString(T2_ON_B3)+","+ofToString(T3_ON_B3)+","+ofToString(T4_ON_B3)+","+ofToString(T5_ON_B3)+","+ofToString(T6_ON_B3)+","+ofToString(T7_ON_B3)+","+ofToString(T8_ON_B3));
    
    testSequence.push_back("#"+ofToString(T1_ON_R4));
    testSequence.push_back("#"+ofToString(T1_ON_R4)+","+ofToString(T2_ON_R4));
    testSequence.push_back("#"+ofToString(T1_ON_R4)+","+ofToString(T2_ON_R4)+","+ofToString(T3_ON_R4));
    testSequence.push_back("#"+ofToString(T1_ON_R4)+","+ofToString(T2_ON_R4)+","+ofToString(T3_ON_R4)+","+ofToString(T4_ON_R4));
    testSequence.push_back("#"+ofToString(T1_ON_R4)+","+ofToString(T2_ON_R4)+","+ofToString(T3_ON_R4)+","+ofToString(T4_ON_R4)+","+ofToString(T5_ON_R4));
    testSequence.push_back("#"+ofToString(T1_ON_R4)+","+ofToString(T2_ON_R4)+","+ofToString(T3_ON_R4)+","+ofToString(T4_ON_R4)+","+ofToString(T5_ON_R4)+","+ofToString(T6_ON_R4));
    testSequence.push_back("#"+ofToString(T1_ON_R4)+","+ofToString(T2_ON_R4)+","+ofToString(T3_ON_R4)+","+ofToString(T4_ON_R4)+","+ofToString(T5_ON_R4)+","+ofToString(T6_ON_R4)+","+ofToString(T7_ON_R4));
    testSequence.push_back("#"+ofToString(T1_ON_R4)+","+ofToString(T2_ON_R4)+","+ofToString(T3_ON_R4)+","+ofToString(T4_ON_R4)+","+ofToString(T5_ON_R4)+","+ofToString(T6_ON_R4)+","+ofToString(T7_ON_R4)+","+ofToString(T8_ON_R4));
    
    testSequence.push_back("#"+ofToString(T1_ON_G4));
    testSequence.push_back("#"+ofToString(T1_ON_G4)+","+ofToString(T2_ON_G4));
    testSequence.push_back("#"+ofToString(T1_ON_G4)+","+ofToString(T2_ON_G4)+","+ofToString(T3_ON_G4));
    testSequence.push_back("#"+ofToString(T1_ON_G4)+","+ofToString(T2_ON_G4)+","+ofToString(T3_ON_G4)+","+ofToString(T4_ON_G4));
    testSequence.push_back("#"+ofToString(T1_ON_G4)+","+ofToString(T2_ON_G4)+","+ofToString(T3_ON_G4)+","+ofToString(T4_ON_G4)+","+ofToString(T5_ON_G4));
    testSequence.push_back("#"+ofToString(T1_ON_G4)+","+ofToString(T2_ON_G4)+","+ofToString(T3_ON_G4)+","+ofToString(T4_ON_G4)+","+ofToString(T5_ON_G4)+","+ofToString(T6_ON_G4));
    testSequence.push_back("#"+ofToString(T1_ON_G4)+","+ofToString(T2_ON_G4)+","+ofToString(T3_ON_G4)+","+ofToString(T4_ON_G4)+","+ofToString(T5_ON_G4)+","+ofToString(T6_ON_G4)+","+ofToString(T7_ON_G4));
    testSequence.push_back("#"+ofToString(T1_ON_G4)+","+ofToString(T2_ON_G4)+","+ofToString(T3_ON_G4)+","+ofToString(T4_ON_G4)+","+ofToString(T5_ON_G4)+","+ofToString(T6_ON_G4)+","+ofToString(T7_ON_G4)+","+ofToString(T8_ON_G4));
    
    testSequence.push_back("#"+ofToString(T1_ON_B4));
    testSequence.push_back("#"+ofToString(T1_ON_B4)+","+ofToString(T2_ON_B4));
    testSequence.push_back("#"+ofToString(T1_ON_B4)+","+ofToString(T2_ON_B4)+","+ofToString(T3_ON_B4));
    testSequence.push_back("#"+ofToString(T1_ON_B4)+","+ofToString(T2_ON_B4)+","+ofToString(T3_ON_B4)+","+ofToString(T4_ON_B4));
    testSequence.push_back("#"+ofToString(T1_ON_B4)+","+ofToString(T2_ON_B4)+","+ofToString(T3_ON_B4)+","+ofToString(T4_ON_B4)+","+ofToString(T5_ON_B4));
    testSequence.push_back("#"+ofToString(T1_ON_B4)+","+ofToString(T2_ON_B4)+","+ofToString(T3_ON_B4)+","+ofToString(T4_ON_B4)+","+ofToString(T5_ON_B4)+","+ofToString(T6_ON_B4));
    testSequence.push_back("#"+ofToString(T1_ON_B4)+","+ofToString(T2_ON_B4)+","+ofToString(T3_ON_B4)+","+ofToString(T4_ON_B4)+","+ofToString(T5_ON_B4)+","+ofToString(T6_ON_B4)+","+ofToString(T7_ON_B4));
    //    testSequence.push_back("#"+ofToString(T1_ON_B4)+","+ofToString(T2_ON_B4)+","+ofToString(T3_ON_B4)+","+ofToString(T4_ON_B4)+","+ofToString(T5_ON_B4)+","+ofToString(T6_ON_B4)+","+ofToString(T7_ON_B4)+","+ofToString(T8_ON_B4));
    
    testSequence.push_back("#"+ofToString(ALL_ON_WHITE));
    testSequence.push_back("#"+ofToString(ALL_OFF));
    testSequence.push_back("#"+ofToString(ALL_ON_R1));
    testSequence.push_back("#"+ofToString(ALL_ON_R2));
    testSequence.push_back("#"+ofToString(ALL_ON_R3));
    testSequence.push_back("#"+ofToString(ALL_ON_R4));
    testSequence.push_back("#"+ofToString(ALL_ON_G1));
    testSequence.push_back("#"+ofToString(ALL_ON_G2));
    testSequence.push_back("#"+ofToString(ALL_ON_G3));
    testSequence.push_back("#"+ofToString(ALL_ON_G4));
    testSequence.push_back("#"+ofToString(ALL_ON_B1));
    testSequence.push_back("#"+ofToString(ALL_ON_B2));
    testSequence.push_back("#"+ofToString(ALL_ON_B3));
    testSequence.push_back("#"+ofToString(ALL_ON_B4));
    testSequence.push_back("#"+ofToString(ALL_OFF));
    testSequence.push_back("#"+ofToString(ALL_ON_B4));
    testSequence.push_back("#"+ofToString(ALL_ON_B3));
    testSequence.push_back("#"+ofToString(ALL_ON_B2));
    testSequence.push_back("#"+ofToString(ALL_ON_B1));
    testSequence.push_back("#"+ofToString(ALL_ON_G4));
    testSequence.push_back("#"+ofToString(ALL_ON_G3));
    testSequence.push_back("#"+ofToString(ALL_ON_G2));
    testSequence.push_back("#"+ofToString(ALL_ON_G1));
    testSequence.push_back("#"+ofToString(ALL_ON_R4));
    testSequence.push_back("#"+ofToString(ALL_ON_R3));
    testSequence.push_back("#"+ofToString(ALL_ON_R2));
    testSequence.push_back("#"+ofToString(ALL_ON_R1));
    
}
//--------------------------------------------------------------
void ofApp::setupTrees(int numberOfTrees)
{
    for (int ch = 1; ch < (numberOfTrees*3); ch += 3) {
        Tree t;
        t.setup((ch/3)+1, ch);
        trees.push_back(t);
    }
}
//--------------------------------------------------------------
void ofApp::onNewMessage(string & message)
{
    bool validString = false;
    cout << "onNewMessage, message: " << message << "\n";
    if (message.size() > 0) {
        string vS = message.substr(0,1);
        if (vS == "#") {
            string cut = message.substr(1,message.length());
            split.clear();
            split = ofSplitString(cut, ",");
            for(int i = 0; i < split.size(); i++) {
                if (i == split.size()-1) {
                    cout << split[i] << endl;
                }
                else {
                    cout << split[i] << " ";
                }
            }
            validString = true;
        }
    }
    
    if (validString) {
        for (int i = 0; i < split.size(); i++) {
            for(int e = 1; e <= trees.size(); e++) {
                if (split[i].substr(0,1) == ofToString(e)) {
                    cout << "We Have A " << ofToString(e) << endl;
                    if (split[i].substr(2,1) == "R") {
                        if (split[i].substr(3,1) == "1") {
                            trees[e-1].setColor(RED_1);
                        }
                        else if (split[i].substr(3,1) == "2") {
                            trees[e-1].setColor(RED_2);
                        }
                        else if (split[i].substr(3,1) == "3") {
                            trees[e-1].setColor(RED_3);
                        }
                        else if (split[i].substr(3,1) == "4") {
                            trees[e-1].setColor(RED_4);
                        }
                    }
                    else if (split[i].substr(2,1) == "G") {
                        if (split[i].substr(3,1) == "1") {
                            trees[e-1].setColor(GREEN_1);
                        }
                        else if (split[i].substr(3,1) == "2") {
                            trees[e-1].setColor(GREEN_2);
                        }
                        else if (split[i].substr(3,1) == "3") {
                            trees[e-1].setColor(GREEN_3);
                        }
                        else if (split[i].substr(3,1) == "4") {
                            trees[e-1].setColor(GREEN_4);
                        }
                    }
                    else if (split[i].substr(2,1) == "B") {
                        if (split[i].substr(3,1) == "1") {
                            trees[e-1].setColor(BLUE_1);
                        }
                        else if (split[i].substr(3,1) == "2") {
                            trees[e-1].setColor(BLUE_2);
                        }
                        else if (split[i].substr(3,1) == "3") {
                            trees[e-1].setColor(BLUE_3);
                        }
                        else if (split[i].substr(3,1) == "4") {
                            trees[e-1].setColor(BLUE_4);
                        }
                    }
                    else if (split[i].substr(2,2) == "WH") {
                        trees[e-1].setColor(WHITE);
                    }
                    else if (split[i].substr(2,2) == "FF") {
                        trees[e-1].setColor(OFF);
                    }
                }
                else if (split[i].substr(0,1) == "A") {
                    if (split[i].substr(2,2) == "WH") {
                        trees[e-1].setColor(WHITE);
                    }
                    else if (split[i].substr(2,2) == "FF") {
                        trees[e-1].setColor(OFF);
                    }
                    for (int tr = 0; tr < trees.size();  tr++) {
                        if (split[i].substr(2,2) == "R1") {
                            trees[tr].setColor(RED_1);
                        }
                        else if (split[i].substr(2,2) == "R2") {
                            trees[tr].setColor(RED_2);
                        }
                        else if (split[i].substr(2,2) == "R3") {
                            trees[tr].setColor(RED_3);
                        }
                        else if (split[i].substr(2,2) == "R4") {
                            trees[tr].setColor(RED_4);
                        }
                        else if (split[i].substr(2,2) == "G1") {
                            trees[tr].setColor(GREEN_1);
                        }
                        else if (split[i].substr(2,2) == "G2") {
                            trees[tr].setColor(GREEN_2);
                        }
                        else if (split[i].substr(2,2) == "G3") {
                            trees[tr].setColor(GREEN_3);
                        }
                        else if (split[i].substr(2,2) == "G4") {
                            trees[tr].setColor(GREEN_4);
                        }
                        else if (split[i].substr(2,2) == "B1") {
                            trees[tr].setColor(BLUE_1);
                        }
                        else if (split[i].substr(2,2) == "B2") {
                            trees[tr].setColor(BLUE_2);
                        }
                        else if (split[i].substr(2,2) == "B3") {
                            trees[tr].setColor(BLUE_3);
                        }
                        else if (split[i].substr(2,2) == "B4") {
                            trees[tr].setColor(BLUE_4);
                        }
                    }
                }
            }
        }
    }
}
//--------------------------------------------------------------
void ofApp::setup()
{
    doneOnce = false;
    openConfig("configFile.json");
    setupColors();
    counter = 0;
    setupTrees(8);
    setupDMX("/dev/ttyUSB0");
    
    setupTestSequence();
//    lightBug.setup("/dev/tty.usbmodem1421",19200);
//    nTimesRead = 0;
//    nBytesRead = 0;
//    readTime = 0;
//    memset(bytesReadString, 0, 6);
    
}

//--------------------------------------------------------------
void ofApp::updateDMX()
{
    for (int i = 0; i < trees.size(); i++) {
        enttecBox.setLevel(trees[i].getAddresses(),trees[i].getColor().r);
        enttecBox.setLevel(trees[i].getAddresses()+1,trees[i].getColor().g);
        enttecBox.setLevel(trees[i].getAddresses()+2,trees[i].getColor().b);
    }
    enttecBox.update();
}
//--------------------------------------------------------------
void ofApp::update()
{
    string command = "";
    
    if (counter > testSequence.size()-1) {
        counter = 0;
    }
    
    if(ofGetFrameNum() % 10 == 0) {
        onNewMessage(testSequence[counter]);
        counter++;
    }
    updateDMX();
}
//--------------------------------------------------------------
void ofApp::draw()
{
    ofBackground(50);
    for(int i = 0; i < colorsArray.size(); i++) {
        ofSetColor(colorsArray[i]);
        ofCircle(25, (ofGetHeight()/2-(colorsArray.size()/2*25))+(i*25), 10);
    }
    
    for (int i = 0; i < trees.size(); i++) {
        trees[i].draw((ofGetWidth()/2-(trees.size()/2*75))+(i*100), ofGetHeight()/2);
    }
}
//--------------------------------------------------------------
void ofApp::exit()
{
    enttecBox.clear();
    enttecBox.update(true);
}
//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
    requestRead = true;
}
//--------------------------------------------------------------
void ofApp::keyReleased(int key)
{
    
}
