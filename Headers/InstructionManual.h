#ifndef COURSEWORK_INSTRUCTIONMANUAL_H
#define COURSEWORK_INSTRUCTIONMANUAL_H
#include <SFML/Graphics.hpp>
#include "Logs.h"

class InstructionManual {
private:
    sf::RenderWindow &window;
    sf::Texture background;
    sf::Texture buttonExitRed;
    sf::Sprite spriteBackground;
    sf::Sprite spriteExitRed;

    bool redExit = false;

public:
    InstructionManual(sf::RenderWindow &other) : window(other)
    {
        if (!background.loadFromFile("../Resources/Img/Instruction manual/windInstBut.png")) {
            logError(
                    "Error 2: file opening error, the place where the error occurred: /Headers/InstructionManual.h, line 18");
            exit(1);
        }

        if (!buttonExitRed.loadFromFile("../Resources/Img/Instruction manual/buttonExitRed.png")) {
            logError(
                    "Error 2: file opening error, the place where the error occurred: /Headers/InstructionManual.h, line 24");
            exit(1);
        }

        spriteBackground.setTexture(background);
        spriteExitRed.setTexture(buttonExitRed);
        spriteExitRed.setPosition(658.f, 915.f);
    }
    void instructionManualRun();
};


#endif //COURSEWORK_INSTRUCTIONMANUAL_H
