#ifndef COURSEWORK_INSTRUCTION_MANUAL_H
#define COURSEWORK_INSTRUCTION_MANUAL_H
#include <SFML/Graphics.hpp>
#include "main_menu.h"

class instruction_manual {
private:
    sf::RenderWindow window;
    sf::Texture background;
    sf::Texture button_exit_blue;
    sf::Texture button_exit_red;
    sf::Sprite sprite_background;
    sf::Sprite sprite_exit_blue;
    sf::Sprite sprite_exit_red;
public:
    instruction_manual() : window(sf::VideoMode(1846,1048),"Battlership")
    {
        background.loadFromFile("../Resources/Img/Instruction manual/window_instruction_manual.png");
        button_exit_blue.loadFromFile("../Resources/Img/Instruction manual/button_exit_blue.png");
        button_exit_red.loadFromFile("../Resources/Img/Instruction manual/button_exit_red.png");
        sprite_background.setTexture(background);
        sprite_exit_blue.setTexture(button_exit_blue);
        sprite_exit_blue.setPosition(665.f,918.f);
        sprite_exit_red.setTexture(button_exit_red);
        sprite_exit_red.setPosition(665.f,918.f);
    }
    void instruction_manual_run();
};


#endif //COURSEWORK_INSTRUCTION_MANUAL_H
