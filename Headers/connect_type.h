#ifndef COURSEWORK_CONNECT_TYPE_H
#define COURSEWORK_CONNECT_TYPE_H
#include <SFML/Graphics.hpp>

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
    sf::RectangleShape tmp;

public:
    connect_type(sf::RenderWindow &other) : window(other)
    {
        background.loadFromFile("../Resources/Img/Type connect/w_connect_type.png");
       // background.loadFromFile("../Resources/Img/Type connect/w_connect_type_without.png");
        sprite_background.setTexture(background);

        //texture_atlas.loadFromFile("../Resources/Img/Type connect/w_connect_type.png");
        button_client.loadFromFile("../Resources/Img/Type connect/button_client.png");
        sprite_button_client.setTexture(button_client);
        //sprite_button_client.setTextureRect(sf::IntRect(573.f,280.f,700.f, 125.f));
        sprite_button_client.setPosition(sf::Vector2f(573.f,280.f));

        button_server.loadFromFile("../Resources/Img/Type connect/button_server.png");
        sprite_button_server.setTexture(button_server);
        sprite_button_server.setPosition(sf::Vector2f(573.f,450.f));

        button_exit.loadFromFile("../Resources/Img/Type connect/button_exit.png");
        sprite_button_exit.setTexture(button_exit);
        sprite_button_exit.setPosition(sf::Vector2f(573.f,620.f));

        //position client
//        tmp.setSize(sf::Vector2f(700.f, 125.f));
//        tmp.setFillColor(sf::Color(255, 255, 255, 128));
//        tmp.setPosition(573.f,280.f);

        //position server
//        tmp.setSize(sf::Vector2f(700.f, 125.f));
//        tmp.setFillColor(sf::Color(255, 255, 255, 128));
//        tmp.setPosition(573.f,450.f);
//
//        //position exit
        tmp.setSize(sf::Vector2f(700.f, 125.f));
        tmp.setFillColor(sf::Color(255, 255, 255, 128));
        tmp.setPosition(573.f,620.f);

    }
    void connect_type_run();

};


#endif //COURSEWORK_CONNECT_TYPE_H
