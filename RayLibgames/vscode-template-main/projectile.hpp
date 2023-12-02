#include "raylib.h"
#include "Entity.hpp"

class projectile: public Entity
{
private:

    /* data */
public:
int lives;
Vector2 intitalPostion;
bool firing;
Rectangle rec;
int frame;
float updatetime;
float runningtime;
float projectileDeltaTime;

projectile(int lives,Vector2 intitalPostion,Rectangle rec, int frame, float updatetime, float runningtime);

void move();
void despawn();
};
