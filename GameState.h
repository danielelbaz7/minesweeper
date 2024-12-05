//
// Created by Daniel Elbaz on 12/4/24.
//

#ifndef GAMESTATE_H
#define GAMESTATE_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include "Tile.h"


class GameState {
    friend class Toolbox;
public:
    enum PlayStatus {WIN, LOSS, PLAYING};
    GameState(sf::Vector2i _dimensions = sf::Vector2i(25, 16), int _numberOfMines = 50);
    GameState(const char* filepath);
    int getFlagCount();
    int getMineCount();
    Tile* getTile(int x, int y);
    PlayStatus getPlayStatus();
    void setPlayStatus(PlayStatus _status);

private:
    std::vector<std::vector<Tile*>> tiles;
    std::vector<std::vector<int>> mineOrNot;
    int xMines;
    int yMines;
    PlayStatus playStatus;
    void createNeighborList();
};

#endif //GAMESTATE_H
