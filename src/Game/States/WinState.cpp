#include "WinState.h"

WinState::WinState() {
	text = "Continue?";
    redo = new Button(ofGetWidth()/2 - text.length()*8, ofGetHeight()/2 - text.length()*3, 64, 50, "Continue?");
	winscreen.load("images/money.png");
}
void WinState::tick() {
	redo->tick();
	if(redo->wasPressed()){
		setNextState("Game");
		setFinished(true);
	}
}
void WinState::render() {
	ofSetBackgroundColor(144,238,144);
	ofSetColor(255);
	winscreen.draw(50, 0, ofGetWidth() - 150, ofGetHeight() - 75);
	text = "Business is Booming! You're a natural!";
	ofSetColor(0);
	ofDrawBitmapString("Business is Booming! You're a natural!", ofGetWidth() / 2 -text.length() *4 , ofGetHeight() / 2 -19.5);
	redo->setColor(200,74,68);
	redo->render();
}

void WinState::keyPressed(int key){
	if(key == 'r'){
		setNextState("Game");
		setFinished(true);
		setRetry(true);
	}
	
}

void WinState::mousePressed(int x, int y, int button){
	redo->mousePressed(x, y);
}

void WinState::reset(){
	setFinished(false);
	setNextState("");
	redo->reset();
}