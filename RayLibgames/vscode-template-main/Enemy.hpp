#include "raylib.h"
#include "Entity.hpp"
class Enemy: public Entity
{
private:
 // zombies will be set to one life by default.
int lives;
bool respawning;


public:

int difficulty; // I will use this to control the speed of the enemies
//Rectangle SourceRec;
Rectangle rec;
int frame;
float framesCounter;
float framesSpeed;
float deltaTime;
Enemy(int lives, int difficulty, Rectangle rec, int frame,float framesCounter, float framesSpeed, float deltaTime);
//Enemy();
void animation(); // the animation setup. Taken from class
void move();
void setLives();
void respawn();
void drawEnemy();
void direction();
void difficultychange();
void decreaseLives();
void kill();
void unload();
//void die();

};

