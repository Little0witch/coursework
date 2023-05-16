#include <SFML/Graphics.hpp>
#include "../Headers/main_menu.h"

int main() {
    srand(time(nullptr));

//главное окно и все остальные от него
//    sf::RenderWindow window(sf::VideoMode(1846, 1048), "Battlership");
//
//    main_menu main_window(window);
//    main_window.main_menu_run();

    sf::RenderWindow window(sf::VideoMode(1846, 1048), "Battlership");
//окно выбора типа подключения
    connect_type window_connect_type(window);
    window_connect_type.connect_type_run();

    return 0;
}
