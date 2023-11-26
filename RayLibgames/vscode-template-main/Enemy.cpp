#include "Enemy.hpp"

Enemy::Enemy(int lives,int difficulty, Rectangle rec, int frame, float updatetime, float runningtime)
:Entity(position, Sprite, speed, ismovingright, ismovingleft, Alive),lives(lives), difficulty(difficulty), rec(rec),frame(frame),updatetime(updatetime),runningtime(runningtime)
{
    lives = 1;
    position = {(float)1280/2,(float)720/2};
    Sprite = LoadTexture("./Textures/Sprites/SpriteSheet2.0.png");
    ismovingleft = false;
    ismovingright = false;
    difficulty = 1;
}


//640
void Enemy::move()
{
    if(position.x > 640) position.x -=speed, ismovingleft = true;
    if(position.x < 640) position.x +=speed, ismovingright = true;
}


