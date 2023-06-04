#ifndef COURSEWORK_WINDOWEXIT_H
#define COURSEWORK_WINDOWEXIT_H

#include <SFML/Graphics.hpp>
#include "Logs.h"

class WindowExit {

private:
    sf::RenderWindow &window;
    sf::Texture background;
    sf::Texture buttonYesRed;
    sf::Texture buttonNoRed;

    sf::Sprite spriteBackground;
    sf::Sprite spriteYesRed;
    sf::Sprite spriteNoRed;
    bool redYes = false;
    bool redNo = false;

public:
    WindowExit(sf::RenderWindow &other) : window(other) {
        if (!background.loadFromFile("../Resources/Img/End of the game/endingGame.png")) {
            logError(
                    "Error 2: file opening error, the place where the error occurred: /Headers/WindowExit.h, line 21");
            exit(1);
        }
        spriteBackground.setTexture(background);
        spriteBackground.setPosition(590.f, 290.f);
        if (!buttonYesRed.loadFromFile("../Resources/Img/End of the game/buttonYesRed.png")) {
            logError(
                    "Error 2: file opening error, the place where the error occurred: /Headers/WindowExit.h, line 28");
            exit(1);
        }
        spriteYesRed.setTexture(buttonYesRed);
        spriteYesRed.setPosition(750.f, 524.f);
        if (!buttonNoRed.loadFromFile("../Resources/Img/End of the game/buttonNoRed.png")) {
            logError(
                    "Error 2: file opening error, the place where the error occurred: /Headers/WindowExit.h, line 35");
            exit(1);
        }
        spriteNoRed.setTexture(buttonNoRed);
        spriteNoRed.setPosition(1059.f, 524.f);

    }

    void windowExitRun(bool &flag);
};

#endif //COURSEWORK_WINDOWEXIT_H
