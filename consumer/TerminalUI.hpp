#ifndef TERMINALUI_HPP
#define TERMINALUI_HPP

#include <iostream>
#include <string>
#include <deque>
#include <algorithm>
#include "../common/MetricPacket.hpp"

using namespace std;

class TerminalUI {
    private:
        static const size_t MAX_HISTORY_SIZE = 20; 
        deque<double> cpuHistory;
        
        double maxCpu;
        double maxRam;

        string generateProgressBar(double percentage, int width) const;
        string generateSparkline() const;
        void resetCursor() const;
    
    public:
        TerminalUI();
        void render(const MetricPacket& packet);
};

#endif