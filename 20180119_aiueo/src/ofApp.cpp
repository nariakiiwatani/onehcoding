#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofAddListener(mecab_.parseEvent, this, &ofApp::productAdded);
	mecab_.setDict("/Users/nariakiiwatani/Works/of098/addons/ofxMeCab/dict/ipadic");
	
	input_.setDidLoadListener([this](vector<string>& data, const ofJson& json) {
		product_.clear();
		mecab_.parse(data[1]);
		request_ = true;
	});
	input_.load("data.json");
}
void ofApp::productAdded(MorphObj &obj)
{
//	obj.dump();
	string &data = obj.yomi;
	
	if((false
		|| obj.hinshi == "名詞"
		|| obj.hinshi == "動詞"
		|| obj.hinshi == "形容詞"
		|| obj.hinshi == "副詞"
		|| obj.hinshi == "形容動詞"
		)
	   && obj.hyousou.length() >= 9 && data[0] == '\343') {
		product_.insert(make_pair(getCh(data, 0), obj.hyousou));
	}
}

ofApp::UTF8CH ofApp::getCh(string data, int head) {
	UTF8CH ch;
	ch.resize(3);
	for(int i = 0; i < 3; ++i) {
		ch[i] = data[head+i];
	}
	return ch;
}

void ofApp::proc(string data) {
	for(int i = 0; i < data.length(); i += 3) {
		UTF8CH ch = getCh(data, i);
		auto p = product_.equal_range(ch);
		int count = std::distance(p.first, p.second);
		if(count == 0) {
			std::cout << ch << "：該当なし" << std::endl;
		}
		else {
			auto it = p.first;
			for(int j = 0, num = (int)ofRandom(count); j < num; ++j, ++it) {}
			std::cout << ch << "：" << it->second << std::endl;
		}
	}
}

//--------------------------------------------------------------
void ofApp::update(){
	if(request_ && mecab_.isEnd()) {
		proc(input_[0]);
		request_ = false;
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	switch(key) {
			case ' ': proc(input_[0]);
	}
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
