#include "../Headers/Array.h"

void freeMemory(int **array, int n) {
    for (int i = 0; i < n; i++) {
        free(array[i]);
    }

    free(array);
}

int **allocateMemory(int **array, int n, int m) {
    if (!(array = (int **) malloc(n * sizeof(int *)))) {
        logError(
                "Error 1: memory allocation error, the place where the error occurred: /Headers/Array.cpp, line 14");
        exit(1);
    }

    for (int i = 0; i < n; i++) {
        if (!(array[i] = (int *) malloc(m * sizeof(int)))) {
            logError(
                    "Error 1: memory allocation error, the place where the error occurred: /Headers/Array.cpp, line 21");
            exit(1);
        }
    }

    return array;
}

void init(int **array, int n, int m) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            array[i][j] = 0;
        }
    }
}

void showArray(int **array, int n, int m) {
    if (!array)
        return;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }

}

char *allocateMemoryForString(char *string, int n) {
    if (!(string = (char *) malloc(n))) {
        logError(
                "Error 1: memory allocation error, the place where the error occurred: /Headers/Array.cpp, line 53");
        exit(1);
    }
    return string;
}
