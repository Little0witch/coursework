#ifndef COURSEWORK_PLACEMENR_FIELD_H
#define COURSEWORK_PLACEMENR_FIELD_H
#include <SFML/Graphics.hpp>

class placemenr_field {
private:
    sf::RenderWindow &window;
    sf::Texture background;
    sf::Texture button_back_blue;
    sf::Texture button_back_red;
    sf::Texture button_auto_blue;
    sf::Texture button_auto_red;
    sf::Texture button_reset_blue;
    sf::Texture button_reset_red;
    sf::Texture button_play_blue;
    sf::Texture button_play_red;

    sf::Sprite sprite_background;
    sf::Sprite sprite_button_back;
    sf::Sprite sprite_button_auto;
    sf::Sprite sprite_button_reset;
    sf::Sprite sprite_button_play;

    sf::RectangleShape tmp;

public:
    placemenr_field(sf::RenderWindow &other_window) : window(other_window)
    {
//        background.loadFromFile("../Resources/Img/Ships/window_field.png");
//        sprite_background.setTexture(background);
        background.loadFromFile("../Resources/Img/Ships/placement_window.png");
        sprite_background.setTexture(background);
        button_back_red.loadFromFile("../Resources/Img/Ships/button_back.png");
        sprite_button_back.setTexture(button_back_red);
        sprite_button_back.setPosition(170.f,20.f);
        tmp.setSize(sf::Vector2f(350.f,140.f));
        tmp.setPosition(170.f,20.f);
        tmp.setFillColor(sf::Color(255, 255, 255, 128));
    }
    void placemenr_field_run();
};


#endif //COURSEWORK_PLACEMENR_FIELD_H
