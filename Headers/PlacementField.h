#ifndef COURSEWORK_PLACEMENTFIELD_H
#define COURSEWORK_PLACEMENTFIELD_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include "ListOfShips.h"
#include "Player.h"
#include "PlayWindow.h"
#include "Socket.h"


class PlacementField {
private:
    sf::RenderWindow &window;
    sf::Texture background;
    sf::Texture textureAtlas;
    sf::Texture textureAtlas1;

    sf::Texture buttonBackRed;
    sf::Texture buttonAutoBlue;
    sf::Texture buttonAutoRed;
    sf::Texture buttonResetBlue;
    sf::Texture buttonResetRed;
    sf::Texture buttonPlayBlue;
    sf::Texture buttonPlayRed;

    sf::Sprite spriteBackgroundTextureAtlas;
    sf::Sprite spriteBackground;
    sf::Sprite spriteButtonBack;
    sf::Sprite spriteButtonAuto;
    sf::Sprite spriteButtonReset;
    sf::Sprite spriteButtonPlay;
    sf::Sprite spriteShips;

    sf::Sprite spriteButtonAutoRed;
    sf::Sprite spriteButtonResetRed;
    sf::Sprite spriteButtonPlayRed;

    sf::Texture shipOf1;
    sf::Texture shipOf2;
    sf::Texture shipOf3;
    sf::Texture shipOf4;

    sf::Sprite ships[10];

    bool flagAutoPressed = false;
    bool redAuto = false;
    bool redPlay = false;

public:
    PlacementField(sf::RenderWindow &other_window) : window(other_window)
    {
        background.loadFromFile("../Resources/Img/Ships/placementWindow.png");
        spriteBackground.setTexture(background);

        textureAtlas.loadFromFile("../Resources/Img/Ships/windowField.png");

        spriteButtonBack.setTexture(textureAtlas);
        spriteButtonBack.setTextureRect(sf::IntRect(170.f, 20.f, 350.f, 140.f));
        spriteButtonBack.setPosition(sf::Vector2f(170.f, 20.f));

        spriteShips.setTexture(textureAtlas);
        spriteShips.setTextureRect(sf::IntRect(1025.f, 283.f, 570.f, 400.f));
        spriteShips.setPosition(1025.f, 283.f);

        spriteButtonReset.setTexture(textureAtlas);
        spriteButtonReset.setTextureRect(sf::IntRect(1028.f, 742.f, 113.f, 110.f));
        spriteButtonReset.setPosition(sf::Vector2f(1028.f, 742.f));

        spriteButtonAuto.setTexture(textureAtlas);
        spriteButtonAuto.setTextureRect(sf::IntRect(1190.f, 742.f, 240.f, 110.f));
        spriteButtonAuto.setPosition(sf::Vector2f(1190.f, 742.f));

        spriteButtonPlay.setTexture(textureAtlas);
        spriteButtonPlay.setTextureRect(sf::IntRect(1483.f, 742.f, 113.f, 110.f));
        spriteButtonPlay.setPosition(sf::Vector2f(1483.f, 742.f));

        buttonResetRed.loadFromFile("../Resources/Img/Ships/buttonResetRed.png");
        spriteButtonResetRed.setTexture(buttonResetRed);
        spriteButtonResetRed.setPosition(sf::Vector2f(1028.f, 742.f));

        buttonAutoRed.loadFromFile("../Resources/Img/Ships/buttonAutoRed.png");
        spriteButtonAutoRed.setTexture(buttonAutoRed);
        spriteButtonAutoRed.setPosition(sf::Vector2f(1190.f, 742.f));

        buttonPlayRed.loadFromFile("../Resources/Img/Ships/buttonPlayRed.png");
        spriteButtonPlayRed.setTexture(buttonPlayRed);
        spriteButtonPlayRed.setPosition(sf::Vector2f(1483.f, 742.f));


        textureAtlas1.loadFromFile("../Resources/Img/Ships/allShips.png");
        for (auto & ship : ships) {
            ship.setTexture(textureAtlas1);
        }

        ships[0].setTextureRect(sf::IntRect(0.f, 0.f,228.f,56.f));//4

        ships[1].setTextureRect(sf::IntRect(0.f,123.5, 169.f,54.5));//3
        ships[2].setTextureRect(sf::IntRect(0.f,123.5, 169.f,54.5));//3

        ships[3].setTextureRect(sf::IntRect(0.f,230.f,112.f,56.f));//2
        ships[4].setTextureRect(sf::IntRect(0.f,230.f,112.f,56.f));//2
        ships[5].setTextureRect(sf::IntRect(0.f,230.f,112.f,56.f));//2

        ships[6].setTextureRect(sf::IntRect(0.f,344.f,56.f,56.f));//1
        ships[7].setTextureRect(sf::IntRect(0.f,344.f,56.f,56.f));//1
        ships[8].setTextureRect(sf::IntRect(0.f,344.f,56.f,56.f));//1
        ships[9].setTextureRect(sf::IntRect(0.f,344.f,56.f,56.f));//1

    }
    void placementFieldRun(int complexity, bool &flag);
    void placementFieldRun(int complexity, bool &flag, bool& flagOfReturn, struct dataOfSocket);
    void setPlacement(ListOfShips listOfShips);
    void showPlacement();
};


#endif //COURSEWORK_PLACEMENTFIELD_H
