#pragma once

#include "ofMain.h"
#include "ofxJSON.h"

class ofxCooperHewittAPI {

public:

	ofxCooperHewittAPI();
	~ofxCooperHewittAPI();

	ofxJSONElement apiCall(string apiMethod, map<string, string> args);
	void setAPIEndpoint(string endpoint);
	void setAPIArgs(map<string, string> args);
	map<string, string> getAPIArgs();

protected:

	string requestMethod;
	string apiEndpoint;
	map<string, string> apiArgs;

	ofxJSONElement apiResponse;

	ofxJSONElement apiGetCall(string apiMethod, map<string, string> args);
	string buildRequestURL(string apiMethod, map<string, string> args);

};