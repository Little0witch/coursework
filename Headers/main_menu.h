#ifndef COURSEWORK_MAIN_MENU_H
#define COURSEWORK_MAIN_MENU_H
#pragma once
#include <SFML/Graphics.hpp>
#include "dif_levels.h"

class main_menu
{
private:
    sf::RenderWindow window;
    sf::Texture background;
    sf::Texture button_difficult_levels;
    sf::Sprite sprite_background;
    sf::Sprite sprite_button_levels;
public:
    main_menu() : window(sf::VideoMode(1846,1048),"aaaa")
    {
        background.loadFromFile("../Resources/Img/Main window/main_window.png");
        sprite_background.setTexture(background);
        button_difficult_levels.loadFromFile("../Resources/Img/Main window/Игра с ботом.png");
        sprite_button_levels.setTexture(button_difficult_levels);
        sprite_button_levels.setPosition(570.f,513.f);
    }
    void main_menu_run();
};

#endif //COURSEWORK_MAIN_MENU_H
