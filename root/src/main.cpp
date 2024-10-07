#include <Windows.h>
#include <iostream>

using namespace std;

string cdir = "root/";
#include "CommandHandler.h"

int main() {
    cout << "Hello World!" << endl;

    while (true) {
        cout << cdir << "> ";
        string command; getline(cin, command);
        stringstream ss(command);

        CommandHandler ch(ss);

        if (command == "exit") {
            break;
        }
    }

    system("pause");
}