#include <SFML/Graphics.hpp>
#include "Headers/placement_field.h"
#include "Headers/connect_type.h"
#include "Headers/input_code.h"
#include "Headers/dif_levels.h"

int main()
{
    //RenderWindow window(sf::VideoMode(1846, 1048), "SFML works!");
   // sf::RenderWindow _yes(sf::VideoMode(1836, 1048),"Battlership");
    //main_menu window(_yes);



//главное окно и все остальные от него
    sf::RenderWindow window(sf::VideoMode(1846,1048),"Battlership");
//
//    main_menu main_window(window);
//    main_window.main_menu_run();

//поля для игры
//    play_window window_play(window);
//    window_play.play_window_run();

//поле для расстановки
//placement_field placementField(window);
//placementField.placement_field_run(1);

//окно выбора типа подключения
connect_type window_connect_type(window);
window_connect_type.connect_type_run();

//input_code window_input_code(window);
//window_input_code.input_code_run();

//выбор сложности игры с ботом
//dif_levels window_dif_levels(window);
//window_dif_levels.dif_levels_run();


//
//    BotSoft botSoft1;
//
//    ListOfShips listOfShips = botSoft1.getListOfMyShips();
//
//    struct coordinateOfShip coord{};
//
//    coord = giveCoordOfShip(listOfShips, 2);
//    showList(listOfShips);
//
//    printf("\n\n\nx: %d, y: %d, ori: %d, size: %d",coord.x,coord.y,coord.orientation,coord.size);
//
//
   return 0;
}
