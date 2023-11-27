#include "Enemy.hpp"

Enemy::Enemy(int lives,int difficulty, Rectangle rec, int frame, float updatetime, float runningtime)
:Entity(position, Sprite, speed, ismovingright, ismovingleft, Alive)
{
    lives = 1;
    difficulty = 1;
    position = {(float)0,(float)720/2};
    Sprite = LoadTexture("./Textures/Sprites/Zombie Sprite Sheet.png");
    ismovingleft = false;
    ismovingright = false;
    
}

void Enemy::animation()
{
    rec.width = Sprite.width/10;
    rec.height = Sprite.height;
    rec.x = 0;
    rec.y = 0;
    position.x=position.x;
    position.y = 720 - rec.height;
    frame = 0;
    updatetime = 1.0;
    runningtime = 0.0;
}
//640
void Enemy::move()
{
    

    if(position.x > 640) 
    {
        position.x -=speed*deltaTime, ismovingleft = true;//enemy movement
        runningtime += deltaTime;
        if(runningtime>= updatetime)
        {
            runningtime=0.0;
            rec.x=(float)frame * rec.width;
            frame ++;
            if(frame>9)
            {
                frame = 0;
            }
        }
    }
    if(position.x < 640) 
    {
        position.x +=speed*deltaTime, ismovingright = true;//enemy movement
        runningtime += deltaTime;
        if(runningtime>= updatetime)
        {
            runningtime=0.0;
            rec.x=(float)frame * rec.width;
            frame ++;
            if(frame>9)
            {
                frame = 0;
            }
        }
    }
    


    DrawTextureRec(Sprite,rec,position,WHITE);
}

void Enemy::difficultychange()
{
    if(difficulty==1)
    {
        speed = 1;
    }
    else if(difficulty==2)
    {
        speed=2;
    }
    else
    {
        speed = 3;
    }
}


