#include <SFML/Graphics.hpp>
#include "../Headers/MainMenu.h"

int main() {
    srand(time(nullptr));

    sf::RenderWindow window(sf::VideoMode(1846, 1048), "Battlership");

    MainMenu mainWindow(window);
    mainWindow.mainMenuRun();

    return 0;
}
