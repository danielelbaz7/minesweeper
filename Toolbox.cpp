//
// Created by Daniel Elbaz on 12/4/24.
//

#include "Toolbox.h"

#include <iostream>

#include "minesweeper.h"


Toolbox::Toolbox() {
    window.create(sf::VideoMode(800, 600), "P4 - Minesweeper, Daniel Elbaz", sf::Style::Close | sf::Style::Titlebar);
    gameState = new GameState();
    sf::Vector2f pos = sf::Vector2f(368, 512);
    newGameButton = new Button(pos, restart);
    newGameButton->setSprite(new sf::Sprite(getAllTextures.at(2)));
    sf::Vector2f pos1 = sf::Vector2f(560, 512);
    testButton1 = new Button(pos1, restart);
    testButton1->setSprite(new sf::Sprite(getAllTextures.at(15)));
    sf::Vector2f pos2 = sf::Vector2f(624, 512);
    testButton2 = new Button(pos2, restart);
    testButton2->setSprite(new sf::Sprite(getAllTextures.at(16)));
    sf::Vector2f pos3 = sf::Vector2f(600, 512);
    debugButton = new Button(pos3, restart);


    xMineCount = gameState->xMines;
    yMineCount = gameState->yMines;
}

void Toolbox::callBoardOne() {
    getInstance().gameState = new GameState("./MineSweeper/boards/testboard1.brd");
}

void Toolbox::callBoardTwo() {
    getInstance().gameState = new GameState("./MineSweeper/boards/testboard2.brd");
}




