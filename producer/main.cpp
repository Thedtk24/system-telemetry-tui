#include "SystemSimulator.hpp"
#include "../common/MetricPacket.hpp"
#include <iostream>
#include <thread>
#include <chrono>
#include <string>

using namespace std;

int main(){
    SystemSimulator simulator;

    while(true){
        MetricPacket packet = simulator.generateNext();
        string serializedData = packet.serialize();
        cout << serializedData << endl;
        this_thread::sleep_for(chrono::milliseconds(200));
    }
}