#include <iostream>
#include <random>
#include <chrono>
#include "SystemSimulator.hpp"
#include "../common/MetricPacket.hpp"

using namespace std;

constexpr double SEUIL_CRITIQUE_TEMP = 75.0;
constexpr double SEUIL_CRITIQUE_CPU = 95.0;

SystemSimulator::SystemSimulator()
    : engine(rd()),
      cpuDist(50.0, 10.0),
      ramDist(50.0, 10.0),
      tempDist(60.0, 5.0)
{}

MetricPacket SystemSimulator::generateNext(){
    MetricPacket packet;

    auto now = std::chrono::system_clock::now();
    long long time = chrono::duration_cast<chrono::milliseconds>(now.time_since_epoch()).count();

    packet.setTimestamp(time);

    double cpuHardValue = cpuDist(engine);

    if(cpuHardValue < 0.0){
        packet.setCpuUsage(0.0);
    }else if(cpuHardValue > 100.0){
        packet.setCpuUsage(100.0);
    }else{
        packet.setCpuUsage(cpuHardValue);
    }

    double ramHardValue = ramDist(engine);

    if(ramHardValue < 0.0){
        packet.setRamUsage(0.0);
    }else if(ramHardValue > 100.0){
        packet.setRamUsage(100.0);
    }else{
        packet.setRamUsage(ramHardValue);
    }

    double temperature = tempDist(engine);
    packet.setTemperature(temperature);

    if(temperature >= SEUIL_CRITIQUE_TEMP || cpuHardValue >= SEUIL_CRITIQUE_CPU){
        packet.setErrorCode(1);
    }else{
        packet.setErrorCode(0);
    }

    return packet;
}