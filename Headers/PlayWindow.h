#ifndef COURSEWORK_PLAYWINDOW_H
#define COURSEWORK_PLAYWINDOW_H

#include <SFML/Graphics.hpp>
#include "Player.h"
#include "WindowWin.h"
#include "WindowLose.h"
#include "WindowExit.h"
#include "Socket.h"


class PlayWindow {
private:
    sf::RenderWindow &window;
    sf::Texture background;
    sf::Texture tMissedBomb;
    sf::Texture tHit;
    sf::Texture tLeftArrow;
    sf::Texture tRightArrow;
    sf::Texture buttonBack;

    sf::Sprite spriteBackground;
    sf::Sprite spriteButtonBack;
    sf::Sprite spriteMissedBomb;
    sf::Sprite spriteLeftArrow;
    sf::Sprite spriteRightArrow;

    sf::Sprite shipsOfPlayer[10];
    sf::Sprite missedOnBotField[80];

    sf::Sprite missedOnPlayerField[80];
    sf::RectangleShape tmp;

    sf::Sprite hitsOfBot[100];
    int valueOfSpriteBot;
    sf::Sprite hitsOfPlayer[100];
    int valueOfSpritePlayer;

    int arrayOfPositionForBot[10][10];
    int arrayOfPositionForPlayer[10][10];

    bool flagExit = false;

public:
    PlayWindow(sf::RenderWindow &other, sf::Sprite *shipsOfPlayer) : window(other) {
        valueOfSpriteBot = 0;
        valueOfSpritePlayer = 0;

        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < 10; ++j) {
                arrayOfPositionForBot[i][j] = 0;
                arrayOfPositionForPlayer[i][j] = 0;
            }
        }

        if (!background.loadFromFile("../Resources/Img/Play window/field.png")) {
            logError(
                    "Error 2: file opening error, the place where the error occurred: /Headers/PlayWindow.h, line 56");
            exit(1);
        }

        if (!buttonBack.loadFromFile("../Resources/Img/Play window/arrowBackRed.png")) {
            logError(
                    "Error 2: file opening error, the place where the error occurred: /Headers/PlayWindow.h, line 62");
            exit(1);
        }

        if (!tMissedBomb.loadFromFile("../Resources/Img/Play window/missedBomb.png")) {
            logError(
                    "Error 2: file opening error, the place where the error occurred: /Headers/PlayWindow.h, line 68");
            exit(1);
        }

        if (!tHit.loadFromFile("../Resources/Img/Play window/injury.png")) {
            logError(
                    "Error 2: file opening error, the place where the error occurred: /Headers/PlayWindow.h, line 74");
            exit(1);
        }

        spriteBackground.setTexture(background);
        spriteButtonBack.setTexture(buttonBack);
        spriteButtonBack.setPosition(170.f, 30.f);
        spriteMissedBomb.setTexture(tMissedBomb);

        if (!tLeftArrow.loadFromFile("../Resources/Img/Play window/leftArrowBlue.png")) {
            logError(
                    "Error 2: file opening error, the place where the error occurred: /Headers/PlayWindow.h, line 85");
            exit(1);
        }

        if (!tRightArrow.loadFromFile("../Resources/Img/Play window/rightArrowBlue.png")) {
            logError(
                    "Error 2: file opening error, the place where the error occurred: /Headers/PlayWindow.h, line 91");
            exit(1);
        }

        spriteLeftArrow.setTexture(tLeftArrow);
        spriteRightArrow.setTexture(tRightArrow);

        spriteRightArrow.setPosition(835.f, 458.f);
        spriteLeftArrow.setPosition(835.f, 458.f);

        for (int i = 0; i < 10; ++i) {
            this->shipsOfPlayer[i] = shipsOfPlayer[i];
        }

        for (int i = 0; i < 80; ++i) {
            missedOnBotField[i].setTexture(tMissedBomb);
            missedOnPlayerField[i].setTexture(tMissedBomb);
        }

    }

    void playWindowRun(Player &player, int complexity, bool &flag);

    void playWithSoft(Player &player, bool &flag);

    void playWithHard(Player &player, bool &flag);

    void playWithServer(Player &player, bool &flag, struct dataOfSocket dataOfSocket);

    void playWithClient(Player &player, bool &flag, struct dataOfSocket dataOfSocket);

    void playWindowRunForPlayer(Player &player, bool &flag, struct dataOfSocket dataOfSocket);

    void showPlacement();

    void setSpriteOfHit(int **field, int flag);

    void showHits();

    bool isEmpty(int x, int y, int **field);
};


#endif //COURSEWORK_PLAYWINDOW_H
