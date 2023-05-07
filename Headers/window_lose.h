#ifndef COURSEWORK_WINDOW_LOSE_H
#define COURSEWORK_WINDOW_LOSE_H
#include <SFML/Graphics.hpp>

class window_lose {
private:
    sf::RenderWindow &window;
    sf::Texture background;
    sf::Texture ok_red;
    sf::Texture ok_blue;
    sf::Sprite sprite_background;
    sf::Sprite sprite_ok_red;
    sf::Sprite sprite_ok_blue;
public:
    window_lose(sf::RenderWindow &other) : window(other)
    {
        background.loadFromFile("../Resources/Img/Win and lose/window_lose.png");
        sprite_background.setTexture(background);
        ok_blue.loadFromFile("../Resources/Img/Win and lose/ok_blue.png");
        sprite_ok_blue.setTexture(ok_blue);
        sprite_ok_blue.setPosition(700.f,570.f);
        ok_red.loadFromFile("../Resources/Img/Win and lose/ok_red.png");
        sprite_ok_red.setTexture(ok_red);
        sprite_ok_red.setPosition(700.f,570.f);
    }
    void window_lose_run();
};


#endif //COURSEWORK_WINDOW_LOSE_H
