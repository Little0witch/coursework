#include "../Headers/Game.h"

bool statusGame(int** field) {
    int valueOfShips = 0;

    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            if (field[i][j] == 3)
                valueOfShips++;
        }
    }

    if (valueOfShips == 20)
        return true;

    return false;
}
