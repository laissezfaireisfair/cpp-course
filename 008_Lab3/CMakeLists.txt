cmake_minimum_required(VERSION 3.16)
project(008_Lab3)

set(CMAKE_CXX_STANDARD 20)

include_directories(include)

if (MSVC)
    add_compile_options(/W4)
else ()
    add_compile_options(-Wall -Wextra -Wpedantic)
endif ()

add_executable(008_Lab3 src/main.cpp
        include/Audio.h
        src/Audio.cpp
        include/WavEncoder.h
        src/WavEncoder.cpp
        include/Application.h
        src/Application.cpp
        include/Commands/ICommand.h
        include/Commands/ICommandFactory.h
        src/Commands/ICommand.cpp
        src/Commands/ICommandFactory.cpp
        include/Commands/MuteCommand.h
        src/Commands/MuteCommand.cpp
        include/Commands/MuteCommandFactory.h
        src/Commands/MuteCommandFactory.cpp
        include/AppParameters.h
        include/Commands/MixCommand.h
        src/Commands/MixCommand.cpp
        include/Commands/MixCommandFactory.h
        src/Commands/MixCommandFactory.cpp
        include/IAudioPoolFacade.h
        src/IAudioPoolFacade.cpp
        include/Commands/InsertCommand.h
        src/Commands/InsertCommand.cpp
        include/Commands/InsertCommandFactory.h
        src/Commands/InsertCommandFactory.cpp
        src/IAudioPoolFacade.cpp
)
