#ifndef COURSEWORK_WINDOW_LOSE_H
#define COURSEWORK_WINDOW_LOSE_H

#include <SFML/Graphics.hpp>
#include "logs.h"

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
    window_lose(sf::RenderWindow &other) : window(other) {
        if (!background.loadFromFile("../Resources/Img/Win and lose/m_window_lose.png")) {
            logError(
                    "Error 2: file opening error, the place where the error occurred: /Headers/window_lose.h, line 18");
            exit(1);
        }
        sprite_background.setPosition(590.f, 290.f);
        sprite_background.setTexture(background);
        if (!ok_blue.loadFromFile("../Resources/Img/Win and lose/m_ok_blue.png")) {
            logError(
                    "Error 2: file opening error, the place where the error occurred: /Headers/window_lose.h, line 26");
            exit(1);
        }
        sprite_ok_blue.setTexture(ok_blue);
        sprite_ok_blue.setPosition(894.f, 520.f);
        if (!ok_red.loadFromFile("../Resources/Img/Win and lose/m_ok_red.png")) {
            logError(
                    "Error 2: file opening error, the place where the error occurred: /Headers/window_lose.h, line 31");
            exit(1);
        }
        sprite_ok_red.setTexture(ok_red);
        sprite_ok_red.setPosition(894.f, 520.f);
    }

    void window_lose_run();
};


#endif //COURSEWORK_WINDOW_LOSE_H
