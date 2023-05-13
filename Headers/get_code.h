#ifndef COURSEWORK_GET_CODE_H
#define COURSEWORK_GET_CODE_H
#include <SFML/Graphics.hpp>

class get_code {

private:
    sf::RenderWindow &window;
    sf::Texture background;
    sf::Texture button_ok_red;

    sf::Sprite sprite_background;
    sf::Sprite sprite_ok_red;

    sf::Font font;
    sf::Text connect_code;

public:
    get_code(sf::RenderWindow &other): window(other)
    {
        background.loadFromFile("../Resources/Img/Input code/w_get_code.png");
        sprite_background.setTexture(background);

        button_ok_red.loadFromFile("../Resources/Img/Input code/m_button_exit.png");
        sprite_ok_red.setTexture(button_ok_red);
        sprite_ok_red.setPosition(572.f,621.f);

        font.loadFromFile("../Resources/Txt/JetBreins.ttf");

        connect_code.setFont(font);
        connect_code.setCharacterSize(50);
        connect_code.setFillColor(sf::Color::Black);
        connect_code.setPosition(668.f,413.f);

    }
};


#endif //COURSEWORK_GET_CODE_H
