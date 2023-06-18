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

    void ExecuteCommand(COMMAND &command, CommandRegistry &registry)
    {
        auto cmd = registry.GetCommand(command.name);
        if (cmd != nullptr)
        {
            COMMANDRESULT result = cmd(command.args);

            switch (result)
            {
            case COMMANDRESULT::Success:
                std::cout << "Command executed successfully." << std::endl;
                break;
            case COMMANDRESULT::Failure:
                std::cout << "Command execution failed." << std::endl;
                break;
            case COMMANDRESULT::InvalidArguments:
                std::cout << "Invalid command arguments." << std::endl;
                break;
            default:
                break;
            }
        }
        else
            std::cout << "Command not found: " << command.name << std::endl;
    }
}