#pragma once
#include <stdio.h>
#include <stdlib.h>
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
typedef ListNode* List;

void showList(List);
bool isEmpty(List);
void freeList(List*);
void insertListFromFile(List*, char*);
void insertNode(List*, int, int);
bool checkFile(char*);
int sizeList(List);
void removeNode(List*, int);
int randomNumber(int);
struct coordinates giveCoord(List, int);
