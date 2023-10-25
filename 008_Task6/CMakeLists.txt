cmake_minimum_required(VERSION 3.22)
project(008_Task6)

set(CMAKE_CXX_STANDARD 20)

include_directories(include)

if (MSVC)
    add_compile_options(/W4)
else ()
    add_compile_options(-Wall -Wextra -Wpedantic)
endif ()

add_executable(008_Task6 src/main.cpp
        include/INotifier.h
        include/SmsNotifier.h
        src/SmsNotifier.cpp
        include/EmailNotifier.h
        src/EmailNotifier.cpp)
