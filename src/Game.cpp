#include <SFML/Graphics.hpp>
#include "Game.hpp"

Game::Game(): player(nullptr),state(GameState::RUNNING)
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
    items.push_back(Item(sf::Vector2f(50.f,50.f)));
    items.push_back(Item(sf::Vector2f(150.f,150.f)));
    items.push_back(Item(sf::Vector2f(250.f,250.f)));
    items.push_back(Item(sf::Vector2f(700.f,450.f)));
    items.push_back(Item(sf::Vector2f(501.f,501.f)));
    totalItems=5;
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

void Game::checkCollision()
{
    for(Entity* e: enemies)
    {
        if(player->getShape()->getGlobalBounds().intersects(e->getShape()->getGlobalBounds()))
        {   
            player->takeDamage(e->getAttackPower());
        }
    }

}

void Game::checkItemCollision()
{
    for(Item& i:items)
    {
        if(!i.isCollected() && player->getShape()->getGlobalBounds().intersects(i.getShape().getGlobalBounds()))
        {
            i.collect();
            player->setCollectedItem();
        }

    }
    
}

void Game::update(float dt)
{
    if(!player->getAliveCondition())
    {
        state = GameState::LOST;
    }
    checkCollision();
    checkItemCollision();
    if(player->getCollectedItem()>=totalItems)
    {
        state = GameState::WIN;

    }
    player->updateState(dt);
    sf::Vector2f playerPosition = player->getPosition();
    for(Enemy* e : enemies)
    {
        if(e->getAliveCondition())
        {
            e->updateState(dt,playerPosition);//polymorphism
        } 
    }

}

void Game::render()
{
    window.clear(sf::Color::Black);
    if(player->getAliveCondition())
    {
        player->draw(window);
    }
    for(Entity* e: enemies)
    {
        if(e->getAliveCondition()==true)
        {
            e->draw(window);
        }
    }
    for(Item& i:items)
    {
        if(!i.isCollected())
        {
            i.draw(window);
        }
    }
    window.display();

}

void Game::gameLoop()
{
    while(window.isOpen())
    {
        float dt = clock.restart().asSeconds();
        handleEvents();
        update(dt);
        render();

        if(state==GameState::LOST || state==GameState::WIN)
        {
            window.close();
        }
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

