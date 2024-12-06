//
// Created by Daniel Elbaz on 12/4/24.
//

#include "GameState.h"
#include <fstream>
#include <iostream>

GameState::GameState(const char *filepath) {
    playStatus = PLAYING;
    std::ifstream boardFile(filepath);

    std::string currentLine;
    int rowCount = 0;
    while(std::getline(boardFile, currentLine)) {
        std::vector<Tile*> tileRow;
        int colCount = 0;
        for(char c : currentLine) {
            sf::Vector2f tilePos(colCount, rowCount);
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
        tiles.push_back(tileRow);
        rowCount++;
    }

    createNeighborList();

    yMines = tiles.size();
    xMines = tiles[0].size();

}

GameState::GameState(sf::Vector2i _dimensions, int _numberOfMines) {
    playStatus = PLAYING;
    tiles.clear();
    for(auto& row : tiles) {
        row.resize(_dimensions.x);
    }
    std::set<int> mines;
    std::srand(std::time(nullptr));

    while(mines.size() < _numberOfMines) {
        int randomNumber = rand() % (_dimensions.x * _dimensions.y);
        mines.insert(randomNumber);
    }

    for(int i = 0; i < _dimensions.y; i++) {
        std::vector<Tile*> tileRow;
        for(int j = 0; j < _dimensions.x; j++) {
            sf::Vector2f tilePos(j, i);
            if(mines.contains(((i * _dimensions.x) + j))) {
                MineTile* currentTile = new MineTile(tilePos);
                tileRow.push_back(currentTile);
            } else {
                Tile* currentTile = new Tile(tilePos);
                tileRow.push_back(currentTile);
            }
        }

        tiles.push_back(tileRow);
    }

    createNeighborList();

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

            for(int k = 0; k < 8; k++) {
                if(neighborList[k] != nullptr) {
                    if(k == 0) {
                        neighborList[k] = tiles[i-1][j-1];
                    } else if (k == 1) {
                        neighborList[k] = tiles[i-1][j];
                    } else if (k == 2) {
                        neighborList[k] = tiles[i-1][j+1];
                    } else if (k == 3) {
                        neighborList[k] = tiles[i][j-1];
                    } else if (k == 4) {
                        neighborList[k] = tiles[i][j+1];
                    } else if (k == 5) {
                        neighborList[k] = tiles[i+1][j-1];
                    } else if (k == 6) {
                        neighborList[k] = tiles[i+1][j];
                    } else if (k == 7) {
                        neighborList[k] = tiles[i+1][j+1];
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





