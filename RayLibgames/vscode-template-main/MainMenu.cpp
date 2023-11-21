#include "MainMenu.hpp"
void MainMenu::requestClose()
{
    if(WindowShouldClose() || IsKeyPressed(KEY_ESCAPE)) exitWindowRequested = true;
    if(exitWindowRequested)
    {
        if(IsKeyPressed(KEY_Y)) exitWndow = true;
        else if(IsKeyPressed(KEY_N)) exitWindowRequested = false;
    }
}

void MainMenu::DrawCloseMenu()
{
    if(exitWindowRequested == true)
    {
        DrawRectangle(0, 100, 1280, 200, BLACK);
        DrawText("Are you sure you want to exit progra,? [Y/N]",40, 180, 30, WHITE);
    }
}

void MainMenu::playerVictory()
{
    DrawTexture(winScreen,0,0,RAYWHITE);
}

