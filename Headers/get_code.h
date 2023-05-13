#ifndef COURSEWORK_GET_CODE_H
#define COURSEWORK_GET_CODE_H
#include <SFML/Graphics.hpp>
#include "socket.h"

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

    get_code(sf::RenderWindow &other): window(other)
    {
        background.loadFromFile("../Resources/Img/Input code/w_get_code.png");
        sprite_background.setTexture(background);

        button_ok_red.loadFromFile("../Resources/Img/Input code/m_button_exit.png");
        sprite_ok_red.setTexture(button_ok_red);
        sprite_ok_red.setPosition(572.f,621.f);

        font.loadFromFile("../Resources/Txt/JetBreins.ttf");

        s_tmp = getCode();

        connect_code.setFont(font);
        connect_code.setCharacterSize(70);
        connect_code.setFillColor(sf::Color::Black);
        connect_code.setPosition(614.f,410.f);
        connect_code.setString(s_tmp);
    }
    void get_code_run();
};


#endif //COURSEWORK_GET_CODE_H
