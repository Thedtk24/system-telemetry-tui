#ifndef METRICPACKET_HPP
#define METRICPACKET_HPP

#include <iostream>
#include <string>

using namespace std;

class MetricPacket{
    private:
        long long timestamp;
        double cpuUsage;
        double ramUsage;
        double temperature;
        int errorCode;
    
    public:
        string serialize() const;  // Converts the object into a line of formatted text (ex: CSV timestamp;cpu;ram;temp;error)
        static MetricPacket deserialize(const std::string& line); // Parses a received character string to reconstruct the object
        void setTimestamp(long long t);
        void setCpuUsage(double c);
        void setRamUsage(double r);
        void setTemperature(double T);
        void setErrorCode(int E);
        long long getTimestamp() const;
        double getCpu() const;
        double getRam() const;
        double getTemp() const;
        int getError() const;
};

#endif