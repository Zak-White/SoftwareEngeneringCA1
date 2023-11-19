#include "Entity.hpp"

Entity::Entity(Vector2 position,Texture2D Sprite, int speed, bool ismovingright, bool ismovingleft, bool alive)
{
    speed = 0;
    ismovingright = false;
    ismovingleft = false;
    alive=false;
}

