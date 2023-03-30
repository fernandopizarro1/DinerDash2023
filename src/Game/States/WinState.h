#include "State.h"
#include "EntityManager.h"

class WinState : public State {
private:
	Button *redo;
	string text; 
	ofImage winscreen; 
public:
	WinState();
	void tick();
	void render();
	void keyPressed(int key);
	void mousePressed(int x, int y, int button);
	void reset();
};
