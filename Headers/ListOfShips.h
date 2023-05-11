#pragma once
#include <cstdio>
#include <cstdlib>
#include "ListOfCoord.h"

struct Node{
    bool destroy;
    int size;
    int hit;
    ListOfCoord list = nullptr;
    int orientation;
    struct Node* next;
};


typedef struct Node ListNodeShips;
typedef ListNodeShips* ListOfShips;

void showList(ListOfShips);
bool isEmpty(ListOfShips);
void freeList(ListOfShips*);
void insertNode(ListOfShips*, ListOfCoord, int);
int sizeList(ListOfShips);
void autoRemoveNode(ListOfShips*);
int isHit(ListOfShips,ListOfShips*, int, int);
struct coordinateOfShip giveCoordOfShip(ListOfShips, int);

