#include "raylib.h"
#include "Entity.hpp"

// Looking into constructor code from the following: https://www.geeksforgeeks.org/constructors-c/
// No matching function explanation looking into: https://stackoverflow.com/questions/15113856/no-matching-function-for-call-to I did not figure this out but I did try some stuff that may be in the history
class Player: public Entity
{
//set up a default player at a later stage 
public:
    // set the players status in the game
    bool hasWon = false;

    Player(bool hasWon,int kills, int lives);
    

    void move(); // Player movement function
    void playerKillsIncrease();
    void endGame();// end the game when the player hits a certain number of kills or if they have enough lives toi keep playing
    void direction(); //changes the players sprite based on the decoration travelled
    void checkBorder(); // stops the player going off the sides of the screen
    void unload(); // unloads the players textures

    private:
    int kills = 0;
    int lives = 4;
};



