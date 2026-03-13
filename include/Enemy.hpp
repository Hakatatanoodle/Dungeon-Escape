#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "Entity.hpp"

class Enemy: public Entity
{
    protected:

    public:

    Enemy(int h , int ap,float s , sf::Vector2f)

    virtual void draw(sf::RenderWindow& window);
    virtual void move(float dt) = 0;
    virtual void attack(Entity& target);
    virtual void updateState(float dt);

    virtual ~Enemy() {};
};
#endif