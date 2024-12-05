cmake_minimum_required(VERSION 3.29)
project(MineSweeper)

set(CMAKE_CXX_STANDARD 20)

set(SFML_DIR "/opt/homebrew/opt/sfml")
find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

add_executable(MineSweeper
        minesweeper.cpp
        minesweeper.h
        Toolbox.cpp
        Toolbox.h
        Button.cpp
        Button.h
        Tile.cpp
        Tile.h
        GameState.cpp
        GameState.h)

target_link_libraries(MineSweeper sfml-graphics sfml-audio sfml-system)
