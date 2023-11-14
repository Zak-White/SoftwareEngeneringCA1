#include "raylib.h"

class Entity
{
    public:
    Vector2 position;
    Texture2D Sprite;
    int speed;
    bool ismovingright= false;
    bool ismovingleft = false;
    bool Alive;

    Entity(Vector2 position,Texture2D Sprite, int speed, bool ismovingright, bool ismovingleft, bool alive): position(position), Sprite(Sprite), speed(speed), ismovingright(ismovingright), ismovingleft(ismovingleft), Alive(alive){}
};