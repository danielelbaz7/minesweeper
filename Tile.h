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
    Tile(sf::Vector2f position) {location = position;};
    sf::Vector2f getLocation() {return location;};
    State getState() {return thisState;};
    std::array<Tile*, 8>& getNeighbors() {return neighbors;};
    void setState(State _state) {thisState = _state;};
    void setNeighbors(std::array<Tile*, 8> _neighbors) {neighbors = _neighbors;}
    void onClickLeft() {thisState = REVEALED;};
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

protected:
    State thisState;
    void revealNeighbors() {
        for(Tile* neighbor : neighbors) {
            neighbor->setState(REVEALED);
        }};
};

class MineTile : public Tile {
public:
    MineTile(sf::Vector2f position) : Tile(position) {};
    void onClickLeft() {thisState = EXPLODED;}
};



#endif //TILE_H
