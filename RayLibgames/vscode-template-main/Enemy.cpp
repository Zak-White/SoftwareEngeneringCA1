#include "Enemy.hpp"

Enemy::Enemy(int lives,int difficulty, Rectangle SourceRec, Rectangle rec, int frame, float updatetime, float runningtime)
:Entity(position, Sprite, speed, ismovingright, ismovingleft, Alive)
{
    lives = 1;
    difficulty = 1;
    position = {(float)0,(float)720/2};
    Sprite = LoadTexture("./Textures/Sprites/Zombie Sprite Sheet.png");
    ismovingleft = false;
    ismovingright = false;
    
}


//640
void Enemy::move()
{
    if(position.x > 640) position.x -=speed, ismovingleft = true;
    if(position.x < 640) position.x +=speed, ismovingright = true;
}


