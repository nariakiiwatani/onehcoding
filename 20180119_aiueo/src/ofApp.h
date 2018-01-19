#pragma once

#include "ofMain.h"
#include "ofxMeCab.hpp"
#include "ofxJsonUtilsUtils.h"
#include "ofxJsonUtilsUtilsContainer.h"

class ofApp : public ofBaseApp{
	
public:
	void setup();
	void update();
	void draw();
	
	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);
	
	void proc(string data);
private:
	bool request_=false;
	ofxMeCab mecab_;
	typedef string UTF8CH;
	multimap<UTF8CH, string> product_;
	UTF8CH getCh(string data, int i);
	void productAdded(MorphObj &obj);
	
	ofxJsonContainer<vector<string>> input_;
};
