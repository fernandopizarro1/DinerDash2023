#include "StartScreen.h"

StartScreen::StartScreen() {
	string text = "Close";
	CloseHelp = new Button(ofGetWidth() - text.length() * 15, 0, 64, 30, "Close");
	Screen.load("images/people/Thoughtful_Chef.png");
}
void StartScreen::tick() {
	CloseHelp->tick(); 
	if(CloseHelp->wasPressed()){
		setNextState("Game");
		setFinished(true);

	}
}
void StartScreen::render() {
	ofSetColor(255);
	Screen.draw(0,ofGetHeight() / 2, 219, 316);
	ofSetColor(0);
    ofDrawBitmapString("This is the help menu!", 0, pos * 2);
    ofDrawBitmapString("The controls are the following: ",0 , pos * 3);
	ofDrawBitmapString("Use the arrow keys to move.", 0, pos * 4);
    ofDrawBitmapString("E - Picks up ingredients/Starts to cook the patty.", 0, pos * 5);
    ofDrawBitmapString("S - Serve the client.",0,pos * 6);
	ofDrawBitmapString("H - Open and close the help menu.", 0, pos * 7);
	ofDrawBitmapString("U - removes the last ingredient in the burger.", 0, pos * 8);
	ofDrawBitmapString("Remember to cook the patty! You don't want to fall behind.", 0,pos * 9);
	ofDrawBitmapString("Watch out for the Inspector! You will lose half your money if he leaves angry.", 0, pos * 10);
	ofSetBackgroundColor(169,169,169);
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