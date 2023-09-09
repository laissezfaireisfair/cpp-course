cmake_minimum_required(VERSION 3.22)
project(Tests)

add_subdirectory(lib)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(Tests CreationTest.cpp
        InitAndPushTest.cpp
        InfoMethodsTest.cpp
        RotationTest.cpp
        CapactiyTest.cpp
        TestUtils.cpp
        TestUtils.h
        ResizeTest.cpp
        LinearizeTest.cpp
        InsertAndEraseTest.cpp
        ComparisonTest.cpp
        UniquePtrTest.cpp
        ExceptionsTest.cpp)

target_link_libraries(Tests 002_Lab2bLib)

target_link_libraries(Tests gtest gtest_main)