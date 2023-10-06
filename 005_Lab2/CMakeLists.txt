cmake_minimum_required(VERSION 3.22)
project(005_Lab2)

set(CMAKE_CXX_STANDARD 20)

include_directories(include)

add_executable(005_Lab2 src/main.cpp
        src/Game/GameRules.cpp
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
        include/Player/Strategies/EvilRepeaterStrategy.h
        src/Player/Strategies/EvilRepeaterStrategy.cpp
        include/Player/Strategies/KindDumbassStrategy.h
        src/Player/Strategies/KindDumbassStrategy.cpp
        include/Player/Strategies/EvilDumbassStrategy.h
        src/Player/Strategies/EvilDumbassStrategy.cpp
        include/Player/Strategies/RandomStrategy.h
        src/Player/Strategies/RandomStrategy.cpp
        include/Player/Strategies/KindForgivingRepeaterStrategy.h
        src/Player/Strategies/KindForgivingRepeaterStrategy.cpp
        include/Player/Strategies/InconsistentStrategy.h
        src/Player/Strategies/InconsistentStrategy.cpp)
