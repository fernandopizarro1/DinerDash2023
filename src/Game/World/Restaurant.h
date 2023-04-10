//
// Created by joshu on 11/3/2020.
//
#pragma once

#include "BaseCounter.h"
#include "EntityManager.h"
#include "Player.h"
#include "ofMain.h"
#include "Inspector.h"

class Restaurant {
    private:
        Player* player;
        EntityManager* entityManager;
        // Ticks to cook burger
        int bticks = 0; 
        int ticks=0;
        std::vector<ofImage> people;
        int money = 10;
        vector<Item*> posingredients; 
        ofImage inspector;
        int message_ticks = 0;


    public:
        Restaurant();
        Player* getPlayer();
        void setPlayer(Player *player);
        Item* cheese;
        Item* lettuce;
        Item* tomato;
        Item* burger;
        Item* botBread;
        Item* topBread;
        ofImage FurnitureSpriteSheet, chairImg, tableImg, towelchairImg; 
        ofImage WelcomeMattImg;
        ofImage floor;
        void initItems();
        void initCounters();
        void initClients();
        void generateClient();
        void generateInspector();
        void serveClient();
        void tick();
        void render();
        void keyPressed(int key);
        EntityManager* getEntityManager() { return entityManager; }

        void setMoney(int money){this->money = money;}

        int getMoney(){return money;}

};
