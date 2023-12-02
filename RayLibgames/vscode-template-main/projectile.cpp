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

void projectile::fire()
{
    //What was important was removing this from the move function and making it its own thing as it was stopping the movement from ever being called.
    //the inital position is only important at the moment when space is pressed
    if(IsKeyPressed(KEY_SPACE))
    {
        firing = true;
        position.x=intitalPostion.x;
    }
}

void projectile::move()
{
    // I want it to take which way the player is facing and then change which way it flies
     
    if(firing==true&&Alive==true)
    {
        DrawTextureRec(Sprite,rec,position,WHITE);
     if(ismovingleft == true)
        {
           
            position.x -= speed;
        }
    else
        {
            
            position.x+=speed;
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

void projectile::projectileDecreaseLives()
{
    lives--;
}

void projectile::kill()
{
    if(lives==0)
    {
            Alive=false;
    }

}