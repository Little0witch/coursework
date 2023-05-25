#ifndef COURSEWORK_WINDOW_EXIT_H
#define COURSEWORK_WINDOW_EXIT_H

#include <SFML/Graphics.hpp>
#include "logs.h"

class window_exit {

private:
    sf::RenderWindow &window;
    sf::Texture background;
    sf::Texture button_yes_red;
    sf::Texture button_no_red;

    sf::Sprite sprite_background;
    sf::Sprite sprite_yes_red;
    sf::Sprite sprite_no_red;
    bool red_yes = false;
    bool red_no = false;

public:
    window_exit(sf::RenderWindow &other) : window(other) {
        if (!background.loadFromFile("../Resources/Img/End of the game/m_m_ending_game.png")) {
            logError(
                    "Error 2: file opening error, the place where the error occurred: /Headers/window_exit.h, line 21");
            exit(1);
        }
        sprite_background.setTexture(background);
        sprite_background.setPosition(590.f, 290.f);
        if (!button_yes_red.loadFromFile("../Resources/Img/End of the game/m_button_yes_red.png")) {
            logError(
                    "Error 2: file opening error, the place where the error occurred: /Headers/window_exit.h, line 28");
            exit(1);
        }
        sprite_yes_red.setTexture(button_yes_red);
        sprite_yes_red.setPosition(750.f, 524.f);
        if (!button_no_red.loadFromFile("../Resources/Img/End of the game/m_button_no_red.png")) {
            logError(
                    "Error 2: file opening error, the place where the error occurred: /Headers/window_exit.h, line 35");
            exit(1);
        }
        sprite_no_red.setTexture(button_no_red);
        sprite_no_red.setPosition(1059.f, 524.f);

    }

    void window_exit_run(bool &flag);
};

#endif //COURSEWORK_WINDOW_EXIT_H
