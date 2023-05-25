#ifndef COURSEWORK_PLACEMENT_FIELD_H
#define COURSEWORK_PLACEMENT_FIELD_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include "ListOfShips.h"
#include "Player.h"
#include "play_window.h"
#include "socket.h"


class placement_field {
private:
    sf::RenderWindow &window;
    sf::Texture background;
    sf::Texture texture_atlas;
    sf::Texture texture_atlas_1;

    sf::Texture button_back_red;
    sf::Texture button_auto_blue;
    sf::Texture button_auto_red;
    sf::Texture button_reset_blue;
    sf::Texture button_reset_red;
    sf::Texture button_play_blue;
    sf::Texture button_play_red;

    sf::Sprite sprite_background_texture_atlas;
    sf::Sprite sprite_background;
    sf::Sprite sprite_button_back;
    sf::Sprite sprite_button_auto;
    sf::Sprite sprite_button_reset;
    sf::Sprite sprite_button_play;
    sf::Sprite sprite_ships;

    sf::Sprite sprite_button_auto_red;
    sf::Sprite sprite_button_reset_red;
    sf::Sprite sprite_button_play_red;

    sf::Texture shipOf1;
    sf::Texture shipOf2;
    sf::Texture shipOf3;
    sf::Texture shipOf4;

    sf::Sprite ships[10];

    //флаг нажатия на автоматическую расстановку
    bool flag_auto_pressed = false;
    bool red_auto = false;
    bool red_play = false;

public:
    placement_field(sf::RenderWindow &other_window) : window(other_window)
    {
        background.loadFromFile("../Resources/Img/Ships/placement_window.png");
        sprite_background.setTexture(background);

        texture_atlas.loadFromFile("../Resources/Img/Ships/window_field.png");

        sprite_button_back.setTexture(texture_atlas);
        sprite_button_back.setTextureRect(sf::IntRect(170.f,20.f, 350.f,140.f));
        sprite_button_back.setPosition(sf::Vector2f(170.f,20.f));

        sprite_ships.setTexture(texture_atlas);
        sprite_ships.setTextureRect(sf::IntRect(1025.f,283.f,570.f,400.f));
        sprite_ships.setPosition(1025.f,283.f);

        sprite_button_reset.setTexture(texture_atlas);
        sprite_button_reset.setTextureRect(sf::IntRect(1028.f,742.f,113.f,110.f));
        sprite_button_reset.setPosition(sf::Vector2f(1028.f,742.f));

        sprite_button_auto.setTexture(texture_atlas);
        sprite_button_auto.setTextureRect(sf::IntRect(1190.f,742.f,240.f,110.f));
        sprite_button_auto.setPosition(sf::Vector2f(1190.f,742.f));

        sprite_button_play.setTexture(texture_atlas);
        sprite_button_play.setTextureRect(sf::IntRect(1483.f,742.f,113.f,110.f));
        sprite_button_play.setPosition(sf::Vector2f(1483.f,742.f));

        button_reset_red.loadFromFile("../Resources/Img/Ships/button_reset_red.png");
        sprite_button_reset_red.setTexture(button_reset_red);
        sprite_button_reset_red.setPosition(sf::Vector2f(1028.f,742.f));

        button_auto_red.loadFromFile("../Resources/Img/Ships/button_auto_red.png");
        sprite_button_auto_red.setTexture(button_auto_red);
        sprite_button_auto_red.setPosition(sf::Vector2f(1190.f,742.f));

        button_play_red.loadFromFile("../Resources/Img/Ships/button_play_red.png");
        sprite_button_play_red.setTexture(button_play_red);
        sprite_button_play_red.setPosition(sf::Vector2f(1483.f,742.f));


        texture_atlas_1.loadFromFile("../Resources/Img/Ships/m_all_ships.png");
        for (auto & ship : ships) {
            ship.setTexture(texture_atlas_1);
        }

        ships[0].setTextureRect(sf::IntRect(0.f, 0.f,228.f,56.f));//4

        ships[1].setTextureRect(sf::IntRect(0.f,123.5, 169.f,54.5));//3
        ships[2].setTextureRect(sf::IntRect(0.f,123.5, 169.f,54.5));//3

        ships[3].setTextureRect(sf::IntRect(0.f,230.f,112.f,56.f));//2
        ships[4].setTextureRect(sf::IntRect(0.f,230.f,112.f,56.f));//2
        ships[5].setTextureRect(sf::IntRect(0.f,230.f,112.f,56.f));//2

        ships[6].setTextureRect(sf::IntRect(0.f,344.f,56.f,56.f));//1
        ships[7].setTextureRect(sf::IntRect(0.f,344.f,56.f,56.f));//1
        ships[8].setTextureRect(sf::IntRect(0.f,344.f,56.f,56.f));//1
        ships[9].setTextureRect(sf::IntRect(0.f,344.f,56.f,56.f));//1

    }
    void placement_field_run(int, bool &flag);//0 online 1 soft 2 hard
    void placement_field_run(int, bool &flag, bool& flagOfReturn, struct dataOfSocket);//0 online 1 soft 2 hard
    void set_placement(ListOfShips);
    void show_placement();
};


#endif //COURSEWORK_PLACEMENT_FIELD_H
