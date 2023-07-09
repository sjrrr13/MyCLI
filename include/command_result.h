//
// Created by Jiarui She on 2023/6/12
// Command results
//

#ifndef COMMAND_RESULT_H
#define COMMAND_RESULT_H

#include <string>

struct COMMANDRESULT
{
    int code;
    std::string msg;

    COMMANDRESULT(int c, const std::string &m) : code(c), msg(m){};
};

#endif // COMMAND_RESULT_H
