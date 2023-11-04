#include "raylib.h"
//Based off my game from Multiplayer Distributed programming from last year and https://github.com/raylib-extras/asteroids_example/blob/main/game/include/game.h

enum class GameStates //Creates the class GameStates that is restricted to the following variables 
{
    Menu,
    Playing,
    Paused,
    Dead,
    Won
};
extern GameStates GameState; // this allows me to declare a global variable that can be called througout the program or in the stated header files
bool updateGameState(); // I will use this to update the game state
inline bool isPaused() {return GameState == GameStates::Paused; }; // This will be used to determine if the game is paused 
void DrawOverlay();