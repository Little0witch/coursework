#ifndef COURSEWORK_INPUT_CODE_H
#define COURSEWORK_INPUT_CODE_H

#include <SFML/Graphics.hpp>
#include <string>
#include "placement_field.h"
#include "socket.h"

class input_code {
private:
    sf::RenderWindow &window;
    sf::Texture texture_atlas;
    sf::Texture button_exit;
    sf::Sprite sprite;
    sf::Sprite sprite_exit;

    sf::Font font;
    sf::Text text;
    bool flag = false;
    sf::RectangleShape tmp;
    bool move_exit = false;


public:
    input_code(sf::RenderWindow &other) : window(other) {
        if (!texture_atlas.loadFromFile("../Resources/Img/Input code/m_w_input_code.png")) {
            logError(
                    "Error 2: file opening error, the place where the error occurred: /Headers/input_code.h, line 26");
            exit(1);
        }

        sprite.setTexture(texture_atlas);

        if (!font.loadFromFile("../Resources/Txt/JetBreins.ttf")) {
            logError(
                    "Error 2: file opening error, the place where the error occurred: /Headers/input_code.h, line 34");
            exit(1);
        }

        text.setFont(font);
        text.setCharacterSize(50);
        text.setFillColor(sf::Color::Black);
        text.setPosition(668.f, 413.f);

        if (!button_exit.loadFromFile("../Resources/Img/Input code/m_button_exit.png")) {
            logError(
                    "Error 2: file opening error, the place where the error occurred: /Headers/input_code.h, line 45");
            exit(1);
        }

        sprite_exit.setTexture(button_exit);
        sprite_exit.setPosition(572.f, 621.f);

        tmp.setSize(sf::Vector2f(523.f, 120.f));
        tmp.setFillColor(sf::Color(255, 255, 255, 128));
        tmp.setPosition(660.f, 400.f);

    }

    void input_code_run(bool &);
};


#endif //COURSEWORK_INPUT_CODE_H
