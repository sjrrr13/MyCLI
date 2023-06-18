//
// Created by Jiarui She on 2023/6/13
//

#ifndef MYCLI_H
#define MYCLI_H

#include "command_parser.h"
#include "command_register.h"
#include "command_executor.h"

static bool flag;

class MyCLI
{
public:
    void Run();

    void SetPrompt(std::string &);

    void SetUsage(std::string &);

    void AddCommand(const std::string &, CommandHandler);

    MyCLI();

private:
    CommandRegistry &registry;
    bool flag;
    std::string prompt;
    std::string usage;
};

COMMANDRESULT HelpCommand(const std::vector<std::string> &);
COMMANDRESULT ExitCommand(const std::vector<std::string> &);

#endif // MYCLI_H
