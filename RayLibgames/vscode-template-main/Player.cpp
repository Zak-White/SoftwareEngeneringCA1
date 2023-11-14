#include "Player.hpp"


void Player::move() 
{
        if(IsKeyDown(KEY_RIGHT)) chefPosition.x +=speed, isMovingRight = true;
        if(IsKeyDown(KEY_LEFT)) chefPosition.x -=speed, isMovingLeft = true;
        if(!IsKeyDown(KEY_RIGHT)) isMovingRight = false;
        if(!IsKeyDown(KEY_LEFT))  isMovingLeft = false;
        if(IsKeyDown(KEY_UP)) chefPosition.y -=speed;
        if(IsKeyDown(KEY_DOWN)) chefPosition.y +=speed;
}

void Player::endGame()
{
    if(kills >= 30)
    {
        //end game functionality
    }

    if(lives<=0)
    {
        //death functionality here
    }
}

void Player::direction()
{
      
        if(isMovingLeft)
        {
        DrawTextureRec(ChefFront,
        Rectangle{134,35,18,32},
        Vector2{chefPosition},
        RAYWHITE);
        }

        else if(isMovingRight)
        {
        DrawTextureRec(ChefFront,
        Rectangle{134,66,18,32},
        Vector2{chefPosition},
        RAYWHITE);
        }
        else
        {
        DrawTextureRec(ChefFront,
        Rectangle{128,0,29,32},
        Vector2{chefPosition},
        RAYWHITE);
        }
}

void Player::checkBorder()
{
    if(chefPosition.x>=1265)
    {
        chefPosition.x=1265;
    }
    else if(chefPosition.x<=0)
    {
        chefPosition.x=0;
    }
}

void Player::unload()
{
    UnloadTexture(ChefFront);
}