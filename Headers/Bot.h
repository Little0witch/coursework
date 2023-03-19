#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "List.h"
#include "Array.h"

class Bot{
private:
    int** enemyField = nullptr;
    int** myField = nullptr;
    bool hit;
    bool theFirstHit;
    int x,y;
    List head;

    bool checkPositions(int**,int,int,int,int);

public:

    Bot(){
        hit = false;
        theFirstHit = true;
        x = y = -1;
        enemyField = allocateMemory(enemyField, 10, 10);
        init(enemyField, 10, 10);
        insertListFromFile(&head,"/home/user/CLionProjects/coursework/Resources/Txt/PointsFor4");
        myField = autoPositioningOfShips();
    }

    int** getMyField() const;
    int** autoPositioningOfShips();
    virtual ~Bot();
};

Bot::~Bot() {
    freeMemory(enemyField, 10);
    freeMemory(myField,10);
    freeList(&head);
}

int** Bot::autoPositioningOfShips() {
    int** field = nullptr;
    field = allocateMemory(field,10,10);
    init(field,10,10);

    int sizeOfShips[] = {4,3,2,1};
    int valueOfShips[] = {1,2,3,4};
    srand(time(NULL));
    bool placed;

    for (int i = 0; i < 4; ++i) {

        int size = sizeOfShips[i];

        for (int j = 0; j < valueOfShips[i]; ++j) {
            placed = false;

            while (!placed){
                int x = randomNumber(9);
                int y = randomNumber(9);
                int orientation = randomNumber(2);

                if (orientation == 0 && x + size <= 10)
                {
                    if (checkPositions(field,x,y,size,orientation)) {
                        for (int k = x; k < x + size; ++k) {
                            field[k][y] = size;
                        }
                        placed = true;
                    }

                } else if (orientation == 1 && y + size <= 10)
                {
                    if (checkPositions(field,x,y,size,orientation)){
                        for (int k = y; k < y+size; ++k) {
                            field[x][k] = size;
                        }
                        placed = true;
                    }
                }
            }
        }
    }

    return field;
}

int** Bot::getMyField() const {
    return myField;
}

bool Bot::checkPositions(int** field, int x, int y, int size, int orientation) {
    int point1, point2, point3, point4;

    if (orientation == 0){

        if (x > 0)
            point1 = x - 1;
        else
            point1 = x;

        if (x + size + 1 <= 10)
            point2 = x + size + 1;
        else
            point2 = x + size;

        if (y > 0)
            point3 = y - 1;
        else
            point3 = y;

        if (y + 1 > 9)
            point4 = y;
        else
            point4 = y + 1;

        for (int i = point1; i < point2; ++i) {
            for (int j = point3; j <= point4; ++j) {
                if (field[i][j] != 0 )
                    return false;
            }
        }

        return true;
    }
    else
    {
        if (y > 0)
            point1 = y - 1;
        else
            point1 = y;

        if (y + size + 1 <= 10)
            point2 = y + size + 1;
        else
            point2 = y + size;

        if (x > 0)
            point3 = x - 1;
        else
            point3 = x;

        if (x + 1 > 9)
            point4 = x;
        else
            point4 = x + 1;

        for (int i = point1; i < point2; ++i) {
            for (int j = point3; j <= point4; ++j) {
                if (field[j][i] != 0)
                    return false;
            }
        }

        return true;
    }
}




