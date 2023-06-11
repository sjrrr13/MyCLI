//
// Created by Jiarui She on 2023/6/9
//

#include <iostream>
#include <string>
#include <vector>

struct COMMAND
{
    std::string name;
    std::vector<std::string> args;

    // COMMAND() {};

    void Info()
    {
        std::cout << name << "; ";
        std::vector<std::string>::iterator it;
        for (it = args.begin(); it != args.end(); ++it)
            std::cout << *it << " ";

        std::cout << std::endl;
    }
};

namespace parser
{
    // 解析用户输入的命令字符串
    void ParseCommand(const std::string &, COMMAND *);

    // 提取命令名称
    void ExtractName(const std::string &, std::string *);

    // 提取命令参数
    void ExtractArguments(const std::string &, const std::string, std::vector<std::string> *);

    // 执行命令或将解析结果传递给其他模块
    void ExecuteCommand(const std::string &, const std::vector<std::string> &);
};
