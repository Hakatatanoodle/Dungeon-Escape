#include<SFML/Graphics.hpp>
#include "Player.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800,600),"Dungeon Escape");

    //values for testing - not fixed 
    float speed = 100;
    int health = 50;
    int attackPower = 50;
    sf::Vector2f position(50.f,50.f);

    //create player instance
    Player player(health,attackPower,speed,position);
    
    

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
        player.updateState(dt);
        window.clear(sf::Color::Black);
        player.draw(window);
        window.display();
    }
}
    
