#include <SFML/Graphics.hpp>
#include "Headers/placement_field.h"
//#include "Headers/placement_field.h"
//#include "Headers/connect_type.h"
//#include "Headers/input_code.h"
//#include "Headers/dif_levels.h"
//#include "Headers/window_exit.h"
//#include "Headers/instruction_manual.h"
//#include "Headers/main_menu.h"

int main() {
    //RenderWindow window(sf::VideoMode(1846, 1048), "SFML works!");
    // sf::RenderWindow _yes(sf::VideoMode(1836, 1048),"Battlership");
    //main_menu window(_yes);

    srand(time(nullptr));


//главное окно и все остальные от него
    sf::RenderWindow window(sf::VideoMode(1846, 1048), "Battlership");
//
//    main_menu main_window(window);
//    main_window.main_menu_run();

//поля для игры
//    play_window window_play(window);
//    window_play.play_window_run();
bool flag = true;
//поле для расстановки
placement_field placementField(window);
placementField.placement_field_run(1,flag);

//окно выбора типа подключения
//connect_type window_connect_type(window);
//window_connect_type.connect_type_run();

//окно ввода для подключения в server
//input_code window_input_code(window);
//window_input_code.input_code_run();

//выбор сложности игры с ботом
//dif_levels window_dif_levels(window);
//window_dif_levels.dif_levels_run();

//окна запроса на завершение игры
//window_exit window_end(window);
//window_end.window_exit_run();




//    Player player;
//    for (int i = 0; i < 10; ++i) {
//        player.autoPositioningOfShips();
//
//        //ListNodeShips* listNodeShips = player.getListOfMyShips();
//        //printf("\n\n");
//        showArray(player.getMyField(),10,10);
//        printf("\n\n");
//    }
    //showList(listNodeShips);

    return 0;
}
