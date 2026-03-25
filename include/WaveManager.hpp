#ifndef WAVEMANAGER_HPP
#define WAVEMANAGER_HPP
#include<vector>
#include "Enemy.hpp"
class WaveManager
{
    private:
    int currentWave;
    std::vector<Enemy*>& enemies;


    public:
    bool isWaveCleared();
    void spawnNextWave();

    WaveManager(std::vector<Enemy*>& enemiesRef);

    ~WaveManager();
};
#endif