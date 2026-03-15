#ifndef STALKER_HPP
#define STALKER_HPP

#include "Enemy.hpp"

class Stalker: public Enemy
{
    private:
    float randomFactor;

    public: 
    Stalker(int h , int ap,float s , sf::Vector2f pos);

    void move(float dt,sf::Vector2f playerPos);

    virtual ~Stalker();//destructor
};

#endif