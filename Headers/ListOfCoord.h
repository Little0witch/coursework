#pragma once
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <unistd.h>

struct node{
    int x;
    int y;
    struct node* next;
};

struct coordinates{
    int x;
    int y;
};

typedef struct node ListNode;
typedef ListNode* ListOfCoord;

void showList(ListOfCoord);
bool isEmpty(ListOfCoord);
void freeList(ListOfCoord*);
void insertListFromFile(ListOfCoord*, char*);
void insertNode(ListOfCoord*, int, int);
bool checkFile(char*);
int sizeList(ListOfCoord);
void removeNode(ListOfCoord*, int);
int randomNumber(int);
struct coordinates giveCoord(ListOfCoord, int);
bool findNode(ListOfCoord, int, int);
void removeNode(ListOfCoord*, int, int);
struct coordinates giveMinCoord(ListOfCoord);
struct coordinates giveMaxCoord(ListOfCoord);
