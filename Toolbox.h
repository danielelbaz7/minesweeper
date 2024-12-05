//
// Created by Daniel Elbaz on 12/4/24.
//
#ifndef TOOLBOX_H
#define TOOLBOX_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include "GameState.h"
#include "Button.h"


class Toolbox {

public:
    sf::RenderWindow window;
    GameState* gameState;
    Button* debugButton;
    Button* newGameButton;
    Button* testButton1;
    Button* testButton2;


    static Toolbox &getInstance() {
        static Toolbox instance;
        return instance;
    }

    int xMineCount;
    int yMineCount;

private:
    Toolbox();
    static void callBoardOne();
    static void callBoardTwo();


};

static std::vector<sf::Texture> getAllTextures = []{
    std::vector<sf::Texture> textures(19);
    textures.at(0).loadFromFile("./images/debug.png");
    textures.at(1).loadFromFile("./images/digits.png");
    textures.at(2).loadFromFile("./images/face_happy.png");
    textures.at(3).loadFromFile("./images/face_lose.png");
    textures.at(4).loadFromFile("./images/face_win.png");
    textures.at(5).loadFromFile("./images/flag.png");
    textures.at(6).loadFromFile("./images/mine.png");
    textures.at(7).loadFromFile("./images/number_1.png");
    textures.at(8).loadFromFile("./images/number_2.png");
    textures.at(9).loadFromFile("./images/number_3.png");
    textures.at(10).loadFromFile("./images/number_4.png");
    textures.at(11).loadFromFile("./images/number_5.png");
    textures.at(12).loadFromFile("./images/number_6.png");
    textures.at(13).loadFromFile("./images/number_7.png");
    textures.at(14).loadFromFile("./images/number_8.png");
    textures.at(15).loadFromFile("./images/test_1.png");
    textures.at(16).loadFromFile("./images/test_2.png");
    textures.at(17).loadFromFile("./images/tile_hidden.png");
    textures.at(18).loadFromFile("./images/tile_revealed.png");
    return textures;
}();



#endif //TOOLBOX_H
