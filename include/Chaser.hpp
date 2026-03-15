#ifndef CHASER_HPP
#define CHASER_HPP
#include "Enemy.hpp"

class Chaser : public Enemy
{
    public:
    Chaser(int h , int ap,float s , sf::Vector2f pos); 

    void move(float dt,sf::Vector2f playerPos);

    virtual ~Chaser();//destructor
};

#endif