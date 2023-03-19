#include "../Headers/Array.h"

void freeMemory(int** array, int n)
{
    for (int i = 0; i < n; i++)
    {
        free(array[i]);
    }

    free(array);
}

int** allocateMemory(int** array, int n, int m)
{
    if (!(array = (int**)malloc(n * sizeof(int*))))
    {
        printf("Память под матрицу не выделилась");
        return nullptr;
    }

    for (int i = 0; i < n; i++)
    {
        if (!(array[i] = (int*)malloc(m * sizeof(int))))
        {
            printf("Память под матрицу не выделилась");
            return nullptr;
        }
    }

    return array;
}

void init(int** array, int n, int m)
{
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            array[i][j] = 0;
        }
    }
}