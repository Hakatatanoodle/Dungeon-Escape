    #include "Bullet.hpp"
  

    Bullet::Bullet(sf::Vector2f direction,sf::Vector2f position)
    {
        active = true;
        shape.setFillColor(sf::Color::White);
        shape.setPosition(position);
        shape.setSize(sf::Vector2f(10.f,20.f));
        this->direction = direction;
        speed = 130.f;
    }

    bool Bullet::isActive()
    {
        return active;
    }

    void Bullet::setActiveStatus(bool status)
    {
        active = status;

    }

    sf::RectangleShape& Bullet::getShape()
    {
        return shape;
    }

    void Bullet::move(float dt)
    {
        shape.move(direction*speed*dt);
        if(shape.getPosition().x <0 || shape.getPosition().x>800 || shape.getPosition().y<0 || shape.getPosition().y>600)
        {
            active = false;
        }
    }

    void Bullet::draw(sf::RenderWindow& window)
    {
        if(active)
        {
            window.draw(shape);
        }
    }
