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
    input_code(sf::RenderWindow &other) : window(other)
    {
        texture_atlas.loadFromFile("../Resources/Img/Input code/m_w_input_code.png");
        sprite.setTexture(texture_atlas);

        font.loadFromFile("../Resources/Txt/JetBreins.ttf");

        text.setFont(font);
        text.setCharacterSize(50);
        text.setFillColor(sf::Color::Black);
        text.setPosition(668.f,413.f);

        button_exit.loadFromFile("../Resources/Img/Input code/m_button_exit.png");
        sprite_exit.setTexture(button_exit);
        sprite_exit.setPosition(572.f,621.f);

        //окна с вводом
//        tmp.setSize(sf::Vector2f(703.f, 333.f));
//        tmp.setFillColor(sf::Color(255, 255, 255, 128));
//        tmp.setPosition(572.f,240.f);
//
//        //ввод
        tmp.setSize(sf::Vector2f(523.f, 120.f));
        tmp.setFillColor(sf::Color(255, 255, 255, 128));
        tmp.setPosition(660.f,400.f);

        //выход
//        tmp.setSize(sf::Vector2f(703.f, 122.f));
//        tmp.setFillColor(sf::Color(255, 255, 255, 128));
//        tmp.setPosition(572.f,621.f);



    }
    void input_code_run(bool&);
};


#endif //COURSEWORK_INPUT_CODE_H
