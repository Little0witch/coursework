#include <SFML/Graphics.hpp>
#include "../Headers/main_menu.h"

int main() {
    srand(time(nullptr));

//главное окно и все остальные от него
    sf::RenderWindow window(sf::VideoMode(1846, 1048), "Battlership");

    main_menu main_window(window);
    main_window.main_menu_run();

    return 0;
}
