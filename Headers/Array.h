#pragma once

#include <stdio.h>
#include <stdlib.h>

void freeMemory(int **array, int n);

int **allocateMemory(int **array, int n, int m);

void init(int **array, int n, int m);

void showArray(int **array, int n, int m);

char *allocateMemoryForString(char *, int n);


