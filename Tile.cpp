//
// Created by Daniel Elbaz on 12/4/24.
//

#include "Tile.h"

#include <iostream>

#include "Toolbox.h"

void Tile::draw() {
    sf::Sprite s;
    if(thisState == HIDDEN) {
        s.setTexture(getAllTextures.at(17));
    } else if(thisState == REVEALED) {
        if(typeid(*this) != typeid(MineTile)) {
            s.setTexture(getAllTextures.at(18));
        } else {
            sf::RenderTexture rt;
            rt.create(32, 32);
            sf::Sprite t6(getAllTextures.at(6));
            sf::Sprite t18(getAllTextures.at(18));
            rt.draw(t18);
            rt.draw(t6);
            rt.display();
            s.setTexture(rt.getTexture());
        }
    } else if(thisState == FLAGGED) {
        s.setTexture(getAllTextures.at(5));
    }
    s.setPosition(location.x*32, location.y*32);
    Toolbox::getInstance().window.draw(s);
};




