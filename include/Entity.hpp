#ifndef ENTITY_HPP
#define ENTITY_HPP
#include<SFML/Graphics.hpp>

class Entity
{
    protected:
    int health;
    int attackPower;
    float speed;
    sf::Vector2f position;
    sf::Shape* shape;//I actually dont know what type shape should be
    
    public:
    virtual void draw() = 0;
    virtual void attack() = 0;
    virtual void updateState() = 0;
    virtual void move() = 0;
    virtual void takeDamage();
    virtual void die();

    Entity(int h,int ap,float s , sf::Vector2f,sf::Shape*);//constructor 

    virtual ~Entity() {};//destrucor
};

#endif