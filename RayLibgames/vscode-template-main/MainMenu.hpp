#include "raylib.h"
//the exit game code was taken from the raylib examples library https://www.raylib.com/examples.html
class MainMenu
{
public:
    Texture2D winScreen;
    Texture2D lossScreen;
    bool exitWindowRequested = false;
    bool exitWndow = false;
    bool inMainMenu = false;
    bool inDifficultyMenu = false;
    //menu based functions 

    void playerVictory();
    void playerLoss();
    void requestClose();
    void DrawCloseMenu();
};


