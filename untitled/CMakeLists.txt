cmake_minimum_required(VERSION 4.3)
project(untitled)

set(CMAKE_CXX_STANDARD 20)

add_executable(
        untitled src/main.cpp
        "include/message components/4.4 Tags.h"
        "include/decoder.h"
        "include/message components/Application Messages.h"
        "include/message components/Session Messages.h"
)
