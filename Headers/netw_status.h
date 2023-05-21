#ifndef COURSEWORK_NETW_STATUS_H
#define COURSEWORK_NETW_STATUS_H
#include <SFML/Graphics.hpp>

#include "../Headers/logs.h"

class netw_status {

private:
    sf::RenderWindow &window;
    sf::Texture background;
    sf::Texture button_ok;

    sf::Sprite sprite_background;
    sf::Sprite sprite_button_ok;
    bool move_ok = false;

public:
    netw_status(sf::RenderWindow &other);
    void netw_status_run();
};


#endif //COURSEWORK_NETW_STATUS_H
