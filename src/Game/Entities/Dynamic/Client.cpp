#include "Client.h"

Client::Client(int x, int y, int width, int height, ofImage sprite, Burger* burger): Entity(x, y, width, height, sprite){
    this->burger = burger;
}
Client::~Client(){
    delete burger;
}
void Client::render(){
    burger->render();
    double patienceloss = (patience/originalPatience)*255;
    ofSetColor(255,patienceloss,patienceloss);
    sprite.draw(x, y, width, height);
    ofSetColor(ofColor::white);
    if(nextClient != nullptr){
        nextClient->render();
    }
}

void Client::tick(){
    patience--;
    burger->setY(y);
    if(patience == 0){
        isLeaving = true;
    }
    if(nextClient != nullptr){
        nextClient->tick();
    }
}

int Client::serve(Burger* burger){
    isLeaving = true;
    vector<Item *> ingredients = burger->getIngredients();
    int finalprice = 0;
    for(Item* i : ingredients){
        if(i->name == "cheese"){
            finalprice += 3;
        }else if(i->name == "tomato" || i->name == "lettuce"){
            finalprice += 2;
        }else if(i->name == "patty"){
            finalprice +=4;
        }else if(i->name == "topBun" || i->name == "bottomBun"){
            finalprice++;
        }
    }
    return finalprice;
}