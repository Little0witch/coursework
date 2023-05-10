#pragma once
#ifndef COURSEWORK_DIF_LEVELS_H
#define COURSEWORK_DIF_LEVELS_H
#include <SFML/Graphics.hpp>
#include "placement_field.h"


class dif_levels
{
private:
    sf::RenderWindow &window;
    sf::Texture background;
    sf::Texture button_easy_blue;
    sf::Texture button_easy_red;
    sf::Texture button_hard_blue;
    sf::Texture button_hard_red;
    sf::Texture button_exit_blue;
    sf::Texture button_exit_red;

    sf::Sprite sprite_background;
    sf::Sprite sprite_button_easy_blue;
    sf::Sprite sprite_button_easy_red;
    sf::Sprite sprite_button_hard_blue;
    sf::Sprite sprite_button_hard_red;
    sf::Sprite sprite_button_exit_blue;
    sf::Sprite sprite_button_exit_red;

    bool flag = false;
    sf::RectangleShape tmp;
public:
    dif_levels(sf::RenderWindow &other) : window(other)
    {
        background.loadFromFile("../Resources/Img/Difficulty levels/difficulty_levels.png");
        button_easy_red.loadFromFile("../Resources/Img/Difficulty levels/m_button_easy_red.png");
        button_hard_red.loadFromFile("../Resources/Img/Difficulty levels/m_button_hard_red.png");
        button_exit_red.loadFromFile("../Resources/Img/Difficulty levels/m_button_exit_red.png");
        sprite_background.setTexture(background);

        sprite_button_easy_red.setTexture(button_easy_red);
        sprite_button_easy_red.setPosition(570.f,450.f);
        sprite_button_hard_red.setTexture(button_hard_red);
        sprite_button_hard_red.setPosition(570.f,623.f);
        sprite_button_exit_red.setTexture(button_exit_red);
        sprite_button_exit_red.setPosition(570.f,793.f);

    }
    void dif_levels_run();
};


#endif //COURSEWORK_DIF_LEVELS_H
