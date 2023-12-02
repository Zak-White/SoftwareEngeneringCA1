#include "Player.hpp"

// Used last years c++ module as a base for this. Not sure if it helped https://github.com/ethan-reilly/ethan-zak-MDP-CA2/blob/main/GD4SFMLCode23/Aircraft.hpp
Player::Player(bool hasWon,Rectangle sourcerec,int kills, int lives)
:Entity(position, Sprite, speed, ismovingright, ismovingleft, Alive),hasWon(hasWon),sourcerec(sourcerec),kills(kills),lives(lives)
{
    hasWon=false;
    kills = 0;
    lives = 4;
    position = {(float)1280/2,(float)720/2};
    Sprite = LoadTexture("./Textures/Sprites/SpriteSheet2.0.png");
    ismovingleft = false;
    ismovingright = false;
}

void Player::move() 
{
        if(IsKeyDown(KEY_RIGHT)) position.x +=speed, ismovingright = true;
        if(IsKeyDown(KEY_LEFT)) position.x -=speed, ismovingleft = true;
        if(!IsKeyDown(KEY_RIGHT)) ismovingright = false;
        if(!IsKeyDown(KEY_LEFT))  ismovingleft = false;
        if(IsKeyDown(KEY_UP)) position.y -=speed;
        if(IsKeyDown(KEY_DOWN)) position.y +=speed;
}

void Player::playerKillsIncrease()
{
   if(IsKeyPressed(KEY_M))
    {
        kills = kills+1;
    }
    else if(IsKeyPressed(KEY_Y))
    {
        lives=lives-1;
    }
}
void Player::endGame()
{

    if(kills >= 3)
    {
        hasWon=true;
        //victory screen reference <a href="https://www.freepik.com/free-vector/cartoon-fastfood-with-self-kiosk-background_19964668.htm#query=fast%20food%20interior&position=0&from_view=keyword&track=ais&uuid=8c01f6b1-5b9b-4d1b-89e6-d9505fa09ebb">Image by pikisuperstar</a> on Freepik
        //MainMenu::playerVictory();
    }

    if(lives<=0)
    {

        DrawRectangle(0, 100, 1280, 200, BLACK);
        DrawText("You Have Died",40, 180, 30, WHITE);
    }
}

void Player::direction()
{
      //Basic animations because I could not get spritesheet animation to work
        if(ismovingleft)
        {
        DrawTextureRec(Sprite,
        Rectangle{134,35,18,32},
        Vector2{position},
        RAYWHITE);
        }

        else if(ismovingright)
        {
        DrawTextureRec(Sprite,
        Rectangle{134,66,18,32},
        Vector2{position},
        RAYWHITE);
        }
        else
        {
        DrawTextureRec(Sprite,
        Rectangle{128,0,29,32},
        Vector2{position},
        RAYWHITE);
        }
}

void Player::checkBorder()
{
    if(position.x>=1265)
    {
        position.x=1265;
    }
    else if(position.x<=0)
    {
        position.x=0;
    }
}

void Player::unload()
{
    UnloadTexture(Sprite);
}