//
// Created by Jiarui She on 2023/6/12
// Command results
//

#ifndef COMMAND_RESULT_H
#define COMMAND_RESULT_H

#include <string>

// enum class COMMANDRESULT
// {
//     Success,
//     Failure
// };

struct COMMANDRESULT
{
    int code;
    std::string msg;

    COMMANDRESULT(int c, const std::string &m) : code(c), msg(m){};
};

// class CommandResult
// {
// public:
//     CommandResult();

//     std::string GetMessage();

// private:
//     int code;
//     std::string message;
// };

#endif // COMMAND_RESULT_H
