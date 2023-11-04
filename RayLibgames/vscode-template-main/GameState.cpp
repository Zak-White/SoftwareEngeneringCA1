#include "GameState.hpp"

double time;

double GetCurrentTime() //the two following functions are used to help with the pause feature
{
    return time;
}
float GetDeltaTime()
{
    if(GameState== GameStates::Paused)
    {
        return 0;
    }
    else
    {
        return GetFrameTime();
    }
}

bool updateGameState()
{
    if(GameState !=GameStates::Paused)
    {
        time += GetDeltaTime();
    }

    if(GameState == GameStates::Paused)
    {
        // Add code in here at later stage for functionality
    }

    if(GameState ==GameStates::Playing)
    {
        if(IsKeyPressed(KEY_ESCAPE))
        {
            GameState = GameStates::Paused;
        }
    }

    if(GameState == GameStates::Won)
    {
        //Add functionality at a later stage
    }

    if(GameState == GameStates::Dead)
    {
        //Add functionality at a later stage 
    }
}
void DrawWin()
{
    DrawText("Winning, escape to quit, click to resume",0,0,30,BLUE);
}
void DrawDead()
{
    DrawText("Dead, escape to quit, click to resume",0,0,30,BLUE);
}
void DrawGame()
{
    DrawText("Playing, escape to quit, click to resume",0,0,30,BLUE);
}
void DrawMenu()
{
    DrawText("Menu Times, escape to quit, click to resume",0,0,30,BLUE);
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
