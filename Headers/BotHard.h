#pragma once

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "ListOfCoord.h"
#include "ListOfShips.h"
#include "Array.h"

class BotHard {
private:
    int **myField = nullptr;
    int **enemyField = nullptr;
    bool hit;
    int xOfLastHit, yOfLastHit;
    int arrayOfDeathShips[5] = {0, 4, 3, 2, 1};
    int numberOfFile;
    ListOfCoord listOfHit = nullptr;
    ListOfShips listOfMyShips = nullptr;
    ListOfCoord listOfCoord = nullptr;
    char *nameOfFile = nullptr;
public:
    int **getEnemyField() const;

private:
    void addEmptyCells();

    int **autoPositioningOfShips();

    bool checkPositions(int **field, int x, int y, int size, int orientation);

public:
    BotHard();

    ListNodeShips *getListOfMyShips() {
        return listOfMyShips;
    }

    int **getMyField() {
        return myField;
    }

    virtual ~BotHard() {
        if (enemyField != nullptr)
            freeMemory(enemyField, 10);
        if (myField != nullptr)
            freeMemory(myField, 10);
        if (listOfMyShips != nullptr)
            freeList(&listOfMyShips);
        if (listOfHit != nullptr)
            freeList(&listOfHit);
        if (listOfCoord != nullptr)
            freeList(&listOfCoord);
    }

    void statusGame(int);

    struct coordinates giveCoordinates();
};
