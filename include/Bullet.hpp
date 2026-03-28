#ifndef BULLET_HPP
#define BULLET_HPP

#include<SFML/Graphics.hpp>
class Bullet
{
    private:
    float speed;
    bool active;
    sf::RectangleShape shape;
    sf::Vector2f direction;

    public:
    Bullet(sf::Vector2f direction   , sf::Vector2f position);

    void move(float dt);
    bool isActive();
    sf::RectangleShape& getShape();

};
#endif