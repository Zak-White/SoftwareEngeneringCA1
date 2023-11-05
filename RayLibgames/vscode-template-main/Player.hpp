#include "raylib.h"

class Player
{

public:
    Vector2 chefPosition;
    Texture2D ChefFront;
    int speed;
    bool isMovingLeft = false; //Setting up some example variables
    bool isMovingRight = false; //Setting up some example variables
    bool Alive = false;


    void move();
    void direction();
    void unload();
};



