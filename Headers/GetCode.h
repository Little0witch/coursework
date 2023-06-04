#ifndef COURSEWORK_GETCODE_H
#define COURSEWORK_GETCODE_H

#include <SFML/Graphics.hpp>
#include "Socket.h"
#include "PlacementField.h"
#include "NetwStatus.h"

class GetCode {

private:
    sf::RenderWindow &window;
    sf::Texture background;
    sf::Texture buttonOkRed;

    sf::Sprite spriteBackground;
    sf::Sprite spriteOkRed;

    sf::Font font;
    sf::Text connectCode;

    bool moveOnButton = false;
    bool flagIncorrectCode = false;
    std::string sTmp;

public:

    GetCode(sf::RenderWindow &other) : window(other) {

        if (!background.loadFromFile("../Resources/Img/Input code/getCode.png")) {
            logError(
                    "Error 2: file opening error, the place where the error occurred: /Headers/GetCode.h, line 28");
            exit(1);
        }


        spriteBackground.setTexture(background);

        if (!buttonOkRed.loadFromFile("../Resources/Img/Input code/buttonExit.png")) {
            logError(
                    "Error 2: file opening error, the place where the error occurred: /Headers/GetCode.h, line 37");
            exit(1);
        }

        spriteOkRed.setTexture(buttonOkRed);
        spriteOkRed.setPosition(572.f, 621.f);

        if (!font.loadFromFile("../Resources/Txt/JetBreins.ttf")) {
            logError(
                    "Error 2: file opening error, the place where the error occurred: /Headers/GetCode.h, line 46");
            exit(1);
        }

        if (getCode() == nullptr)
        {
            flagIncorrectCode = true;
            NetwStatus windowNetwStatus(window);
            windowNetwStatus.netwStatusRun();
            return;
        }
        else
        {
            sTmp = getCode();
        }

        connectCode.setFont(font);
        connectCode.setCharacterSize(70);
        connectCode.setFillColor(sf::Color::Black);
        connectCode.setPosition(614.f, 410.f);
        connectCode.setString(sTmp);
    }

    void getCodeRun(bool & flagOfReturn);
};


#endif //COURSEWORK_GETCODE_H
