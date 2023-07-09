//
// Created by Jiarui She on 2023/6/12
// Command structure
//

#ifndef COMMAND_H
#define COMMAND_H

#include <iostream>
#include <string>
#include <vector>

struct COMMAND
{
    std::string name;
    std::vector<std::string> args;

    void Info()
    {
        std::cout << name << "; ";
        std::vector<std::string>::iterator it;
        std::cout << args.size() << " args: ";
        for (it = args.begin(); it != args.end(); ++it)
            std::cout << *it << " ";

        std::cout << std::endl;
    }

    void clear()
    {
        name = "";
        args.clear();
    }
};

#endif  // COMMAND
