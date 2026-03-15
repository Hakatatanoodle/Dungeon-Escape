#include<SFML/Graphics.hpp>
#include "Player.hpp"
#include "Stalker.hpp"
#include "Chaser.hpp"
#include "Entity.hpp"



int main()
{
    sf::RenderWindow window(sf::VideoMode(800,600),"Dungeon Escape");

    //values for testing - not fixed 
    float p_speed = 150.f;
    int p_health = 50;
    int p_attackPower = 50;
    sf::Vector2f p_position(50.f,50.f);

    //values for chaser
    float c_speed = 100.f;
    int c_health = 30;
    int c_attackPower = 10;
    sf::Vector2f c_position(600.f,400.f);

    //values for stalker
    float s_speed = 50.f;
    int s_health = 100;
    int s_attackPower = 25;
    sf::Vector2f s_position(200.f,200.f);

    //create Entity instances instance
    Player player(p_health,p_attackPower,p_speed,p_position);
    Chaser chaser(c_health,c_attackPower,c_speed,c_position);
    Stalker stalker(s_health,s_attackPower,s_speed,s_position);

    

    
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

        sf::Vector2f playerPosition = player.getPosition();
        
        player.updateState(dt);
        chaser.updateState(dt,playerPosition);
        stalker.updateState(dt,playerPosition);
        window.clear(sf::Color::Black);
        player.draw(window);
        chaser.draw(window);
        stalker.draw(window);
        window.display();
    }
}
    
