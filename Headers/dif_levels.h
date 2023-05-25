#pragma once
#ifndef COURSEWORK_DIF_LEVELS_H
#define COURSEWORK_DIF_LEVELS_H

#include <SFML/Graphics.hpp>
#include "placement_field.h"


class dif_levels {
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
    bool red_easy = false;
    bool red_hard = false;
    bool red_exit = false;

public:
    dif_levels(sf::RenderWindow &other) ;

    void dif_levels_run();
};


#endif //COURSEWORK_DIF_LEVELS_H
