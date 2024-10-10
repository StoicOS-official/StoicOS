#ifndef COMMANDHANDLER_H
#define COMMANDHANDLER_H

#include <string>
#include <sstream>
#include <vector>

using namespace std;
using namespace std::ranges;

class CommandHandler {
    bool type_sudo = false;
    string command;
    vector<pair<string, string>> args;
public:
    bool GetTypeSudo();
    string GetCommandType();
    vector<pair<string, string>> GetArgs();

    friend istream& operator>> (istream& in, CommandHandler& handler);
};

#endif
