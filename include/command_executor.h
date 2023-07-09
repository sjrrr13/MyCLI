//
// Created by Jiarui She on 2023/6/13
// Command executor module
//

#ifndef COMMAND_EXECUTOR_H
#define COMMAND_EXECUTOR_H

#include "command_register.h"
#include "command.h"
#include <sstream>

// class CommandExecutor
// {
// public:
//     static CommandExecutor &GetInstance();

//     void ExecuteCommand(COMMAND &);

// private:
//     CommandRegistry& registry;

//     CommandExecutor(): registry(CommandRegistry::GetInstance()) {};
// };

namespace commandexe
{
    void Run(CommandRegistry &);

    void ExecuteCommand(COMMAND &, CommandRegistry &, std::ostringstream &);
};

#endif // COMMAND_EXECUTOR_H
