#include "Player.hpp"

// Used last years c++ module as a base for this. Not sure if it helped https://github.com/ethan-reilly/ethan-zak-MDP-CA2/blob/main/GD4SFMLCode23/Aircraft.hpp
Player::Player(int kills, int lives)
:Entity(position, Sprite, speed, ismovingright, ismovingleft, Alive),kills(kills),lives(lives)
{
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
        DrawRectangle(0, 100, 1280, 200, BLACK);
        DrawText("You Have Won",40, 180, 30, WHITE);
    }

    if(lives<=0)
    {
        DrawRectangle(0, 100, 1280, 200, BLACK);
        DrawText("You Have Died",40, 180, 30, WHITE);
    }
}

void Player::direction()
{
      
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