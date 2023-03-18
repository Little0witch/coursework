#include <stdio.h>
#include <stdlib.h>

struct node
{
    int pointOfX;
    int pointOfY;
    struct node* next;
};

typedef struct node ListNode;
typedef ListNode* ListNodePtr;

void printList(ListNodePtr);
int check(ListNodePtr);
void insert(ListNodePtr*);
void countList(ListNodePtr);
void counting_el(ListNodePtr*);
void deleteList(ListNodePtr*);