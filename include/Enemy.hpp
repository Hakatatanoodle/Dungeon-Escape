#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "Entity.hpp"

class Enemy: public Entity
{
    protected:
    int respawnCounter ;

    public:

    Enemy(int h , int ap,float s , sf::Vector2f pos);

    virtual void move(float dt,sf::Vector2f playerPos) = 0;
    virtual void updateState(float dt,sf::Vector2f playerPos);

    virtual ~Enemy() {};
};
#endif