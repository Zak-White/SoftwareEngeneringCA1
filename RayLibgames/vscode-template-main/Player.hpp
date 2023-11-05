#include "raylib.h"

class Player
{
//set up a default player at a later stage 
public:
    Vector2 chefPosition;
    Texture2D ChefFront;
    int speed;
    bool isMovingLeft = false; //Setting up some example variables
    bool isMovingRight = false; //Setting up some example variables
    bool Alive = false; // set the players status in the game


    void move();
    void direction();
    void checkBorder();
    void unload();
};



