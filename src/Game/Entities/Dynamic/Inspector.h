#pragma once
#include "Burger.h"
#include "Client.h"


class Inspector : public Client{               
    private:
        Burger* burger;

    public: 
        Inspector(int x, int y, int width, int height, ofImage sprite, Burger* burger);

};