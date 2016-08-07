#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofLog() << "Hello World!" << endl;

	ofFile apiSettings;

	apiSettings.open(ofToDataPath("api_settings.txt"), ofFile::ReadWrite, false);
	ofBuffer access_token = apiSettings.readToBuffer();
	
	map<string, string> args;
	args["access_token"] = access_token;
	string method = "cooperhewitt.labs.whatWouldMicahSay";

	ch_api.setAPIArgs(args);

	apiResponse = ch_api.apiCall(method, args);

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw() {

	ofClear(0);
	ofDrawBitmapString("Hello World!", 100, 100);

	ofDrawBitmapString(apiResponse["micah"]["says"].asString(), 100, 120);
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

	string method = "cooperhewitt.labs.whatWouldMicahSay";
	apiResponse = ch_api.apiCall(method, ch_api.getAPIArgs());

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
