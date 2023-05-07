#pragma once
#include "Array.h"
#include "ListOfCoord.h"
#include "ListOfShips.h"

class Player {
private:
    int** myField = nullptr;
    ListOfShips listOfMyShips = nullptr;
public:
    void autoPositioningOfShips();
    bool checkPositions(int**,int,int,int,int);
    int **getMyField() const;
    ListNodeShips *getListOfMyShips() const;


    ~Player();
};

