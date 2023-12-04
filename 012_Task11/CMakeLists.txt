cmake_minimum_required(VERSION 3.22)
project(012_Task11)

include_directories(include)

set(CMAKE_CXX_STANDARD 20)

if (MSVC)
    add_compile_options(/W4)
else ()
    add_compile_options(-Wall -Wextra -Wpedantic)
endif ()

add_executable(012_Task11 src/main.cpp
        include/Email.h
        src/Email.cpp
        include/Workers/Worker.h
        src/Workers/Worker.cpp
        include/Workers/Reader.h
        src/Workers/Reader.cpp
        include/Workers/Filter.h
        src/Workers/Filter.cpp
        include/Workers/Copier.h
        src/Workers/Copier.cpp
        include/Workers/Sender.h
        src/Workers/Sender.cpp
        include/PipelineBuilder.h
        src/PipelineBuilder.cpp)
