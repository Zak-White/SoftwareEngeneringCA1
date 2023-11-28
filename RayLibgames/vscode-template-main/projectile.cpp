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