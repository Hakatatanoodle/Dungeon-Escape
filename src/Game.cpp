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

    waveManager = new WaveManager(enemies);

    font.loadFromFile("Assets/DejaVuSansMono.ttf");
    messageText.setFont(font);
    promptText.setFont(font);
    messageText.setFillColor(sf::Color::White);
    promptText.setFillColor(sf::Color::White);
    messageText.setCharacterSize(60);
    promptText.setCharacterSize(30);
    messageText.setPosition(400.f,250.f);
    promptText.setPosition(300.f,350.f);

}

void Game::restart()
{
    delete player;
    for(Enemy* e:enemies)
    {
        delete e;
    }
    enemies.clear();
    items.clear();
    delete waveManager;
    state= GameState::RUNNING;
    init();

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
        //for testing purpose only , will be removed later

        if(event.type== sf::Event::KeyPressed   && event.key.code == sf::Keyboard::K)
        {
            for(Enemy* e:enemies)
            {
                e->takeDamage(9999);    
            }
        }
        if(event.type==sf::Event::KeyPressed && event.key.code == sf::Keyboard::R)
        {
            restart();
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
    if(waveManager->isWaveCleared())
    {
        waveManager->spawnNextWave();
    }

}

void Game::render()
{
    window.clear(sf::Color::Black);
    if(state == GameState::LOST || state == GameState::WIN)
    {
        messageText.setString(state == GameState::WIN ? "YOU WIN" : "YOU LOST");
        promptText.setString("Press R to Play Again");
        window.draw(messageText);
        window.draw(promptText);
        window.display();
        return;  // stop here, don't draw game
    }
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

