#include <Windows.h>
#include <iostream>

#include "CommandHandler.h"
#include "CommandProcessor.h"

using namespace std;

string CurrentDirectory = "root/";

int main() {
    //cout << "Hello World!" << endl;

    while (true) {
        CommandHandler handler; cin >> handler;

        cout << handler.GetCommandType() << '\n';
        auto args = handler.GetArgs();
        for (const auto& x : args) {
            cout << x.first << " " << x.second << endl;
        }

        if (handler.GetCommandType() == "exit") {
            goto ExitHandler;
        }
    }

    ExitHandler:
    cout << "Shutting down ..." << endl;
}