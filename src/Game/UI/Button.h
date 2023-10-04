#include "ofMain.h"

class Button {
    
    public:
        Button();
        Button(int, int, int, int, string);
        void mousePressed(int x, int y);
        void tick();
        void render();
        bool wasPressed();
        void reset();
        void setColor(int red, int green, int blue){
            this->red = red;
            this->green = green;
            this->blue = blue; 
        }

    private:
        int xPos, yPos, width, height;
        int red, green, blue; // to change color of button to whatever i want
        ofImage buttonImage;
        ofImage clickedButtonImage;
        bool pressed = false;
        int pressedCounter = -1;
        string buttonText;
};