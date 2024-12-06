//
// Created by Daniel Elbaz on 12/4/24.
//

#include "Tile.h"

#include <iostream>

#include "Toolbox.h"

void Tile::draw() {
    sf::RenderTexture rt;
    rt.create(32, 32);
    rt.clear();
    sf::Sprite revealed(getAllTextures.at(18));
    sf::Sprite mine(getAllTextures.at(6));
    rt.draw(revealed);
    rt.draw(mine);
    rt.display();
    sf::Sprite s;
    if(thisState == HIDDEN) {
        if(Toolbox::getInstance().debug == false) {
            s.setTexture(getAllTextures.at(17));
        } else {
            if(typeid(*this) == typeid(MineTile)) {
                s.setTexture(rt.getTexture());
            } else {
                s.setTexture(getAllTextures.at(17));
            }
        }
    } else if(thisState == REVEALED) {
        s.setTexture(getAllTextures.at(18));
    } else if(thisState == FLAGGED) {
        s.setTexture(getAllTextures.at(5));
    } else if(thisState == EXPLODED) {
        s.setTexture(rt.getTexture());
    }
    s.setPosition(location.x*32, location.y*32);
    Toolbox::getInstance().window.draw(s);
};

void Tile::onClickLeft() {
    if(thisState == HIDDEN) {
        if(typeid(*this) == typeid(MineTile)) {
            thisState = EXPLODED;
            Toolbox::getInstance().gameState->setPlayStatus(GameState::LOSS);
        } else {
            thisState = REVEALED;
            bool anyMineNeighbors = false;
            for(Tile* n : this->neighbors) {
                if(n != nullptr) {
                    std::cout << "SSKSSJSJSHJHJ" << std::endl;
                    if(typeid(*n) == typeid(MineTile)) {
                        anyMineNeighbors = true;
                    }
                }
            }
            if(anyMineNeighbors == false) {
                revealNeighbors();
            }
        }
    }
}




