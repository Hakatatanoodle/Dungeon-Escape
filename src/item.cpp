#include <SFML/Graphics.hpp>
#include "Item.hpp"

Item::Item(sf::Vector2f position)
{
    shape.setRadius(10.f);
    shape.setPosition(position);
    shape.setFillColor(sf::Color::Yellow);
    shape.setPointCount(3);
    collected = false;
}

void Item::draw(sf::RenderWindow& window)
{
    window.draw(shape);
}

void Item::collect()
{
    collected = true;
}

bool Item::isCollected()
{
    return collected;
}


