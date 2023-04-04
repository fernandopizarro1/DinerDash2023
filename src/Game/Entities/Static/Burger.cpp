//
// Created by joshu on 11/4/2020.
//

#include "Burger.h"

Burger::Burger(int x, int y, int width, int height){
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
}

void Burger::addIngredient(Item *item) {
    ingredients.push_back(item);
}

void Burger::removeIngredient(){
    if(ingredients.size() >= 1){
        ingredients.pop_back();
    } 
}

void Burger::render(){
    int counter = 1;
    for (Item* ingredient:ingredients){
        if(ingredient->name == "patty"){
            ofSetColor(153,101,21);
        }else {
            ofSetColor(255);
        }
        ingredient->sprite.draw(x-5,y-(counter * 10)+55,width*0.70,height*0.70);
        counter++; 
    }
}

void Burger::clear(){
    ingredients.clear();
}

bool Burger::Burgers_Equal(Burger* burger1, Burger* burger2){
    vector<Item *> burg1ing = burger1->getIngredients();
    vector<Item *> burg2ing = burger2->getIngredients();
    vector<Item *> copy2 = burg2ing;
    int lastitem = burg2ing.size() - 1;
    if(burg1ing.size() != burg2ing.size()){
        return false;
    } else if(burg2ing[lastitem]->name != "topBun" || burg2ing[0]->name != "bottomBun"){
        return false;
    }
    for(int i = 0; i < burg1ing.size(); i++){
        bool same = false;
        for(int j = 0; j < copy2.size(); j++){
            if(burg1ing[i] == copy2[j]){
                same = true;
                copy2.erase(copy2.begin() + j);
                break;
            }
        }
        if(!same){
            return false;
        }
    }
    return true; 
}