#include "Entity.hpp"

Entity::Entity(int h,int ap,float s , sf::Vector2f pos):health(h),attackPower(ap),speed(s),position(pos),isAlive(true)
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

void Entity::draw(sf::RenderWindow& window)
{
    window.draw(*shape);
}