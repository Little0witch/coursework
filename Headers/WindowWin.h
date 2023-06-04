#ifndef COURSEWORK_WINDOWWIN_H
#define COURSEWORK_WINDOWWIN_H

#include <SFML/Graphics.hpp>
#include "Logs.h"

class WindowWin {

private:
    sf::RenderWindow &window;
    sf::Texture background;
    sf::Texture okRed;
    sf::Texture okBlue;
    sf::Sprite spriteBackground;
    sf::Sprite spriteOkRed;
    sf::Sprite spriteOkBlue;

public:
    WindowWin(sf::RenderWindow &other) : window(other) {
        if (!background.loadFromFile("../Resources/Img/Win and lose/windowWin.png")) {
            logError(
                    "Error 2: file opening error, the place where the error occurred: /Headers/WindowWin.h, line 20");
            exit(1);
        }
        spriteBackground.setTexture(background);
        spriteBackground.setPosition(590.f, 290.f);
        if (!okBlue.loadFromFile("../Resources/Img/Win and lose/okBlue.png")) {
            logError(
                    "Error 2: file opening error, the place where the error occurred: /Headers/WindowWin.h, line 26");
            exit(1);
        }
        spriteOkBlue.setTexture(okBlue);
        spriteOkBlue.setPosition(894.f, 520.f);
        if (!okRed.loadFromFile("../Resources/Img/Win and lose/okRed.png")) {
            logError(
                    "Error 2: file opening error, the place where the error occurred: /Headers/WindowWin.h, line 33");
            exit(1);
        }
        spriteOkRed.setTexture(okRed);
        spriteOkRed.setPosition(894.f, 520.f);
    }

    void windowWinRun();
};


#endif //COURSEWORK_WINDOWWIN_H
