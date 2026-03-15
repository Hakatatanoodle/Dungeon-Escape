#include "utils.hpp"
#include<random>
int utility::randomNumberGenerator(int min , int max)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(min,max);

    return dist(gen);
}

float utility::randomFloatGenerator(float min,float max)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dist(min,max);

    return dist(gen);
}