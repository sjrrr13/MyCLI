//
// Created by Jiarui She on 2023/6/12
// Command register module
//

#ifndef COMMAND_REGISTER_H
#define COMMAND_REGISTER_H

#include <iostream>
#include <unordered_map>
#include <functional>
#include <vector>
#include "command_result.h"
#include "command_parser.h"

using CommandHandler = std::function<COMMANDRESULT(const std::vector<std::string> &)>;

class CommandRegistry
{
public:
    static CommandRegistry &GetInstance();

    void RegisterCommand(const std::string &, CommandHandler);

    CommandHandler GetCommand(const std::string &);

private:
    std::unordered_map<std::string, CommandHandler> registry;

    CommandRegistry() = default;

    // Disable copy constructor.
    CommandRegistry(const CommandRegistry &) = delete;

    // Disable assignment operator.
    CommandRegistry &operator=(const CommandRegistry &) = delete;
};

#endif // COMMAND_REGISTER_H
