#include <string>
#include <sstream>

class CommandHandler {
private:
  bool type_sudo = false;
  string command_locname = cdir;
  string args = "";
public:
    CommandHandler (stringstream ss) {
      string s; ss >> s;
      type_sudo = (s == "sudo");

      if (type_sudo) {
        cerr << "Command type sudo!\n";
      }

      while (ss >> s) {
        args += s;
      }
    }
};