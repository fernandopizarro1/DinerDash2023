#include "GameState.h"

GameState::GameState() {
    this->restaurant = new Restaurant();
}
void GameState::tick() {
	restaurant->tick();
}
void GameState::render() {
	restaurant->render();
}

void GameState::keyPressed(int key){
	if (key == 'h') {
		setNextState("Start");
		setFinished(true);
	} else {
		restaurant->keyPressed(key);
	}
}

void GameState::mousePressed(int x, int y, int button){
}

void GameState::keyReleased(int key){
}

void GameState::reset(){
	setFinished(false);
	setNextState("");
}