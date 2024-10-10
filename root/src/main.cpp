#define DEBUG 1
#include <iostream>

#include "CommandHandler.h"
#include "CommandProcessor.h"

using namespace std;

bool sudo_mode = false;
string CurrentDirectory = "root/";

int main()
{
    cout << "Hello World!" << endl;
    while (true) {
        CommandHandler command;
        cout << CurrentDirectory << "> "; cin >> command;

        #if DEBUG == 1
        cerr << command.GetCommandType() << " called " << (command.GetTypeSudo() ? "with sudo " : "without sudo ") << "with args: " << endl;
        for (auto x : command.GetArgs())
            cerr << x.first << " " << x.second << endl;
        cerr << endl;
        #endif

        if (command.GetCommandType() == "exit")
            goto ExitCase;

        CommandProcessor cmp;
        cmp.run(CurrentDirectory, command);
    }

ExitCase:
    cout << "Bye World!" << endl;
    system ("pause");
    exit (0);
}
