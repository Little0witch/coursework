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
    connect_type(sf::RenderWindow &other) : window(other) {

        if (!background.loadFromFile("../Resources/Img/Type connect/w_connect_type.png")) {
            logError(
                    "Error 2: file opening error, the place where the error occurred: /Headers/connect_type.h, line 29");
            exit(1);
        }

        sprite_background.setTexture(background);

        if (!button_client.loadFromFile("../Resources/Img/Type connect/button_client.png")) {
            logError(
                    "Error 2: file opening error, the place where the error occurred: /Headers/connect_type.h, line 37");
            exit(1);
        }

        sprite_button_client.setTexture(button_client);
        sprite_button_client.setPosition(sf::Vector2f(573.f, 280.f));

        if (!button_server.loadFromFile("../Resources/Img/Type connect/button_server.png")) {
            logError(
                    "Error 2: file opening error, the place where the error occurred: /Headers/connect_type.h, line 46");
            exit(1);
        }

        sprite_button_server.setTexture(button_server);
        sprite_button_server.setPosition(sf::Vector2f(573.f, 450.f));

        if (!button_exit.loadFromFile("../Resources/Img/Type connect/button_exit.png")) {
            logError(
                    "Error 2: file opening error, the place where the error occurred: /Headers/connect_type.h, line 55");
            exit(1);
        }

        sprite_button_exit.setTexture(button_exit);
        sprite_button_exit.setPosition(sf::Vector2f(573.f, 620.f));
    }

    void connect_type_run();

};


#endif //COURSEWORK_CONNECT_TYPE_H
