#ifndef GAME_HPP
#define GAME_HPP

#include<SFML/Graphics.hpp>
#include<vector>
#include "Player.hpp"
#include "Chaser.hpp"
#include "Stalker.hpp"
#include "Enemy.hpp"

enum class GameState {RUNNING,LOST,WIN};
class Game
{
    private:
    sf::RenderWindow window;
    Player* player;
    std::vector<Enemy*> enemies;  
    sf::Clock clock;
    GameState state;

    void init();
    void handleEvents();
    void update(float dt);
    void render();

    public: 
    void gameLoop();

    Game();

    virtual ~Game();

};
#endif