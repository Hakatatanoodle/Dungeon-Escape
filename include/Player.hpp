#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Entity.hpp"

class Player: public Entity 
{
    private:
    int collectedItems;

    public:
    Player(int h,int ap,float s , sf::Vector2f,sf::Shape*);

    virtual void draw(sf::RenderWindow& window);
    virtual void attack(Entity& target);
    virtual void updateState(float dt) ;
    virtual void move(float dt);

};


#endif