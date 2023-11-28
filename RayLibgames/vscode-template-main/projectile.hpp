#include "raylib.h"
#include "Entity.hpp"

class projectile: public Entity
{
private:

    /* data */
public:
int lives;
Rectangle rec;
int frame;
float updatetime;
float runningtime;
float projectileDeltaTime;

projectile(int lives, int difficulty, Rectangle rec, int frame, float updatetime, float runningtime);

void move();

};
