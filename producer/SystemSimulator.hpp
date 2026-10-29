#ifndef SYSTEMSIMULATOR_HPP
#define SYSTEMSIMULATOR_HPP

#include <iostream>
#include <random>
#include "../common/MetricPacket.hpp"

using namespace std;

class SystemSimulator{
    private:
        random_device rd;
        default_random_engine engine;
        normal_distribution<double> cpuDist;
        normal_distribution<double> ramDist;
        normal_distribution<double> tempDist;
    
    public:
    SystemSimulator();
    MetricPacket generateNext();
};

#endif