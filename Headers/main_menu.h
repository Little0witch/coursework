#ifndef COURSEWORK_MAIN_MENU_H
#define COURSEWORK_MAIN_MENU_H
#pragma once

#include <SFML/Graphics.hpp>
#include "connect_type.h"
#include "dif_levels.h"
#include "instruction_manual.h"
#include "window_exit.h"

class main_menu {
private:
    sf::RenderWindow &window;
    sf::Texture background;
    sf::Texture button_online_play;
    sf::Texture button_difficult_levels;
    sf::Texture button_instruction_manual;
    sf::Texture button_exit;

    sf::Sprite sprite_background;
    sf::Sprite sprite_online_play;
    sf::Sprite sprite_button_levels;
    sf::Sprite sprite_instruction_manual;
    sf::Sprite sprite_exit;

    bool red_online = false;
    bool red_dif_lv = false;
    bool red_man = false;
    bool red_exit = false;

public:
    main_menu(sf::RenderWindow &other) : window(other) {
        if (!background.loadFromFile("../Resources/Img/Main window/main_window.png")) {
            logError(
                    "Error 2: file opening error, the place where the error occurred: /Headers/main_menu.h, line 28");
            exit(1);
        }
        sprite_background.setTexture(background);
        if (!button_online_play.loadFromFile("../Resources/Img/Main window/button_online_red.png")) {
            logError(
                    "Error 2: file opening error, the place where the error occurred: /Headers/main_menu.h, line 34");
            exit(1);
        }
        sprite_online_play.setTexture(button_online_play);
        sprite_online_play.setPosition(562.f, 340.f);
        if (!button_difficult_levels.loadFromFile("../Resources/Img/Main window/m_button_bot_red.png")) {
            logError(
                    "Error 2: file opening error, the place where the error occurred: /Headers/main_menu.h, line 41");
            exit(1);
        }
        sprite_button_levels.setTexture(button_difficult_levels);
        sprite_button_levels.setPosition(562.f, 513.f);
        if (!button_instruction_manual.loadFromFile("../Resources/Img/Main window/button_instruction_red.png")) {
            logError(
                    "Error 2: file opening error, the place where the error occurred: /Headers/main_menu.h, line 48");
            exit(1);
        }
        sprite_instruction_manual.setTexture(button_instruction_manual);
        sprite_instruction_manual.setPosition(562.f, 685.f);
        if (!button_exit.loadFromFile("../Resources/Img/Main window/button_exit_red.png")) {
            logError(
                    "Error 2: file opening error, the place where the error occurred: /Headers/main_menu.h, line 55");
            exit(1);
        }
        sprite_exit.setTexture(button_exit);
        sprite_exit.setPosition(562.f, 857.f);
    }

    void main_menu_run();
};

#endif //COURSEWORK_MAIN_MENU_H
