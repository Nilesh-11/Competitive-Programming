#include "Random.h"

int RandomNum(int min, int max){
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(min, max);
    return (int)distrib(gen);
}