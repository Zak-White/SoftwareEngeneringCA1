#include "Enemy.hpp"

Enemy::Enemy(int lives,int difficulty, Rectangle rec, int frame,float framesCounter, float framesSpeed, float deltaTime)
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
    framesCounter = 0;
    framesSpeed = 10;
    
}
//A mix of my own code and the animation code from class
void Enemy::move()
{

    if(Alive==true)
    {
         framesCounter++;
    if(framesCounter >=(60/framesSpeed))
    {
        framesCounter=0;
        frame++;
    }
        if(frame>10) frame = 0;
        rec.x= frame*Sprite.width/10;
    if(position.x > 640) 
    {
        position.x -=speed, ismovingleft = true;//enemy movement
        /*
            runningtime += deltaTime;
        if(runningtime>= updatetime)
        {
            runningtime=0.f;
            rec.x=(float)frame * rec.width;
            frame ++;
            if(frame>9)
            {
                frame = 0;
            }
        }
        */
        
    }
    if(position.x < 640) 
    {
        position.x +=speed, ismovingright = true;//enemy movement
        /*
        runningtime += deltaTime;
        if(runningtime>= updatetime)
        {
            runningtime=0.f;
            rec.x=(float)frame * rec.width;
            frame ++;
            if(frame>9)
            {
                frame = 0;
            }
        }
        */
        
    }
    }

}

void Enemy::setLives()
{
    lives = 1;
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

void Enemy::decreaseLives()
{
    lives = lives-1;
}

void Enemy::drawEnemy()
{
    if(Alive == true)
    {
        DrawTextureRec(Sprite,rec,position,WHITE);
    }
    
}

void Enemy::kill()
{
        if(lives==0)
    {
            Alive=false;
    }
}
