#include "raylib.h"
#include "Entity.hpp"
class Enemy: public Entity
{
private:
int lives; // zombies will be set to one life by default.



public:
int difficulty; // I will use this to control the speed of the enemies
//Rectangle SourceRec;
Rectangle rec;
int frame;
float framesCounter;
float framesSpeed;
float deltaTime;
Enemy(int lives, int difficulty, Rectangle rec, int frame,float framesCounter, float framesSpeed, float deltaTime);

void animation(); // the animation setup. Taken from class
void move();
void drawEnemy();
void direction();
void difficultychange();
void unload();
//void die();

};

