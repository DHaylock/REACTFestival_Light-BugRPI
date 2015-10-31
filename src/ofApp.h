#pragma once

#include "ofMain.h"
#include "ofxDmx.h"
#include "ofxJSON.h"
#include "MyTimer.h"
#include "tree.h"
#include "ofxGui.h"

//------------------------------------------------
// *
// * Color Definitions
// *
//------------------------------------------------
//#define RED_1 ofColor(255,80,80)
//#define RED_2 ofColor(255,0,0)
//#define RED_3 ofColor(255,50,0)
//#define RED_4 ofColor(255,80,0)
//
//#define GREEN_1 ofColor(255,255,0)
//#define GREEN_2 ofColor(0,255,0)
//#define GREEN_3 ofColor(0,220,10)
//#define GREEN_4 ofColor(0,140,40)
//
//#define BLUE_1 ofColor(0,220,170)
//#define BLUE_2 ofColor(0,0,255)
//#define BLUE_3 ofColor(40,0,170)
//#define BLUE_4 ofColor(255,0,255)
//
//#define WHITE ofColor(255,255,255)
//#define OFF ofColor(0,0,0)

//------------------------------------------------
// *
// * Block Colors
// *
//------------------------------------------------
#define ALL_OFF "AOFF"
#define ALL_ON_WHITE "AOWH"
#define ALL_ON_R1 "AOR1"
#define ALL_ON_R2 "AOR2"
#define ALL_ON_R3 "AOR3"
#define ALL_ON_R4 "AOR4"
#define ALL_ON_G1 "AOG1"
#define ALL_ON_G2 "AOG2"
#define ALL_ON_G3 "AOG3"
#define ALL_ON_G4 "AOG4"
#define ALL_ON_B1 "AOB1"
#define ALL_ON_B2 "AOB2"
#define ALL_ON_B3 "AOB3"
#define ALL_ON_B4 "AOB4"

//------------------------------------------------
// *
// * Individual Colors
// *
//------------------------------------------------
#define T1_ON_R1 "1OR1"
#define T1_ON_R2 "1OR2"
#define T1_ON_R3 "1OR3"
#define T1_ON_R4 "1OR4"
#define T1_ON_G1 "1OG1"
#define T1_ON_G2 "1OG2"
#define T1_ON_G3 "1OG3"
#define T1_ON_G4 "1OG4"
#define T1_ON_B1 "1OB1"
#define T1_ON_B2 "1OB2"
#define T1_ON_B3 "1OB3"
#define T1_ON_B4 "1OB4"
#define T1_ON_WH "1OWH"
#define T1_OFF "1OFF"

#define T2_ON_R1 "2OR1"
#define T2_ON_R2 "2OR2"
#define T2_ON_R3 "2OR3"
#define T2_ON_R4 "2OR4"
#define T2_ON_G1 "2OG1"
#define T2_ON_G2 "2OG2"
#define T2_ON_G3 "2OG3"
#define T2_ON_G4 "2OG4"
#define T2_ON_B1 "2OB1"
#define T2_ON_B2 "2OB2"
#define T2_ON_B3 "2OB3"
#define T2_ON_B4 "2OB4"
#define T2_ON_WH "2OWH"
#define T2_OFF "2OFF"

#define T3_ON_R1 "3OR1"
#define T3_ON_R2 "3OR2"
#define T3_ON_R3 "3OR3"
#define T3_ON_R4 "3OR4"
#define T3_ON_G1 "3OG1"
#define T3_ON_G2 "3OG2"
#define T3_ON_G3 "3OG3"
#define T3_ON_G4 "3OG4"
#define T3_ON_B1 "3OB1"
#define T3_ON_B2 "3OB2"
#define T3_ON_B3 "3OB3"
#define T3_ON_B4 "3OB4"
#define T3_ON_WH "3OWH"
#define T3_OFF "3OFF"

#define T4_ON_R1 "4OR1"
#define T4_ON_R2 "4OR2"
#define T4_ON_R3 "4OR3"
#define T4_ON_R4 "4OR4"
#define T4_ON_G1 "4OG1"
#define T4_ON_G2 "4OG2"
#define T4_ON_G3 "4OG3"
#define T4_ON_G4 "4OG4"
#define T4_ON_B1 "4OB1"
#define T4_ON_B2 "4OB2"
#define T4_ON_B3 "4OB3"
#define T4_ON_B4 "4OB4"
#define T4_ON_WH "4OWH"
#define T4_OFF "4OFF"

