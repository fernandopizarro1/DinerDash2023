#pragma once

#include "Entity.h"
#include "Burger.h"

class Client: public Entity{
    private:
        Burger* burger;
        double originalPatience = 2500.0;
        int patience=2500;
    public:
        Client(int, int, int, int, ofImage, Burger*);
        virtual ~Client();
        void tick();
        void render();
        int serve(Burger*);
        Client* nextClient=nullptr;
        bool isLeaving=false;

        int getPatience() { return patience; }
        Burger* getBurger() {return burger;}
};