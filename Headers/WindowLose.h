#ifndef COURSEWORK_WINDOWLOSE_H
#define COURSEWORK_WINDOWLOSE_H

#include <SFML/Graphics.hpp>
#include "Logs.h"

class WindowLose {
private:
    sf::RenderWindow &window;
    sf::Texture background;
    sf::Texture okRed;
    sf::Texture okBlue;
    sf::Sprite spriteBackground;
    sf::Sprite spriteOkRed;
    sf::Sprite spriteOkBlue;
public:
    WindowLose(sf::RenderWindow &other) : window(other) {
        if (!background.loadFromFile("../Resources/Img/Win and lose/windowLose.png")) {
            logError(
                    "Error 2: file opening error, the place where the error occurred: /Headers/WindowLose.h, line 18");
            exit(1);
        }
        spriteBackground.setPosition(590.f, 290.f);
        spriteBackground.setTexture(background);
        if (!okBlue.loadFromFile("../Resources/Img/Win and lose/okBlue.png")) {
            logError(
                    "Error 2: file opening error, the place where the error occurred: /Headers/WindowLose.h, line 26");
            exit(1);
        }
        spriteOkBlue.setTexture(okBlue);
        spriteOkBlue.setPosition(894.f, 520.f);
        if (!okRed.loadFromFile("../Resources/Img/Win and lose/okRed.png")) {
            logError(
                    "Error 2: file opening error, the place where the error occurred: /Headers/WindowLose.h, line 31");
            exit(1);
        }
        spriteOkRed.setTexture(okRed);
        spriteOkRed.setPosition(894.f, 520.f);
    }

    void windowLoseRun();
};


#endif //COURSEWORK_WINDOWLOSE_H
