//
// Created by Daniel Elbaz on 12/4/24.
//

#ifndef TILE_H
#define TILE_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>



class Tile {
public:
    enum State {REVEALED, HIDDEN, FLAGGED, EXPLODED};
    Tile(sf::Vector2f position) {location = position; thisState = HIDDEN;}
    sf::Vector2f getLocation() {return location;}
    State getState() {return thisState;}
    std::array<Tile*, 8>& getNeighbors() {return neighbors;}
    void setState(State _state) {thisState = _state;}
    void setNeighbors(std::array<Tile*, 8> _neighbors) {neighbors = _neighbors;}
    void onClickLeft();
    void onClickRight() {
        if(thisState == HIDDEN) {
            thisState = FLAGGED;
        } else if (thisState == FLAGGED) {
            thisState = HIDDEN;
        }};
    void draw();
    virtual ~Tile() {};

private:
    std::array<Tile*, 8> neighbors;
    sf::Vector2f location;
    int type;
    void initializeTile();

    sf::RenderTexture rt;
    State thisState;
protected:
    void revealNeighbors() {
        for(Tile* neighbor : neighbors) {
            if(neighbor != nullptr && neighbor->getState() == HIDDEN) {
                neighbor->onClickLeft();
            }
        }};
};

class MineTile : public Tile {
public:
    MineTile(sf::Vector2f position) : Tile(position) {};
};



#endif //TILE_H
