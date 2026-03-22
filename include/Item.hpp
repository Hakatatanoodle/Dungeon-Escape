#ifndef ITEM_HPP
#define ITEM_HPP
#include<SFML/Graphics.hpp>
class Item
{
    private: 
    sf::CircleShape shape;
    bool collected;

    public: 
    //getter
    sf::CircleShape getShape() const {return shape;}
     
    void draw(sf::RenderWindow&  window);
    bool isCollected();
    void collect();

    Item(sf::Vector2f position);
    

};
#endif