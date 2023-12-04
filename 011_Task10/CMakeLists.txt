cmake_minimum_required(VERSION 3.22)
project(011_Task10)

set(CMAKE_CXX_STANDARD 20)

include_directories(include)

if (MSVC)
    add_compile_options(/W4)
else ()
    add_compile_options(-Wall -Wextra -Wpedantic)
endif ()

add_executable(011_Task10 src/main.cpp
        include/Section.h
        include/Document.h
        include/Reader.h
        src/Section.cpp
        src/Document.cpp
        src/Reader.cpp
        include/Writer.h
        src/Writer.cpp)
