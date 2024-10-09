#include "CommandHandler.h"
#include <string>
#include <sstream>
#include <vector>

using namespace std;

istream& operator>> (istream& in, CommandHandler& handler) {
    string line; getline(in, line);
    stringstream ss(line);

    string segment; bool CommandFlag = false;
    handler.args.clear();
    while (ss >> segment) {
        if (segment == "sudo") {
            handler.type_sudo = true;
        }
        else if (CommandFlag == false) {
            CommandFlag = true;
            handler.command = segment;
        }
        else {
            if (handler.args.empty() || !handler.args.back().second.empty()) { // if the last arg pair is empty
                handler.args.emplace_back(segment, "");
            }
            else {
                handler.args.back().second = segment;
            }
        }
    }

    return in;
}