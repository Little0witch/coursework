#include <SFML/Graphics.hpp>
#include "../Headers/main_menu.h"
//#include "../Headers/socket.h"

int main() {

    srand(time(nullptr));


//главное окно и все остальные от него
    //sf::RenderWindow window(sf::VideoMode(1846, 1048), "Battlership");
//
//    main_menu main_window(window);
//    main_window.main_menu_run();

//поля для игры
//    play_window window_play(window);
//    window_play.play_window_run();
//поле для расстановки
//    bool flag = false;
//placement_field placementField(window);
//placementField.placement_field_run(2,flag);



    sf::RenderWindow window(sf::VideoMode(1846, 1048), "Battlership");
//окно выбора типа подключения
    connect_type window_connect_type(window);
    window_connect_type.connect_type_run();




//окно ввода для подключения в server
//input_code window_input_code(window);
//window_input_code.input_code_run();





    return 0;
}
