#ifndef GAME_HPP
#define GAME_HPP

#include<SFML/Graphics.hpp>
#include<vector>
#include "Player.hpp"
#include "Chaser.hpp"
#include "Stalker.hpp"
#include "Enemy.hpp"
#include "Item.hpp"
#include "WaveManager.hpp"
#include "Bullet.hpp"

enum class GameState {RUNNING,LOST,WIN};
class Game
{
    private:
    sf::RenderWindow window;
    Player* player;
    std::vector<Enemy*> enemies;  
    sf::Clock clock;
    GameState state;
    std::vector<Item> items;
    int totalItems;
    WaveManager* waveManager;     
    sf::Font font;
    sf::Text messageText;
    sf::Text promptText;
    std::vector<Bullet> bullets;


    void checkCollision();
    void checkItemCollision();
    void init();
    void handleEvents();
    void update(float dt);
    void render();
    void restart();
    void checkBulletCollision();

    public: 
    void gameLoop();

    Game();

    virtual ~Game();

};
#endif