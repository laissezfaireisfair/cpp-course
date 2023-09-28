cmake_minimum_required(VERSION 3.22)
project(005_Lab2)

set(CMAKE_CXX_STANDARD 20)

include_directories(include)

add_executable(005_Lab2 src/main.cpp
        include/GameRules.h
        src/GameRules.cpp
        include/IStrategy.h
        include/Decision.h
        include/IPlayerStatusFacade.h
        include/IPlayerPlayFacade.h
        include/Player.h
        src/Player.cpp
        src/PlayerFactory.cpp
        include/PlayerFactory.h
        include/KindRepeaterStrategy.h
        src/KindRepeaterStrategy.cpp
        include/IGameState.h
        src/IGameState.cpp
        include/Game.h
        src/Game.cpp
        include/InitializationGameState.h
        src/InitializationGameState.cpp
        include/EndGameState.h
        src/EndGameState.cpp)
