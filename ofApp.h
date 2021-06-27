#pragma once

#include "ofMain.h"
#include "ofxCsv.h"
#include "ofxGui.h"

#define JOINT_NUM 25

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
		
		ofEasyCam camera;

		ofxPanel gui;
		ofParameter<float> speed;

		ofxCsv csvLoader;
		ofVec3f jointPositions[JOINT_NUM];

		int rowNum;
		int frameNumber = 0;

		int gridFieldSize = 1600;
		int gridSize = 100;
};
