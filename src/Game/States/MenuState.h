#pragma once

#include "State.h"

class MenuState : public State {
private:
	ofImage img1;
	Button *startButton;
	ofImage title; 
	
public:
	MenuState();
	void tick();
	void render();
	void keyPressed(int key);
	void mousePressed(int x, int y, int button);
	void reset();
};
