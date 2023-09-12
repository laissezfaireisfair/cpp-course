cmake_minimum_required(VERSION 3.16)
project(002_Lab2b)

set(CMAKE_CXX_STANDARD 20)

include_directories(include)

if (MSVC)
    add_compile_options(/W4)
else ()
    add_compile_options(-Wall -Wextra -Wpedantic -Werror)
endif ()

add_library(002_Lab2bLib SHARED
        include/CircularBuffer.h)

set_target_properties(002_Lab2bLib PROPERTIES LINKER_LANGUAGE CXX)

add_subdirectory(tests)

add_executable(002_Lab2bExec)
target_sources(002_Lab2bExec PRIVATE src/main.cpp)
target_link_libraries(002_Lab2bExec PRIVATE 002_Lab2bLib)