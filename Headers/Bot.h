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

public:

    Bot(){
        hit = false;
        theFirstHit = true;
        x = y = -1;
        enemyField = allocateMemory(enemyField, 10, 10);
        init(enemyField, 10, 10);
        insertListFromFile(&head,"/home/user/CLionProjects/coursework/Resources/Txt/PointsFor4");
        myField = allocateMemory(myField,10,10);
        init(myField,10,10);
        myField = autoPositioningOfShips(myField,10,10);
    }

    int** getMyField() const;
    int** autoPositioningOfShips(int**,int, int);
    virtual ~Bot();
};

Bot::~Bot() {
    freeMemory(enemyField, 10);
    freeList(&head);
}

int** Bot::autoPositioningOfShips(int** field, int n, int m) {
    int sizeOfShips[] = {4,3,2,1};
    int valueOfShips[] = {1,2,3,4};
    srand(time(NULL));
    bool placed;
    bool intersect;
    int point1, point2,point3, point4;

    for (int i = 0; i < 4; ++i) {

        int size = sizeOfShips[i];

        for (int j = 0; j < valueOfShips[i]; ++j) {
            placed = false;

            while (!placed){
                int x = randomNumber(9);
                int y = randomNumber(9);
                int orientation = randomNumber(1);

                printf("x: %d  y: %d\n",x,y);

                if (orientation == 0 && x + size <= 10)//0 - gorizont 1 - virticelno
                {
                    intersect = false;


                    for (int k = x; k < x + size; ++k) {
                        if (myField[k][y] != 0){
                            intersect = true;
                            break;
                        }
                    }



                    if (!intersect){
                        for (int k = x; k < x + size; ++k) {
                            myField[k][y] = size;
                        }
                        placed = true;
                    }
                } else if (orientation == 1 && y + size <= 10)
                {
                    intersect = false;

                    for (int k = y; k < y + size; ++k) {
                        if (myField[x][k] != 0){
                            intersect = true;
                            break;
                        }
                    }

                    if (!intersect){
                        for (int k = y; k < y+size; ++k) {
                            myField[x][k] = size;
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




