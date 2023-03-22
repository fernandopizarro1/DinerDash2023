#include "MenuState.h"

MenuState::MenuState() {
	string text = "Start";
	title.load("images/title.jpg");
	startButton = new Button(ofGetWidth()/2 - text.length()*8, ofGetHeight()/2 - text.length()*11, 64, 50, "Start");
}
void MenuState::tick() {
	startButton->tick();
	if(startButton->wasPressed()){
		setNextState("Start");
		setFinished(true);

	}
}
void MenuState::render() {
	ofSetColor(255);
	title.draw(0,0,ofGetWidth(),ofGetHeight());
	ofSetBackgroundColor(230, 230, 250);
	startButton->setColor(0,0,0);
	startButton->render();
}

void MenuState::keyPressed(int key){
	
}

void MenuState::mousePressed(int x, int y, int button){
	startButton->mousePressed(x, y);
}

void MenuState::reset(){
	setFinished(false);
	setNextState("");
	startButton->reset();
}