#include "raylib.h"
#include "Entity.hpp"

class Player: public Entity
{
//set up a default player at a later stage 
public:
    Vector2 chefPosition;
    Texture2D ChefFront;
    int speed;
    bool isMovingLeft = false; //Setting up some example variables
    bool isMovingRight = false; //Setting up some example variables
    bool Alive = false; // set the players status in the game
    
    Player(Vector2 chefPosition,Texture2D ChefFront, int speed, bool ismovingright, bool ismovingleft, bool alive, int kills, int lives):
    Entity(chefPosition,ChefFront,speed,ismovingright,ismovingleft,alive), kills(kills), lives(lives){}

    void move(); // Player movement function
    void endGame();// end the game when the player hits a certain number of kills or if they have enough lives toi keep playing
    void direction(); //changes the players sprite based on the decoration travelled
    void checkBorder(); // stops the player going off the sides of the screen
    void unload(); // unloads the players textures

    private:
    int kills;
    int lives;
};



