//
// Created by joshu on 11/4/2020.
//
#pragma once

#include "Entity.h"
#include "Item.h"

class Burger {
  private:
    int x, y, width, height;
    vector<Item *> ingredients;

  public:
    Burger(int, int, int, int);
    void addIngredient(Item *item);
    void removeIngredient();
    void render();
    void clear();
    void setY(int y) {
        this->y = y;
    }
    bool Burgers_Equal(Burger* burger1, Burger* burger2);
    vector<Item *> getIngredients() {return ingredients;}
};
