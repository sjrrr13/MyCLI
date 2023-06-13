#include "command_register.h"

CommandRegistry &CommandRegistry::GetInstance()
{
    static CommandRegistry instance;
    return instance;
}

void CommandRegistry::RegisterCommand(const std::string &name, CommandHandler handler)
{
    registry[name] = handler;
}

void CommandRegistry::ExecuteCommand(COMMAND& command)
{
    auto it = registry.find(command.name);
    if (it != registry.end())
    {
        COMMANDRESULT result = it->second(command.args);

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
