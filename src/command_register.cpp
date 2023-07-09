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

CommandHandler CommandRegistry::GetCommand(const std::string &name)
{
    auto it = registry.find(name);
    if (it != registry.end())
        return it->second;
    else
        return nullptr;
}
