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
    ListOfCoord listOfHit = nullptr;
    ListOfShips listOfMyShips = nullptr;

public:
    ListNodeShips *getListOfMyShips(){
        return listOfMyShips;
    }
    int **getMyField(){
        return myField;
    }


};