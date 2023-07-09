#include <unordered_map>
#include "command_executor.h"

// void CommandExecutor::ExecuteCommand(COMMAND &command)
// {
//     registry.ExecuteCommand(command);
// }

namespace commandexe
{
    // void Run(CommandRegistry &registry)
    // {
    //     std::string input;
    //     COMMAND command;

    //     while (flag)
    //     {
    //         std::cout << prompt << " ";
    //         std::getline(std::cin, input);

    //         commandparser::ParseCommand(input, &command);
    //         commandexe::ExecuteCommand(command, registry);
    //     }
    // }

    void ExecuteCommand(COMMAND &command, CommandRegistry &registry, std::ostringstream &buffer)
    {
        auto cmd = registry.GetCommand(command.name);
        if (cmd != nullptr)
        {
            COMMANDRESULT result = cmd(command.args);
            buffer << "code " << result.code << ": " << result.msg << std::endl;

            // switch (result.code)
            // {
            // case 1:
            //     buffer << result.msg << std::endl;
            //     break;
            // case -1:
            //     buffer << "Command execution failed." << std::endl;
            //     break;
            // default:
            //     break;
            // }
        }
        else
            buffer << "Command not found: " << command.name << std::endl;
    }
}