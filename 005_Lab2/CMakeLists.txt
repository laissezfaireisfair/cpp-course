cmake_minimum_required(VERSION 3.26)
project(005_Lab2)

set(CMAKE_CXX_STANDARD 20)

include_directories(include)

add_executable(005_Lab2 src/main.cpp
        include/GameRules.h
        src/GameRules.cpp
        include/IStrategy.h
        include/Decision.h)
