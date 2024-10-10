#ifndef COMMANDPROCESSOR_H
#define COMMANDPROCESSOR_H

#include "CommandHandler.h"

using namespace std;

class CommandProcessor
{
public:
    void run (string path, CommandHandler handler);
};

#endif
