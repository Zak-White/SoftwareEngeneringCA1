#include "raylib.h"
#ifndef ENTITY_HPP
#define ENTITY_HPP
class Entity
{
    public:
    Vector2 position;
    Texture2D Sprite;
    int speed = 0;
    bool ismovingright=false;
    bool ismovingleft=false;
    bool Alive=false;

    Entity(Vector2 position,Texture2D Sprite, int speed, bool ismovingright, bool ismovingleft, bool alive);
};
#endif