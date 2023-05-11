#pragma once

#include <SFML/Graphics.hpp>
#include "Array.h"
#include "ListOfCoord.h"
#include "ListOfShips.h"

class Player {
private:
    int **myField = nullptr;
    int **enemyField = nullptr;
    ListOfShips listOfMyShips = nullptr;
public:
    void autoPositioningOfShips();

    bool checkPositions(int **, int, int, int, int);

    int **getMyField() const;

    ListNodeShips *getListOfMyShips() const;

    void addEmptyCells();

    void addHit(int, int, int);

    int **getEnemyField() const;

    Player();

    ~Player();
};

