#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "ListOfCoord.h"

struct Node{
    bool destroy;
    int size;
    int hit;
    ListOfCoord list = nullptr;
    struct Node* next;
};


typedef struct Node ListNodeShips;
typedef ListNodeShips* ListOfShips;

void showList(ListOfShips);
bool isEmpty(ListOfShips);
void freeList(ListOfShips*);
void insertNode(ListOfShips*, ListOfCoord);
int sizeList(ListOfShips);
void removeNode(ListOfShips*, int);
int isHit(ListOfShips*, int, int);
