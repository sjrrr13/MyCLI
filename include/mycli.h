//
// Created by Jiarui She on 2023/6/13
//

#ifndef MYCLI_H
#define MYCLI_H

#include "command_parser.h"
#include "command_register.h"
#include "command_executor.h"
#include <sstream>

class MyCLI
{
public:
    void Run();

    // void Stop();

    void SetPrompt(std::string &);

    // void SetBuffer();

    // void SetUsage(std::string &);

    // void SetHelp(const std::string &);

    void AddCommand(const std::string &, CommandHandler);

    MyCLI();

private:
    CommandRegistry &registry;
    bool flag;
    std::string prompt;
    // std::string usage;
    std::ostringstream buffer;
};

//  COMMANDRESULT HelpCommand(const std::vector<std::string> &);

#endif // MYCLI_H
