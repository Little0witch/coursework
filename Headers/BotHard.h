#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "ListOfCoord.h"
#include "ListOfShips.h"
#include "Array.h"

class BotHard{
    int** myField = nullptr;
    int** enemyField = nullptr;//0 - пустая 1 - удар 2 - корабль
    bool hit;
    int xOfLastHit, yOfLastHit;
    int sizeOfShips;
    ListOfCoord listOfHit = nullptr;
    ListOfShips listOfMyShips = nullptr;
    ListOfCoord  listOfCoord = nullptr;

public:
    BotHard();

    ListNodeShips *getListOfMyShips(){
        return listOfMyShips;
    }
    int **getMyField(){
        return myField;
    }

    virtual ~BotHard() {
        freeMemory(enemyField,10);
        freeMemory(myField,10);
        freeList(&listOfMyShips);
        freeList(&listOfHit);
        freeList(&listOfCoord);
    }
};

BotHard::BotHard() {
    hit = false;
    enemyField = allocateMemory(enemyField,10,10);
    init(enemyField,10,10);
    xOfLastHit = yOfLastHit = -1;
    myField = autoPositioningOfShips();
    sizeOfShips = 4;
    insertListFromFile(&listOfCoord,"/home/user/CLionProjects/coursework/Resources/Txt/PointsFor4");
}
