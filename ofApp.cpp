#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	if (!csvLoader.load("PositionData.csv"))
	{
		cout << "failed to load csv data" << endl;
	}
	
	rowNum = csvLoader.getNumRows();

	gui.setup();

	speed.set("speed", 0.3, 0.0, 3.0);
	gui.add(speed);
}

//--------------------------------------------------------------
void ofApp::update(){

	
	frameNumber = int(ofGetFrameNum() * speed);

	for (int i = 0; i < JOINT_NUM; i++) 
	{
		jointPositions[i].x = csvLoader.getRow(frameNumber %rowNum).getFloat(i * 3);
		jointPositions[i].y = csvLoader.getRow(frameNumber % rowNum).getFloat(i * 3 + 1);
		jointPositions[i].z = csvLoader.getRow(frameNumber % rowNum).getFloat(i * 3 + 2);
	}
}

//--------------------------------------------------------------
void ofApp::draw(){

	camera.begin();

	for (int x = -gridFieldSize / 2; x < gridFieldSize / 2; x += gridSize)
	{
		for (int z = -gridFieldSize / 2; z < gridFieldSize / 2; z += gridSize)
		{
			ofPushMatrix();
			ofTranslate(x, 0, z);
			ofRotateXDeg(90);
			ofNoFill();
			ofSetRectMode(OF_RECTMODE_CENTER);
			ofSetColor(255);

			ofDrawRectangle(0, 0, 0, gridSize, gridSize);

			ofPopMatrix();
		}
	}

	for (int i = 0; i < JOINT_NUM; i++)
	{
		ofSetColor(255, 0, 0);
		ofDrawSphere(jointPositions[i].x * 500, (jointPositions[i].y + 1) * 500, (jointPositions[i].z - 1) * 500, 10);
	}
	
	camera.end();

	gui.draw();

	ofDrawBitmapString("frame number" + ofToString(frameNumber%rowNum), ofGetWidth() - 200, 20);
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
