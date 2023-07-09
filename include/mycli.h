//
// Created by Jiarui She on 2023/6/13
//

#ifndef MYCLI_H
#define MYCLI_H

#include "command_parser.h"
#include "command_register.h"
#include "command_executor.h"
#include "command_result.h"
#include <sstream>

class MyCLI
{
public:
    void Run();

    void SetPrompt(std::string &);

    void AddCommand(const std::string &, CommandHandler);

    MyCLI();

private:
    CommandRegistry &registry;
    bool flag;
    std::string prompt;
    std::ostringstream buffer;
};

#endif // MYCLI_H
