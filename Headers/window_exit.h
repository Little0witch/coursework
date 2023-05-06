#ifndef COURSEWORK_WINDOW_EXIT_H
#define COURSEWORK_WINDOW_EXIT_H
#include <SFML/Graphics.hpp>

class window_exit {

private:
    sf::RenderWindow &window;
    sf::Texture background;

    sf::Texture button_yes_blue;
    sf::Texture button_yes_red;
    sf::Texture button_no_blue;
    sf::Texture button_no_red;

    sf::Sprite sprite_background;
    sf::Sprite sprite_yes_blue;
    sf::Sprite sprite_yes_red;
    sf::Sprite sprite_no_blue;
    sf::Sprite sprite_no_red;

    sf::RectangleShape _yes;
    sf::RectangleShape _no;

public:
    window_exit(sf::RenderWindow &other): window(other)
    {
        background.loadFromFile("../Resources/Img/End of the game/m_ending_game.png");
        sprite_background.setTexture(background);
//позиция кнопкии "да"
        _yes.setSize(sf::Vector2f (310.f, 268.f));
        _yes.setPosition(400.f, 570.f);
        _yes.setFillColor(sf::Color(255, 255, 255, 128));

//позиция кнопкии "нет"
        _no.setSize(sf::Vector2f (310.f, 268.f));
        _no.setPosition(1185.f, 570.f);
        _no.setFillColor(sf::Color(255, 255, 255, 128));

        //загрузка и расстановка кнопок
//        button_yes_blue.loadFromFile();
//        sprite_yes_blue.setTexture(button_yes_blue);
//        sprite_yes_blue.setPosition(400.f, 570.f);
//        button_yes_red.loadFromFile();
//        sprite_yes_red.setTexture(button_yes_red);
//        sprite_yes_red.setPosition(400.f, 570.f);
//        button_no_blue.loadFromFile();
//        sprite_no_blue.setTexture(button_no_blue);
//        sprite_no_blue.setPosition(1185.f, 570.f);
//        button_no_red.loadFromFile();
//        sprite_no_red.setTexture(button_no_red);
//        sprite_no_red.setPosition(1185.f, 570.f);


    }
    void window_exit_run();
};


#endif //COURSEWORK_WINDOW_EXIT_H
