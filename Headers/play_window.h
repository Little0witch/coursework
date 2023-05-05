#ifndef COURSEWORK_PLAY_WINDOW_H
#define COURSEWORK_PLAY_WINDOW_H
#include <SFML/Graphics.hpp>

class play_window {
private:
    sf::RenderWindow &window;
    sf::Texture background;
    sf::Texture t_missed_bomb;


    sf::Sprite sprite_background;
    sf::Sprite sprite_missed_bomb;

    sf::RectangleShape tmp_A1;
    sf::RectangleShape tmp_B1;

public:
    play_window(sf::RenderWindow &other) : window(other)
    {
        background.loadFromFile("../Resources/Img/Play window/field.png");
        t_missed_bomb.loadFromFile("../Resources/Img/Play window/m_missed_bomb.png");

        sprite_background.setTexture(background);
        sprite_missed_bomb.setTexture(t_missed_bomb);
        sprite_missed_bomb.setPosition(228.f,342.f);
        //размер клетки
        tmp_A1.setSize(sf::Vector2f(56.f,56.f));
        tmp_A1.setPosition(228.f, 285.f);
        tmp_B1.setSize(sf::Vector2f(56.f,56.f));
        tmp_B1.setFillColor(sf::Color::Red);
        tmp_B1.setPosition(228.f, 342.f);
    }
    void play_window_run();
};


#endif //COURSEWORK_PLAY_WINDOW_H
