#pragma once
#ifndef COURSEWORK_DIFLEVELS_H
#define COURSEWORK_DIFLEVELS_H

#include <SFML/Graphics.hpp>
#include "PlacementField.h"


class DifLevels {
private:
    sf::RenderWindow &window;
    sf::Texture background;
    sf::Texture buttonEasyBlue;
    sf::Texture buttonEasyRed;
    sf::Texture buttonHardBlue;
    sf::Texture buttonHardRed;
    sf::Texture buttonExitBlue;
    sf::Texture buttonExitRed;

    sf::Sprite spriteBackground;
    sf::Sprite spriteButtonEasyBlue;
    sf::Sprite spriteButtonEasyRed;
    sf::Sprite spriteButtonHardBlue;
    sf::Sprite spriteButtonHardRed;
    sf::Sprite spriteButtonExitBlue;
    sf::Sprite spriteButtonExitRed;

    bool flag = false;
    bool redEasy = false;
    bool redHard = false;
    bool redExit = false;

public:
    DifLevels(sf::RenderWindow &other) ;

    void difLevelsRun();
};


#endif //COURSEWORK_DIFLEVELS_H
