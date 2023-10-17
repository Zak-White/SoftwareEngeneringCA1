#pragma once
//This code is based off an astroid game found here: https://github.com/raylib-extras/asteroids_example/blob/main/game/include/entity.h

class Entity
{
    public:

    bool alive = false;// The alive status of a entity.
    float speed = 0;// The base speed of an entity.

    virtual void update();// This updates the enemies
    virtual bool colide(const Entity& other); // This controls the collision between two different entities.

    inline virtual void Draw() const{};// This is a draw function 
};