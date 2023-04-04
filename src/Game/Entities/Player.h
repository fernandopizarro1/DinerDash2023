#pragma once
#include "Animation.h"
#include "Burger.h"
#include "EntityManager.h"
#include "BaseCounter.h"
class Player: public Entity{

    private:
        int speed = 5;
        float counterx, countery, counterw, counterh; 
        string facing = "right";
        Animation *chefAnim;
        Burger *burger;
        EntityManager* entityManager;
        Item* item; 
    public:
        Player(int x, int y, int width, int height, ofImage sprite, EntityManager* em);
        void tick();
        void render();
        void keyPressed(int);
        void keyReleased(int);
        void mousePressed(int, int, int);
        void setFacing(string);
        BaseCounter* getActiveCounter();
        StoveCounter* getActiveStove();
        Burger* getBurger(){ return burger;
        }
        bool remove = false; 
        bool cooked = false;
        bool cooking = false; 
};