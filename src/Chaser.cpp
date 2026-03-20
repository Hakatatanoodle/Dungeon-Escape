#include "Chaser.hpp"
#include<cmath>

Chaser::Chaser(int h , int ap,float s , sf::Vector2f pos):Enemy(h,ap,s,pos)
{
    shape = new sf::CircleShape(40.f);
    shape->setFillColor(sf::Color::Red);
}
void Chaser::move(float dt , sf::Vector2f playerPos)
{
    float dx,dy,distance;
    sf::Vector2f currentPosition=shape->getPosition();
    dx = playerPos.x - currentPosition.x;
    dy = playerPos.y - currentPosition.y;
    distance = std::sqrt(dx*dx+dy*dy);

    //guard to protect 0/0 undefined behaviour division 
    if(distance ==0)
    {
        return ;
    }

    dx = dx/distance; //normalize into  unit vector 
    dy = dy/distance; 

    shape->move(dx*speed*dt,dy*speed*dt);
}

Chaser:: ~Chaser()
{
    delete shape;
}