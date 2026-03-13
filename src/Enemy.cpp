#include "Enemy.hpp"

Enemy::Enemy(int h , int ap,float s , sf::Vector2f pos):Entity(h,ap,s,pos) 
{
    respawnCounter = 0;

}

void Enemy::updateState(float dt, sf::Vector2f playerPos)
{
    if(health<=0)
    {
        health = 0;
        die();
    }
    move(dt,playerPos);
}