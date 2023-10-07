cmake_minimum_required(VERSION 3.16)
project(Tests)

add_subdirectory(lib)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(Tests GameCreationTest.cpp)

target_link_libraries(Tests 005_Lab2Lib)

target_link_libraries(Tests gtest gtest_main)