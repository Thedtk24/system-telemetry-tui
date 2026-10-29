#include <iostream>
#include <string>
#include "TerminalUI.hpp"
#include "../common/MetricPacket.hpp"

int main(){
    cout << "\033[2J";

    TerminalUI ui;
    string line;

    while(getline(cin, line)){
        if(line.empty()) continue;

        MetricPacket packet = MetricPacket::deserialize(line);

        ui.render(packet);
    }

    return 0;
}