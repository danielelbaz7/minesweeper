//
// Created by Daniel Elbaz on 12/4/24.
//

#include <iostream>
#include <SFML/Graphics.hpp>

#include "minesweeper.h"
#include "Toolbox.h"

Toolbox* TB = &Toolbox::getInstance();

void restart() {

}


void render() {
    for(int i = 0; i < TB->yMineCount; i++) {
        for(int j = 0; j < TB->xMineCount; j++) {
            TB->gameState->getTile(i, j)->draw();
        }
    }
    sf::Sprite newGameButtonSprite = *TB->newGameButton->getSprite();
    newGameButtonSprite.setPosition(TB->newGameButton->getPosition());
    TB->window.draw(newGameButtonSprite);

    sf::Sprite button1Sprite = *TB->testButton1->getSprite();
    button1Sprite.setPosition(TB->testButton1->getPosition());
    TB->window.draw(button1Sprite);

    sf::Sprite button2Sprite = *TB->testButton2->getSprite();
    button2Sprite.setPosition(TB->testButton2->getPosition());
    TB->window.draw(button2Sprite);
}

int launch() {
    while (Toolbox::getInstance().window.isOpen()) {
        sf::Event event;
        while (TB->window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                TB->window.close();
        }
        TB->window.clear(sf::Color::White);
        render();
        TB->window.display();
    }
    return 0;
}

