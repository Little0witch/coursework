#pragma once
#ifndef COURSEWORK_DIF_LEVELS_H
#define COURSEWORK_DIF_LEVELS_H
#include <SFML/Graphics.hpp>
#include "main_menu.h"

class dif_levels
{
private:
    sf::RenderWindow window;
    sf::Texture background;
    sf::Texture button_easy;
    sf::Texture button_hard;
    sf::Texture button_exit;
    sf::Sprite sprite;
public:
    dif_levels() : window(sf::VideoMode(1846,1048),"Battlership")
    {
        background.loadFromFile("../Resources/Img/Difficulty levels/difficulty_levels.png");
        sprite.setTexture(background);
    }
    void dif_levels_run();
};


#endif //COURSEWORK_DIF_LEVELS_H
