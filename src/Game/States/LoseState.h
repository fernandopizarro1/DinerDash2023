#include "State.h"
#include "EntityManager.h"

class LoseState : public State {
private:
	Button *Restart;
	string text; 
	ofImage losescreen; 
public:
	LoseState();
	void tick();
	void render();
	void keyPressed(int key);
	void mousePressed(int x, int y, int button);
	void reset();
};
