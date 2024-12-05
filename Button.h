//
// Created by Daniel Elbaz on 12/4/24.
//

#ifndef BUTTON_H
#define BUTTON_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>


class Button {
public:
    Button(sf::Vector2f _position, std::function<void(void)> _onClick);
    sf::Vector2f getPosition();
    sf::Sprite* getSprite();
    void setSprite(sf::Sprite* _sprite);
    void onClick();

private:
    sf::Vector2f position;
    sf::Sprite* sprite;
    std::function<void(void)> onClickFunction;
};



#endif //BUTTON_H
