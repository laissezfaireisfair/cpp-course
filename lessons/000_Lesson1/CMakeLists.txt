cmake_minimum_required(VERSION 3.26)
project(000_Lesson1)

set(CMAKE_CXX_STANDARD 20)

include_directories(include)

if (MSVC)
    add_compile_options(/W4)
else ()
        add_compile_options(-Wall -Wextra -Wpedantic -Werror)
endif ()

add_executable(000_Lesson1 src/main.cpp
        src/SquareEquation.cpp)
