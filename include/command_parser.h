//
// Created by Jiarui She on 2023/6/9
// Command parser module
//

#ifndef COMMAND_PARSER_H
#define COMMAND_PARSER_H

#include "command.h"

namespace commandparser
{
    void ParseCommand(const std::string &, COMMAND *);

    void ExtractName(const std::string &, std::string *);

    void ExtractArguments(const std::string &, const std::string, std::vector<std::string> *);

    // void ExecuteCommand(const std::string &, const std::vector<std::string> &);
};

#endif  // COMMAND_PARSER_H
