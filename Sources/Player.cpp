#include "../Headers/Player.h"

void Player::autoPositioningOfShips() {
    ListOfCoord coordOfShips = nullptr;
    if (myField == nullptr)
        myField = allocateMemory(myField, 10, 10);
    else {
        myField = nullptr;
        myField = allocateMemory(myField, 10, 10);
    }
    init(myField, 10, 10);

    freeList(&listOfMyShips);

    int sizeOfShips[] = {4, 3, 2, 1};
    int valueOfShips[] = {1, 2, 3, 4};

    bool placed;

    for (int i = 0; i < 4; ++i) {

        int size = sizeOfShips[i];

        for (int j = 0; j < valueOfShips[i]; ++j) {
            placed = false;

            while (!placed) {
                int x = randomNumber(9);
                int y = randomNumber(9);
                int orientation = randomNumber(2);

                if (orientation == 0 && x + size <= 10) {
                    if (checkPositions(myField, x, y, size, orientation)) {
                        for (int k = x; k < x + size; ++k) {
                            insertNode(&coordOfShips, k, y);
                            myField[k][y] = size;
                        }

                        insertNode(&listOfMyShips, coordOfShips, orientation);
                        placed = true;
                        freeList(&coordOfShips);
                    }

                } else if (orientation == 1 && y + size <= 10) {
                    if (checkPositions(myField, x, y, size, orientation)) {
                        for (int k = y; k < y + size; ++k) {
                            insertNode(&coordOfShips, x, k);
                            myField[x][k] = size;
                        }
                        insertNode(&listOfMyShips, coordOfShips, orientation);
                        placed = true;
                        freeList(&coordOfShips);
                    }
                }
            }
        }
    }
}

bool Player::checkPositions(int **field, int x, int y, int size, int orientation) {
    int point1, point2, point3, point4;

    if (orientation == 0) {

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
                if (field[i][j] != 0)
                    return false;
            }
        }

        return true;
    } else {
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

Player::~Player() {
    if (myField != nullptr)
        freeMemory(myField, 10);
    if (enemyField != nullptr)
        freeMemory(enemyField,10);

    if (listOfMyShips != nullptr)
        freeList(&listOfMyShips);
}

int **Player::getMyField() const {
    return myField;
}

ListNodeShips *Player::getListOfMyShips() const {
    return listOfMyShips;
}

void Player::addEmptyCells() {
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            if (enemyField[i][j] == 2) {
                if (i - 1 >= 0 && j - 1 >= 0)
                    enemyField[i - 1][j - 1] = 1;

                if (i - 1 >= 0 && enemyField[i - 1][j] != 2)
                    enemyField[i - 1][j] = 1;

                if (i - 1 >= 0 && j + 1 <= 9)
                    enemyField[i - 1][j + 1] = 1;

                if (j - 1 >= 0 && enemyField[i][j - 1] != 2)
                    enemyField[i][j - 1] = 1;

                if (j + 1 <= 9 && enemyField[i][j + 1] != 2)
                    enemyField[i][j + 1] = 1;

                if (i + 1 <= 9 && j - 1 >= 0)
                    enemyField[i + 1][j - 1] = 1;

                if (i + 1 <= 9 && enemyField[i + 1][j] != 2)
                    enemyField[i + 1][j] = 1;

                if (i + 1 <= 9 && j + 1 <= 9)
                    enemyField[i + 1][j + 1] = 1;

            }
        }
    }

}

Player::Player() {
    enemyField = allocateMemory(enemyField, 10, 10);
    init(enemyField, 10, 10);
}

void Player::addHit(int x, int y, int isHit) {
    if (isHit > 1) {
        enemyField[x][y] = 2;
        addEmptyCells();
    }
    if (isHit == -1) {
        enemyField[x][y] = -1;
    } else {
        enemyField[x][y] = 2;
    }

}

int **Player::getEnemyField() const {
    return enemyField;
}






