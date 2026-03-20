    #include "Player.hpp"

    Player::Player(int h,int ap,float s , sf::Vector2f pos):Entity(h,ap,s,pos)
    {
        collectedItems = 0;
        shape = new sf::RectangleShape(sf::Vector2f(50.f,50.f));
        shape->setFillColor(sf::Color::White);
        shape->setPosition(pos);
    }   

    void Player::move(float dt,sf::Vector2f playerPos)
    {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            shape->move(0,-speed*dt);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            shape->move(0,+speed*dt);   
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            shape->move(-speed*dt,0);       
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            shape->move(+speed*dt,0);   
        }
    }

    void Player::updateState(float dt)
    {
        if(health<=0)
        {
            health = 0;
            die();
        }
        move(dt,position);

    }

    Player:: ~Player()
    {
        delete shape;

    }