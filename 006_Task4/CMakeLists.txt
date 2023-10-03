cmake_minimum_required(VERSION 3.26)
project(006_Task4)

set(CMAKE_CXX_STANDARD 20)

include_directories(include)

if (MSVC)
    add_compile_options(/W4)
else ()
    add_compile_options(-Wall -Wextra -Wpedantic -Werror)
endif ()

add_executable(006_Task4 src/main.cpp
        src/Date.cpp
        src/Budget.cpp)
