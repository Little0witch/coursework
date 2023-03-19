#pragma once
#include <cstdio>
#include <cstdlib>
#include "Array.h"
#include "List.h"

class BotSoft{
private:
    int** myField = nullptr;
    int** enemyField = nullptr;
    bool hit;
    int xOfLastHit, yOfLastHit;
    List list;

    bool checkPositions(int**,int,int,int,int);
    int** autoPositioningOfShips();
    void fillHit();


public:
    BotSoft() {
        hit = false;
        enemyField = allocateMemory(enemyField,10,10);
        init(enemyField,10,10);
        xOfLastHit = yOfLastHit = -1;

        myField = autoPositioningOfShips();
    }

    int **getMyField() const;
    struct coordinates giveCoord();
    void statusGame(int);
    virtual ~BotSoft();
};

int** BotSoft::autoPositioningOfShips() {
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

bool BotSoft::checkPositions(int** field, int x, int y, int size, int orientation) {
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

BotSoft::~BotSoft() {
    freeMemory(enemyField,10);
    freeMemory(myField,10);
}

int **BotSoft::getMyField() const {
    return myField;
}

void BotSoft::statusGame(int isHit) {
    //0 - мимо
    //1 - удар
    //2 - потопил весь корабль
    if (isHit == 1)
    {
        hit = true;

    }

    if (isHit)
    {
        enemyField[xOfLastHit][yOfLastHit] = 2;//потопил
    }
    else
        enemyField[xOfLastHit][yOfLastHit] = 1;//мимо

    if (isHit == 2)
    {
        freeList(&list);
        hit = false;
    }
}

struct coordinates BotSoft::giveCoord() {
    struct coordinates coord{};

    if (isEmpty(list))
    {
        int x,y;
        do
        {
            x = randomNumber(9);
            y = randomNumber(9);
        } while (enemyField[x][y] != 0);

        xOfLastHit = x;
        yOfLastHit = y;

        coord.x = x;
        coord.y = y;

        return coord;
    }
    else
    {



        return coord;
    }
}

void BotSoft::fillHit() {



}
