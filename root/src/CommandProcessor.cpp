#include "CommandProcessor.h"

void CommandProcessor::run (string path, CommandHandler handler)
{
    bool sudo = handler.GetTypeSudo();
    string cmdname = handler.GetCommandType();
    auto args = handler.GetArgs();


}
