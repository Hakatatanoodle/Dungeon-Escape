#include "Stalker.hpp"
#include "utils.hpp"
#include<cmath>

Stalker::Stalker(int h , int ap,float s , sf::Vector2f pos):Enemy(h,ap,s,pos)
{
    shape = new sf::CircleShape(50.f);
    shape->setFillColor(sf::Color::Cyan);
    shape->setPosition(pos);
}
void Stalker::move(float dt , sf::Vector2f playerPos)
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

    //adding random noise to dx and dy for random movements 
    dx+=utility::randomFloatGenerator(-1,1);
    dy+=utility::randomFloatGenerator(-1,1);


    shape->move(dx*speed*dt,dy*speed*dt);
}

Stalker:: ~Stalker()
{
    delete shape;
}