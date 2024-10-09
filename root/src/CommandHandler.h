#ifndef COMMANDHANDLER_H
#define COMMANDHANDLER_H

class CommandHandler {
public:
    bool type_sudo = false;
    string command;
    vector<pair<string, string>> args;

    string GetCommandType() const {
        return command;
    }

    vector<pair<string, string>> GetArgs() const {
        return args;
    }

    friend istream& operator>> (istream& in, CommandHandler& handler);
};

#endif