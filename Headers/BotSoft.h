#pragma once
#include <cstdio>
#include <cstdlib>
#include "Array.h"
#include "ListOfCoord.h"
#include "ListOfShips.h"

class BotSoft{
private:
    int** myField = nullptr;
    int** enemyField = nullptr;//0 - пустая 1 - удар 2 - корабль
    bool hit;
    int xOfLastHit, yOfLastHit;
    ListOfCoord listOfHit = nullptr;
    ListOfShips listOfMyShips = nullptr;

private:
public:
    int **getEnemyField() const;

private:

    bool checkPositions(int**,int,int,int,int);
    int** autoPositioningOfShips();
    void addEmptyCells();

public:
    BotSoft() {
        hit = false;
        enemyField = allocateMemory(enemyField,10,10);
        init(enemyField,10,10);
        xOfLastHit = yOfLastHit = -1;
        myField = autoPositioningOfShips();
    }


    int **getMyField() const;
    struct coordinates giveCoordinates();
    void statusGame(int);
    virtual ~BotSoft();
    ListNodeShips *getListOfMyShips();
};
