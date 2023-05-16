#ifndef COURSEWORK_GET_CODE_H
#define COURSEWORK_GET_CODE_H

#include <SFML/Graphics.hpp>
#include "socket.h"
#include "placement_field.h"

class get_code {

private:
    sf::RenderWindow &window;
    sf::Texture background;
    sf::Texture button_ok_red;

    sf::Sprite sprite_background;
    sf::Sprite sprite_ok_red;

    sf::Font font;
    sf::Text connect_code;

    bool move_on_button = false;
    std::string s_tmp;

public:

    get_code(sf::RenderWindow &other) : window(other) {

        if (!background.loadFromFile("../Resources/Img/Input code/w_get_code.png")) {
            logError(
                    "Error 2: file opening error, the place where the error occurred: /Headers/get_code.h, line 28");
            exit(1);
        }


        sprite_background.setTexture(background);

        if (!button_ok_red.loadFromFile("../Resources/Img/Input code/m_button_exit.png")) {
            logError(
                    "Error 2: file opening error, the place where the error occurred: /Headers/get_code.h, line 37");
            exit(1);
        }

        sprite_ok_red.setTexture(button_ok_red);
        sprite_ok_red.setPosition(572.f, 621.f);

        if (!font.loadFromFile("../Resources/Txt/JetBreins.ttf")) {
            logError(
                    "Error 2: file opening error, the place where the error occurred: /Headers/get_code.h, line 46");
            exit(1);
        }

        s_tmp = getCode();
        connect_code.setFont(font);
        connect_code.setCharacterSize(70);
        connect_code.setFillColor(sf::Color::Black);
        connect_code.setPosition(614.f, 410.f);
        connect_code.setString(s_tmp);
    }

    void get_code_run(bool &);
};


#endif //COURSEWORK_GET_CODE_H
