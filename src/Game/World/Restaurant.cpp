//
// Created by joshu on 11/3/2020.
//

#include "Restaurant.h"

Player *Restaurant::getPlayer() { return player; }
void Restaurant::setPlayer(Player *player) { this->player = player; }

Restaurant::Restaurant() {
    floor.load("images/floor.jpg");
    FurnitureSpriteSheet.load("images/sprite.png");
    WelcomeMattImg.load("images/Welcome.png");
    entityManager = new EntityManager();
    ofImage chefPlayerImage;
    chefPlayerImage.load("images/chef.png");
    this->player = new Player(0, 600, 64, 64, chefPlayerImage, entityManager);    
    initItems();
    initCounters();
    initClients();
    generateClient();
    tableImg.cropFrom(FurnitureSpriteSheet, 20, 28, 63, 52); // table
    chairImg.cropFrom(FurnitureSpriteSheet, 108, 14, 31, 37); // chair
    towelchairImg.cropFrom(FurnitureSpriteSheet, 108, 52, 31, 37); // the other chair 
    entityManager->addEntity(new Entity(200, 100, 100, 100, tableImg)); // top left
    entityManager->addEntity(new Entity(150, 150, 50, 50, chairImg));
    entityManager->addEntity(new Entity(300, 150, 50, 50, chairImg));
    entityManager->addEntity(new Entity(200, 300, 100, 100, tableImg)); // bottom left
    entityManager->addEntity(new Entity(150, 350, 50, 50, chairImg));
    entityManager->addEntity(new Entity(300, 350, 50, 50, chairImg)); 
    entityManager->addEntity(new Entity(500, 100, 100, 100, tableImg)); // top right
    entityManager->addEntity(new Entity(450, 150, 50, 50, chairImg));
    entityManager->addEntity(new Entity(600, 150, 50, 50, chairImg));
    entityManager->addEntity(new Entity(500, 300, 100, 100, tableImg)); // bottom right
    entityManager->addEntity(new Entity(450, 350, 50, 50, chairImg));
    entityManager->addEntity(new Entity(600, 350, 50, 50, chairImg));
    entityManager->addEntity(new Entity(ofGetWidth() - 70, 0, 70, 70, WelcomeMattImg)); // Welcome matt

}
void Restaurant::initItems(){
    ofImage burgerSpriteSheet, cheeseImg, lettuceImg, tomatoImg, burgerImg, botBreadImg, topBreadImg, plateImg;
    burgerSpriteSheet.load("images/burger.png");

    topBreadImg.cropFrom(burgerSpriteSheet, 25, 16, 112, 43); // top bun
    burgerImg.cropFrom(burgerSpriteSheet, 30, 134, 103, 48); // patty
    cheeseImg.cropFrom(burgerSpriteSheet, 169, 213, 102, 39); // cheese
    tomatoImg.cropFrom(burgerSpriteSheet, 169, 158, 110, 41); // tomato
    lettuceImg.cropFrom(burgerSpriteSheet, 161, 62, 117, 34); // lettuce
    botBreadImg.cropFrom(burgerSpriteSheet, 444, 270, 115, 39); // bottom bun
    plateImg.cropFrom(burgerSpriteSheet, 575, 263, 131, 51); // plate

    cheese = new Item(cheeseImg, "cheese");
    lettuce = new Item(lettuceImg, "lettuce");
    tomato = new Item(tomatoImg, "tomato");
    burger = new Item(burgerImg, "patty");
    botBread = new Item(botBreadImg, "bottomBun");
    topBread = new Item(topBreadImg, "topBun");
    posingredients = {cheese,lettuce,tomato,burger};
}
void Restaurant::initCounters(){
    int counterWidth = 96;
    int yOffset = 500;
    ofImage counterSheet, plateCounterImg, cheeseCounterImg, stoveCounterImg, lettuceCounterImg, emptyCounterImg, tomatoCounterImg, breadCounterImg;
    counterSheet.load("images/kitchen_cabinets_by_ayene_chan.png");
    stoveCounterImg.cropFrom(counterSheet, 224,12,32,43);//stoveTop
    lettuceCounterImg.cropFrom(counterSheet,96,76,32,43);//Vegetables
    emptyCounterImg.cropFrom(counterSheet,0,245,30,43);//Empty
    tomatoCounterImg.cropFrom(counterSheet,96,200,32,48);//fruit basket
    cheeseCounterImg.cropFrom(counterSheet,64,73,32,46);//cheese
    plateCounterImg.cropFrom(counterSheet,0,133,32,50);//plates
    breadCounterImg.cropFrom(counterSheet,0,63,34,56);//buns
    entityManager->addEntity(new BaseCounter(0,yOffset-16, counterWidth, 117, nullptr, plateCounterImg));
    entityManager->addEntity( new BaseCounter(counterWidth,yOffset-7, counterWidth,108, cheese, cheeseCounterImg));
    entityManager->addEntity(new BaseCounter(counterWidth*2,yOffset, counterWidth, 102, burger, stoveCounterImg));
    entityManager->addEntity(new BaseCounter(counterWidth*3, yOffset, counterWidth, 102, lettuce, lettuceCounterImg));
    entityManager->addEntity(new BaseCounter(counterWidth*4,yOffset, counterWidth, 102, nullptr, emptyCounterImg));
    entityManager->addEntity(new BaseCounter(counterWidth*5, yOffset -10, counterWidth, 113, tomato, tomatoCounterImg));
    entityManager->addEntity(new BaseCounter(counterWidth*6, yOffset-32, counterWidth, 133, botBread, breadCounterImg));
    entityManager->addEntity(new BaseCounter(counterWidth*7, yOffset-32, counterWidth, 133, topBread, breadCounterImg));

}
void Restaurant::initClients(){
    ofImage temp;
    temp.load("images/People/Car_Designer3Female.png");
    people.push_back(temp);
    temp.load("images/People/Freedom_Fighter2Male.png");
    people.push_back(temp);
    temp.load("images/People/Hipster.png");
    people.push_back(temp);
    temp.load("images/People/Lawyer2Male.png");
    people.push_back(temp);
    temp.load("images/People/Mad_Scientist3Female.png");
    people.push_back(temp);
    temp.load("images/People/Programmer2Male.png");
    people.push_back(temp);
    temp.load("images/People/Songwriter3Male.png");
    people.push_back(temp);
    temp.load("images/People/Weather_Reporter2Female.png");
    people.push_back(temp);
}
void Restaurant::tick() {
    ticks++;
    if(ticks % 400 == 0){
        generateClient();
    }
    player->tick();
    entityManager->tick();

}


void Restaurant::generateClient(){
    Burger* b = new Burger(72, 100, 50, 25);
    b->addIngredient(botBread);
    for(int i = 0; i < ofRandom(posingredients.size()); i++){
        b->addIngredient(posingredients[ofRandom(posingredients.size())]);
    }
    b->addIngredient(topBread);
    entityManager->addClient(new Client(0, 50, 64, 72,people[ofRandom(8)], b));
}
void Restaurant::render() {
    floor.draw(0,0, ofGetWidth(), ofGetHeight());
    player->render();
    entityManager->render();
    ofSetColor(0, 100, 0);
    ofDrawBitmapString("Money: $" + to_string(money), ofGetWidth()/2, 10);
    ofSetColor(256, 256, 256);
}
void Restaurant::serveClient(){
    if(entityManager->firstClient!= nullptr){
        if(player->getBurger()->Burgers_Equal(entityManager->firstClient->getBurger(),player->getBurger())){
            money += entityManager->firstClient->serve(player->getBurger());
        }
    }
}
void Restaurant::keyPressed(int key) {
    player->keyPressed(key);
    if(player->remove){
        money--;
        player->remove = false; 
    }
    if(key == 's'){
        serveClient();
    }
}
