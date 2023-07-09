//
// Created by Jiarui She on 2023/6/9
// Command parser module
//

#ifndef COMMAND_PARSER_H
#define COMMAND_PARSER_H

#include "command.h"
#include <sstream>

namespace commandparser
{
    void ParseCommand(const std::string &, COMMAND *);
};

#endif  // COMMAND_PARSER_H
