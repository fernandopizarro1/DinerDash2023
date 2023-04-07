#include "GameState.h"

GameState::GameState() {
    this->restaurant = new Restaurant();
}
void GameState::tick() {
	restaurant->tick();
	if(restaurant->getEntityManager()->left == 10){
		setNextState("Lose");
		setFinished(true);
		setRetry(true);
		restaurant->getEntityManager()->left = 0;
	}
	if(restaurant->getMoney() >= 100){
		setNextState("Win");
		setFinished(true);
		setRetry(true);
		restaurant->setMoney(10);
	}
}
void GameState::render() {
	restaurant->render();
}

void GameState::keyPressed(int key){
	if (key == 'h') {
		setNextState("Start");
		setFinished(true);
		setRetry(false); 
	} else {
		restaurant->keyPressed(key);
	}
}

void GameState::mousePressed(int x, int y, int button){
}

void GameState::keyReleased(int key){
}

void GameState::reset(){
	if(getRetry()){
		this->restaurant = new Restaurant();
	}
	setFinished(false);
	setNextState("");
}