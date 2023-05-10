#ifndef COURSEWORK_INSTRUCTION_MANUAL_H
#define COURSEWORK_INSTRUCTION_MANUAL_H
#include <SFML/Graphics.hpp>
//#include "main_menu.h"

class instruction_manual {
private:
    sf::RenderWindow &window;
    sf::Texture background;
    sf::Texture button_exit_red;
    sf::Sprite sprite_background;
    sf::Sprite sprite_exit_red;

public:
    instruction_manual(sf::RenderWindow &other) : window(other)
    {
        background.loadFromFile("../Resources/Img/Instruction manual/wind_inst_w_but.png");
        button_exit_red.loadFromFile("../Resources/Img/Instruction manual/m_button_exit_red.png");
        sprite_background.setTexture(background);
        sprite_exit_red.setTexture(button_exit_red);
        sprite_exit_red.setPosition(658.f,915.f);
    }
    void instruction_manual_run();
};


#endif //COURSEWORK_INSTRUCTION_MANUAL_H
