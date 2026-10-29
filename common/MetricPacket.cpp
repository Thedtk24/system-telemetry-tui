#include "MetricPacket.hpp"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

string MetricPacket::serialize() const{
    return to_string(timestamp) + ";" + to_string(cpuUsage) + ";" + to_string(ramUsage) + ";" + to_string(temperature) + ";" + to_string(errorCode);
}

MetricPacket MetricPacket::deserialize(const std::string& line){
    stringstream ss(line);
    string time, cpu, ram, temp, err;
    getline(ss, time, ';');
    getline(ss, cpu, ';');
    getline(ss, ram, ';');
    getline(ss, temp, ';');
    getline(ss, err, ';');

    MetricPacket packet;

    packet.timestamp = stoll(time);
    packet.cpuUsage = stod(cpu);
    packet.ramUsage = stod(ram);
    packet.temperature = stod(temp);
    packet.errorCode = stoi(err);

    return packet;
}

void MetricPacket::setTimestamp(long long t){
    timestamp = t;
}

void MetricPacket::setCpuUsage(double c){
    cpuUsage = c;
}

void MetricPacket::setRamUsage(double r){
    ramUsage = r;
}

void MetricPacket::setTemperature(double T){
    temperature = T;
}

void MetricPacket::setErrorCode(int E){
    errorCode = E;
}

long long MetricPacket::getTimestamp() const{
    return timestamp;
}

double MetricPacket::getCpu() const{
    return cpuUsage;
}

double MetricPacket::getRam() const{
    return ramUsage;
}

double MetricPacket::getTemp() const{
    return temperature;
}

int MetricPacket::getError() const{
    return errorCode;
}