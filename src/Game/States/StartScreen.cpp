#include "StartScreen.h"

StartScreen::StartScreen() {
	string text = "Close";
	CloseHelp = new Button(ofGetWidth() - text.length() * 15, 0, 64, 30, "Close");
}
void StartScreen::tick() {
	CloseHelp->tick(); 
	if(CloseHelp->wasPressed()){
		setNextState("Game");
		setFinished(true);

	}
}
void StartScreen::render() {
	ofSetColor(0);
    ofDrawBitmapString("This is the help menu!", 0, pos * 2);
    ofDrawBitmapString("The controls are the following: ",0 , pos * 3);
    ofDrawBitmapString("E - Pick up ingredients.", 0, pos * 4);
    ofDrawBitmapString("S - Serve the client.",0,pos * 5);
	ofDrawBitmapString("H - Open and close the help menu.", 0, pos * 6);
	ofSetBackgroundColor(230, 230, 250);
	CloseHelp->setColor(0,0,0);
	CloseHelp->render();
}

void StartScreen::keyPressed(int key){
	if (key == 'h') {
        setNextState("Game");
		setFinished(true);
    }
}

void StartScreen::mousePressed(int x, int y, int button){
	CloseHelp->mousePressed(x, y);
}

void StartScreen::reset(){
	setFinished(false);
	setNextState("");
	CloseHelp->reset();
}