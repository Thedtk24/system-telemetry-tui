#include <iostream>
#include <string>
#include <deque>
#include <algorithm>
#include "TerminalUI.hpp"
#include "../common/MetricPacket.hpp"

#define WIDTH 20

TerminalUI::TerminalUI() : maxCpu(0.0), maxRam(0.0) {}

void TerminalUI::resetCursor() const {
    cout << "\033[H";
}

string TerminalUI::generateProgressBar(double percentage, int width) const {
    if (percentage > 100.0) percentage = 100.0;
    else if (percentage < 0.0) percentage = 0.0;

    int filled = (percentage / 100.0) * width;
    string bar = string(filled, '#') + string(width - filled, '-');
    return bar;
}

string TerminalUI::generateSparkline() const {
    const string steps = " _.-*#"; 
    string sparkline = "";

    for (double val : cpuHistory) {
        int index = (val / 100.0) * (steps.length() - 1);
        if (index < 0) index = 0;
        if (index >= (int)steps.length()) index = steps.length() - 1;
        sparkline += steps[index];
    }
    return sparkline;
}

void TerminalUI::render(const MetricPacket& packet) {
    resetCursor();

    // Mise à jour des pics maximaux
    if (packet.getCpu() > maxCpu) maxCpu = packet.getCpu();
    if (packet.getRam() > maxRam) maxRam = packet.getRam();

    cpuHistory.push_back(packet.getCpu());
    if (cpuHistory.size() > MAX_HISTORY_SIZE) {
        cpuHistory.pop_front();
    }

    cout << "========================================" << endl;
    cout << "SYSTEM TELEMETRY DASHBOARD" << endl;
    cout << "Timestamp : " << packet.getTimestamp() << " ms" << endl;
    cout << "----------------------------------------" << endl;

    double cpu = packet.getCpu();
    cout << "CPU : " << generateProgressBar(cpu, WIDTH) << " " << cpu << " %" << endl;
    cout << "      Max : " << maxCpu << " %" << endl;

    cout << "Hist  : [" << generateSparkline() << "]" << endl;

    cout << "----------------------------------------" << endl;

    double ram = packet.getRam();
    cout << "RAM : " << generateProgressBar(ram, WIDTH) << " " << ram << " %" << endl;
    cout << "      Max : " << maxRam << " %" << endl;

    double temp = packet.getTemp();
    cout << "Temp  : " << temp << " °C" << endl;

    cout << "----------------------------------------" << endl;

    int error = packet.getError();
    if (error != 0) {
        cout << "\033[31mALERTE CRITIQUE    \033[0m" << endl;
    } else {
        cout << "\033[32mSTATUT NOMINAL     \033[0m" << endl;
    }

    cout << "========================================" << endl;
}