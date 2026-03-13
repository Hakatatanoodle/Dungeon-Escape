#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Entity.hpp"

class Player: public Entity 
{
    private:
    int collectedItems;

    public:
    Player(int h,int ap,float s , sf::Vector2f);//constructor

    virtual void updateState(float dt) ;
    virtual void move(float dt,sf::Vector2f playerPos);

    virtual ~Player();//destructor

};


#endif