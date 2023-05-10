#ifndef COURSEWORK_WINDOW_EXIT_H
#define COURSEWORK_WINDOW_EXIT_H
#include <SFML/Graphics.hpp>

class window_exit {

private:
    sf::RenderWindow &window;
    sf::Texture background;
    sf::Texture button_yes_red;
    sf::Texture button_no_red;

    sf::Sprite sprite_background;
    sf::Sprite sprite_yes_red;
    sf::Sprite sprite_no_red;

public:
    window_exit(sf::RenderWindow &other): window(other)
    {
        background.loadFromFile("../Resources/Img/End of the game/m_ending_game.png");
        sprite_background.setTexture(background);
        button_yes_red.loadFromFile("../Resources/Img/End of the game/button_yes_red.png");
        sprite_yes_red.setTexture(button_yes_red);
        sprite_yes_red.setPosition(400.f, 570.f);
        button_no_red.loadFromFile("../Resources/Img/End of the game/button_no_red.png");
        sprite_no_red.setTexture(button_no_red);
        sprite_no_red.setPosition(1185.f, 570.f);
    }
    void window_exit_run(bool &flag);
};

#endif //COURSEWORK_WINDOW_EXIT_H
