#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "List.h"
#include "Array.h"

class Bot{
private:
    int** field = nullptr;
    bool hit;
    bool theFirstHit;
    int x,y;
    List head;

public:

    Bot(){
        hit = false;
        theFirstHit = true;
        x = y = -1;
        field = allocateMemory(field,10,10);
        init(field,10,10);
        insertListFromFile(&head,"/home/user/CLionProjects/coursework/Resources/Txt/PointsFor4");
    }

    struct coordinates givePoints(bool);


    virtual ~Bot();
};

Bot::~Bot() {
    freeMemory(field,10);
    freeList(&head);
}




