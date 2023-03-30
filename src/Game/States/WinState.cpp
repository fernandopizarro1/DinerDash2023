#include "WinState.h"

WinState::WinState() {
	text = "redo?";
    redo = new Button(ofGetWidth()/2 - text.length()*8, ofGetHeight()/2 - text.length()*13, 64, 50, "redo?");
	winscreen.load("images/Sad Chef.png");
}
void WinState::tick() {
	redo->tick();
	if(redo->wasPressed()){
		setNextState("Game");
		setFinished(true);
	}
}
void WinState::render() {
	ofSetBackgroundColor(170, 74, 68);
	ofSetColor(255);
	text = "Business is Booming!";
	ofDrawBitmapString("Business is Booming!", ofGetWidth() / 2 -text.length() *4 , ofGetHeight() / 2 - (text.length() + 30));
	redo->setColor(200,74,68);
	redo->render();
}

void WinState::keyPressed(int key){
	
}

void WinState::mousePressed(int x, int y, int button){
	redo->mousePressed(x, y);
}

void WinState::reset(){
	setFinished(false);
	setNextState("");
	redo->reset();
}