cmake_minimum_required(VERSION 3.20)
project(MyCLI)

set(CMAKE_CXX_STANDARD 14)

include_directories(
        ${PROJECT_SOURCE_DIR}/include/
)

add_executable(
    MyCLI 
    main.cpp
    include/command.h
    include/command_parser.h
    include/command_register.h
    include/command_result.h
    src/command_parser.cpp
    src/command_register.cpp
    )

# target_link_libraries 必须要在 add_executable 之后，因为要先编译再链接
target_link_libraries(
        MyCLI
)