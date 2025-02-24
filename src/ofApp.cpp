#include "ofApp.h"
//--------------------------------------------------------------
void ofApp::openConfig(string configFile)
{
    bool isOpen = config.open(configFile);
    
    if (!isOpen) {
        cout << "File Not Opened" << endl;
        return;
    }
    
    showGui = config["showGui"].asBool();
    
    noTrees = config["numberoftrees"].asInt();
    
    debugLights = config["debug"]["debugLights"].asBool();
    debugTime = config["debug"]["debugtimer"].asInt();
    
    dmxController = config["serialaddresses"]["dmxcontrolleraddress"].asString();
    dmxChannels = config["dmxlight"]["channels"].asInt();
    dmxOffset = config["dmxlight"]["offset"].asInt();

    serialInLightBug = config["serialaddresses"]["lightbug"]["serialaddress"].asString();
    lightBugBaud = config["serialaddresses"]["lightbug"]["baud"].asInt();
    
    idleTime = config["timers"]["idletime"].asInt();
    resetTime = config["timers"]["resettime"].asInt();
    
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
    
    WHITE = ofColor(config["colors"][12]["white"]["r"].asInt(),config["colors"][12]["white"]["g"].asInt(),config["colors"][12]["white"]["b"].asInt());
    
    OFF = ofColor(0,0,0);
}
//--------------------------------------------------------------
// *
// * Setup DMX Unit
// * The DMX Addresses are generated here
// *
//--------------------------------------------------------------
void ofApp::setupDMX(string device)
{
    // Allow for an extra tree so we can use DMX address tricks to make
    // some lights pretend to be others (eg Dragons instead of LEDj Quads)
    const int channels = (noTrees+1) * dmxChannels + dmxOffset;

    cout << "DMX trees: " << noTrees << endl
         << "DMX channels/tree: " << dmxChannels << endl
         << "DMX offset/tree: " << dmxOffset << endl
         << "DMX channels: " << channels << endl;

    enttecBox.connect(device, channels);

    if (!enttecBox.isConnected()) {
        cout << "DMX not connected: " << device << endl;
        dmxConnected = false;
        ofExit( 1 );
    }
    else {
        dmxConnected = true;
        cout << "DMX connected: " << device << endl;
    }
}
//--------------------------------------------------------------
// *
// * Setup the Tree objects
// * The DMX Addresses are generated here
// *
//--------------------------------------------------------------
void ofApp::setupTrees(int numberOfTrees)
{
    for ( int id = 1; id <= numberOfTrees; ++id ) {
        Tree tree;
        tree.setup( id, (id-1) * dmxChannels + dmxOffset, 3, showGui );
        trees.push_back( tree );
    }
}
//--------------------------------------------------------------
void ofApp::onNewMessage(string message)
{
    bool validString = false;
    cout << "onNewMessage, message: " << message << endl;
    if (message.size() > 0) {

        // ignore any cruft before the actual message
        const size_t hashPos = message.find( '#' );
        if( hashPos != string::npos ) {
            string cut = message.substr( hashPos + 1 );

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
    // Loop through the commands
    // Loop through the Trees
    // If the FIRST character is equal to a number
    // If the command is longer than 0 continue
    // This is where we decide what color to set the trees
    if (validString) {
        idleTimer.stop();
        for (int i = 0; i < split.size(); i++) {
            for(int e = 1; e <= trees.size(); e++) {
                if (split[i].substr(0,1) == ofToString(e)) {
                    if (split[i].length() > 0) {
                        if (split[i].substr(2,1) == "R") {
                            if (split[i].substr(3,1) == "1") {
                                trees[e-1].setColor(RED_1);
                                trees[e-1].setIsTreeOn(true);
                            }
                            else if (split[i].substr(3,1) == "2") {
                                trees[e-1].setColor(RED_2);
                                trees[e-1].setIsTreeOn(true);
                            }
                            else if (split[i].substr(3,1) == "3") {
                                trees[e-1].setColor(RED_3);
                                trees[e-1].setIsTreeOn(true);
                            }
                            else if (split[i].substr(3,1) == "4") {
                                trees[e-1].setColor(RED_4);
                                trees[e-1].setIsTreeOn(true);
                            }
                        }
                        else if (split[i].substr(2,1) == "G") {
                            if (split[i].substr(3,1) == "1") {
                                trees[e-1].setColor(GREEN_1);
                                trees[e-1].setIsTreeOn(true);
                            }
                            else if (split[i].substr(3,1) == "2") {
                                trees[e-1].setColor(GREEN_2);
                                trees[e-1].setIsTreeOn(true);
                            }
                            else if (split[i].substr(3,1) == "3") {
                                trees[e-1].setColor(GREEN_3);
                                trees[e-1].setIsTreeOn(true);
                            }
                            else if (split[i].substr(3,1) == "4") {
                                trees[e-1].setColor(GREEN_4);
                                trees[e-1].setIsTreeOn(true);
                            }
                        }
                        else if (split[i].substr(2,1) == "B") {
                            if (split[i].substr(3,1) == "1") {
                                trees[e-1].setColor(BLUE_1);
                                trees[e-1].setIsTreeOn(true);
                            }
                            else if (split[i].substr(3,1) == "2") {
                                trees[e-1].setColor(BLUE_2);
                                trees[e-1].setIsTreeOn(true);
                            }
                            else if (split[i].substr(3,1) == "3") {
                                trees[e-1].setColor(BLUE_3);
                                trees[e-1].setIsTreeOn(true);
                            }
                            else if (split[i].substr(3,1) == "4") {
                                trees[e-1].setColor(BLUE_4);
                                trees[e-1].setIsTreeOn(true);
                            }
                        }
                        else if (split[i].substr(2,2) == "WH") {
                            trees[e-1].setColor(WHITE);
                            trees[e-1].setIsTreeOn(true);
                        }
                        else if (split[i].substr(2,2) == "FF") {
                            trees[e-1].setColor(OFF);
                            trees[e-1].setIsTreeOn(false);
                        }
                    }
                }
                else if (split[i].substr(0,1) == "A") {
                    for (int tr = 0; tr < trees.size();  tr++) {
                        if (split[i].substr(2,2) == "WH") {
                            trees[tr].setColor(WHITE);
                            trees[tr].setIsTreeOn(true);
                        }
                        else if (split[i].substr(2,2) == "FF") {
                            trees[tr].setColor(OFF);
                            trees[tr].setIsTreeOn(false);
                            
                        }
                        else if (split[i].substr(2,2) == "R1") {
                            trees[tr].setColor(RED_1);
                            trees[tr].setIsTreeOn(true);
                        }
                        else if (split[i].substr(2,2) == "R2") {
                            trees[tr].setColor(RED_2);
                            trees[tr].setIsTreeOn(true);
                        }
                        else if (split[i].substr(2,2) == "R3") {
                            trees[tr].setColor(RED_3);
                            trees[tr].setIsTreeOn(true);
                        }
                        else if (split[i].substr(2,2) == "R4") {
                            trees[tr].setColor(RED_4);
                            trees[tr].setIsTreeOn(true);
                        }
                        else if (split[i].substr(2,2) == "G1") {
                            trees[tr].setColor(GREEN_1);
                            trees[tr].setIsTreeOn(true);
                        }
                        else if (split[i].substr(2,2) == "G2") {
                            trees[tr].setColor(GREEN_2);
                            trees[tr].setIsTreeOn(true);
                        }
                        else if (split[i].substr(2,2) == "G3") {
                            trees[tr].setColor(GREEN_3);
                            trees[tr].setIsTreeOn(true);
                        }
                        else if (split[i].substr(2,2) == "G4") {
                            trees[tr].setColor(GREEN_4);
                            trees[tr].setIsTreeOn(true);
                        }
                        else if (split[i].substr(2,2) == "B1") {
                            trees[tr].setColor(BLUE_1);
                            trees[tr].setIsTreeOn(true);
                        }
                        else if (split[i].substr(2,2) == "B2") {
                            trees[tr].setColor(BLUE_2);
                            trees[tr].setIsTreeOn(true);
                        }
                        else if (split[i].substr(2,2) == "B3") {
                            trees[tr].setColor(BLUE_3);
                            trees[tr].setIsTreeOn(true);
                        }
                        else if (split[i].substr(2,2) == "B4") {
                            trees[tr].setColor(BLUE_4);
                            trees[tr].setIsTreeOn(true);
                        }
                    }
                }
            }
        }
        idleTimer.start();
    }
}
//--------------------------------------------------------------
void ofApp::setupGUI()
{
    gui.setup();
    parameters.setName("Beacons");
    
    for (int i = 0; i < noTrees; i++) {
        parameters.add(trees[i].parameters);
    }
    gui.add(parameters);
}
//--------------------------------------------------------------
void ofApp::setup()
{
    reset = true;
    doneOnce = false;
    idle = true;
    openConfig("configFile.json");
    
    
    setupColors();
    counter = 0;
    setupTestSequence();
    setupTrees(noTrees);
    
    if (showGui) {
        setupGUI();
    }
    setupDMX(dmxController);
    treeNames.loadFont("NewMedia Fett.ttf", 15);
    lightBug.setup(serialInLightBug,lightBugBaud);
    
    readTimer.setup(1000, "Read Timer", true);
    readTimer.start();
    
    idleTimer.setup(idleTime, "Idle Timer", false);
    resetTimer.setup(resetTime, "Reset Timer", false);
    
    debugTimer.setup(debugTime,"Debug Lights Timer",true);
    debugTimer.start();
    
}
//--------------------------------------------------------------
void ofApp::updateDMX()
{
    for (int i = 0; i < trees.size(); i++) {
        enttecBox.setLevel(trees[i].getAddresses(),trees[i].getColor().r);
        enttecBox.setLevel(trees[i].getAddresses()+1,trees[i].getColor().g);
        enttecBox.setLevel(trees[i].getAddresses()+2,trees[i].getColor().b);
    }

    errno = 0;
    enttecBox.update();
    if( errno ) {
        cout << "Enttec write error: " << strerror( errno ) << endl;
        ofExit( 1 );
    }
}
//--------------------------------------------------------------
void ofApp::update()
{
    readTimer.update();
    idleTimer.update();
    resetTimer.update();
    debugTimer.update();
    
    
    
    if (!doneOnce && !debugLights) {
        if (counter > testSequence.size()-1) {
            counter = testSequence.size()-1;
            for (int tr = 0; tr < trees.size();  tr++) {
                trees[tr].setColor(OFF);
                trees[tr].setIsTreeOn(false);
            }
            debugTimer.stop();
            doneOnce = true;
        }
    }
    
    
    if (debugLights) {
        
        if (showGui) {
            for (int tr = 0; tr < trees.size();  tr++) {
                trees[tr].update();
            }
        }
        else {
            if (counter > testSequence.size()-1) {
                counter = 0;
                for (int tr = 0; tr < trees.size();  tr++) {
                    trees[tr].setColor(OFF);
                    trees[tr].setIsTreeOn(false);
                }
                doneOnce = true;
            }
        }
    }
    else {
        // This is the read mode
        if (!idle) {
            for (int tr = 0; tr < trees.size();  tr++) {
                ofColor idleColor;
                resetIdleColor = WHITE;
                if (!trees[tr].getIsTreeOn()) {
                    if (trees[tr].getColor() != resetIdleColor) {
                        idleColor.set(trees[tr].getColor());
                        if (idleColor.r < resetIdleColor.r) {
                            idleColor.r += 3;
                        }
                        else if(idleColor.r > resetIdleColor.r) {
                            idleColor.r -= 3;
                        }
                        
                        if (idleColor.g < resetIdleColor.g) {
                            idleColor.g += 3;
                        }
                        else if (idleColor.g > resetIdleColor.g) {
                            idleColor.g -= 3;
                        }
                        if(idleColor.b < resetIdleColor.b) {
                            idleColor.b += 3;
                        }
                        else if(idleColor.b > resetIdleColor.b) {
                            idleColor.b -= 3;
                        }
                        trees[tr].setColor(idleColor);
                    }
                    else {
                        trees[tr].setColor(resetIdleColor);
                        idle = true;
                    }
                }
            }
        }
        
        if (!reset) {
            ofColor tmpResetColor = OFF;
            for (int tr = 0; tr < trees.size();  tr++) {
                ofColor resetColor;
                trees[tr].setColor(tmpResetColor);
                trees[tr].setIsTreeOn(false);
                reset = true;
            }
        }
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
    
    string serialConnection = lightBug.isInitialized() ? "Connected" : "Not Connected";
    string dmxConnection = enttecBox.isConnected() ? "Connected" : "Not Connected";
    treeNames.drawString("DMX is " + dmxConnection, 150, ofGetHeight()/2);
    treeNames.drawString("Serial is " +serialConnection, 150, ofGetHeight()/2 + 30);
    treeNames.drawString("Incoming Command: " + messageBuffer, 150, ofGetHeight()/2+60);
    ofSetColor(255);
    ofPushMatrix();
    ofScale(2.5, 2.5);
    treeNames.drawString("LIGHT BUG", 5, 20);
    ofPopMatrix();
    
    if (showGui) {
        gui.draw();
    }
}
//--------------------------------------------------------------
void ofApp::exit()
{
    enttecBox.clear();
    enttecBox.update(true);
}
//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg)
{
    if (msg.message == "Read Timer Finished") {
        if (!debugLights && doneOnce) {
            messageBuffer = "";

	    int result = lightBug.available();
	    if( result == OF_SERIAL_ERROR ) {
		cout << "lightbug serial available error" << endl;
		ofExit( 1 );
	    }

            if ( result > 0 ) {
                while(lightBug.available() > 0) {

                    if( lightBug.readBytes(bytesReturned, 1) == OF_SERIAL_ERROR ) {
                        cout << "lightbug serial read error" << endl;
                        ofExit( 1 );
                    }

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
    else if (msg.message == "Idle Timer Finished") {
        cout << msg.message << endl;
        idle = false;
    }
    else if (msg.message == "Idle Timer Started") {
        cout << msg.message << endl;
    }
    else if (msg.message == "Reset Timer Finished") {
        cout << msg.message << endl;
        reset = false;
    }
    else if (msg.message == "Reset Timer Started") {
        cout << msg.message << endl;
    }
    else if(msg.message == "Debug Lights Timer Finished") {
        cout << msg.message << endl;
        if(counter < testSequence.size()) {
            messageBuffer = testSequence[counter];
            onNewMessage(testSequence[counter]);
            counter++;
        }
    }
}
//--------------------------------------------------------------
void ofApp::keyPressed(int key) {   }
//--------------------------------------------------------------
void ofApp::keyReleased(int key) {   }
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
