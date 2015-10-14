#include "ofApp.h"
void ofApp::setup() {
	dmx.connect("/dev/ttyUSB0"); // use the name /dev/tty.usbserial-EN150288
	//dmx.connect(0); // or use a number
}

void ofApp::update() {
	// use the time to generate a level
	level = ofMap(sin(ofGetElapsedTimef() * 10), -1, 1, 0, 255);
	
	// pulses channels 1 and 2
	dmx.setLevel(1, level);
	dmx.setLevel(2, 255 - level);
	dmx.update();
}

void ofApp::draw() {
	ofSetColor(level);
	ofRect(0, 0, ofGetWidth() / 2, ofGetHeight());
	
	ofSetColor(255 - level);
	ofRect(ofGetWidth() / 2, 0, ofGetWidth() / 2, ofGetHeight());
}
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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
