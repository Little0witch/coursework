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
    int **enemyField = nullptr;//0 - пустая 1 - удар 2 - корабль
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
        freeMemory(enemyField, 10);
        freeMemory(myField, 10);
        freeList(&listOfMyShips);
        freeList(&listOfHit);
        freeList(&listOfCoord);
    }

    void statusGame(int);

    struct coordinates giveCoordinates();
};

//BotHard::BotHard() {
//    hit = false;
//    enemyField = allocateMemory(enemyField, 10, 10);
//    init(enemyField, 10, 10);
//    xOfLastHit = yOfLastHit = -1;
//    myField = autoPositioningOfShips();
//    numberOfFile = 4;
//    nameOfFile = allocateMemoryForString(nameOfFile, 28);
//    strcpy(nameOfFile, "../Resources/Txt/PointsFor4");
//    insertListFromFile(&listOfCoord, nameOfFile);
//}
//
//int **BotHard::autoPositioningOfShips() {
//    int **field = nullptr;
//    ListOfCoord coordOfShips = nullptr;
//    freeList(&listOfMyShips);
//
//    if (myField == nullptr)
//        myField = allocateMemory(myField, 10, 10);
//    else {
//        myField = nullptr;
//        myField = allocateMemory(myField, 10, 10);
//    }
//
//    field = allocateMemory(field, 10, 10);
//    init(field, 10, 10);
//
//    int sizeOfShips[] = {4, 3, 2, 1};
//    int valueOfShips[] = {1, 2, 3, 4};
//
//    bool placed;
//
//    for (int i = 0; i < 4; ++i) {
//
//        int size = sizeOfShips[i];
//
//        for (int j = 0; j < valueOfShips[i]; ++j) {
//            placed = false;
//
//            while (!placed) {
//                int x = randomNumber(9);
//                int y = randomNumber(9);
//                int orientation = randomNumber(2);
//
//                if (orientation == 0 && x + size <= 10) {
//                    if (checkPositions(field, x, y, size, orientation)) {
//                        for (int k = x; k < x + size; ++k) {
//                            insertNode(&coordOfShips, k, y);
//                            field[k][y] = size;
//                        }
//
//                        insertNode(&listOfMyShips, coordOfShips, orientation);
//                        placed = true;
//                        freeList(&coordOfShips);
//                    }
//
//                } else if (orientation == 1 && y + size <= 10) {
//                    if (checkPositions(field, x, y, size, orientation)) {
//                        for (int k = y; k < y + size; ++k) {
//                            insertNode(&coordOfShips, x, k);
//                            field[x][k] = size;
//                        }
//                        insertNode(&listOfMyShips, coordOfShips, orientation);
//                        placed = true;
//                        freeList(&coordOfShips);
//                    }
//                }
//            }
//        }
//    }
//
//    return field;
//}
//
//bool BotHard::checkPositions(int **field, int x, int y, int size, int orientation) {
//    int point1, point2, point3, point4;
//
//    if (orientation == 0) {
//
//        if (x > 0)
//            point1 = x - 1;
//        else
//            point1 = x;
//
//        if (x + size + 1 <= 10)
//            point2 = x + size + 1;
//        else
//            point2 = x + size;
//
//        if (y > 0)
//            point3 = y - 1;
//        else
//            point3 = y;
//
//        if (y + 1 > 9)
//            point4 = y;
//        else
//            point4 = y + 1;
//
//        for (int i = point1; i < point2; ++i) {
//            for (int j = point3; j <= point4; ++j) {
//                if (field[i][j] != 0)
//                    return false;
//            }
//        }
//
//        return true;
//    } else {
//        if (y > 0)
//            point1 = y - 1;
//        else
//            point1 = y;
//
//        if (y + size + 1 <= 10)
//            point2 = y + size + 1;
//        else
//            point2 = y + size;
//
//        if (x > 0)
//            point3 = x - 1;
//        else
//            point3 = x;
//
//        if (x + 1 > 9)
//            point4 = x;
//        else
//            point4 = x + 1;
//
//        for (int i = point1; i < point2; ++i) {
//            for (int j = point3; j <= point4; ++j) {
//                if (field[j][i] != 0)
//                    return false;
//            }
//        }
//
//        return true;
//    }
//}
//
//void BotHard::addEmptyCells() {
//    for (int i = 0; i < 10; ++i) {
//        for (int j = 0; j < 10; ++j) {
//            if (enemyField[i][j] == 2) {
//                if (i - 1 >= 0 && j - 1 >= 0)
//                    enemyField[i - 1][j - 1] = 1;
//
//                if (i - 1 >= 0 && enemyField[i - 1][j] != 2)
//                    enemyField[i - 1][j] = 1;
//
//                if (i - 1 >= 0 && j + 1 <= 9)
//                    enemyField[i - 1][j + 1] = 1;
//
//                if (j - 1 >= 0 && enemyField[i][j - 1] != 2)
//                    enemyField[i][j - 1] = 1;
//
//                if (j + 1 <= 9 && enemyField[i][j + 1] != 2)
//                    enemyField[i][j + 1] = 1;
//
//                if (i + 1 <= 9 && j - 1 >= 0)
//                    enemyField[i + 1][j - 1] = 1;
//
//                if (i + 1 <= 9 && enemyField[i + 1][j] != 2)
//                    enemyField[i + 1][j] = 1;
//
//                if (i + 1 <= 9 && j + 1 <= 9)
//                    enemyField[i + 1][j + 1] = 1;
//
//            }
//        }
//    }
//}
//
//void BotHard::statusGame(int isHit) {
//
//    if (isHit == -1) {
//        enemyField[xOfLastHit][yOfLastHit] = 1;
//    }
//
//    if (isHit > 0) {
//        arrayOfDeathShips[isHit]--;
//        if ((arrayOfDeathShips[numberOfFile] == 0 && numberOfFile >= 1) || sizeList(listOfCoord) == 0) {
//            numberOfFile--;
//            freeList(&listOfCoord);
//            switch (numberOfFile) {
//                case 1:
//                    strcpy(nameOfFile, "../Resources/Txt/PointsFor1");
//                    insertListFromFile(&listOfCoord, nameOfFile);
//                    break;
//                case 2:
//                    strcpy(nameOfFile, "../Resources/Txt/PointsFor2");
//                    insertListFromFile(&listOfCoord, nameOfFile);
//                    break;
//                case 3:
//                    strcpy(nameOfFile, "../Resources/Txt/PointsFor3");
//                    insertListFromFile(&listOfCoord, nameOfFile);
//                    break;
//            }
//        }
//        hit = false;
//        freeList(&listOfHit);
//        enemyField[xOfLastHit][yOfLastHit] = 2;
//        addEmptyCells();
//    }
//
//    if (isHit == 0) {
//        hit = true;
//        enemyField[xOfLastHit][yOfLastHit] = 2;
//        insertNode(&listOfHit, xOfLastHit, yOfLastHit);
//    }
//}
//
//struct coordinates BotHard::giveCoordinates() {
//    struct coordinates coord{};
//
//    if (hit) {
//        if (sizeList(listOfHit) == 1) {
//            coord = giveCoord(listOfHit, 0);
//
//            if (coord.x - 1 >= 0 && enemyField[coord.x - 1][coord.y] != 1)
//                coord.x--;
//            else {
//                if (coord.x + 1 <= 9 && enemyField[coord.x + 1][coord.y] != 1)
//                    coord.x++;
//                else {
//                    if (coord.y - 1 >= 0 && enemyField[coord.x][coord.y - 1] != 1)
//                        coord.y--;
//                    else {
//                        if (coord.y + 1 <= 9 && enemyField[coord.x][coord.y + 1] != 1)
//                            coord.y++;
//                    }
//                }
//            }
//        } else {
//            int xOfMin, yOfMin, xOfMax, yOfMax;
//
//            xOfMax = giveMaxCoord(listOfHit).x;
//            yOfMax = giveMaxCoord(listOfHit).y;
//
//            xOfMin = giveMinCoord(listOfHit).x;
//            yOfMin = giveMinCoord(listOfHit).y;
//
//            if (xOfMin - xOfMax == 0) {
//                if (yOfMin - 1 >= 0 && enemyField[xOfMin][yOfMin - 1] != 1) {
//                    coord.y = yOfMin - 1;
//                    coord.x = xOfMin;
//                } else if (yOfMax + 1 <= 9 && enemyField[xOfMax][yOfMax + 1] != 1) {
//                    coord.y = yOfMax + 1;
//                    coord.x = xOfMax;
//                }
//            } else {
//                if (xOfMin - 1 >= 0 && enemyField[xOfMin - 1][yOfMin] != 1) {
//                    coord.x = xOfMin - 1;
//                    coord.y = yOfMin;
//                } else if (xOfMax + 1 <= 9 && enemyField[xOfMax + 1][yOfMax] != 1) {
//                    coord.x = xOfMax + 1;
//                    coord.y = yOfMax;
//                }
//            }
//        }
//    } else {
//        do {
//            coord = giveCoord(listOfCoord, randomNumber(sizeList(listOfCoord)));
//        } while (enemyField[coord.x][coord.y] != 0);
//
//        removeNode(&listOfCoord, coord.x, coord.y);
//    }
//
//    xOfLastHit = coord.x;
//    yOfLastHit = coord.y;
//
//    return coord;
//}
//
//int **BotHard::getEnemyField() const {
//    return enemyField;
//}

