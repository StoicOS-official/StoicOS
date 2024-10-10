#include "CommandHandler.h"

bool CommandHandler::GetTypeSudo()
{
    return type_sudo;
}

string CommandHandler::GetCommandType()
{
    return command;
}

vector<pair<string, string>> CommandHandler::GetArgs()
{
    return args;
}

istream& operator>> (istream& in, CommandHandler& handler)
{
    string line;
    getline(in, line);
    stringstream ss(line);

    string segment;
    bool CommandFlag = false;
    handler.args.clear();

    while (getline(ss, segment, ' ')) {  // Split by whitespace
        // Trim whitespace from both ends of the segment
        segment.erase(segment.begin(), find_if(segment.begin(), segment.end(), [](unsigned char ch) {
            return !isspace(ch);
        }));
        segment.erase(find_if(segment.rbegin(), segment.rend(), [](unsigned char ch) {
            return !isspace(ch);
        }).base(), segment.end());

        if (segment.empty()) continue;  // Skip empty segments

        if (segment == "sudo") {
            handler.type_sudo = true;
        }
        else if (!CommandFlag) {
            CommandFlag = true;
            handler.command = segment; // First non-sudo word is the command
        }
        else {
            // Check for key-value pairs or flags
            size_t pos = segment.find('=');
            if (pos != string::npos) {
                // Handle key-value pairs
                string key = segment.substr(0, pos);
                string value = segment.substr(pos + 1);
                handler.args.emplace_back(key, value);
            } else if (segment.rfind("--", 0) == 0 || segment[0] == '-') {
                // Handle flags
                handler.args.emplace_back(segment, "");
            } else {
                // Treat as a standalone argument
                if (handler.args.empty() || !handler.args.back().second.empty()) {
                    handler.args.emplace_back(segment, "");
                } else {
                    // Treat the segment as a value for the previous key
                    handler.args.back().second = segment;
                }
            }
        }
    }

    return in;
}
