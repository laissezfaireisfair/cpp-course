cmake_minimum_required(VERSION 3.22)
project(003_Lesson2)

set(CMAKE_CXX_STANDARD 20)

if (MSVC)
    add_compile_options(/W4)
else ()
    add_compile_options(-Wall -Wextra -Wpedantic -Werror)
endif ()

add_executable(003_Lesson2 main.cpp)
