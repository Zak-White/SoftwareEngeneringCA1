#include "GameState.hpp"




void DrawWin()
{
    DrawText("Paused, escape to quit, click to resume",0,0,30,BLUE);
}
void DrawDead()
{
    DrawText("Paused, escape to quit, click to resume",0,0,30,BLUE);
}
void DrawGame()
{
    DrawText("Paused, escape to quit, click to resume",0,0,30,BLUE);
}
void DrawMenu()
{
    DrawText("Paused, escape to quit, click to resume",0,0,30,BLUE);
}

void DrawPaused()
{
    DrawText("Paused, escape to quit, click to resume",0,0,30,BLUE);
}
void DrawOverlay()
{
    switch (GameState)
    {
    case GameStates::Menu:
        DrawMenu();
        break;
    
    case GameStates::Playing:
        DrawGame();
        break;
    case GameStates::Paused:
        DrawPaused();
        break;
    case GameStates::Dead:
        DrawDead();
        break;
    case GameStates::Won:
        DrawWin();
        break;
    }
}
