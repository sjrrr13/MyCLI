#include <iostream>
#include <sstream>

#include "command_parser.h"
#include "command_register.h"

#include <string>
#include <vector>
#include "mycli.h"

// void test()
// {
//     std::string argumentsString = "  cmd  \t -a\t -b  -c";
//     std::istringstream iss(argumentsString);
//     std::string argument;
//     while (iss >> argument)
//         std::cout << argument << ";" << std::endl;
// }

COMMANDRESULT PrintArguments(const std::vector<std::string> &arguments)
{
    if (arguments.size() >= 1)
    {
        std::string temp;
        for (const auto &arg : arguments)
            temp += arg + " ";
        return COMMANDRESULT(0, temp);
    }
    else
    {
        return COMMANDRESULT(-1, "Invalid arguments");
    }
}

int test(const std::vector<std::string> &arguments)
{
    return 1;
}

int main()
{
    // //  cmd \t -a\t-b  -c
    // std::string userInput;
    // COMMAND cmd;
    // auto p = &cmd;
    // CommandRegistry &cr = CommandRegistry::GetInstance();

    // std::cout << "Enter a command: ";
    // std::getline(std::cin, userInput);
    // commandparser::ParseCommand(userInput, p);
    // // p->Info();

    // cr.RegisterCommand("PrintArguments", PrintArguments);
    // // cr.ExecuteCommand(cmd);

    MyCLI cli = MyCLI();
    std::string p = ">>>";
    cli.SetPrompt(p);
    cli.AddCommand("args", PrintArguments);
    cli.Run();

    return 0;
}
