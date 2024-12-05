//
// Created by Daniel Elbaz on 12/4/24.
//

#include "GameState.h"
#include <fstream>
#include <iostream>

GameState::GameState(const char *filepath) {
    std::ifstream boardFile(filepath);

    std::string currentLine;
    std::vector<int> row;
    std::vector<Tile*> tileRow;
    int rowCount = 0;
    while(std::getline(boardFile, currentLine)) {
        int colCount = 0;
        for(char &c : currentLine) {
            row.push_back(static_cast<int>(c));
            sf::Vector2f tilePos(rowCount, colCount);
            Tile* currentTile;
            if(c == '1') {
                currentTile = new MineTile(tilePos);
            } else if(c == '0') {
                currentTile = new Tile(tilePos);
            }
            currentTile->setState(Tile::HIDDEN);
            tileRow.push_back(currentTile);
            colCount++;
        }
        mineOrNot.push_back(row);
        tiles.push_back(tileRow);
    }

    createNeighborList();

    yMines = tiles.size();
    xMines = tiles[0].size();

}

GameState::GameState(sf::Vector2i _dimensions, int _numberOfMines) {
    std::set<int> mines;
    while(mines.size() < _numberOfMines) {
        int randomNumber = rand() % _dimensions.x * _dimensions.y;
        mines.insert(randomNumber);
    }

    for(int i = 0; i < _dimensions.x; i++) {
        for(int j = 0; j < _dimensions.y; j++) {
            if(mines.contains(i * _dimensions.x + j)) {

            }
        }
    }

    yMines = tiles.size();
    xMines = tiles[0].size();

}

void GameState::createNeighborList() {

    for(int i = 0; i < tiles.size(); i++) {
        for(int j = 0; j < tiles[i].size(); j++) {
            std::array<Tile*, 8> neighborList;
            if(i == 0) {
                neighborList[0] = nullptr;
                neighborList[1] = nullptr;
                neighborList[2] = nullptr;
            }

            if(i == tiles.size() - 1) {
                neighborList[5] = nullptr;
                neighborList[6] = nullptr;
                neighborList[7] = nullptr;
            }

            if(j == 0) {
                neighborList[0] = nullptr;
                neighborList[3] = nullptr;
                neighborList[5] = nullptr;
            }

            if(i == tiles[i].size() - 1) {
                neighborList[2] = nullptr;
                neighborList[4] = nullptr;
                neighborList[7] = nullptr;
            }

            for(int i = 0; i < 8; i++) {
                if(neighborList[i] != nullptr) {
                    if(i == 0) {
                        neighborList[i] = tiles[i-1][j-1];
                    } else if (i == 1) {
                        neighborList[i] = tiles[i-1][j];
                    } else if (i == 2) {
                        neighborList[i] = tiles[i-1][j+1];
                    } else if (i == 3) {
                        neighborList[i] = tiles[i][j-1];
                    } else if (i == 4) {
                        neighborList[i] = tiles[i][j+1];
                    } else if (i == 5) {
                        neighborList[i] = tiles[i+1][j-1];
                    } else if (i == 6) {
                        neighborList[i] = tiles[i+1][j];
                    } else if (i == 7) {
                        neighborList[i] = tiles[i+1][j+1];
                    }
                }
            }

            tiles[i][j]->setNeighbors(neighborList);

        }
    }
}


int GameState::getFlagCount() {
    int flagCount = 0;
    for(std::vector<Tile*> tileRow : tiles) {
        for(Tile* tile : tileRow) {
            if(tile->getState() == Tile::FLAGGED) {
                flagCount++;
            }
        }
    }
    return flagCount;
}

Tile* GameState::getTile(int x, int y) {
    return tiles[y][x];
}

GameState::PlayStatus GameState::getPlayStatus() {
    return playStatus;
}

void GameState::setPlayStatus(PlayStatus status) {
    playStatus = status;
}

int GameState::getMineCount() {
    int mineCount = 0;
    for(std::vector<Tile*> tileRow : tiles) {
        for(Tile* tile : tileRow) {
            if(tile == dynamic_cast<MineTile*>(tile)) {
                mineCount++;
            }
        }
    }
    return mineCount;

}





