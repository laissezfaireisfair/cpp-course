cmake_minimum_required(VERSION 3.22)
project(005_Lab2)

set(CMAKE_CXX_STANDARD 20)

include_directories(include)

if (MSVC)
    add_compile_options(/W4)
else ()
    add_compile_options(-Wall -Wextra -Wpedantic)
endif ()

add_library(005_Lab2Lib SHARED src/Game/GameRules.cpp
        src/Player/Player.cpp
        src/Player/PlayerFactory.cpp
        src/Player/Strategies/KindRepeaterStrategy.cpp
        src/Game/State/IGameState.cpp
        src/Game/Game.cpp
        src/Game/State/InitializationGameState.cpp
        src/Game/State/EndGameState.cpp
        src/Configurator.cpp
        src/Game/State/ProcessGameState.cpp
        src/Game/State/DetailedGameState.cpp
        src/Decision.cpp
        src/Game/State/FastGameState.cpp
        src/Game/State/TournamentGameState.cpp
        src/Player/Strategies/EvilRepeaterStrategy.cpp
        src/Player/Strategies/KindDumbassStrategy.cpp
        src/Player/Strategies/EvilDumbassStrategy.cpp
        src/Player/Strategies/RandomStrategy.cpp
        src/Player/Strategies/KindForgivingRepeaterStrategy.cpp
        src/Player/Strategies/InconsistentStrategy.cpp)

set_target_properties(005_Lab2Lib PROPERTIES LINKER_LANGUAGE CXX)

add_subdirectory(tests)

add_executable(005_Lab2)
target_sources(005_Lab2 PRIVATE src/main.cpp)
target_link_libraries(005_Lab2 PRIVATE 005_Lab2Lib)