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
    bool isAlive ;
    
    public:
    virtual void draw(sf::RenderWindow& window) = 0;
    virtual void attack(Entity& target) = 0;
    virtual void updateState(float dt) = 0;
    virtual void move(float dt) = 0;
    virtual void takeDamage(int damage);
    virtual void die();

    Entity(int h,int ap,float s , sf::Vector2f pos,sf::Shape* sh);//constructor 

    virtual ~Entity() {};//destrucor
};

#endif