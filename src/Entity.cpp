#include "Entity.hpp"
#include<iostream>

Entity::Entity(int h,int ap,float s , sf::Vector2f pos):health(h),maxHealth(h),attackPower(ap),speed(s),position(pos),isAlive(true)
{
   
}



void Entity::takeDamage(int damage)
{
    health-=damage;
    if(health < 0 ) health =0;//clamp health
    if(health==0) die();
    std::cout << "Health: " << health << std::endl;
}

void Entity::die()
{
    isAlive = false;
}

void Entity::draw(sf::RenderWindow& window)
{
    window.draw(*shape);

    sf::Vector2f barPos = shape->getPosition();
    barPos.y -=10.f;//bar posiiton at the top of the entity 

    sf::RectangleShape background(sf::Vector2f(50.f,5.f));
    background.setPosition(barPos);  
    background.setFillColor(sf::Color::Red);
    window.draw(background);

    float fillWidth = (float)health/maxHealth*50.f;   
    sf::RectangleShape fill(sf::Vector2f(fillWidth,5.f));
    fill.setPosition(barPos);
    fill.setFillColor(sf::Color::Green);
    window.draw(fill);
}

void Entity::attack(Entity& target)
{
    target.takeDamage(attackPower);
}

sf::Vector2f Entity::getPosition() const
{
    return shape->getPosition();
}