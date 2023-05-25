#ifndef COURSEWORK_CONNECT_TYPE_H
#define COURSEWORK_CONNECT_TYPE_H

#include <SFML/Graphics.hpp>
#include "input_code.h"
#include "get_code.h"

class connect_type {
private:
    sf::RenderWindow &window;
    sf::Texture background;
    sf::Texture texture_atlas;
    sf::Texture button_client;
    sf::Texture button_server;
    sf::Texture button_exit;
    sf::Sprite sprite_background;
    sf::Sprite sprite_button_client;
    sf::Sprite sprite_button_server;
    sf::Sprite sprite_button_exit;

    bool move_client = false;
    bool move_server = false;
    bool move_exit = false;
    bool flagOfReturn = false;

public:
    connect_type(sf::RenderWindow& other);
    void connect_type_run();

};


#endif //COURSEWORK_CONNECT_TYPE_H
