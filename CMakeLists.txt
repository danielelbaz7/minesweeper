cmake_minimum_required(VERSION 3.29)
project(MineSweeper)

set(CMAKE_CXX_STANDARD 20)

set(SFML_DIR "/opt/homebrew/opt/sfml")
find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

add_executable(MineSweeper
        main.cpp
        Toolbox.h
        Toolbox.cpp)

target_link_libraries(MineSweeper sfml-system sfml-window sfml-graphics sfml-network sfml-audio)

target_link_libraries(MineSweeper sfml-system sfml-window sfml-graphics sfml-network sfml-audio
        "-framework Cocoa" "-framework OpenGL" "-framework IOKit" "-framework CoreFoundation" "-framework CoreVideo")

