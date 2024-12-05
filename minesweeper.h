//
// Created by Daniel Elbaz on 12/4/24.
//

#ifndef MINESWEEPER_H
#define MINESWEEPER_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>


int launch();
void restart();
void render();
void toggleDebugMode();
bool getDebugMode();



#endif //MINESWEEPER_H
