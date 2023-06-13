# MyCLI

A Command Line Interface built with cpp.

## 命名风格
- 文件名：下划线命名法
- 结构体、枚举、常量：全大写
- 函数名：大驼峰命名法
- 变量名：小驼峰命名法
- 命名空间：小写

## 命令解析模块

- 解析用户输入的命令，并提取出命令名称和参数。
- 可以根据需要设计命令行参数解析器，以支持不同的参数格式和选项。
- 可以使用字符串操作、正则表达式或其他相关技术来实现命令解析。

## 命令注册模块

- 注册、存储和管理所有可用的命令。
- 可以使用哈希表、关联数组或其他合适的数据结构来存储命令和对应的执行函数或对象。
- 提供注册和查询命令的接口，用于添加新命令和查找已注册的命令。

## 命令执行模块

- 执行解析后的命令。
- 可以使用命令对象/类或函数指针等机制来封装命令的执行逻辑。
- 通过查找命令注册表中的命令并调用相应的执行函数或方法来实现命令的执行。

## 可扩展性支持模块

- 支持CLI的可扩展性，允许动态添加、修改或删除命令。
- 可以实现命令插件系统、脚本语言集成、动态链接库加载等机制，以实现动态扩展命令的能力。

## 用户界面模块

- 与用户交互，接收用户输入和显示输出结果。
- 可以使用控制台、命令行界面库或图形界面库来实现用户界面。

### 注意点

1. C++声明变量时，声明后取指针和直接声明指针是不同的。声明后取指针由编译器进行内存管理，直接声明指针需要手动分配内存，一般用new关键字。以struct为例，struct中包含一个vector，如果直接声明一个指针，并且不用new分配内存，那么无法对vector进行操作。
2. 命令注册表使用了单例模式。
3. 头文件中定义的变量类似于全局变量，在不同的源文件中引入会造成重复定义的问题，应该采用条件编译或者`#pragma once`指令来解决该问题。