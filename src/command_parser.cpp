#include "command_parser.h"

namespace commandparser
{
    void ParseCommand(const std::string &input, COMMAND *command)
    {
        std::istringstream iss(input);
        std::string i;
        iss >> i;
        command->name = i;
        while (iss >> i)
            command->args.push_back(i);
    }
}
