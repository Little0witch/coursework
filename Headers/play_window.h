#ifndef COURSEWORK_PLAY_WINDOW_H
#define COURSEWORK_PLAY_WINDOW_H
#include <SFML/Graphics.hpp>
//#include "Player.h"

class play_window {
private:
    sf::RenderWindow &window;
    sf::Texture background;
    sf::Texture t_missed_bomb;
    sf::Texture t_left_arrow;
    sf::Texture t_right_arrow;
    sf::Texture button_back;

    sf::Sprite sprite_background;
    sf::Sprite sprite_button_back;
    sf::Sprite sprite_missed_bomb;
    sf::Sprite sprite_left_arrow;
    sf::Sprite sprite_right_arrow;


    sf::RectangleShape tmp_A1;
    sf::RectangleShape tmp_B1;

    sf::RectangleShape tmp;

public:
    play_window(sf::RenderWindow &other) : window(other)
    {
        background.loadFromFile("../Resources/Img/Play window/field.png");
        button_back.loadFromFile("../Resources/Img/Play window/m_arrow_back_red.png");
        t_missed_bomb.loadFromFile("../Resources/Img/Play window/m_missed_bomb.png");

        sprite_background.setTexture(background);
        sprite_button_back.setTexture(button_back);
        sprite_button_back.setPosition(170.f,30.f);
        sprite_missed_bomb.setTexture(t_missed_bomb);
        sprite_missed_bomb.setPosition(228.f,342.f);

        t_left_arrow.loadFromFile("../Resources/Img/Play window/m_left_arrow_blue.png");
        t_right_arrow.loadFromFile("../Resources/Img/Play window/m_right_arrow_blue.png");

        sprite_left_arrow.setTexture(t_left_arrow);
        sprite_right_arrow.setTexture(t_right_arrow);

        sprite_right_arrow.setPosition(835.f,458.f);
        sprite_left_arrow.setPosition(835.f,458.f);

        //размер клетки
        tmp_A1.setSize(sf::Vector2f(56.f,56.f));
        tmp_A1.setPosition(228.f, 285.f);
        tmp_B1.setSize(sf::Vector2f(56.f,56.f));
        tmp_B1.setFillColor(sf::Color::Red);
        tmp_B1.setPosition(228.f, 342.f);

        tmp.setSize(sf::Vector2f(345.f,110.f));
        tmp.setPosition(170.f,30.f);
        tmp.setFillColor(sf::Color(255, 255, 255, 128));
    }
    void play_window_run(int);
};


#endif //COURSEWORK_PLAY_WINDOW_H
