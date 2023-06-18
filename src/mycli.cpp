#include "mycli.h"
#include "command_result.h"

bool flag = true;

COMMANDRESULT ExitCommand(const std::vector<std::string> &)
{
    throw CommandResult();
}

MyCLI::MyCLI() : registry(CommandRegistry::GetInstance()), flag(true), prompt(">"), usage("")
{
    registry.RegisterCommand("help", HelpCommand);
    registry.RegisterCommand("exit", ExitCommand);
}

void MyCLI::Run()
{
    std::string input;
    COMMAND command;

    while (flag)
    {
        std::cout << prompt << " ";
        std::getline(std::cin, input);

        commandparser::ParseCommand(input, &command);
        try
        {
            commandexe::ExecuteCommand(command, registry);
        }
        catch (CommandResult &e)
        {
        }
    }
}
