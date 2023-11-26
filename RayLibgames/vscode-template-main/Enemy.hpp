#include "raylib.h"
#include "Entity.hpp"
class Enemy: public Entity
{
private:
int lives; // zombies will be set to one life by default.
int difficulty; // I will use this to control the speed


public:
Rectangle SourceRec;
Rectangle rec;
int frame;
float updatetime;
float runningtime;
Enemy(int lives, int difficulty, Rectangle SourceRec, Rectangle rec, int frame, float updatetime, float runningtime);


void move();
void direction();
void difficultychange();
void unload();
//void die();

};

