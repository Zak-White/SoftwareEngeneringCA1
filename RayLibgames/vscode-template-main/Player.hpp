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


    void move(); // Player movement function
    void direction(); //changes the players sprite based on the decoration travelled
    void checkBorder(); // stops the player going off the sides of the screen
    void unload(); // unloads the players textures
};



