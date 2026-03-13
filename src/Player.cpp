    #include "Player.hpp"

    Player::Player(int h,int ap,float s , sf::Vector2f pos):Entity(h,ap,s,pos)
    {
        collectedItems = 0;
        shape = new sf::RectangleShape(sf::Vector2f(50.f,50.f));
        shape->setFillColor(sf::Color::White);
    }   

    void Player::move(float dt,sf::Vector2f playerPos)
    {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            position.y-=speed*dt;
            shape->move(0,-speed*dt);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            position.y+=speed*dt;
            shape->move(0,+speed*dt);   
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            position.x-=speed*dt;
            shape->move(-speed*dt,0);       
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            position.x+=speed*dt;
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