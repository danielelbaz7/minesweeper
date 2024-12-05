//
// Created by Daniel Elbaz on 12/4/24.
//

#include "Tile.h"
#include "Toolbox.h"

void Tile::draw() {
    if(thisState == HIDDEN) {
        sf::Sprite s(getAllTextures.at(17));
        Toolbox::getInstance().window.draw(s);
        s.setPosition(location);
    } else if(thisState == REVEALED) {
        sf::Sprite s(getAllTextures.at(18));
        Toolbox::getInstance().window.draw(s);
        s.setPosition(location);
    } else if(thisState == FLAGGED) {
        sf::Sprite s(getAllTextures.at(5));
        Toolbox::getInstance().window.draw(s);
        s.setPosition(location);
    }
};



