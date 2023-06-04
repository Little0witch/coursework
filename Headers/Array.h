#pragma once

#include <cstdio>
#include <cstdlib>
#include "Logs.h"


void freeMemory(int **array, int n);

int **allocateMemory(int **array, int n, int m);

void init(int **array, int n, int m);

void showArray(int **array, int n, int m);

char *allocateMemoryForString(char *, int n);


