#include "GameState.hpp"




void DrawWin()
{

}
void DrawDead()
{

}
void DrawGame()
{

}
void DrawMenu()
{

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
