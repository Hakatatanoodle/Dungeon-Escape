#include "WaveManager.hpp"
#include "utils.hpp"
#include "Chaser.hpp"
#include "Stalker.hpp"

WaveManager::WaveManager(std::vector<Enemy*>& enemiesRef):enemies(enemiesRef)
{
    currentWave = 1;

}


bool WaveManager::isWaveCleared()
{ 
    for(Enemy* e: enemies)
    {
        if(e->getAliveCondition()) return false;
    }
    return true;    
}

void WaveManager::spawnNextWave()
{
    for(Enemy* e:enemies)
    {
        delete e;
    }
    enemies.clear();//clear the vector to clear the dangling pointers
    currentWave++;
    for(int i =1 ;i<(2+currentWave);i++)
    {
        if(i%2!=0) 
        {
            enemies.push_back(new Chaser(30+2*currentWave,10+2*currentWave,100.f+2*currentWave,sf::Vector2f(utility::randomFloatGenerator(0,790),utility::randomFloatGenerator(0,590))));
        }
        else
        {
            enemies.push_back(new Stalker(100+2*currentWave,25+2*currentWave,59.f+2*currentWave,sf::Vector2f(utility::randomFloatGenerator(0,790),utility::randomFloatGenerator(0,590))));
        }
    }
}   