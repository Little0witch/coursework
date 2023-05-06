#ifndef COURSEWORK_MAIN_MENU_H
#define COURSEWORK_MAIN_MENU_H
#pragma once
#include <SFML/Graphics.hpp>
#include "dif_levels.h"
#include "instruction_manual.h"
#include "window_exit.h"

class main_menu
{
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

    sf::Texture back_instr_man;
    sf::Sprite sprite_back_instr_man;

public:
    main_menu(sf::RenderWindow &other) : window(other)
    {
        background.loadFromFile("../Resources/Img/Main window/main_window.png");
        sprite_background.setTexture(background);
        button_online_play.loadFromFile("../Resources/Img/Main window/button_online_play_red.png");
        sprite_online_play.setTexture(button_online_play);
        sprite_online_play.setPosition(570.f,340.f);
        button_difficult_levels.loadFromFile("../Resources/Img/Main window/button_dif_level_red.png");
        sprite_button_levels.setTexture(button_difficult_levels);
        sprite_button_levels.setPosition(570.f,513.f);
        button_instruction_manual.loadFromFile("../Resources/Img/Main window/button_instruction_red.png");
        sprite_instruction_manual.setTexture(button_instruction_manual);
        sprite_instruction_manual.setPosition(570.f,685.f);
        button_exit.loadFromFile("../Resources/Img/Main window/button_exit_red.png");
        sprite_exit.setTexture(button_exit);
        sprite_exit.setPosition(570.f,857.f);

        back_instr_man.loadFromFile("../Resources/Img/Instruction manual/window_instruction_manual.png");
        sprite_back_instr_man.setTexture(back_instr_man);

    }
    void main_menu_run();
};

#endif //COURSEWORK_MAIN_MENU_H
