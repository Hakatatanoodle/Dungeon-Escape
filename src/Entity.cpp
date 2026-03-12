#include "Entity.hpp"

Entity::Entity(int h,int ap,float s , sf::Vector2f pos,sf::Shape* sh):health(h),attackPower(ap),speed(s),position(pos),shape(sh),isAlive(true)
{
   
}


void Entity::takeDamage(int damage)
{
    health-=damage;
    if(health<0)
    {
        health = 0;
    }
}

void Entity::die()
{
    isAlive = false;
}