#include "mycli.h"
#include "command_result.h"

// bool flag = true;

// COMMANDRESULT ExitCommand(const std::vector<std::string> &)
// {
//     throw CommandResult();
// }

MyCLI::MyCLI() : registry(CommandRegistry::GetInstance()), flag(true), prompt(">")
{
    // registry.RegisterCommand("help", HelpCommand);
    // registry.RegisterCommand("exit", ExitCommand);
}

// COMMANDRESULT MyCLI::ExitCommand(const std::vector<std::string> &args)
// {
//     if (args.size() > 0)
//         return COMMANDRESULT(-1, "Invalid arguments");
//     else
//     {

//     }
// }

void MyCLI::Run()
{
    std::string input;
    COMMAND command;

    while (flag)
    {
        std::cout << prompt << " ";
        std::getline(std::cin, input);

        commandparser::ParseCommand(input, &command);
        command.Info();
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

void MyCLI::SetPrompt(std::string & p)
{
    prompt = p;
}

void MyCLI::AddCommand(const std::string & name, CommandHandler handler)
{
    registry.RegisterCommand(name, handler);
}
