#ifndef COURSEWORK_INPUTCODE_H
#define COURSEWORK_INPUTCODE_H

#include <SFML/Graphics.hpp>
#include <string>
#include "PlacementField.h"
#include "Socket.h"

class InputCode {
private:
    sf::RenderWindow &window;
    sf::Texture textureAtlas;
    sf::Texture buttonExit;
    sf::Sprite sprite;
    sf::Sprite spriteExit;

    sf::Font font;
    sf::Text text;
    bool flag = false;
    sf::RectangleShape tmp;
    bool moveExit = false;


public:
    InputCode(sf::RenderWindow &other) : window(other) {
        if (!textureAtlas.loadFromFile("../Resources/Img/Input code/inputCode.png")) {
            logError(
                    "Error 2: file opening error, the place where the error occurred: /Headers/InputCode.h, line 26");
            exit(1);
        }

        sprite.setTexture(textureAtlas);

        if (!font.loadFromFile("../Resources/Txt/JetBreins.ttf")) {
            logError(
                    "Error 2: file opening error, the place where the error occurred: /Headers/InputCode.h, line 34");
            exit(1);
        }

        text.setFont(font);
        text.setCharacterSize(50);
        text.setFillColor(sf::Color::Black);
        text.setPosition(668.f, 413.f);

        if (!buttonExit.loadFromFile("../Resources/Img/Input code/buttonExit.png")) {
            logError(
                    "Error 2: file opening error, the place where the error occurred: /Headers/InputCode.h, line 45");
            exit(1);
        }

        spriteExit.setTexture(buttonExit);
        spriteExit.setPosition(572.f, 621.f);

        tmp.setSize(sf::Vector2f(523.f, 120.f));
        tmp.setFillColor(sf::Color(255, 255, 255, 128));
        tmp.setPosition(660.f, 400.f);

    }

    void inputCodeRun(bool &);
};


#endif //COURSEWORK_INPUTCODE_H
