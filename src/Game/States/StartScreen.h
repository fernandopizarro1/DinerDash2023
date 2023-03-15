#include "State.h"

class StartScreen : public State {
private:
	Button *CloseHelp;
    int pos = 15; // y-positions of strings 
	
public:
	StartScreen();
	void tick();
	void render();
	void keyPressed(int key);
	void mousePressed(int x, int y, int button);
	void reset();
};