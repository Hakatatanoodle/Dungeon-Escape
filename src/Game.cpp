#include <SFML/Graphics.hpp>
#include "Game.hpp"

Game::Game()
{
    init();//set initial state
}
void Game::init()
{
    //stuck on init so decided to build later
    //new Player* player(100,100,100.f,sf::Vector2f(50.f,50.f));
    window.create(sf::VideoMode(800.f,600.f),"Dungeon Escape");
    player = new Player(100,100,200.f,sf::Vector2f(50.f,50.f));
    enemies.push_back(new Chaser(30, 10, 100.f, sf::Vector2f(600.f, 400.f)));
    enemies.push_back(new Stalker(100, 25, 50.f, sf::Vector2f(200.f, 200.f)));
}

void Game::handleEvents()
{
    sf::Event event;
    while(window.pollEvent(event))
    {
        if(event.type== sf::Event::Closed)
        {
            window.close();
        }
    }
}

void Game::update(float dt)
{
    player->updateState(dt);
    sf::Vector2f playerPosition = player->getPosition();
    for(Enemy* e : enemies)
    {
        e->updateState(dt,playerPosition);//polymorphism
    }

}

void Game::render()
{
    window.clear(sf::Color::Black);
    player->draw(window);
    for(Entity* e: enemies)
    {
        e->draw(window);
    }
    window.display();

}

void Game::gameLoop()
{
    init();
    while(window.isOpen())
    {
        float dt = clock.restart().asSeconds();
        handleEvents();
        update(dt);
        render();
    }
}

Game::~Game()
{

    delete player;
    for(Enemy* e: enemies)
    {
        delete e;
    }
}