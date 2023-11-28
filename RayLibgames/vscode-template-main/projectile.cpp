#include "projectile.hpp"

projectile::projectile(int lives, Rectangle rec, int frame,float updatetime,float runningtime)
:Entity(position, Sprite, speed, ismovingright, ismovingleft, Alive)
{
    lives = 1;
    position = {(float)0,(float)720/2};
    Sprite = LoadTexture("./Textures/Sprites/projectile.png");
    ismovingleft = false;
    ismovingright = false;
    
}

void projectile::move()
{
    // I want it to take which way the player is facing and then change which way it flies
    if(IsKeyPressed(KEY_SPACE))
    {
    DrawTextureRec(Sprite,rec,position,WHITE);
    if(ismovingleft==true)
    {
        position.x=position.x+ speed;
        
    }
    if(ismovingright==true)
    {
        position.x=position.x- speed;
    }

    }

}