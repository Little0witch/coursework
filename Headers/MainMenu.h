#ifndef COURSEWORK_MAINMENU_H
#define COURSEWORK_MAINMENU_H
#pragma once

#include <SFML/Graphics.hpp>
#include "ConnectType.h"
#include "DifLevels.h"
#include "InstructionManual.h"
#include "WindowExit.h"

class MainMenu {
private:
    sf::RenderWindow &window;
    sf::Texture background;
    sf::Texture buttonOnlinePlay;
    sf::Texture buttonDifficultLevels;
    sf::Texture buttonInstructionManual;
    sf::Texture buttonExit;

    sf::Sprite spriteBackground;
    sf::Sprite spriteOnlinePlay;
    sf::Sprite spriteButtonLevels;
    sf::Sprite spriteInstructionManual;
    sf::Sprite spriteExit;

    bool redOnline = false;
    bool redDifLv = false;
    bool redMan = false;
    bool redExit = false;

public:
    MainMenu(sf::RenderWindow &other) : window(other) {
        if (!background.loadFromFile("../Resources/Img/Main window/mainWindow.png")) {
            logError(
                    "Error 2: file opening error, the place where the error occurred: /Headers/MainMenu.h, line 28");
            exit(1);
        }
        spriteBackground.setTexture(background);
        if (!buttonOnlinePlay.loadFromFile("../Resources/Img/Main window/buttonOnlineRed.png")) {
            logError(
                    "Error 2: file opening error, the place where the error occurred: /Headers/MainMenu.h, line 34");
            exit(1);
        }
        spriteOnlinePlay.setTexture(buttonOnlinePlay);
        spriteOnlinePlay.setPosition(562.f, 340.f);
        if (!buttonDifficultLevels.loadFromFile("../Resources/Img/Main window/buttonBotRed.png")) {
            logError(
                    "Error 2: file opening error, the place where the error occurred: /Headers/MainMenu.h, line 41");
            exit(1);
        }
        spriteButtonLevels.setTexture(buttonDifficultLevels);
        spriteButtonLevels.setPosition(562.f, 513.f);
        if (!buttonInstructionManual.loadFromFile("../Resources/Img/Main window/buttonInstructionRed.png")) {
            logError(
                    "Error 2: file opening error, the place where the error occurred: /Headers/MainMenu.h, line 48");
            exit(1);
        }
        spriteInstructionManual.setTexture(buttonInstructionManual);
        spriteInstructionManual.setPosition(562.f, 685.f);
        if (!buttonExit.loadFromFile("../Resources/Img/Main window/buttonExitRed.png")) {
            logError(
                    "Error 2: file opening error, the place where the error occurred: /Headers/MainMenu.h, line 55");
            exit(1);
        }
        spriteExit.setTexture(buttonExit);
        spriteExit.setPosition(562.f, 857.f);
    }

    void mainMenuRun();
};

#endif //COURSEWORK_MAINMENU_H
