#include "raylib.h"
//the exit game code was taken from the raylib examples library https://www.raylib.com/examples.html
class MainMenu
{
public:
    Texture2D winScreen;
    bool exitWindowRequested = false;
    bool exitWndow = false;
    //menu based functions 

    void playerVictory();
    void requestClose();
    void DrawCloseMenu();
};


