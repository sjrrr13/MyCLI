#include "parser.h"

#include <sstream>

namespace parser
{
    void ParseCommand(const std::string &input, COMMAND *command)
    {
        // 提取命令名称和参数
        // std::string commandName = ExtractName(input);
        // std::vector<std::string> commandArgs = ExtractArguments(input);
        // std::cout << input << std::endl;
        // std::cout << &(command->name) << std::endl;
        // std::cout << &(command->args) << std::endl;
        // ExtractName(input, &(command->name));
        // ExtractArguments(input, command->name, &(command->args));

        // std::cout << "start" << std::endl;
        std::istringstream iss(input);
        std::string i;
        iss >> i;
        // std::cout << i << std::endl;
        command->name = i;
        // std::cout << command->name << std::endl;
        while (iss >> i)
        {
            command->args.push_back(i);
        }
        // std::cout << "a" << std::endl;
        // std::cout << command->args[0] << std::endl;

        // 执行命令或将解析结果传递给其他模块
        // ExecuteCommand(commandName, commandArgs);
    }

    void ExtractName(const std::string &input, std::string *name)
    {
        std::size_t firstSpacePos = input.find_first_of(" ");
        std::size_t firstTabPos = input.find_first_of("\t");
        std::size_t commandEndPos = std::min(firstSpacePos, firstTabPos);

        std::cout << commandEndPos << std::endl;

        if (commandEndPos != std::string::npos)
            *name = input.substr(0, commandEndPos);
        else
            *name = input;

        std::cout << "name" << std::endl;
    }

    void ExtractArguments(const std::string &input, const std::string name, std::vector<std::string> *args)
    {
        std::size_t commandNamePos = input.find(name);

        if (commandNamePos != std::string::npos)
        {
            std::size_t argumentsStartPos = commandNamePos + name.length();
            argumentsStartPos = input.find_first_not_of(" \t", argumentsStartPos);

            if (argumentsStartPos != std::string::npos)
            {
                std::string argumentsString = input.substr(argumentsStartPos);
                std::istringstream iss(argumentsString);
                std::string argument;
                while (iss >> argument)
                    args->push_back(argument);
            }
        }
    }

    void ExecuteCommand(const std::string &commandName, const std::vector<std::string> &commandArgs)
    {
    }
}
