#include "ofApp.h"

//#pragma mark - Setups
//--------------------------------------------------------------
void ofApp::setupColors()
{
    colors r1;
    r1.c = RED_1;
    r1.name = "Red 1";

    colors r2;
    r2.c = RED_2;
    r2.name = "Red 2";

    colors r3;
    r3.c = RED_3;
    r3.name = "Red 3";

    colors r4;
    r4.c = RED_4;
    r4.name = "Red 4";

    colors g1;
    g1.c = GREEN_1;
    g1.name = "Green 1";

    colors g2;
    g2.c = GREEN_2;
    g2.name = "Green 2";

    colors g3;
    g3.c = GREEN_3;
    g3.name = "Green 3";

    colors g4;
    g4.c = GREEN_4;
    g4.name = "Green 4";

    colors b1;
    b1.c = BLUE_1;
    b1.name = "Blue 1";

    colors b2;
    b2.c = BLUE_2;
    b2.name = "Blue 2";

    colors b3;
    b3.c = BLUE_3;
    b3.name = "Blue 3";

    colors b4;
    b4.c = BLUE_4;
    b4.name = "Blue 4";

    colors w;
    w.c = WHITE;
    w.name = "White";

    colors bl;
    bl.c = OFF;
    bl.name = "Black";

    colorsArray.push_back(r1);
    colorsArray.push_back(r2);
    colorsArray.push_back(r3);
    colorsArray.push_back(r4);

    colorsArray.push_back(g1);
    colorsArray.push_back(g2);
    colorsArray.push_back(g3);
    colorsArray.push_back(g4);

    colorsArray.push_back(b1);
    colorsArray.push_back(b2);
    colorsArray.push_back(b3);
    colorsArray.push_back(b4);

    colorsArray.push_back(w);
    colorsArray.push_back(bl);
}
//--------------------------------------------------------------
void ofApp::openConfig(string configFile)
{
    bool isOpen = config.open(configFile);

    if (!isOpen) {
        cout << "File Not Opened" << endl;
        return;
    }

    debugLights = config["debugLights"].asBool();
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
void ofApp::timer1StartedHandler( int &args )
{

}
//--------------------------------------------------------------
void ofApp::timer1CompleteHandler( int &args )
{
    if (!debugLights) {
//        lightBug.writeByte('r');
        messageBuffer = "";
        if (lightBug.available() > 0) {
            while(lightBug.available() > 0) {
                lightBug.readBytes(bytesReturned, 1);
                if (*bytesReturned == '\n') {
                    cout << messageBuffer << endl;
                    onNewMessage(messageBuffer);

                    break;
                }
                else
                {
                    if (*bytesReturned != '\n') {
                        messageBuffer += *bytesReturned;
                    }
                }
            }
            memset(bytesReturned, 0, 1);
        }
    }
}
//--------------------------------------------------------------
void ofApp::onNewMessage(string message)
{
    bool validString = false;
    cout << "New Message: " << message << "\n";
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

    // If the string is valid continue
    if (validString) {

        // Loop through the commands
        for (int i = 0; i < split.size(); i++) {

            // Loop through the Trees
            for(int e = 1; e <= trees.size(); e++) {

                // If the FIRST character is equal to a number
                if (split[i].substr(0,1) == ofToString(e)) {

                    // If the command is longer than 0 continue
                    if (split[i].length() > 0) {

                        // This is where we decide what color to set the trees
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
                }
                // If we get a A command set all the lights to the specified color
                else if (split[i].substr(0,1) == "A") {
                    for (int tr = 0; tr < trees.size();  tr++) {
                        if (split[i].substr(2,2) == "WH") {
                            trees[tr].setColor(WHITE);
                        }
                        else if (split[i].substr(2,2) == "FF") {
                            trees[tr].setColor(OFF);
                        }
                        else if (split[i].substr(2,2) == "R1") {
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
    counter = 0;
    debugLights = false;
    openConfig("configFile.json");
    setupColors();
    setupTrees(8);
    setupDMX("/dev/ttyUSB0");
    setupTestSequence();
    treeNames.loadFont("NewMedia Fett.ttf", 15);
    timer1.setup( 1000 ) ;
    timer1.start( true ) ;
    ofAddListener( timer1.TIMER_COMPLETE , this, &ofApp::timer1CompleteHandler ) ;
    ofAddListener( timer1.TIMER_STARTED , this, &ofApp::timer1StartedHandler ) ;
//    lightBug.setup("/dev/tty.usbmodem1421",19200);
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
    timer1.update();
    if (debugLights) {
        if (counter > testSequence.size()-1) {
            counter = 0;
        }

        if(ofGetFrameNum() % 10 == 0) {
            onNewMessage(testSequence[counter]);
            counter++;
        }
    }
    else {
        // This is the read mode
    }
    updateDMX();
}
//--------------------------------------------------------------
void ofApp::draw()
{
    ofBackground(50);
    for(int i = 0; i < colorsArray.size(); i++) {
        ofSetColor(colorsArray[i].c);
        ofCircle(25, (ofGetHeight()/2-(colorsArray.size()/2*25))+(i*25), 10);
        ofSetColor(255, 255, 255);
        treeNames.drawString(colorsArray[i].name, 40, (ofGetHeight()/2-(colorsArray.size()/2*25))+(i*25)+5);
    }

    for (int i = 0; i < trees.size(); i++) {
        trees[i].draw((ofGetWidth()/2-(trees.size()/2*75))+(i*100), 100);
        ofSetColor(255);
        ofPushMatrix();
        ofTranslate((ofGetWidth()/2-(trees.size()/2*75))+(i*100)-35, 100+85);
        ofRotateZ(-45);
        ofPushMatrix();
        treeNames.drawString("Tree "+ ofToString(i+1), 0, 0);
        ofPopMatrix();
        ofPopMatrix();
    }
    ofSetColor(255);
    ofPushMatrix();
    ofScale(2.5, 2.5);
    treeNames.drawString("LIGHT BUG", 5, 20);
    ofPopMatrix();
}
//--------------------------------------------------------------
void ofApp::exit()
{
    enttecBox.clear();
    enttecBox.update(true);
}
//--------------------------------------------------------------
void ofApp::keyPressed(int key) {   }
//--------------------------------------------------------------
void ofApp::keyReleased(int key) {   }
