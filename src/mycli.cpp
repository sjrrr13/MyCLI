#include "mycli.h"

MyCLI::MyCLI() : registry(CommandRegistry::GetInstance()), flag(true), prompt(">") {}

void MyCLI::Run()
{
    std::string input;
    COMMAND command;

    while (flag)
    {
        std::cout << prompt << " ";
        std::getline(std::cin, input);

        commandparser::ParseCommand(input, &command);
        // Exit command
        if (command.name == "exit" && command.args.size() == 0)
        {
            std::cout << "Goodbye :)\n";
            break;
        }
        commandexe::ExecuteCommand(command, registry, buffer);
        std::cout << buffer.str();
        buffer.str("");
        command.clear();
    }
}

void MyCLI::SetPrompt(std::string &p)
{
    prompt = p;
}

void MyCLI::AddCommand(const std::string &name, CommandHandler handler)
{
    registry.RegisterCommand(name, handler);
}
