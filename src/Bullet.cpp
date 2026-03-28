#include "Bullet.hpp"
#include "Enemy.hpp"

Bullet::Bullet(sf::Vector2f direction,sf::Vector2f position)
{
    active = true;
    shape.setFillColor(sf::Color::White);
    shape.setPosition(position);
    shape.setSize(sf::Vector2f(10.f,20.f));
    this->direction = direction;
    speed = 130.f;
}

bool Bullet::isActive()
{
    return active;
}

sf::RectangleShape& Bullet::getShape()
{
    return shape;
}

void Bullet::move(float dt)
{

    float dx,dy,distance;   
    dx = 
}
