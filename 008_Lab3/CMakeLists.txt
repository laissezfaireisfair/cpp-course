cmake_minimum_required(VERSION 3.16)
project(008_Lab3)

set(CMAKE_CXX_STANDARD 20)

include_directories(include)

if (MSVC)
    add_compile_options(/W4)
else ()
    add_compile_options(-Wall -Wextra -Wpedantic -Werror)
endif ()

add_executable(008_Lab3 src/main.cpp
        include/Audio.h
        src/Audio.cpp
        include/WavEncoder.h
        src/WavEncoder.cpp
        include/Application.h
        src/Application.cpp
        include/Commands/ICommand.h)