#define T5_ON_R1 "5OR1"
#define T5_ON_R2 "5OR2"
#define T5_ON_R3 "5OR3"
#define T5_ON_R4 "5OR4"
#define T5_ON_G1 "5OG1"
#define T5_ON_G2 "5OG2"
#define T5_ON_G3 "5OG3"
#define T5_ON_G4 "5OG4"
#define T5_ON_B1 "5OB1"
#define T5_ON_B2 "5OB2"
#define T5_ON_B3 "5OB3"
#define T5_ON_B4 "5OB4"
#define T5_ON_WH "5OWH"
#define T5_OFF "5OFF"

#define T6_ON_R1 "6OR1"
#define T6_ON_R2 "6OR2"
#define T6_ON_R3 "6OR3"
#define T6_ON_R4 "6OR4"
#define T6_ON_G1 "6OG1"
#define T6_ON_G2 "6OG2"
#define T6_ON_G3 "6OG3"
#define T6_ON_G4 "6OG4"
#define T6_ON_B1 "6OB1"
#define T6_ON_B2 "6OB2"
#define T6_ON_B3 "6OB3"
#define T6_ON_B4 "6OB4"
#define T6_ON_WH "6OWH"
#define T6_OFF "6OFF"

#define T7_ON_R1 "7OR1"
#define T7_ON_R2 "7OR2"
#define T7_ON_R3 "7OR3"
#define T7_ON_R4 "7OR4"
#define T7_ON_G1 "7OG1"
#define T7_ON_G2 "7OG2"
#define T7_ON_G3 "7OG3"
#define T7_ON_G4 "7OG4"
#define T7_ON_B1 "7OB1"
#define T7_ON_B2 "7OB2"
#define T7_ON_B3 "7OB3"
#define T7_ON_B4 "7OB4"
#define T7_ON_WH "7OWH"
#define T7_OFF "7OFF"

#define T8_ON_R1 "8OR1"
#define T8_ON_R2 "8OR2"
#define T8_ON_R3 "8OR3"
#define T8_ON_R4 "8OR4"
#define T8_ON_G1 "8OG1"
#define T8_ON_G2 "8OG2"
#define T8_ON_G3 "8OG3"
#define T8_ON_G4 "8OG4"
#define T8_ON_B1 "8OB1"
#define T8_ON_B2 "8OB2"
#define T8_ON_B3 "8OB3"
#define T8_ON_B4 "8OB4"
#define T8_ON_WH "8OWH"
#define T8_OFF "8OFF"


//----------------------------------
struct colors {
    string name;
    ofColor c;
};

//------------------------------------------------
class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    void exit();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void gotMessage(ofMessage msg);
    
    //----------------------------------
    // Trees
    //----------------------------------
    void setupTrees(int numberOfTrees);
    vector <Tree> trees;
    int noTrees;
    
    //----------------------------------
    // DMX Stuff
    //----------------------------------
    void setupDMX(string device);
    void updateDMX();
    void drawDMX();
    
    ofxDmx enttecBox;
    bool dmxConnected;
    
    //----------------------------------
    // Serial/UART IN
    //----------------------------------
    void setupLightBugConnection(string device,int baud);
    void updateLightBug();
    
    ofSerial lightBug;
    void onNewMessage(string message);
    bool		requestRead;
    unsigned char	bytesReturned[1];
    string messageBuffer;
    
    
    void setupTestSequence();
    vector<string> testSequence;
    vector <string> split;
    bool doneOnce;
    
    //----------------------------------
    // Load the Config File
    //----------------------------------
    void openConfig(string configFile);
    ofxJSONElement config;
    string serialInLightBug;
    string dmxController;
    int dmxChannels;            // Channels per light
    int dmxOffset;              // Offset of red channel per light
    int lightBugBaud;
    bool debugLights;
    
    
    int counter;
    int counterSpeed;
    
    
    //----------------------------------
    // Colors
    //----------------------------------
    void setupColors();
    vector <colors> colorsArray;
    
    ofColor RED_1;
    ofColor RED_2;
    ofColor RED_3;
    ofColor RED_4;
    ofColor GREEN_1;
    ofColor GREEN_2;
    ofColor GREEN_3;
    ofColor GREEN_4;
    ofColor BLUE_1;
    ofColor BLUE_2;
    ofColor BLUE_3;
    ofColor BLUE_4;
    ofColor WHITE;
    ofColor OFF;
    
    ofColor activeColor;
    ofColor resetIdleColor;
    
    
    ofTrueTypeFont treeNames;
    
    
    //----------------------------------
    // GUI
    //----------------------------------
    bool showGui;
    void setupGUI();
    
    ofxPanel gui;
    ofParameterGroup parameters;
    
    //----------------------------------
    // Timers
    //----------------------------------
    MyTimer     readTimer;
    MyTimer     idleTimer;
    MyTimer     resetTimer;
    MyTimer     debugTimer;
    
    bool idle;
    bool reset;
    
    int idleTime;
    int resetTime;
    int debugTime;
    //----------------------------------
};
