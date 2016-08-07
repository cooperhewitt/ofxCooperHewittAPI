#include "ofMain.h"
#include "ofxCooperHewittAPI.h"

ofxCooperHewittAPI::ofxCooperHewittAPI() {

	apiEndpoint = "https://api.collection.cooperhewitt.org/rest/";
	requestMethod = "GET";

}

ofxCooperHewittAPI::~ofxCooperHewittAPI() {

}

ofxJSONElement ofxCooperHewittAPI::apiCall(string apiMethod, map<string, string> args) {

	ofxJSONElement rsp;

	if (requestMethod == "GET") {
		rsp = apiGetCall(apiMethod, args);
	}

	return rsp;
}

void ofxCooperHewittAPI::setAPIEndpoint(string endpoint)
{
	apiEndpoint = endpoint;
}

void ofxCooperHewittAPI::setAPIArgs(map<string, string> args)
{
	apiArgs = args;
}

map<string, string> ofxCooperHewittAPI::getAPIArgs()
{
	return apiArgs;
}

ofxJSONElement ofxCooperHewittAPI::apiGetCall(string apiMethod, map<string, string> args)
{
	string url = buildRequestURL(apiMethod, args);
	apiResponse.open(url);

	ofLog() << "apiGetCall response: " << apiResponse.getRawString();

	return apiResponse;
}

string ofxCooperHewittAPI::buildRequestURL(string apiMethod, map<string, string> args)
{
	string url = apiEndpoint + "?" + "method=" + apiMethod;

	for (std::map<string, string>::iterator it = args.begin(); it != args.end(); ++it)
		url += "&" + it->first + "=" + it->second;

	return url;
}


