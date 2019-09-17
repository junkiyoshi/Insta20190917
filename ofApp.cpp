#include "ofApp.h"	

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openFrameworks");

	ofBackground(239);
	ofSetBackgroundAuto(false);
	ofSetLineWidth(2);

	ofColor color;
	vector<int> hex_list = { 0x247BA0, 0x70C1B3, 0xB2DBBF, 0xF3FFBD, 0xFF1654 };
	for (auto hex : hex_list) {

		color.setHex(hex);
		this->color_list.push_back(color);
	}
}


//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

	int span = 144;
	int len = 134;

	int count = 0;
	for (int x = span * 0.5; x < ofGetWidth() + span * 0.5; x += span) {

		for (int y = span * 0.5; y < ofGetHeight() + span * 0.5; y += span) {

			if (ofGetFrameNum() % 20 == 0) {

				ofPushMatrix();
				ofTranslate(x, y);

				vector<glm::vec2> vertices;
				int param_start = ofRandom(100);
				int param_end = param_start + ofRandom(25, 50);

				for (int param = param_start; param <= param_end; param++) {

					vertices.push_back(this->make_point(len, param));
				}

				ofFill();
				ofSetColor(this->color_list[(int)ofRandom(this->color_list.size())]);
				ofBeginShape();
				ofVertices(vertices);
				ofEndShape(true);

				ofNoFill();
				ofSetColor(239);
				ofBeginShape();
				ofVertices(vertices);
				ofEndShape(true);

				ofPopMatrix();
			}

			count++;
		}
	}

	for (int i = 0; i < 1000; i++) {

		float x = ofRandom(ofGetWidth());
		float y = ofRandom(ofGetHeight());

		ofSetColor(255, 32);
		ofDrawCircle(x, y, 0.5);
	}
}

//--------------------------------------------------------------
glm::vec2 ofApp::make_point(int len, int param) {

	param = param % 100;
	if (param < 25) {

		return glm::vec2(ofMap(param, 0, 25, -len * 0.5, len * 0.5), -len * 0.5);
	}
	else if (param < 50) {

		return glm::vec2(len * 0.5, ofMap(param, 25, 50, -len * 0.5, len * 0.5));
	}
	else if (param < 75) {

		return glm::vec2(ofMap(param, 50, 75, len * 0.5, -len * 0.5), len * 0.5);
	}
	else {

		return glm::vec2(-len * 0.5, ofMap(param, 75, 100, len * 0.5, -len * 0.5));
	}
}


//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}