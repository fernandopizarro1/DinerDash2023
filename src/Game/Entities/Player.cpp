#include "Player.h"

Player::Player(int x, int y, int width, int height, ofImage sprite, EntityManager* em) : Entity(x, y, width, height, sprite){

    vector<ofImage> chefAnimframes;
    ofImage temp;
    this->burger = new Burger(ofGetWidth()-110, 100, 100, 50);
    temp.cropFrom(sprite, 30,3,66,120);
    chefAnimframes.push_back(temp);
    temp.cropFrom(sprite, 159,3,66,120);
    chefAnimframes.push_back(temp);
    temp.cropFrom(sprite, 287, 3,67,120);
    chefAnimframes.push_back(temp);
    temp.cropFrom(sprite, 31,129,66,120);
    chefAnimframes.push_back(temp);
    this->chefAnim = new Animation(50, chefAnimframes);
    this->entityManager = em;
    
    vector<ofImage> FireAnimFrames; 
    ofImage fire;
    temp.load("images/fire_anim.png"); 
    fire.cropFrom(temp,49,150,132,151);
    FireAnimFrames.push_back(fire);
    fire.cropFrom(temp,229,150,132,151);
    FireAnimFrames.push_back(fire);
    fire.cropFrom(temp,409,150,132,151);
    FireAnimFrames.push_back(fire);
    fire.cropFrom(temp,570,150,132,151);
    this->FireAnim = new Animation(50,FireAnimFrames);
}

void Player::tick(){
    chefAnim->tick();
    FireAnim->tick();
}


void Player::render(){
    BaseCounter *ac = getActiveCounter();
    StoveCounter *sc = getActiveStove();
    if (ac != nullptr) {
        ac->showItem();
    } else if(sc != nullptr){
        sc->showItem();
        item = sc->getItem(); 
        counterx = sc->getX();
        countery = sc->getY(); 
        counterw = sc->getWidth();
        counterh = sc->getHeight(); 
    } 
    if(cooking){
        item->sprite.draw(counterx + counterw / 2 -25, countery - 30, 50, 30);
        ofImage fireFrame = FireAnim->getCurrentFrame(); 
        fireFrame.draw(counterx + counterw / 2 - 35, countery, 25, 15); 
        fireFrame.draw(counterx + counterw / 2 + 8, countery, 25, 15); 
        fireFrame.draw(counterx + counterw / 2 - 35, countery + 20, 25, 15); 
        fireFrame.draw(counterx + counterw / 2 + 8, countery + 20, 25, 15); 

    } else if(cooked){
        ofSetColor(153,101,21);
        item->sprite.draw(counterx + counterw / 2 - 25, countery - 30, 50, 30);
    }
    ofSetColor(256, 256, 256);
    ofImage currentFrame = chefAnim->getCurrentFrame();
    if (facing == "left") {
        currentFrame.mirror(false, true);
    }
    currentFrame.draw(x, y, width, height);
    burger->render();
}

void Player::keyPressed(int key){
    if(key == 'e'){
        BaseCounter* ac = getActiveCounter();
        StoveCounter* sc = getActiveStove();
        if(ac != nullptr){
            Item* item = ac->getItem();
            if(item != nullptr){
                burger->addIngredient(item);
                remove = true; 
            }
        }else if(sc != nullptr){
            Item* item = sc->getItem();
            if(item != nullptr && cooked){
                burger->addIngredient(item);
                remove = true; 
                cooked = false; 
            } else if(item != nullptr && !cooking){
                cooking = true; 
            }
        }
    }else if(key == 'u'){
        burger->removeIngredient();
    }else if(key == OF_KEY_LEFT && x>=0){
        facing = "left";
        x-=speed * 5;
    }else if(key == OF_KEY_RIGHT && x + width <= ofGetWidth() ){
        facing = "right";
        x+=speed * 5;
    }
}
BaseCounter* Player::getActiveCounter(){
    for(Entity* e:entityManager->entities){
        BaseCounter* c = dynamic_cast<BaseCounter*>(e);
        if(StoveCounter* s = dynamic_cast<StoveCounter*>(e)){
            continue;
        }else if(x + e->getWidth()/2 >= e->getX() && x +e->getWidth()/2 <e->getX() + e->getWidth()){
            return c;
        }
    }
    return nullptr;
}

StoveCounter* Player::getActiveStove(){
    for(Entity* e:entityManager->entities){
        StoveCounter* s = dynamic_cast<StoveCounter*>(e);
        if(x + e->getWidth()/2 >= e->getX() && x +e->getWidth()/2 <e->getX() + e->getWidth()){
            return s;
        }
    }
    return nullptr;
}

void Player::keyReleased(int key) {
}
void Player::mousePressed(int x, int y, int button) {
}

void Player::setFacing(string facing){ this->facing = facing; }