//
// Created by Jiarui She on 2023/6/12
// Command results
//

#ifndef COMMAND_RESULT_H
#define COMMAND_RESULT_H

enum class COMMANDRESULT
{
    Success,
    Failure,
    InvalidArguments
};

class CommandResult
{
public:
    CommandResult();

private:
    int result;
};

#endif  // COMMAND_RESULT_H
