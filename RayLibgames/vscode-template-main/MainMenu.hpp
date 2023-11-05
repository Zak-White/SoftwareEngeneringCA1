#include "raylib.h"
//the exit game code was taken from the raylib examples library https://www.raylib.com/examples.html
class MainMenu
{
public:
    bool exitWindowRequested = false;
    bool exitWndow = false;
    //menu based functions 
    void requestClose();
    void DrawCloseMenu();
};


