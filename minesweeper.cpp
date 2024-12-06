//
// Created by Daniel Elbaz on 12/4/24.
//

#include <iostream>
#include <SFML/Graphics.hpp>

#include "minesweeper.h"
#include "Toolbox.h"

Toolbox* TB = &Toolbox::getInstance();

void restart() {
    delete TB->gameState;
    TB->gameState = new GameState();
}

void render() {
    for(int i = 0; i < TB->yMineCount; i++) {
        for(int j = 0; j < TB->xMineCount; j++) {
            TB->gameState->getTile(j, i)->draw();
        }
    }

    sf::Sprite newGameButtonSprite = *TB->newGameButton->getSprite();
    if(TB->gameState->getPlayStatus() == GameState::LOSS) {
        newGameButtonSprite.setTexture(getAllTextures.at(3));
    }
    newGameButtonSprite.setPosition(TB->newGameButton->getPosition());
    TB->window.draw(newGameButtonSprite);

    sf::Sprite button1Sprite = *TB->testButton1->getSprite();
    button1Sprite.setPosition(TB->testButton1->getPosition());
    TB->window.draw(button1Sprite);

    sf::Sprite button2Sprite = *TB->testButton2->getSprite();
    button2Sprite.setPosition(TB->testButton2->getPosition());
    TB->window.draw(button2Sprite);

    sf::Sprite debugButtonSprite = *TB->debugButton->getSprite();
    debugButtonSprite.setPosition(TB->debugButton->getPosition());
    TB->window.draw(debugButtonSprite);
}

int launch() {
    while (Toolbox::getInstance().window.isOpen()) {
        sf::Event event;
        while (TB->window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                TB->window.close();
            }
            if(event.type == sf::Event::MouseButtonPressed) {
                if(event.mouseButton.button == sf::Mouse::Left) {
                    int xPos = event.mouseButton.x;
                    int yPos = event.mouseButton.y;
                    if(yPos < TB->yMineCount*32 && TB->gameState->getPlayStatus() == GameState::PLAYING) {
                        TB->gameState->getTile(xPos/32, yPos/32)->onClickLeft();
                    } else if(yPos > TB->yMineCount*32){
                        if(xPos >= 368 && xPos <= 450) {
                            TB->newGameButton->onClick();
                        } else if (xPos >= 496 && xPos <= 560) {
                            TB->debugButton->onClick();
                        } else if (xPos > 560 && xPos <= 624) {
                            TB->testButton2->onClick();
                        } else if (xPos > 624 && xPos <= 768) {
                            TB->testButton1->onClick();
                        }
                    }
                }
            }
        }

        TB->window.clear(sf::Color::White);
        render();
        TB->window.display();
    }
    return 0;
}

void toggleDebugMode() {
    TB->debug = !TB->debug;
}

bool getDebugMode() {
    return TB->debug;
}
