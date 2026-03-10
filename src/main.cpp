#include<SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800,600),"Dungeon Escape");

    float speed = 100;
    sf::RectangleShape player;
    player.setSize(sf::Vector2f(50.f,50.f));
    player.setFillColor(sf::Color::White);
    player.setPosition(400,300);

    //game loop 
    sf::Clock clock;
    while(window.isOpen())
    {

        float dt = clock.restart().asSeconds();
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type== sf::Event::Closed)
            {
                window.close();
            }
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            player.move(0,-speed*dt);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            player.move(0,+speed*dt);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            player.move(-speed*dt,0);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            player.move(speed*dt,0);
        }

        window.clear(sf::Color::Black);
        window.draw(player);
        window.display();
    }
}
    
