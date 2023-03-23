#include <SFML/Graphics.hpp>
#include "Headers/ListOfCoord.h"
#include "Headers/Array.h"
#include "Headers/BotHard.h"
#include "Headers/ListOfShips.h"
#include "Headers/BotSoft.h"


using namespace sf;

int main()
{
    //RenderWindow window(sf::VideoMode(1846, 1048), "SFML works!");

    /*BotSoft botSoft1;
    BotSoft botSoft2;

    ListOfShips listOfShips1 = nullptr;
    ListOfShips listOfShips2 = nullptr;

    listOfShips1 = botSoft1.getListOfMyShips();
    listOfShips2 = botSoft2.getListOfMyShips();

    int** field1 = botSoft1.getMyField();
    int** field2 = botSoft2.getMyField();

    showArray(field1,10,10);
    printf("\n");
    showArray(field2,10,10);
    printf("\n");


    int x,y;
    int flag = -1;
    struct coordinates coord;

    while (true)
    {
        do {
            printf("\nInput x: ");
            scanf("%d",&x);
            printf("Input y: ");
            scanf("%d",&y);

            flag = isHit(listOfShips2,x,y);
            printf("flag = %d",flag);
        }while(flag > 0);


        do {
            coord = botSoft2.giveCoordinates();
            printf("\nx: %d, y: %d",coord.x,coord.y);
            flag = isHit(listOfShips1,coord.x,coord.y);
            printf("flag = %d",flag);
            botSoft2.statusGame(flag);
        } while (flag >= 0);

    }*/


    ListOfCoord listOfCoord = nullptr;
    ListOfShips listOfShips = nullptr;

    insertNode(&listOfCoord,0,0);
    insertNode(&listOfCoord,0,1);
    insertNode(&listOfCoord,0,2);

    insertNode(&listOfShips,listOfCoord);

    freeList(&listOfCoord);

    insertNode(&listOfCoord,1,0);
    insertNode(&listOfCoord,2,0);

    insertNode(&listOfShips,listOfCoord);

    freeList(&listOfCoord);

    insertNode(&listOfCoord,1,1);
    insertNode(&listOfCoord,2,1);
    insertNode(&listOfCoord,3,1);

    insertNode(&listOfShips,listOfCoord);



    autoRemoveNode(&listOfShips);

    showList(listOfShips);

    isHit(listOfShips,&listOfShips,1,0);
    isHit(listOfShips,&listOfShips,2,0);

    isHit(listOfShips,&listOfShips,1,1);
    isHit(listOfShips,&listOfShips,2,1);
    isHit(listOfShips,&listOfShips,3,1);

    isHit(listOfShips,&listOfShips,0,0);
    isHit(listOfShips,&listOfShips,0,1);
    isHit(listOfShips,&listOfShips,0,2);


    printf("size %d", sizeList(listOfShips));

    return 0;
}
