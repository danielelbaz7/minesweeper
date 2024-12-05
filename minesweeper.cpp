//
// Created by Daniel Elbaz on 12/4/24.
//

#include <iostream>

#include "minesweeper.h"
#include "Toolbox.h"

Toolbox* TB = &Toolbox::getInstance();

void restart() {
    delete Toolbox::getInstance().gameState;
    TB->gameState = new GameState();
}

void render() {
    for(int i = 0; i < TB->yMineCount; i++) {
        for(int j = 0; j < TB->xMineCount; j++) {
            TB->gameState->getTile(j, i)->draw();
        }
    }
}

int launch() {
    while (TB->window.isOpen()) {
        sf::Event event;
        while (TB->window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                TB->window.close();
        }
    }
    return 0;
}

int main() {return launch();}
