cmake_minimum_required(VERSION 3.26)
project(014_Task13)

set(CMAKE_CXX_STANDARD 20)

include_directories(include)

if (MSVC)
    add_compile_options(/W4)
else ()
    add_compile_options(-Wall -Wextra -Wpedantic)
endif ()

add_executable(014_Task13 src/main.cpp
        include/Matrix.h
)
