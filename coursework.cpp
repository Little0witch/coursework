#include <SFML/Graphics.hpp>
#include "Headers/ListOfCoord.h"
#include "Headers/Array.h"
#include "Headers/BotHard.h"
#include "Headers/ListOfShips.h"
#include "Headers/BotSoft.h"
#include "Headers/BotHard.h"
#include "Headers/main_menu.h"
#include "Headers/play_window.h"
#include "Headers/placement_field.h"
using namespace sf;

int main()
{
    //RenderWindow window(sf::VideoMode(1846, 1048), "SFML works!");
   // sf::RenderWindow _yes(sf::VideoMode(1836, 1048),"Battlership");
    //main_menu window(_yes);


    sf::RenderWindow window(sf::VideoMode(1846,1048),"Battlership");

//главное окно и все остальные от него
//    main_menu main_window(window);
//    main_window.main_menu_run();

//поля для игры
    play_window window_play(window);
    window_play.play_window_run();

//поле для расстановки
//placement_field placementField(window);
//placementField.placement_field_run();



//    BotSoft botSoft1;
//    BotHard botHard;
//
//    ListOfShips listOfShips1 = nullptr;
//    ListOfShips listOfShips2 = nullptr;
//
//    listOfShips1 = botSoft1.getListOfMyShips();
//    listOfShips2 = botHard.getListOfMyShips();
//
//    int** field1 = botSoft1.getMyField();
//    int** field2 = botHard.getMyField();
//
//    showArray(field1,10,10);
//    printf("\n");
//    showArray(field2,10,10);
//    printf("\n");
//
//
//    int x,y;
//    int flag = -1;
//    struct coordinates coord{};
//
//    while (sizeList(listOfShips1) > 0)
//    {
//        printf("\nInput x: ");
//        scanf("%d",&x);
//
//
//        do {
//            coord = botHard.giveCoordinates();
//            printf("\nx: %d, y: %d",coord.x,coord.y);
//            flag = isHit(listOfShips1,&listOfShips1,coord.x,coord.y);
//            printf("flag = %d",flag);
//            botHard.statusGame(flag);
//        } while (flag >= 0);
//
//    }
//
//    printf("\n\n\n\nbbbbbbbbb");
    return 0;
}
