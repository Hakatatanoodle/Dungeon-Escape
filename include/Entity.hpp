#ifndef ENTITY_HPP
#define ENTITY_HPP
#include<SFML/Graphics.hpp>

class Entity
{
    protected:
    int maxHealth;
    int health;
    int attackPower;
    float speed;
    sf::Vector2f position;
    sf::Shape* shape;//I actually dont know what type shape should be
    bool isAlive ;
    
    public:
    //getter
    sf::Vector2f getPosition() const;
    sf::Shape* getShape() const {return shape;}
    int getAttackPower() const {return attackPower; } 
    bool getAliveCondition() { return isAlive; }

    virtual void draw(sf::RenderWindow& window);
    virtual void attack(Entity& target);
    virtual void move(float dt,sf::Vector2f playerPos) = 0;
    virtual void takeDamage(int damage);
    virtual void die();

    Entity(int h,int ap,float s , sf::Vector2f pos);//constructor 

    virtual ~Entity() {};//destrucor
};

#endif