cmake_minimum_required(VERSION 3.26)
project(013_Task12)

include_directories(include)

set(CMAKE_CXX_STANDARD 20)

if (MSVC)
    add_compile_options(/W4)
else ()
    add_compile_options(-Wall -Wextra -Wpedantic)
endif ()

add_executable(013_Task12 src/main.cpp
        include/ListAllocator.h
        include/MemoryBlock.h
        src/MemoryBlock.cpp
)
