#include "projectile.hpp"

projectile::projectile(int lives,Vector2 intitalPostion, Rectangle rec, int frame,float updatetime,float runningtime)
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
    if(IsKeyDown(KEY_SPACE))
    {
    firing = true;
    if(firing ==true && ismovingleft == true)
    {
        position.x=intitalPostion.x;
        position.x += speed;;
        DrawTextureRec(Sprite,rec,position,WHITE);
    }
    else if(firing == true)
    {
        position.x=intitalPostion.x;
        position.x-=speed;
        DrawTextureRec(Sprite,rec,position,WHITE);
    }
        
    }

}

void projectile::despawn()
{
    if(position.x>=1265)
    {
        firing = false;
    }
    else if(position.x<=0)
    {
        
        firing = false;
    }
}