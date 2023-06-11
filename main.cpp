#include <iostream>
#include <sstream>

#include "parser.h"

#include <iostream>
#include <string>
#include <vector>

struct A {
    std::string str;
    int a;
    bool b;
    // std::vector<std::string> vec;

    // A() {} // 默认构造函数不再初始化vec
};

// int main() {
//     A *a; // 创建结构体A的对象

//     // 声明一个指向结构体A的指针，并让它指向a对象
//     // A* ptr = &a;

//     // 通过指针对结构体A的变量进行赋值
//     a->str = "Hello";
//     a->a = 1;
//     a->b = false;

//     // 打印赋值后的结果
//     std::cout << "str: " << a->str << std::endl;
//     std::cout << "a: " << a->a << std::endl;
//     std::cout << "b: " << a->b << std::endl;
//     std::cout << std::endl;

//     return 0;
// }


// void test()
// {
//     std::string argumentsString = "  cmd  \t -a\t -b  -c";
//     std::istringstream iss(argumentsString);
//     std::string argument;
//     while (iss >> argument)
//         std::cout << argument << ";" << std::endl;
// }

int main()
{
    //  cmd \t -a\t-b  -c
    std::string userInput;
    COMMAND cmd;

    auto p = &cmd;

    // 接收用户输入
    std::cout << "Enter a command: ";
    std::getline(std::cin, userInput);

    // 解析用户输入的命令
    parser::ParseCommand(userInput, p);
    p->Info();

    // test();

    return 0;
}