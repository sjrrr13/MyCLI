#include "command_executor.h"

namespace commandexe
{
    void ExecuteCommand(COMMAND &command, CommandRegistry &registry, std::ostringstream &buffer)
    {
        auto cmd = registry.GetCommand(command.name);
        if (cmd != nullptr)
        {
            COMMANDRESULT result = cmd(command.args);
            buffer << "code " << result.code << ": " << result.msg << std::endl;
        }
        else
            buffer << "Command not found: " << command.name << std::endl;
    }
}