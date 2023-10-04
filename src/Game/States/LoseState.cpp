#include "LoseState.h"

LoseState::LoseState() {
	text = "Restart?";
    Restart = new Button(ofGetWidth()/2 - text.length()*8, ofGetHeight()/2 - text.length()*13, 64, 50, "Restart?");
	losescreen.load("images/People/Sad_Chef.png");
}
void LoseState::tick() {
	Restart->tick();
	if(Restart->wasPressed()){
		setNextState("Game");
		setFinished(true);
	}
}
void LoseState::render() {
	ofSetColor(255);
	text = "You lost! Too many people left. You have to be faster than that!";
	losescreen.draw(0,0,ofGetWidth(), ofGetHeight());
	ofSetColor(0);
	ofSetBackgroundColor(170, 74, 68);
	ofDrawBitmapString("You lost! Too many people left. You have to be faster than that!", ofGetWidth() / 2 -text.length() *4 , ofGetHeight() / 2 - (text.length() + 30));
	Restart->setColor(200,74,68);
	Restart->render();
}

void LoseState::keyPressed(int key){
	
}

void LoseState::mousePressed(int x, int y, int button){
	Restart->mousePressed(x, y);
}

void LoseState::reset(){
	setFinished(false);
	setNextState("");
	Restart->reset();
}