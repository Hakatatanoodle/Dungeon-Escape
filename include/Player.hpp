#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Entity.hpp"

class Player: public Entity 
{
    private:
    int collectedItems;
    sf::Clock damageClock;
    float damageCooldown; 

    public:
    Player(int h,int ap,float s , sf::Vector2f);//constructor

    //getter
    int getCollectedItem() {return collectedItems;}

    //setter 
    void setCollectedItem() {collectedItems++;}


    virtual void updateState(float dt) ;
    virtual void move(float dt,sf::Vector2f playerPos);
    virtual void takeDamage(int damage) override;

    virtual ~Player();//destructor

};


#endif