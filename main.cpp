#include <iostream>
#include <sstream>

#include "command_parser.h"
#include "command_register.h"

#include <string>
#include <vector>

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
        for (const auto &arg : arguments)
        {
            std::cout << arg << " ";
        }
        std::cout << std::endl;
        return COMMANDRESULT::Success;
    }
    else
    {
        return COMMANDRESULT::InvalidArguments;
    }
}

int main()
{
    //  cmd \t -a\t-b  -c
    std::string userInput;
    COMMAND cmd;
    auto p = &cmd;
    CommandRegistry &cr = CommandRegistry::GetInstance();

    std::cout << "Enter a command: ";
    std::getline(std::cin, userInput);
    commandparser::ParseCommand(userInput, p);
    // p->Info();

    cr.RegisterCommand("PrintArguments", PrintArguments);
    // cr.ExecuteCommand(cmd);

    return 0;
}
