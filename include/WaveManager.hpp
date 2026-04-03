#ifndef WAVEMANAGER_HPP
#define WAVEMANAGER_HPP
#include<vector>
#include "Enemy.hpp"
#include "Item.hpp"
class WaveManager
{
    private:
    int currentWave;
    std::vector<Enemy*>& enemies;
    std::vector<Item>& items;


    public:
    bool isWaveCleared();
    void spawnNextWave();

    WaveManager(std::vector<Enemy*>& enemiesRef,std::vector<Item>& itemRef);

};
#endif